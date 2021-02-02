import swap from '../utils/swap'
import Move from './move'

export default function scrambleArray(state)
{
 let newState   = [...state];

 const moves = ["U", "D", "L", "R"];

 for (let i =0; i < 50000; i++)
 {
    let m = parseInt( Math.random() * 4);
    newState = Move(newState, moves[m])
 }
 return newState
}