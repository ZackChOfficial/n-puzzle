#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

struct Node
{
    vector<int> state;
    Node *parent;

    Node()
    {
        parent = nullptr;
    }
    Node(vector<int> const &data)
    {
        parent = nullptr;
        state.reserve(data.size());
        copy(data.begin(), data.end(), back_inserter(state));
    }
    vector<Node *> nextStates()
    {
        int index;
        vector<Node *> new_states;
        for (int i = 0; i < state.size(); i++)
            if (state[i] == 0)
            {
                index = i;
                break;
            }
        if (index - sqrt(state.size()) >= 0)
        {
            Node *tmp = new Node(createNew(index, index - sqrt(state.size())));
            new_states.push_back(tmp);
        }
        if (index - 1 >= 0)
        {
            Node *tmp = new Node(createNew(index, index -1));
            new_states.push_back(tmp);
        }
        if (index + 1 < state.size())
        {
            Node *tmp = new Node(createNew(index, index + 1));
            new_states.push_back(tmp);
        }
        if (index + sqrt(state.size()) < state.size())
        {
            Node *tmp = new Node(createNew(index, index + sqrt(state.size())));
            new_states.push_back(tmp);
        }
        return new_states;
    }
    vector<int> createNew(int index1, int index2)
    {
        vector<int> newState(state);
        swap(newState[index1], newState[index2]);
        return newState;
    }
};
bool identical(vector<int> &v1, vector<int> &v2)
{
    if (v1.size() != v2.size())
        return false;
    for (int i = 0; i < v1.size(); i++)
        if (v1[i] != v2[i])
            return false;
    return true;
}
Node *bfs(vector<int> &initial, vector<int> &goal)
{
    queue<Node *> states;
    set<vector<int>> visited;
    set<vector<int>> inQueue;
    Node *root = new Node(initial);
    states.push(root);
    inQueue.insert(root->state);
    int i = 1;
    while (!states.empty())
    {
   
        Node *current = states.front();
        states.pop();
        visited.insert(current->state);
        inQueue.insert(root->state);
        if (identical(current->state, goal))
        {
            cout << i << endl;
            return current;
        }
        vector<Node *> neighbor = current->nextStates();
        for (auto state : neighbor)
        {
            if (visited.find(state->state) == visited.end() && inQueue.find(state->state) == inQueue.end())
            {
                state->parent = current;
                states.push(state);
                inQueue.erase(root->state);
            }
        }
        i++;
    }
   
    return nullptr;
}
void printSol(Node *sol)
{
    if (sol->parent != nullptr)
    {
        printSol(sol->parent);
        cout << "\n  |\n";
        cout << "  v\n\n";
    }
    for (int i =0; i < sqrt(sol->state.size()); i++)
    {
        for (int j= 0; j<sqrt(sol->state.size()); j++)
        cout << sol->state[i*sqrt(sol->state.size())+j] << " ";
        cout << endl;
    }
}
vector<int> readInput()
{
    int n,x;
    string s;
    getline(cin, s);
    vector<int> data;
    cin >> n;
     for (int i =0; i < n; i++)
        for (int j= 0; j<n; j++)
        {
            cin >> x;
            data.push_back(x);
        }
    return data;
}
vector <int> goal()
{
    vector<int> sol{
        1,2,3,4,
        12,13,14,5,
        11, 0, 15, 6,
        10, 9, 8, 7
    };
    return sol;
}
int main()
{
    vector<int> tmp = readInput();
    vector<int> ok = goal();
    Node *sol = bfs(tmp, ok);
    for (int i =0; i < sqrt(tmp.size()); i++)
    {
        for (int j= 0; j<sqrt(tmp.size()); j++)
        cout << tmp[i*sqrt(tmp.size())+j] << " ";
        cout << endl;
    }
    cout << "-------------------------------\n";
    if (sol != nullptr)
        printSol(sol);
    // vector<vector<int> > ok = test.nextStates();
    // for (auto i:ok)
    // {
    //     for (auto j:i)
    //         cout << j << "  ";
    //     cout << endl;
    // }
    return 0;
}