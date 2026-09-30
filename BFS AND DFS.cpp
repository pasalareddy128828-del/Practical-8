#include <iostream>
#include <queue>
using namespace std;

int graph[5][5] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0}
};

bool visited[5];

// BFS
void BFS(int start)
{
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 0; i < 5; i++)
        {
            if (graph[node][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

// DFS
void DFS(int node)
{
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < 5; i++)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    cout << "BFS Traversal: ";

    BFS(0);

    // Reset visited
    for (int i = 0; i < 5; i++)
        visited[i] = false;

    cout << "\nDFS Traversal: ";

    DFS(0);

    return 0;
}
