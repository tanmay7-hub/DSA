class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0  , cost = 0;
        for(auto ch : s){
            if(ch == '1') ones++;
            else cost = min(cost + 1 , ones);
        }
        return cost;
    }
};