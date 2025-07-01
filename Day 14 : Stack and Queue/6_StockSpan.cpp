//Question Link --> https://leetcode.com/problems/online-stock-span/description/

//Brute force - 
//T.C.=O(N^2)   [ O(N) for next and Assuming n times next will be called to add n elements resulting nxn ] , S.C.=O(N) [Stack]

class StockSpanner {
public:
    StockSpanner() {
        
    }
    
     vector<int>v;
    int next(int price) {
        int a = 1;
        for(int i=v.size()-1;i>=0;i--){
            if(price >= v[i]){
                a++;
            }else{
                break;
            }
        }
        v.push_back(price);
        return a;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */



//OPTIMIZED - PGE - T.C.=O(N),S.C.=O(N)
// [7,2,1,2,3] at poition 3, pge is 7 so 4(index of 3 )-0(index of 7 ) =4 
class StockSpanner {
public:
    stack<pair<int, int>> st;
    int index;
    StockSpanner() {
        index = -1;
    }
    
    int next(int price) {
        index = index + 1;
        int ans = 1;
        while(!st.empty() && st.top().first <= price) st.pop();
        ans = index - (st.empty()?-1:st.top().second);
        st.push({price, index});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

