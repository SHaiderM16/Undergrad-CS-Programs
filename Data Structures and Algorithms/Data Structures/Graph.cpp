#include <iostream>
using namespace std;

struct GraphLLNode
{
    int data;
    GraphLLNode *next;

    GraphLLNode(int d)
    {
        data = d;
        next = NULL;
    }
};

class Graph
{
    int V, E;
    GraphLLNode **adjList;
    int **adjMatrix;

public:
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;

        // setting up adjList
        adjList = new GraphLLNode *[V];
        for (int i = 0; i < V; ++i)
        {
            adjList[i] = nullptr; // Initialize each adjacency list pointer to nullptr
        }

        // setting up adjMatrix
        adjMatrix = new int *[V];
        for (int i = 0; i < V; ++i)
        {
            adjMatrix[i] = new int[V](); // Initialize with zero
        }
    }

    void addEdge(int u, int v)
    {
        // adding into adjMatrix
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;

        // adding into adjList
        // adding U
        GraphLLNode *newNodeU = new GraphLLNode(u);
        newNodeU->next = adjList[v];
        adjList[v] = newNodeU;
        // adding V
        GraphLLNode *newNodeV = new GraphLLNode(v);
        newNodeV->next = adjList[u];
        adjList[u] = newNodeV;
    }

    void bfsUsingMatrix(int src)
    {
        // Create a visited array to track visited nodes
        int *vis = new int[V]();
        // Create a queue to process nodes
        int q[V] = {0};
        int front = 0, back = 0;
        // Add the source node to the queue and mark it as visited
        q[back++] = src;
        int qSize = 1;
        vis[src] = 1;

        // Perform BFS while the queue is not empty
        while (qSize != 0)
        {
            // Dequeue the parent node and process it
            int parent = q[front++];
            qSize--;
            cout << parent << " ";

            // Traverse all neighbours of the parent node
            for (int i = 0; i < V; i++)
            {
                if (adjMatrix[parent][i] == 1 && vis[i] == 0) // Check for unvisited neighbours
                {
                    // Mark neighbour as visited and enqueue it
                    vis[i] = 1;
                    q[back++] = i;
                    qSize++;
                }
            }
        }
    }

    void bfsUsingList(int src)
    {
        // Create a visited array to track visited nodes
        int *vis = new int[V]();
        // Create a queue to process nodes
        int q[V] = {0};
        int front = 0, back = 0;
        // Add the source node to the queue and mark it as visited
        q[back++] = src;
        int qSize = 1;
        vis[src] = 1;

        // Perform BFS while the queue is not empty
        while (qSize != 0)
        {
            // Dequeue the parent node and process it
            int parent = q[front++];
            qSize--;
            cout << parent << " ";

            // Traverse all neighbours in the adjacency list
            GraphLLNode *temp = adjList[parent];
            while (temp != NULL)
            {
                if (vis[temp->data] == 0) // Check for unvisited neighbours
                {
                    // Mark neighbour as visited and enqueue it
                    q[back++] = temp->data;
                    qSize++;
                    vis[temp->data] = 1;
                }
                temp = temp->next; // Move to the next neighbour
            }
        }
    }

    void dfsUsingMatrix(int src, int *vis)
    {
        // If the node is already visited, return
        if (vis[src] == 1)
        {
            return;
        }
        // Mark the current node as visited and process it
        vis[src] = 1;
        cout << src << " ";

        // Recursively visit all unvisited neighbours
        for (int i = 0; i < V; i++)
        {
            if (adjMatrix[src][i] == 1)
            {
                dfsUsingMatrix(i, vis);
            }
        }
    }

    void dfsUsingList(int src, int *vis)
    {
        // If the node is already visited, return
        if (vis[src] == 1)
        {
            return;
        }
        // Mark the current node as visited and process it
        vis[src] = 1;
        cout << src << " ";
        // Traverse neighbours in the adjacency list and visit them recursively
        GraphLLNode *temp = adjList[src];
        while (temp != NULL)
        {
            dfsUsingList(temp->data, vis);
            temp = temp->next; // Move to the next neighbour
        }
    }
};