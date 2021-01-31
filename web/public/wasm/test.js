const factory = require("./n-puzzle");

factory().then(Module =>{
      // const b  = [8, 6, 0, 7, 2, 5, 1, 3, 4];
      const b  = [4, 10, 1, 2, 14, 6, 15, 9, 8, 0, 7, 13, 3, 12, 5, 11];
      const bv = new Module.VectorInt();
      for (const e of b)
          bv.push_back(e);
      const opts = new Module.Options();
    //   opts.heuristic =  Module.E_Heuristic.DISJOINT_PATTERN_DATABASE;
      console.log(Module.nPuzzle(bv, opts));
})