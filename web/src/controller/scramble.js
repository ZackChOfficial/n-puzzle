import swap from '../utils/swap'

export default function scrambleArray(state)
{
 const newState   = [...state];
 
 for (let i =0; i < 50000; i++)
 {
    let index1 = parseInt( Math.random() * state.length);
    let index2 = parseInt( Math.random() * state.length);
    swap(newState, index1, index2)
 }
 return newState
}