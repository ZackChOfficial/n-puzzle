import swap from '../utils/swap'

export default  function move(state, direction) {
    let zero;
    const size = parseInt(Math.sqrt(state.length));
    const newState = [...state];
    for (let i = 0; i < newState.length; i++) {
        if (newState[i] == 0) {
            zero = i;
            break;
        }
    }
    switch (direction) {
        case "U":
            if (zero - size >= 0)
                swap(newState, zero, zero - size);
            break;
        case "R":
            if ((zero + 1)%size != 0)
                swap(newState, zero, zero + 1);
            break;
        case "D":
            if (zero + size < newState.length)
                swap(newState, zero, zero + size);
            break;
        case "L":
            if ((zero)%size  != 0)
                swap(newState, zero, zero - 1);
            break;

    }
    return newState;
}