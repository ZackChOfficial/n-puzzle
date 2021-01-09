import React, { useState, useEffect } from 'react';
import './App.css';
import Board from './components/board'
import Move from './controller/move'

function App() {
  const [numbers, setNumbers] = useState([0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]);
  const [size, setSize] = useState(0);
  const handleClick = (direction) => {
    const newState = Move(numbers, direction, size);
    setNumbers([...newState]);
  }
  useEffect(() => {
    setSize(parseInt(Math.sqrt(numbers.length)));
  }, [numbers])
  return (
    <div className="App">
      <br />
      <div className="sidePanel">
      <button onClick={() => handleClick("U")}>up</button>
      <button onClick={() => handleClick("R")}>right</button>
      <button onClick={() => handleClick("L")}>left</button>
      <button onClick={() => handleClick("D")}>down</button>
      <br />
      </div>
      
      <Board numbers={numbers} size={size} />
    </div>
  );
}

export default App;
