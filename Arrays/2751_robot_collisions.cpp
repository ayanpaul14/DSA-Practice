#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Robot {
    int pos;
    int health;
    char dir;
    int id;
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots;

        for (int i = 0; i < n; ++i) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        // 1. MUST sort by position to process robots as they encounter each other
        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.pos < b.pos;
        });

        vector<Robot> stack; // Acts as our active line of robots
        
        for (auto& cur : robots) {
            if (cur.dir == 'R') {
                stack.push_back(cur);
            } else {
                // Robot is moving Left ('L'), it will collide with any 'R' in the stack
                while (!stack.empty() && stack.back().dir == 'R' && cur.health > 0) {
                    if (stack.back().health < cur.health) {
                        stack.pop_back();
                        cur.health -= 1;
                    } else if (stack.back().health > cur.health) {
                        stack.back().health -= 1;
                        cur.health = 0;
                    } else {
                        stack.pop_back();
                        cur.health = 0;
                    }
                }
                // If Left-mover survives all collisions or there were no Right-movers
                if (cur.health > 0) {
                    stack.push_back(cur);
                }
            }
        }

        // 2. Sort the survivors back to their original input order (by id)
        sort(stack.begin(), stack.end(), [](const Robot& a, const Robot& b) {
            return a.id < b.id;
        });

        // 3. Extract just the health values
        vector<int> result;
        for (const auto& r : stack) {
            result.push_back(r.health);
        }

        return result;
    }
};