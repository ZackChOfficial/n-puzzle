import React, { useState, useEffect, useCallback } from 'react';
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

const SelectComponent = styled.div`
  margin: 15px 0;
`

const Actions = styled.div`
  display: flex;
  justify-content: space-between;
  margin: 15px 0;
`
const Input = styled.input`
  width: 370px;
  border-color: hsl(0,0%,80%);
  border-radius: 4px;
  border-style: solid;
  border-width: 1px;
  padding:0 10px;
  font-size:16px;
  color: hsl(0,0%,50%);
  &:hover {
    border-color: hsl(0,0%,70%);
  }
  &:focus, &:active {
    border-color: rgb(75, 148, 244);
    border-width: 2px;
    outline:none;
  }
`
function App() {
  const [selectedAlgo, setSelectedAlgo] = useState('Ida*');
  const [selectedheuristic, setSelectedheuristic] = useState('Pattern databases 6-6-3');
  const [numbers, setNumbers] = useState(solutionSize4);
  const [ArrowUp, keyW] = [useKeyPress("ArrowUp"), useKeyPress("w")];
  const [ArrowRight, keyD] = [useKeyPress("ArrowRight"), useKeyPress("d")]
  const [ArrowDown, keyS] = [useKeyPress("ArrowDown"), useKeyPress("s")]
  const [ArrowLeft, keyA] = [useKeyPress("ArrowLeft"), useKeyPress("a")]
  const [execution, setExcution] = useState(false);

  const handleClick = useCallback((direction) => {
    const newState = Move(numbers, direction);
    setNumbers([...newState]);
  }, [numbers])

  const handleMoves = useCallback(async (moves) => {
    setExcution(true);
    const allStates = PlayMoves(numbers, moves);
    await sleep(speed * 1000);
    for (let i = 0; i < allStates.length; i++) {
      setNumbers([...allStates[i]])
      await sleep(speed * 1000);
    }
    setExcution(false);
  }, [numbers])

  useEffect(() => {
    if (!execution)
      if (ArrowUp || keyW)
        handleClick("U");
      else if (ArrowDown || keyS)
        handleClick("D");
      else if (ArrowRight || keyD)
        handleClick("R");
      else if (ArrowLeft || keyA)
        handleClick("L");
  }, [ArrowUp, ArrowDown, ArrowLeft, ArrowRight, keyW, keyD, keyS, keyA])

  const scramble = useCallback(() => {
    setNumbers(scrambleArray(numbers))
  }, [numbers])
  const reset = useCallback(() => {
    setNumbers(solutionSize4);
  },[solutionSize4])

  const onKeyDown = () => {
    setExcution(true);
  }
  const onKeyUp = (e) => {
    setExcution(false);
  }
  return (
    <div className="App">
      <br />
      <SelectComponent>
        <Select
          styles={{ background: "black" }}

          defaultValue={selectedAlgo}
          onChange={setSelectedAlgo}
          options={algorithms}
          isClearable
          placeholder="Select Algorithm"
        />
      </SelectComponent>
      <Select
        defaultValue={selectedheuristic}
        onChange={setSelectedheuristic}
        options={heuristics}
        isClearable
        placeholder="Select Heuristic Function"
      />
      <Actions>
        <Input type="text" onKeyDown={onKeyDown} onKeyUp={onKeyUp}/>
        <button>Run</button>
      </Actions>
      <Actions>
        <button onClick={scramble}> Scramble Board </button>
        <button onClick={() => handleMoves("D L L U U R R R D D")}> Solve </button>
        <button onClick={reset}> Reset </button>
      </Actions>
      <br />
      {
        numbers.length > 0 ?
          <Board numbers={numbers} size={parseInt(Math.sqrt(numbers.length))} />
          : "Loading"
      }
    </div>
  );
}

export default App;
