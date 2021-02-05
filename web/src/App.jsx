import React, { useState, useEffect, useCallback, useRef } from 'react';
import './App.css';
import Board from './components/board'
import Move from './controller/move'
import useKeyPress from './hooks/useKeyPress'
import Select from "react-select";
import styled from 'styled-components'
import { algorithms, heuristics, solutionSize4, solutionSize3, speed } from './config'
import PlayMoves from './controller/playMoves'
import scrambleArray from './controller/scramble'
import sleep from './utils/sleep'
import Header from './components/header'
import Footer from './components/footer'
import Description from './components/description'
import Github from './assets/github.png'
import { sizes } from './config'

const SelectComponent = styled.div`
  margin: 15px 0;
  text-align:left;
`

const Img = styled.img`
  cursor: pointer;
  position: absolute;
  right: 20px;
  top:10px;
  width: 40px;
`

const Actions = styled.div`
  display: flex;
  justify-content: space-between;
  margin: 15px 0;
`
const Input = styled.input`
  width: 70%;
  border-color: ${props => props.error ? "#ff1d44" : "#ccc"};
  border-radius: 4px;
  border-style: solid;
  border-width: 1px;
  padding:0 10px;
  font-size:16px;
  color: ${props => props.error ? "#ff1d44" : "#808080"};
  &:hover {
    border-color: #b3b3b3;
  }
  &:focus, &:active {
    border-color: rgb(75, 148, 244);
    border-width: 2px;
    outline:none;
  }
  &::placeholder { 
    color:  ${props => props.error ? "#ff1d44" : "#808080"};;
  }
`
const Button = styled.button`
  background-color: ${props => props.solved ? "#f5f5f5" : "#1c7ed6"};
  border: 1px solid ${props => props.solved ? "#d9d9d9" : "#1c7ed6"};
  color: ${props => props.solved ? "#00000040" : "#fff"};
  cursor:  ${props => props.solved ? "not-allowed" : "pointer"};

  &:hover {
    background-color: ${props => props.solved ? "#f5f5f5" : "#165896"};
    border: 1px solid ${props => props.solved ? "#d9d9d9" : "#165896"};
    color: ${props => props.solved ? "#00000040" : "#fff"};
    cursor:  ${props => props.solved ? "not-allowed" : "pointer"};
  }

`
const Error = styled.div`
color: red;
`
const worker = new Worker('./n-puzzle.worker.js');

function App() {

  const [selectedAlgo, setSelectedAlgo] = useState('');
  const [selectedheuristic, setSelectedheuristic] = useState('');
  const [numbers, setNumbers] = useState([]);
  const [ArrowUp, keyW] = [useKeyPress("ArrowUp"), useKeyPress("w")];
  const [ArrowRight, keyD] = [useKeyPress("ArrowRight"), useKeyPress("d")]
  const [ArrowDown, keyS] = [useKeyPress("ArrowDown"), useKeyPress("s")]
  const [ArrowLeft, keyA] = [useKeyPress("ArrowLeft"), useKeyPress("a")]
  const [execution, setExcution] = useState(false);
  const moves = useRef(null);
  const [invalidMoves, setInvalidMoves] = useState(false);
  const [invalidBoard, setInvalidBoard] = useState(false);
  const [size, setSize] = useState(0);
  const boards = useRef([solutionSize3, solutionSize4])
  const state = useRef(null)
  const run = useRef(null)
  const [loading, setLoading] = useState(false)
  const [error, setError] = useState(false)
  const [solved, setSolved] = useState(true);
  const [solving, setSolving] = useState(false);
  const [sizeDisabled, setSizeDisabled] = useState(false)

  useEffect(() => {
    setNumbers(boards.current[size])
  }, [size])
  
  useEffect(() => {
    worker.addEventListener("message", event => {
      if (event.data !== -1) {
        moves.current.value = event.data;
        setInvalidMoves(false);
        setLoading(false);
        run.current.click();
      }
      else
        setError(true);
    });
    return worker.removeEventListener("message", event => { });
  }, [])

  useEffect(() => {
    if (!execution)
      if (ArrowUp || keyW)
        handleClick("D");
      else if (ArrowDown || keyS)
        handleClick("U");
      else if (ArrowRight || keyD)
        handleClick("L");
      else if (ArrowLeft || keyA)
        handleClick("R");
  }, [ArrowUp, ArrowDown, ArrowLeft, ArrowRight, keyW, keyD, keyS, keyA])

  useEffect(() => {
    let tmp = true;
    for (let i in numbers)
    {
      if (numbers[i] != boards.current[size][i])
      {
        tmp = false;
        break;
      }
    }
    setSolved(tmp)
  }, [numbers]);

  const handleClick = useCallback((direction) => {
    const newState = Move(numbers, direction);
    setNumbers([...newState]);
  }, [numbers])

  const handleMoves = async (moves) => {
    setExcution(true);
    const allStates = PlayMoves(numbers, moves.trim());
    setSizeDisabled(true);
    if (typeof (allStates[0]) == "string")
      setInvalidMoves(true);
    else {
      await sleep(speed * 1000);
      for (let i = 0; i < allStates.length; i++) {
        setNumbers([...allStates[i]])
        await sleep(speed * 1000);
      }
    }
    setExcution(false);
    setSizeDisabled(false);
    setSolving(false);
  };

  const scramble = () => {
    setNumbers(scrambleArray(numbers));
    setInvalidMoves(false);
    setInvalidBoard(false);
    moves.current.value = "";
    state.current.value = "";
  }

  const reset = useCallback(() => {
    setNumbers(boards.current[size]);
  }, [size])

  const handleRun = () => {
    handleMoves(moves.current.value.toUpperCase())
  }

  const loadBoard = () => {
    const num = state.current.value.trim().split(/ +/);
    const sol = boards.current[size].slice().sort((a, b) => a - b);
    if (num.length != sol.length) {
      setInvalidBoard(true);
      return;
    }
    for (let i = 0; i < num.length; i++) {
      if (!Number.isInteger(parseInt(num[i]))) {
        setInvalidBoard(true);
        return;
      }
      num[i] = parseInt(num[i]);
    }
    const arr = num.slice().sort((a, b) => a - b);
    for (let i = 0; i < sol.length; i++) {
      if (arr[i] != sol[i]) {
        setInvalidBoard(true);
        return;
      }
    }
    setNumbers(num);
  }

  const solve = () => {
    if (!selectedheuristic || !selectedAlgo)
      setError(true);
    else {
      setLoading(true);
      let origin = "";
      for (const i of numbers)
        origin += i + " "
      state.current.value = origin;
      setSolving(true);
      worker.postMessage({ numbers, selectedAlgo, selectedheuristic })
      setInvalidBoard(false);
    }
  }
  return (
    <>
      <Img src={Github} onClick={() => { window.location.href = "https://github.com/ZackChOfficial/n-puzzle"; }} alt="Github link" />
      <Description />
      <div className="App">
        <Header />
        <br />
        {error ? <Error> You must choose algorithm and heuristic function first </Error> : ""}
        <SelectComponent>
          <Select
            s
            onChange={
              (e) => {
                if (e) {
                  setSelectedAlgo(e.value)
                  setError(false);
                }
              }
            }
            options={algorithms}
            isDisabled={solving}
            isClearable
            placeholder="Select Algorithm"
          />
        </SelectComponent>
        <SelectComponent>
          <Select
            isDisabled={solving}
            SelectComponent
            onChange={
              (e) => {
                if (e) {
                  setSelectedheuristic(e.value)
                  setError(false);
                }
              }
            }
            options={size == 1 ? heuristics.filter(h => h.value != "MANHATTAN_DISTANCE") : heuristics.filter(h => h.value != "DISJOINT_PATTERN_DATABASE")}
            isClearable
            placeholder="Select Heuristic Function"
          />
        </SelectComponent>
        <Actions>
          <Input type="text" onChange={null} disabled={solving} onKeyDown={() => {
            if (invalidMoves)
              setInvalidMoves(false);
          }}
            ref={moves} error={invalidMoves} placeholder={invalidMoves ? "Invalid Moves" : "Moves to apply"} />
          <Button onClick={handleRun} ref={run} solved={solving}>Run</Button>
        </Actions>
        <Actions>
          <Input type="text" disabled={solving} onKeyDown={() => {
            if (invalidBoard)
              setInvalidBoard(false)
          }} ref={state} error={invalidBoard} placeholder={invalidBoard ? "Invalid State" : "Load State"} />
          <Button onClick={loadBoard} disabled={solving} solved={solving}>Load</Button>
        </Actions>
        <Actions>
          <Button onClick={scramble} disabled={solving} solved={solving}> Scramble Board </Button>
          <Button onClick={solve}  disabled={solved || solving} solved={solved || solving}>  Solve </Button>
          <Button onClick={reset} disabled={solving} solved={solving}> Reset </Button>

          <div style={{ width: "20%", textAlign: "left" }}>
            <Select
              defaultValue={0}

              onChange={(e) => {
                if (e) {
                  setSize(e.value)
                  setInvalidMoves(false);
                  setInvalidBoard(false);
                  setSelectedAlgo("A_STAR")
                  moves.current.value = "";
                  state.current.value = "";
                }
              }}
              isDisabled={sizeDisabled}
              options={sizes.filter(s => s.value !== size)}
              placeholder="size"
            />
          </div>
        </Actions>
        <br />
        {
          numbers.length > 0 ?
            <Board numbers={numbers} size={parseInt(Math.sqrt(numbers.length))} solution={boards.current[size]} loading={loading} />
            : "Loading"
        }
        <Footer />
      </div>
    </>
  );
}

export default App;
