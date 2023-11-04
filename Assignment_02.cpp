#include <iostream>
using namespace std;

struct edge {
    int src;
    int dest;
    int wt;
};

// Global variables for storing the number of vertices and edges
int V, E;

// Bellman Ford Algorithm Implementation
void BellmanFord(edge* Edge, int source) {
    int Infinity = 100000, u, v, w; // Defining the infinity value and some useful variables
    int distance[V];                // Array to store the distance of each vertex from the source

    // Initializing all the distances to Infinity
    for (int i = 0; i < V; i++)
        distance[i] = Infinity;

    // Setting the distance of the source vertex to 0
    distance[source] = 0;

    // V-1 iterations for calculating the distance from the source
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            u = Edge[j].src;
            v = Edge[j].dest;
            w = Edge[j].wt;

            if (distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Checking whether the given graph forms a negative cycle or not
    for (int j = 0; j < E; j++) {
        u = Edge[j].src;
        v = Edge[j].dest;
        w = Edge[j].wt;
        if (distance[v] > distance[u] + w) {
            cout << "\nGraph has generated a negative cycle.\nBellman Ford algorithm does not work when the graph contains a negative weight cycle." << endl;
            return;
        }
    }

    // Printing the calculated minimum distance of each vertex from the source
    cout << "\n\tFinal Distance\n\n";
    cout << "Vertex\t:\tDistance" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t:\t" << distance[i] << endl;
    cout << "===============================================" << endl;
}

int main() {
    // Taking the number of vertices
    cout << "Enter the Number of Vertex: ";
    cin >> V;

    // Taking the number of edges
    cout << "Enter the Number of Edges: ";
    cin >> E;

    edge Edge[E]; // Defining an array of structure

    // Taking each edge
    cout << "Enter Each Edge (give the first vertex's name as 0)";
    cout << "\n     Source\tDestination\tWeight\n\n";

    for (int i = 0; i < E; i++) {
        cout << "Edge " << i + 1 << "   ";
        cin >> Edge[i].src;
        cin >> Edge[i].dest;
        cin >> Edge[i].wt;
    }

    cout << "------------------------------------------------------------------------" << endl;

    // Calling the function
    BellmanFord(Edge, 0);

    return 0;
}



// Title : Bellman Ford Algorithm using Dynamic Programming
// Problem Statement: Write a program to implement Bellman-Ford Algorithm using Dynamic
// Programming and verify the time complexity.
// Objective: To understand the use of Bellman-Ford algorithm, for finding shortest path and
// implement.
// Theory:
// Bellman-Ford Algorithm:
// Dijkstra and Bellman-Ford Algorithms used to find out single source shortest paths. i.e. there is a
// source node, from that node we have to find shortest distance to every other node. Dijkstra
// algorithm fails when graph has negative weight cycle. But Bellman-Ford Algorithm won’t fail
// even, the graph has negative edge cycle. If there any negative edge cycle it will detect and say there
// is negative edge cycle. If not it will give answer to given problem.
// Bellman-Ford Algorithm will work on logic that, if graph has n nodes, then shortest path never
// contain more than n-1 edges. This is exactly what Bellman-Ford do. It is enough to relax each
// edge (v-1) times to find shortest path. But to find whether there is negative cycle or not we again do
// one more relaxation. If we get less distance in nth relaxation we can say that there is negative edge
// cycle. Reason for this is negative value added and distance get reduced.
// Relaxing edge
// In algorithm and code below we use this term Relaxing edge.
// Relaxing edge is an operation performed on an edge (u, v) . when,
// d(u) > d(v) + Cost(u,v)
// Here d(u) means distance of u. If already known distance to “u” is greater than the path from “s” to
// “v” and “v” to “u” we update that d(u) value with d(v) + cost(u,v)