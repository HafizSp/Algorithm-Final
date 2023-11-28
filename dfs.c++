#include <iostream>

using namespace std;

char int2char[] = {'A', 'B', 'C', 'M', 'N'};

void dfs(int node, int adj[][5], int visited[], int n)
{
    if (visited[node])
        return;

    visited[node] = 1;
    cout << int2char[node] << " ";

    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] == 1 && visited[i] == 0)
        {
            dfs(i, adj, visited, n);
        }
    }
}

int main()
{
    int n = 5;
    int adj[5][5] = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0},
    };
    int visited[5] = {0};
    dfs(0, adj, visited, n);
}