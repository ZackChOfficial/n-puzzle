import move from './move'


export default function  playMoves (state, moves)
{
    const movesToPlay = moves.split(' ');
    const allStates = []
    let current = [...state]
    for(let i=0; i<movesToPlay.length; i++){
        allStates.push(move(current, movesToPlay[i]));
        current = [...allStates[allStates.length - 1]]
    }
    return allStates
}