// https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2025-10-01

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        int emptyBottles=numBottles;// 1st iteration
        while(emptyBottles>=numExchange){
            int newBottles=emptyBottles/numExchange;
            ans=ans + newBottles;
            emptyBottles=newBottles + (emptyBottles % numExchange);//remaining --> int rem=emptyBottles % numExchange;
        }
        return ans;
    }
};
