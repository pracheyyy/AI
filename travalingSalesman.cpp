
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 999999;

struct Node
{
    vector<int> path;
    vector<int> visited;
    int cost;
    int bound;
    int city;
};

struct Compare
{
    bool operator()(Node a, Node b)
    {
        return a.bound > b.bound;
    }
};

// Calculate lower bound
int calculateBound(vector<vector<int>>& graph,
                   vector<int>& visited, int current,
                   int n, int cost)
{
    int bound = cost;

    for(int i = 0; i < n; i++)
    {
        if(i == current || visited[i] == 0)
        {
            int minCost = INF;

            for(int j = 0; j < n; j++)
            {
                if(i != j && (j == 0 || visited[j] == 0))
                {
                    if(graph[i][j] != 0 &&
                       graph[i][j] < minCost)
                    {
                        minCost = graph[i][j];
                    }
                }
            }

            if(minCost == INF)
                return INF;

            bound += minCost;
        }
    }

    return bound;
}

void TSP(vector<vector<int>>& graph, int n)
{
    priority_queue<Node, vector<Node>, Compare> pq;

    int bestCost = INF;
    vector<int> bestPath;

    Node root;

    root.path.push_back(0);
    root.visited.assign(n, 0);
    root.visited[0] = 1;
    root.cost = 0;
    root.city = 0;

    root.bound = calculateBound(
        graph, root.visited, 0, n, 0
    );

    pq.push(root);

    while(!pq.empty())
    {
        Node curr = pq.top();
        pq.pop();

        if(curr.bound >= bestCost)
            continue;

        // All cities visited
        if(curr.path.size() == n)
        {
            int total = curr.cost + graph[curr.city][0];

            if(graph[curr.city][0] != 0 &&
               total < bestCost)
            {
                bestCost = total;
                bestPath = curr.path;
                bestPath.push_back(0);
            }

            continue;
        }

        // Try every unvisited city
        for(int v = 1; v < n; v++)
        {
            if(curr.visited[v] == 0 &&
               graph[curr.city][v] != 0)
            {
                Node child;

                child.path = curr.path;
                child.path.push_back(v);

                child.visited = curr.visited;
                child.visited[v] = 1;

                child.cost = curr.cost +
                             graph[curr.city][v];

                child.city = v;

                child.bound = calculateBound(
                    graph, child.visited,
                    v, n, child.cost
                );

                if(child.bound < bestCost)
                    pq.push(child);
            }
        }
    }

    if(bestPath.empty())
    {
        cout << "No Hamiltonian cycle exists";
        return;
    }

    cout << "\nMinimum Cost Path:\n";

    for(int i = 0; i < bestPath.size(); i++)
    {
        cout << bestPath[i];

        if(i != bestPath.size() - 1)
            cout << " -> ";
    }

    cout << "\nMinimum Cost = " << bestCost;
}

int main()
{
    int n;

    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter cost matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    TSP(graph, n);

    return 0;
}
