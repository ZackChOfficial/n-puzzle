export default function swap(state,i,j) {
    const tmp = state[i];
    state[i] = state[j];
    state[j] = tmp; 
}