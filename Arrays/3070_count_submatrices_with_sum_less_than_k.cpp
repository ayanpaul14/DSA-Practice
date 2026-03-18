/*
Problem: Count Submatrices with Top-Left Element and Sum <= k
Approach: 2D Prefix Sum + Early Break Optimization
Time Complexity: O(m * n)
Space Complexity: O(1) (in-place)

Key Idea:
Convert matrix into prefix sum matrix and count valid cells.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        // Convert grid into prefix sum matrix
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {

                if (i > 0) grid[i][j] += grid[i - 1][j];
                if (j > 0) grid[i][j] += grid[i][j - 1];
                if (i > 0 && j > 0) grid[i][j] -= grid[i - 1][j - 1];

                // Count valid submatrices
                if (grid[i][j] <= k) {
                    count++;
                } else {
                    // Optimization: break since values will only increase
                    break;
                }
            }
        }

        return count;
    }
};