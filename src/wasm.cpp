#include <emscripten/bind.h>

#include "options.hpp"
#include "n-puzzle.hpp"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(wasm_n_puzzle)
{
    enum_<E_Algo>("E_Algo")
        .value("A_STAR", E_Algo::A_STAR)
        .value("IDA_STAR", E_Algo::IDA_STAR);

    enum_<E_Method>("E_Method")
        .value("Normal", E_Method::Normal)
        .value("Greedy", E_Method::Greedy)
        .value("Uniform_Cost", E_Method::Uniform_Cost);

    enum_<E_Heuristic>("E_Heuristic")
        .value("MANHATTAN_DISTANCE_PLUS_LNIEAR_CONFLICT", E_Heuristic::MANHATTAN_DISTANCE_PLUS_LNIEAR_CONFLICT)
        .value("DISJOINT_PATTERN_DATABASE", E_Heuristic::DISJOINT_PATTERN_DATABASE);

    class_<Options>("Options")
        .constructor<>()
        .property("algo", &Options::getAlgo, &Options::setAlgo)
        .property("method", &Options::getMethod, &Options::setMethod)
        .property("heuristic", &Options::getHeuristic, &Options::setHeuristic);

    function("nPuzzle", &n_puzzle);
    register_vector<int>("VectorInt");
}
