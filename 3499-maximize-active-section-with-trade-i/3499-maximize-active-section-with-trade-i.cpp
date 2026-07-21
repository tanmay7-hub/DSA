class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int>zero;
        int r = 0;
        int one = 0;
        for(auto c : s){
             if(c == '1'){
                one++;
               if(r > 0) zero.push_back(r);
                r = 0;
             }else{
                r++;
             }
        }
        if(r )  zero.push_back(r);

        int ans = 0;
        for(int i = 1 ; i < zero.size() ; i++ ){
             ans = max(ans , zero[i] + zero[i - 1]);
        }
        return ans + one;
    
    }
};