class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        vector<int>dp(n , 1);

        int ans = 0;
        unordered_map<int , int> s;
        for(int i = 0 ; i < n ; i++ ){
            int num = arr[i];
            if(s.count(num - difference) ){
                s[num] = s[num - difference] + 1;
            }else{
                s[num] = 1;
            }

            ans = max(ans , s[num]);
        }
        return ans;
    }
};