class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        unordered_map<int , int> mp;
        int mask = 0;
        int ans = 0;
         mp[0] = -1;
        for(int i = 0 ; i < n ; i++ ){
            char ch = s[i];

            if(ch == 'a') mask ^= (1 << 0);
            else if(ch == 'e') mask ^= (1 << 1);
            else if(ch == 'i') mask ^= (1 << 2);
            else if(ch == 'o') mask ^= (1 << 3);
            else if(ch == 'u')  mask ^= (1 << 4);

            if(mp.count(mask)){
               ans = max(ans , i - mp[mask]  );
            }else{
               mp[mask] = i;
            }
            
        }
        return ans;
    }
};