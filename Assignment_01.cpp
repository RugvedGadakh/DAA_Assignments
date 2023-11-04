#include <iostream>

int max(int i, int j) {
    if (i > j)
        return i;
    else
        return j;
}

void Sort1(int w[], int p[], int n) { // ascending order
    int temp1 = 0, temp2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (w[i] <= w[j]) {
                temp1 = w[i];
                w[i] = w[j];
                w[j] = temp1;

                temp2 = p[i];
                p[i] = p[j];
                p[j] = temp2;
            }
        }
    }
}

void sort(float arr[], float w[], float p[], int no_Item) {
    for (int i = 0; i < no_Item; i++) {
        for (int j = 0; j < no_Item; j++) {
            if (arr[i] >= arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                int temp1 = p[i];
                p[i] = p[j];
                p[j] = temp1;

                int temp2 = w[i];
                w[i] = w[j];
                w[j] = temp2;
            }
        }
    }
}

int Knapsack_0_1(int weight[], int profit[], int N, int W) {
    int knap[N + 1][W + 1];

    for (int i = 0; i < N + 1; i++) {
        for (int wt = 0; wt < W + 1; wt++) {
            if (i == 0 || wt == 0) {
                knap[i][wt] = 0;
            }
            else if (weight[i - 1] <= wt) {
                knap[i][wt] = max(knap[i - 1][wt], knap[i - 1][wt - weight[i - 1]] + profit[i - 1]);
            }
            else {
                knap[i][wt] = knap[i - 1][wt];
            }
        }
    }

    return knap[N][W];
}

void f_kanpsack() {
    std::cout << "\nEnter The Capacity Of the Bag:";
    int W;
    std::cin >> W;

    std::cout << "Enter The Number Of Items:";
    int no_Item;
    std::cin >> no_Item;

    float weight[no_Item], profit[no_Item];
    float r[no_Item];

    std::cout << "Enter the Weight and Profit Of Each Item";
    for (int i = 0; i < no_Item; i++) {
        std::cout << "\n\n\tItem " << i + 1;
        std::cout << "\n\tWeight:";
        std::cin >> weight[i];
        std::cout << "\n\tProfit:";
        std::cin >> profit[i];
        r[i] = (profit[i] / weight[i]);
    }

    sort(r, weight, profit, no_Item);

    int total_pro = 0, i = 0;
    while (W > 0) {
        if (W >= weight[i]) {
            std::cout << "\n profit " << profit[i] << " added completely";
            W -= weight[i];
            total_pro += profit[i];
        }
        else {
            float temp = (profit[i] * (W / weight[i]));
            total_pro += temp;
            W = 0;
        }
        i++;
    }
    std::cout << "\ntotal Profit : " << total_pro;
}

int main() {
    int choice = 0;
    do {
        std::cout << "\n-----------------------------------------";
        std::cout << "\n     	Assignment No : 1";
        std::cout << "\n\t1:Fractional Knapsack\n\t2:0/1 Knapsack\n\t3:Exit\n";
        std::cout << "\n\tEnter Choice:";
        std::cin >> choice;
        std::cout << "\n-----------------------------------------";
        switch (choice) {
            case 1:
                f_kanpsack();
                break;
            case 2: {
                std::cout << "\nEnter the Weight Of Knapsack:";
                int W = 0;
                std::cin >> W;
                std::cout << "\nEnter Number Of Item:";
                int N;
                std::cin >> N;
                std::cout << "\nEnter the profit and weight of each item";
                int weight[N], profit[N];
                for (int i = 0; i < N; i++) {
                    std::cout << "\nItem " << i + 1;
                    std::cout << "\n\tProfit:";
                    std::cin >> profit[i];
                    std::cout << "\n\tWeight:";
                    std::cin >> weight[i];
                }
                Sort1(weight, profit, N);
                std::cout << "\nTotal Capacity : " << Knapsack_0_1(weight, profit, N, W);
            }
            break;
            case 3:
                return 0;
        }

    } while (choice != 3);

    return 0;
}


// Problem Statement: Write a program to implement Fractional knapsack using Greedy
// algorithm and 0/1 knapsack using dynamic programming. Show that Greedy strategy does not
// necessarily yield an optimal solution over a dynamic programming approach.
// Objective: Greedy strategy does not necessarily yield an optimal solution over a dynamic
// programming approach.
// Theory:
// 1) Fractional knapsack using Greedy algorithm
// Given weights and values of n items, we need to put these items in a knapsack of capacity W to get
// the maximum total value in the knapsack.
// In Fractional Knapsack, we can break items for maximizing the total value of knapsack. This
// problem in which we can break an item is also called the fractional knapsack problem.
// A brute-force solution would be to try all possible subset with all different fraction but that will be
// too much time taking.
// An efficient solution is to use Greedy approach. The basic idea of the greedy approach is to
// calculate the ratio value/weight for each item and sort the item on basis of this ratio. Then take the
// item with the highest ratio and add them until we can’t add the next item as a whole and at the end
// add the next item as much as we can. Which will always be the optimal solution to this problem.
// A simple code with our own comparison function can be written as follows, please see sort function
// more closely, the third argument to sort function is our comparison function which sorts the item
// according to value/weight ratio in non-decreasing order.
// After sorting we need to loop over these items and add them in our knapsack satisfying abovementioned criteria.
// Input :
// Items as (value, weight) pairs
// arr[] = {{60, 10}, {100, 20}, {120, 30}}
// Knapsack Capacity, W = 50;
// Output :
// Maximum possible value = 240
// By taking full items of 10 kg, 20 kg and
// 2/3rd of last item of 30 kg


// 2) 0/1 knapsack using dynamic programming
// In the Dynamic programming we will work considering the same cases as mentioned in the
// recursive approach. In a DP[][] table let's consider all the possible weights from '1' to 'W' as the
// columns and weights that can be kept as the rows.
// The state DP[i][j] will denote maximum value of 'j-weight' considering all values from '1 to ith'. So
// if we consider 'wi' (weight in 'ith' row) we can fill it in all columns which have 'weight values > wi'.
// Now two possibilities can take place:
//  Fill 'wi' in the given column.
//  Do not fill 'wi' in the given column.
// Now we have to take a maximum of these two possibilities, formally if we do not fill 'ith' weight in
// 'jth' column then DP[i][j] state will be same as DP[i-1][j] but if we fill the weight, DP[i][j] will be
// equal to the value of 'wi'+ value of the column weighing 'j-wi' in the previous row. So we take the
// maximum of these two possibilities to fill the current state. This visualization will make the concept
// clear:
// Let weight elements = {1, 2, 3}
// Let weight values = {10, 15, 40}
// Capacity=6
// 0 1 2 3 4 5 6
// 0 0 0 0 0 0 0 0
// 1 0 10 10 10 10 10 10
// 2 0 10 15 25 25 25 25
// 3 0
// Explanation:
// For filling 'weight = 2' we come
// across 'j = 3' in which
// we take maximum of
// (10, 15 + DP[1][3-2]) = 25
// | |
// '2' '2 filled'
// not filled
// 0 1 2 3 4 5 6
// 0 0 0 0 0 0 0 0
// 1 0 10 10 10 10 10 10
// 2 0 10 15 25 25 25 25
// 3 0 10 15 40 50 55 65
// Explanation:
// For filling 'weight=3',
// we come across 'j=4' in which
// we take maximum of (25, 40 + DP[2][4-3])
// = 50
// For filling 'weight=3'
// we come across 'j=5' in which
// we take maximum of (25, 40 + DP[2][5-3])
// = 55
// For filling 'weight=3'
// we come across 'j=6' in which
// we take maximum of (25, 40 + DP[2][6-3])
// = 65
// Complexity Analysis:
//  Time Complexity: O(N*W).
// where 'N' is the number of weight element and 'W' is capacity. As for every weight element
// we traverse through all weight capacities 1<=w<=W.
//  Auxiliary Space: O(N*W).
// The use of 2-D array of size 'N*W'