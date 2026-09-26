class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        string curr = "";

        unordered_map<string , string > mp;
        for(auto vec : knowledge){
            mp[vec[0]] = vec[1];
        }

        for(int i = 0 ; i < s.size() ; i++ ){
           if(s[i] == '('){
             int j = i + 1;

             while( j < s.size() && s[j] != ')'){
                curr += s[j];
                j++;
             }
             
              i = j;
             if(mp.find(curr) != mp.end()){
                ans += mp[curr];
             }
             else{
                ans += '?';
             }
             curr = "";

           } else{
               ans += s[i]; 
           }
           
        }
        return ans;
    }
};