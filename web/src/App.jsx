import React, {useState, useEffect} from 'react';
import './App.css';
import Board from './components/board'
import Move from './controller/move'

function App() {
 
  return (
    <div className="App">
      <br/><br/><br/>
      <Board/>
    </div>
  );
}

export default App;
