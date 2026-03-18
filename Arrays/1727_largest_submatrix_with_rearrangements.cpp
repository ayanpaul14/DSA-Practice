// Problem: Largest Submatrix With Rearrangements
// Problem No: 1727
// Platform: LeetCode
// Difficulty: Medium
// Approach: Histogram + Sorting
// Time Complexity: O(m * n log n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;

        for (int i = 0; i < m; i++) {

            // Step 1: Build histogram (accumulate heights)
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != 0 && i > 0) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }

            // Step 2: Sort current row in descending order
            vector<int> currRow = matrix[i];
            sort(currRow.begin(), currRow.end(), greater<int>());

            // Step 3: Calculate max area
            for (int j = 0; j < n; j++) {
                int area = currRow[j] * (j + 1);
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};