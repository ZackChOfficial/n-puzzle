#include "parser.h"

using namespace std;

string ft_trim(string s)
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
    return s.substr(l, r+1 - l);
}
vector<string> str_split(string s)
{
    vector<string> result;
    int     j;

    for (int i =0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            for (j = i; j < s.length(); j++)
                if (s[j] == ' ')
                    break;
            result.push_back(s.substr(i, j-i));
            i = j;
        }
    }
    return result;
}
int get_size(string s)
{
    int             n;
    vector<string>  line;
    bool            done;

    line = str_split(s);
    done = false;
    for (int i = 0; i < line.size();i++)
    {
        if (line[i][0] != '#' && !done)
            done = true;
        else if ((line[i][0] != '#' && done) || (line[i][0] == '#' && !done))
        {
            cerr << "Invalid Input 23\n";
            exit(EXIT_SUCCESS);
        }
    }
    n = stoi(s);
    if (n < 1)
    {
        cerr << "Invalid Input 2\n";
        exit(EXIT_SUCCESS);
    }
    return n;
}



void get_line(vector<int> &data, string s, int n)
{
    vector<string> line;
    int         nbr;

    line = str_split(s);
    if (line.size() != n)
        throwError();
    for (int i = 0; i < line.size(); i++)
    {
        if (isdigit(line[i][0]))
        {
            nbr = stoi(line[i]);
            if (nbr < 0 || nbr >= n*n)
            {
                cerr << "Invalid Input 3\n";
                exit(EXIT_SUCCESS);
            }
            data.push_back(nbr);
        }
        else
        {
            cerr << "Invalid Input 4:  " << line[i] << "|" << endl;
            exit(EXIT_SUCCESS);
        }
    }
}

vector<int> parse()
{
    vector<int> data;
    string      s;
    int         n;
    set<int>    occu;

    n = -1;
    while (getline(cin, s))
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
    for (int i = 0; i < data.size(); i++)
    {
        if (occu.find(data[i]) != occu.end())
        {
            cerr << "Invalid Input 5\n";
            exit(EXIT_SUCCESS);
        }
        else occu.insert(data[i]);
    }
    if (occu.size() != n*n)
    {
        cerr << "Invalid Input 6\n";
        exit(EXIT_SUCCESS);
    }
    return data;
}

int main()
{
    parse();
    return 0;
}