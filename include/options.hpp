#pragma once

enum class E_Algo
{
    A_STAR,
    IDA_STAR
};

enum class E_Method
{
    Normal,
    Greedy,
    Uniform_Cost
};

enum class E_Heuristic
{
    MANHATTAN_DISTANCE,
    MANHATTAN_DISTANCE_PLUS_LNIEAR_CONFLICT,
    DISJOINT_PATTERN_DATABASE
};

struct Options
{
    E_Algo algo;
    E_Method method;
    E_Heuristic heuristic;
    bool only_steps;

    Options() : algo(E_Algo::A_STAR),
                method(E_Method::Normal),
                heuristic(E_Heuristic::MANHATTAN_DISTANCE_PLUS_LNIEAR_CONFLICT),
                only_steps(false)
                {};

    E_Algo getAlgo() const
    {
        return this->algo;
    }
    void setAlgo(E_Algo algo)
    {
        this->algo = algo;
    }

    E_Method getMethod() const
    {
        return this->method;
    }
    void setMethod(E_Method method)
    {
        this->method = method;
    }

    E_Heuristic getHeuristic() const
    {
        return this->heuristic;
    }

    void setHeuristic(E_Heuristic heuristic)
    {
        this->heuristic = heuristic;
    }

    bool getOnlySteps() const
    {
        return this->only_steps;
    }

    void setOnlySteps(bool only_steps)
    {
        this->only_steps = only_steps;
    }
};
