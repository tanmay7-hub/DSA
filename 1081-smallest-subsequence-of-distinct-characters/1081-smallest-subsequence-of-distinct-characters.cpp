class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char , int> mp;
        for(auto ch  :s) mp[ch] ++;
        stack<char>st;
        vector<int>taken(26 , false);

        for(auto ch : s){
            mp[ch ]--;
            if(taken[ch - 'a']) continue;
             while(st.size() > 0 ){         
                if(st.top() > ch && mp[st.top()] > 0){
                    char top = st.top();
                    st.pop();
                    taken[top - 'a'] = false;
                   
                }else{
                      break;
                }
             }
            if(!taken[ch - 'a']){
                st.push(ch);
                
                taken[ch - 'a'] = true;
            }
            
        }

        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(begin(ans) , end(ans));
        return ans;
    }
};