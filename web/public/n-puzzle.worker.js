import Wasm from './wasm/build/n-puzzle'

addEventListener("message", event => {
  console.log(event.data)
  const {numbers, selectedAlgo: algo, selectedheuristic : heuristic} = event.data;
  // Do stuff with the message
  Wasm().then(Module => {
    // const b  = [8, 6, 0, 7, 2, 5, 1, 3, 4];
    const algos = { "A_STAR": Module.E_Algo.A_STAR, "IDA_STAR": Module.E_Algo.IDA_STAR }
    const heuristics = {
      "MANHATTAN_DISTANCE": Module.E_Heuristic.MANHATTAN_DISTANCE,
      "MANHATTAN_DISTANCE_PLUS_LNIEAR_CONFLICT": Module.E_Heuristic.MANHATTAN_DISTANCE_PLUS_LNIEAR_CONFLICT,
      "DISJOINT_PATTERN_DATABASE": Module.E_Heuristic.DISJOINT_PATTERN_DATABASE
    }

    const bv = new Module.VectorInt();
    for (const e of numbers)
    bv.push_back(e);
    const opts = new Module.Options();
    console.log(numbers, heuristics[heuristic], algos[algo]);
    opts.heuristic = heuristics[heuristic];
    opts.algo = algos[algo]
    postMessage((Module.nPuzzle(bv, opts)));
  })
});