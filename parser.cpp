#include <bits/stdc++.h>

using namespace std;

string ft_trim(string s)
{
    int l;
    int r;

    l = 0;
    r = s.length();
    for (; l < r; l++)
    {
        if (s[l] != ' ')
            break;
    }
    r--;
    for (; r >= 0; r--)
    {
        if (s[r] != ' ')
            break;
    }
    if (r < l)
        return "";
    return s.substr(l, r+1);
}

int get_size(string s)
{
    int n;

    n = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
        {

            cerr << s << " " << " Invalid Input 1\n";
            exit(EXIT_SUCCESS);
        }
        n = n * 10 + (s[i] - '0');
    }
    if (n < 1)
    {
        cerr << "Invalid Input 2\n";
        exit(EXIT_SUCCESS);
    }
    return n;
}

vector<string> str_split(string s)
{
    vector<string> result;
    stringstream ss(s);
    string str;

    while (getline(ss, str, ' '))
        result.push_back(str);
    return result;
}
void get_line(vector<int> &data, string s, int n)
{
    vector<string> line;
    int         nbr;

    line = str_split(s);
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
            cerr << "Invalid Input 4\n";
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
        cout << "Before: " << s << endl;
        s = ft_trim(s);
        cout <<  "After: " << s << endl;
        if (s.length() > 0 && s[0] != '#')
        {
            if (n == -1)
            {
                cout << "call\n";
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
    // cout << stoi("98asc") << endl;
    return 0;
}