class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string s = "";
        
        for(int i = 0 ; i < n ; i++ ){
            if(i == n - 1  ){
                s += '.';
            }else s += '#'; 
        }
        vector<string>ans(m,s);
        

        for(int i = 0 ; i < ans[0].size() ; i++){
            ans[0][i] = '.';
        }
        return ans;
    }
};