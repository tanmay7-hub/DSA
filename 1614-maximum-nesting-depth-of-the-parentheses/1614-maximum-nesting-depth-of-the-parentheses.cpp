class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char> st;
        for(auto ch : s){
           
           if(ch == '('){
            st.push('(');
            ans = max(ans , (int)st.size());
           }else if(ch == ')'){
            st.pop();
           }
        }
        return ans;
    }
};