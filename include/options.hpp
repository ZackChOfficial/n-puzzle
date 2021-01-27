#pragma once

enum class E_Method
{
    Normal,
    Greedy,
    Uniform_Cost
};

enum class E_Heuristic
{
    MANHATTAN_DISTANCE_PLUS_LNIEAR_CONFLICT,
    DISJOINT_PATTERN_DATABASE
};

enum class E_Algo
{
    A_STAR,
    IDA_STAR
};

struct Options
{
    E_Algo algo;
    E_Method method;
    E_Heuristic heuristic;

    Options() : algo(E_Algo::A_STAR),
                method(E_Method::Normal),
                heuristic(E_Heuristic::MANHATTAN_DISTANCE_PLUS_LNIEAR_CONFLICT){};
};
