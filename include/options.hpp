#pragma once

enum class E_Method {
    NONE,
    Normal,
    Greedy,
    Uniform_Cost
};

enum class E_Heuristic{
    NONE,
    MANHATTAN_DISTANCE_PLUS_LNIEAR_CONFLICT,
    DISJOINT_PATTERN_DATABASE
};

enum class E_Algo{
    NONE,
    A_STAR,
    IDA_STAR
};

struct Options
{
    E_Algo algo;
    E_Method method;
    E_Heuristic heuristic;

    Options() : algo(E_Algo::NONE), method(E_Method::NONE), heuristic(E_Heuristic::NONE){};
};
