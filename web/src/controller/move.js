function swap(state,i,j) {
    const tmp = state[i];
    state[i] = state[j];
    state[j] = tmp; 
}

export default function move(state, direction, size) {
    let zero;
    for (let i = 0; i < state.length; i++) {
        if (state[i] == 0) {
            zero = i;
            break;
        }
    }
    switch (direction) {
        case "U":
            if (zero - size >= 0)
                swap(state, zero, zero - size);
            break;
        case "R":
            if ((zero + 1)%size != 0)
                swap(state, zero, zero + 1);
            break;
        case "D":
            if (zero + size < state.length)
                swap(state, zero, zero + size);
            break;
        case "L":
            if ((zero)%size  != 0)
                swap(state, zero, zero - 1);
            break;

    }
    return state;
}