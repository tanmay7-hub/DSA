class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int , int> mp;
        for(auto num : changed){
            mp[num]++;
        }
        int n = changed.size();
        if(n % 2 != 0) return {};
        int i = 0 ;
        sort(begin(changed) ,end(changed));
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){

         if(mp[changed[i]] == 0)continue;
         if(mp[2 * changed[i]] == 0)return {};

         ans.push_back(changed[i]);
         mp[changed[i]]--;
         mp[2 * changed[i]]--;   
        }

        return ans;

    }
};