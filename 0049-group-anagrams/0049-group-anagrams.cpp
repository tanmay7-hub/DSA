class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;

        for(int i = 0 ; i < strs.size() ; i++ ){
            vector<int> fre(26 , 0);
            for(char ch : strs[i]){
                fre[ch - 'a']++;
            }

            string key = "";
            for(auto num : fre) key+= to_string(num) + "#";
            mp[key].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto& it : mp){
            ans.push_back(it.second);
        }
        return ans;           
    }
};