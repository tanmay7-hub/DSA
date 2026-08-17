class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> st;

        st.insert(s);
        q.push(s);

        string ans = s;
        while(!q.empty()){
            string curr = q.front(); 
            q.pop();

            if(curr < ans)ans = curr;
            string added = curr;
            for(int i = 1 ; i < added.size() ; i += 2 ){
                added[i] = (added[i] -'0' + a ) % 10 + '0';
            }

            if(!st.count(added)){
                st.insert(added);
                q.push(added);
            }

            string rotated = curr.substr(curr.size() - b) + curr.substr( 0 , curr.size() - b);
            if(!st.count(rotated)){
                st.insert(rotated);
                q.push(rotated);
            }
        }
        return ans;
    }
};