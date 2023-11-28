#include <iostream>
#include <queue>

using namespace std;

char int2char[] = {'A', 'B', 'C', 'M', 'N'};

void bfs(int startNode, int adj[][5], int visited[], int n)
{
    queue<int> q;
    visited[startNode] = 1;
    q.push(startNode);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << int2char[node] << " ";

        for (int i = 0; i < n; i++)
        {
            if (adj[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int n = 5;
    int adj[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 1, 0, 1, 0},
    };
    int visited[5] = {0};
    bfs(0, adj, visited, n);
}