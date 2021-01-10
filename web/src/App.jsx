import React, { useState, useEffect } from 'react';
import './App.css';
import Board from './components/board'
import Move from './controller/move'
import useKeyPress from './hooks/useKeyPress'


function App() {
  const [numbers, setNumbers] = useState([]);
  const [ArrowUp, keyW] = [useKeyPress("ArrowUp"),useKeyPress("w")];
  const [ArrowRight,keyD] = [useKeyPress("ArrowRight"),useKeyPress("d")]
  const [ArrowDown,keyS] = [useKeyPress("ArrowDown"),useKeyPress("s")]
  const [ArrowLeft,keyA] = [useKeyPress("ArrowLeft"),useKeyPress("a")]
  const handleClick = (direction) => {
    const newState = Move(numbers, direction);
    setNumbers([...newState]);
  }

  useEffect(() => {
    setNumbers([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15])
  }, [])
  useEffect(() => {
    if (ArrowUp || keyW)
      handleClick("D");
    else if (ArrowDown || keyS)
      handleClick("U");
    else if (ArrowRight || keyD)
      handleClick("L");
    else if (ArrowLeft || keyA)
      handleClick("R");
  }, [ArrowUp, ArrowDown,ArrowLeft,ArrowRight,keyW, keyD, keyS,keyA])

  return (
    <div className="App">
      <br />
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
