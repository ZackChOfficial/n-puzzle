import move from './move'




function invalidMove(move) {
    return  move != 'D' && 
        move != 'U' &&  move != 'L' &&  move != 'R';
}
export default function playMoves(state, moves) {
    const movesToPlay = moves.split(/ +/)
    const allStates = []
    let current = [...state]
    for (let i = 0; i < movesToPlay.length; i++) {
        if (invalidMove(movesToPlay[i]))
            return [movesToPlay[i], i];
        allStates.push(move(current, movesToPlay[i]));
        if (JSON.stringify(current) == JSON.stringify(allStates[allStates.length - 1]))
            return [movesToPlay[i], i];
        current = [...allStates[allStates.length - 1]]
    }
    return allStates
}