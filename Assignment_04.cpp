#include <iostream>
#include <cmath>
using namespace std;

int arr[10][10], completed[10], cost = 0, n;

void take_input() {
    int i, j;
    cout << "Enter number of Cities: ";
    cin >> n;
    cout << "Enter Cost Matrix" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Enter elements of row " << i + 1 << ":" << endl;
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
        completed[i] = 0;
    }
}

int least(int c) {
    int nc = 999, kmin, min = 999;

    for (int i = 0; i < n; i++) {
        if ((arr[c][i] != 0) && (completed[i] == 0)) {
            if (arr[c][i] + arr[i][c] < min) {
                min = arr[i][0] + arr[c][i];
                kmin = arr[c][i];
                nc = i;
            }
        }
    }

    if (min != 999) {
        cost += kmin;
    }

    return nc;
}

void mincost(int city) {
    int ncity;
    completed[city] = 1;
    cout << city + 1 << "--->";
    ncity = least(city);

    if (ncity == 999) {
        ncity = 0;
        cout << ncity + 1;

        cost += arr[city][ncity];
        return;
    }
    mincost(ncity);
}

int main() {
    take_input();
    mincost(0);

    cout << "\n\nMinimum Cost is " << cost << endl;

    return 0;
}


// Problem Statement: Write a program to solve the travelling salesman problem and to print
// the path and the cost using Branch and Bound
// Objective: To understand the concept of Branch and bound used in Travel Salesman Problem.
// Theory:
// Branch and Bound Solution
// In Branch and Bound method, for current node in tree, we compute a bound on best possible
// solution that we can get if we down this node. If the bound on best possible solution itself is worse
// than current best (best computed so far), then we ignore the subtree rooted with the node.
// Note that the cost through a node includes two costs.
// 1) Cost of reaching the node from the root (When we reach a node, we have this cost computed)
// 2) Cost of reaching an answer from current node to a leaf (We compute a bound on this cost to
// decide whether to ignore subtree with this node or not).
//  In cases of a maximization problem, an upper bound tells us the maximum possible solution
// if we follow the given node. For example in 0/1 knapsack we used Greedy approach to find an
// upper bound.
//  In cases of a minimization problem, a lower bound tells us the minimum possible solution if
// we follow the given node. For example, in Job Assignment Problem, we get a lower bound by
// assigning least cost job to a worker.
// In branch and bound, the challenging part is figuring out a way to compute a bound on best possible
// solution. Below is an idea used to compute bounds for Traveling salesman problem.