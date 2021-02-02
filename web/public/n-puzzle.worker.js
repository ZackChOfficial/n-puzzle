import Wasm from './wasm/build/n-puzzle'

addEventListener("message", event => {
  // protect cross-site scripting attacks
  if (event.origin !== "http://localhost:8080" && (event.srcElement && event.srcElement.origin !== "http://localhost:8080" ))
    return;
  const {numbers, selectedAlgo: algo, selectedheuristic : heuristic} = event.data;
  if (!numbers || !algo || !heuristic)
  {
    postMessage(-1);
    return ;
  }
  Wasm().then(Module => {
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
    opts.heuristic = heuristics[heuristic];
    opts.algo = algos[algo]
    opts.onlySteps = true;
    postMessage((Module.nPuzzle(bv, opts)));
  })
});