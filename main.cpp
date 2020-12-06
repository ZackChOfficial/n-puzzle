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
    int score;
    int depth;

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
    bool operator<( const Node& b) {
        cout << "hi\n";
        return true;
    }
    bool operator<=( const Node& b) {
        cout << "hi\n";
        return true;
    }
    bool operator>( const Node& b) {
        cout << "hello\n";
        return true;
    }
     bool operator>=( const Node& b) {
        cout << "hello\n";
        return true;
    }
    void Manhattan_distance(vector<int> &goal)
    {
        int score_tmp = 0;
        for (int i=0;i<goal.size(); i++)
        {
            for (int j=0;j < state.size(); j++)
            {
                if (goal[i] == state[j])
                {
                    score_tmp += abs(i-j) + depth;
                }
            }
        }
        score = score_tmp ;
        score *= -1;
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
    root->depth = 1;
    states.push(root);
    inQueue.insert(root->state);
    int i = 1;
    while (!states.empty())
    {
        Node *current = states.front();
        states.pop();
        visited.insert(current->state);
        inQueue.erase(current->state);
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
                state->depth += current->depth + 1;
                states.push(state);
                inQueue.insert(state->state);
            }
        }
        i++;
    }
   cout << i << endl;
    return nullptr;
}
bool compare(Node *a, Node *b)
{
    return a->score < b->score;
}
struct DereferenceCompareNode : public std::binary_function<Node*, Node*, bool>
{
    bool operator()(const Node* lhs, const Node* rhs) const
    {
        return lhs->score < rhs->score;
    }
};
Node *a_star(vector<int> &initial, vector<int> &goal)
{
    priority_queue<Node *,vector<Node*>, DereferenceCompareNode> states;
    set<vector<int>> visited;
    set<vector<int>> inQueue;
    Node *root = new Node(initial);
    root->Manhattan_distance(goal);
    
    states.push(root);
    inQueue.insert(root->state);
    int i = 1;
    while (!states.empty())
    {
        Node *current = states.top();
        states.pop();
        visited.insert(current->state);
        inQueue.erase(current->state);
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
                state->Manhattan_distance(goal);
                states.push(state);
                inQueue.insert(state->state);
            }
        }
        i++;
    }
    return nullptr;
}
void printSol(Node *sol, int depth)
{
    if (sol->parent != nullptr)
    {
        printSol(sol->parent, depth + 1);
        cout << "\n  |\n";
        cout << "  v\n\n";
    }
    cout << depth << endl;
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
vector <int> goal(int size)
{
     vector< vector<int> > templates;
     templates.push_back(vector<int>{
        1 
    });
    templates.push_back(
    vector<int>{
        1 , 2,
        4,3
    });
    templates.push_back(
    vector<int>{
        1 , 2,3,
        8,0,4,
        7,6,5
    });
    templates.push_back(
    vector<int>{
        1 , 2 , 3 , 4,
        12,13,14,5,
        11,0,15,6,
        10,9,8,7
    })
    ;
    templates.push_back(
    vector<int>{
        1 , 2 , 3 , 4,5,
        16,17,18,19,6,
        15,24,0,20,7,
        14,23,22,21,8,
        13,12,11,10,9
    })
    ;
    return templates[size - 1];
}
int main()
{
    vector<int> tmp = readInput();
    vector<int> ok = goal((int)sqrt(tmp.size()));
    Node *sol = a_star(tmp, ok);
    for (int i =0; i < sqrt(tmp.size()); i++)
    {
        for (int j= 0; j<sqrt(tmp.size()); j++)
        cout << tmp[i*sqrt(tmp.size())+j] << " ";
        cout << endl;
    }
    cout << "-------------------------------\n";
    if (sol != nullptr)
        printSol(sol, 0);
    // vector<vector<int> > ok = test.nextStates();
    // for (auto i:ok)
    // {
    //     for (auto j:i)
    //         cout << j << "  ";
    //     cout << endl;
    // }
    return 0;
}