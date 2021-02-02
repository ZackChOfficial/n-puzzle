#include <unistd.h>
#include <string.h>

#include "parser.hpp"
#include "n-puzzle.hpp"

std::string ft_trim(std::string s)
{
    int l;
    int r;

    l = 0;
    r = s.length();
    for (; l < r; l++)
        if (s[l] != ' ')
            break;
    r--;
    for (; r >= 0; r--)
        if (s[r] != ' ')
            break;
    if (r < l)
        return "";
    return s.substr(l, r + 1 - l);
}

std::vector<std::string> str_split(std::string s)
{
    std::vector<std::string> result;
    size_t j;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            for (j = i; j < s.length(); j++)
                if (s[j] == ' ')
                    break;
            result.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return result;
}

int get_size(std::string s)
{
    int n;
    std::vector<std::string> line;
    bool done;

    line = str_split(s);
    done = false;
    for (size_t i = 0; i < line.size(); i++)
    {
        if (line[i][0] != '#' && !done && isdigit(line[i][0]))
            done = true;
        else if ((line[i][0] != '#' && done) || (line[i][0] == '#' && !done) || (line[i][0] != '#' && !isdigit(line[i][0])))
            throwError();
    }
    n = stoi(s);
    if (n < 1)
        throwError();
    return n;
}

void get_line(std::vector<int> &data, std::string s, int n)
{
    std::vector<std::string> line;
    int nbr;

    line = str_split(s);
    if (line.size() != (size_t)n)
        throwError();
    for (size_t i = 0; i < line.size(); i++)
    {
        if (isdigit(line[i][0]))
        {
            nbr = stoi(line[i]);
            if (nbr < 0 || nbr >= n * n)
                throwError();
            data.push_back(nbr);
        }
        else
            throwError();
    }
}

std::vector<int> parse()
{
    std::vector<int> data;
    std::string s;
    int n;
    std::set<int> occu;

    n = -1;
    while (std::getline(std::cin, s))
    {
        s = ft_trim(s);
        if (s.length() > 0 && s[0] != '#')
        {
            if (n == -1)
            {
                n = get_size(s);
            }
            else
                get_line(data, s, n);
        }
    }
    for (size_t i = 0; i < data.size(); i++)
    {
        if (occu.find(data[i]) != occu.end())
            throwError();
        else
            occu.insert(data[i]);
    }
    if (occu.size() != size_t(n * n))
        throwError();
    else if (occu.size() > 100)
        throwError("Sorry we can't handle this size.");
    return data;
}

Options cmd_args_parse(int argc, char **argv)
{
    Options options;

    char flags_list[] = "a:h:m:s";

    std::string aval;
    std::string hval;
    std::string mval;

    int c;

    opterr = 0;

    while ((c = getopt(argc, argv, flags_list)) != -1)
    {
        switch (c)
        {
        case 'a':
            aval = optarg;
            break;
        case 'h':
            hval = optarg;
            break;
        case 'm':
            mval = optarg;
            break;
        case 's':
            options.only_steps = true;
            break;
        case '?':
            if (strchr(flags_list, optopt))
            {
                if (optopt == 'h')
                {
                    print_help();
                    exit(EXIT_SUCCESS);
                }
                fprintf(stderr, "Option -%c requires an argument.\n", optopt);
            }
            else if (isprint(optopt))
                fprintf(stderr, "Unknown option `-%c'.\n", optopt);
            else
                fprintf(stderr,
                        "Unknown option character `\\x%x'.\n",
                        optopt);
            exit(1);
        }
    }

    if (aval.length())
    {
        if (aval == "a*" || aval == "a_star")
            options.algo = E_Algo::A_STAR;
        else if (aval == "ida*" || aval == "ida_star")
            options.algo = E_Algo::IDA_STAR;
        else
        {
            std::cerr << "invalid argument for -a option\ntype './n-puzzle -h' for more info\n";
            exit(1);
        }
    }
    if (mval.length())
    {
        if (mval == "normal" || mval == "n")
            options.method = E_Method::Normal;
        else if (mval == "greedy" || mval == "g")
            options.method = E_Method::Greedy;
        else if (mval == "uniform" || mval == "u")
            options.method = E_Method::Uniform_Cost;
        else
        {
            std::cerr << "invalid argument for -m option\ntype './n-puzzle -h' for more info\n";
            exit(1);
        }
    }
    if (hval.length())
    {
        if (hval == "m")
            options.heuristic = E_Heuristic::MANHATTAN_DISTANCE;
        else if (hval == "m+l")
            options.heuristic = E_Heuristic::MANHATTAN_DISTANCE_PLUS_LNIEAR_CONFLICT;
        else if (hval == "dpdb")
            options.heuristic = E_Heuristic::DISJOINT_PATTERN_DATABASE;
        else
        {
            std::cerr << "invalid argument for -h option\ntype './n-puzzle -h' for more info\n";
            exit(1);
        }
    }
    return options;
}
