import React from 'react';
import './App.css';
import Board from './components/board'
import Move from './controller/move'

function App() {

  return (
    <div className="App">
      <button onClick={() => Move("U")}>up</button>
      <button onClick={() => Move("R")}>right</button>
      <button onClick={() => Move("L")}>left</button>
      <button onClick={() => Move("D")}>down</button>
      <Board />

    </div>
  );
}

export default App;
