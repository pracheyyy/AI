
#include <iostream>
#include <vector>
using namespace std;

int n = 6;

bool isValid(int task, int col,
             vector<vector<int>>& graph,
             vector<int>& colors,
             vector<vector<int>>& allowed)
{
    
    bool found = false;

    for(int i = 0; i < allowed[task].size(); i++)
    {
        if(allowed[task][i] == col)
            found = true;
    }

    if(!found)
        return false;

  
    for(int v = 0; v < n; v++)
    {
        if(graph[task][v] == 1 && colors[v] == col)
            return false;
    }

    return true;
}

bool assign(int task,
            vector<vector<int>>& graph,
            vector<int>& colors,
            vector<vector<int>>& allowed)
{
   
    if(task == n)
        return true;

    
    for(int i = 0; i < allowed[task].size(); i++)
    {
        int col = allowed[task][i];

        if(isValid(task, col, graph, colors, allowed))
        {
            colors[task] = col;

            if(assign(task + 1, graph, colors, allowed))
                return true;

            
            colors[task] = -1;
        }
    }

    return false;
}

int main()
{
   
    vector<vector<int>> graph =
    {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

 
    vector<vector<int>> allowed =
    {
        {0, 1},
        {0, 1, 2},
        {1, 2},
        {0, 2, 3},
        {1, 2, 3},
        {0, 3}
    };

    vector<int> colors(n, -1);

    if(assign(0, graph, colors, allowed))
    {
        cout << "Resource Allocation:\n";

        for(int i = 0; i < n; i++)
        {
            cout << "Task " << i
                 << " -> Resource "
                 << colors[i] << endl;
        }
    }
    else
    {
        cout << "No valid allocation exists";
    }

    return 0;
}
