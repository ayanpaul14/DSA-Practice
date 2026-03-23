#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> s;
        int repeat = -1;

        int actualSum = 0;
        for(auto &row : grid){
            for(int val : row){
                actualSum += val;
                if(s.count(val)) repeat = val;
                s.insert(val);
            }
        }

        int expSum = (n*n * (n*n + 1)) / 2;
        int missing = expSum + repeat - actualSum;

        return {repeat, missing};
    }
};