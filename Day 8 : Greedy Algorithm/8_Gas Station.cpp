// LINK --> https://leetcode.com/problems/gas-station/description/

//start index--> it is guaranteed to be unique if possible.
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0, curr_tank = 0, start_index = 0;
        for (int i = 0; i < gas.size(); i++) {
            total_tank += gas[i] - cost[i];// total gas - total cost --> at the end
            curr_tank += gas[i] - cost[i];
            
            if (curr_tank < 0) {
                start_index = i + 1;
                curr_tank = 0;
            }
        }
        return (total_tank >= 0) ? start_index : -1;
    }
};
