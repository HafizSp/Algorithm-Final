#include <cstdio>
#include <queue>

using namespace std;

char vertices[5] = {'H', 'A', 'M', 'T', 'V'};

void dfs(int node, int visited[], int adj[][5], int n)
{
    if (visited[node])
    {
        return;
    }
    visited[node] = 1;
    printf("%d ", node);
    for (int j = 0; j < n; j++)
    {
        if (adj[node][j] == 1 && !visited[j])
        {
            dfs(j, visited, adj, n);
        }
    }
}

void bfs(int startNode, int visited[], int adj[][5], int n)
{
    queue<int> q;
    q.push(startNode);
    visited[startNode] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        printf("%c ", vertices[node]);

        for (int j = 0; j < n; j++)
        {
            if (adj[node][j] == 1 && visited[j] != 1)
            {
                visited[j] = 1;
                q.push(j);
            }
        }
    }
}

int main()
{
    int n = 5;
    int adj[5][5] = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
    };

    int visited[5] = {0};
    // bfs(0, visited, adj, n);
    dfs(0, visited, adj, n);
    return 0;
}