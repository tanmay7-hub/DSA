class Solution {
public:
    int minimumPushes(string word) {
        vector<int>fre(26 ,0 );
        for(auto ch : word){
            fre[ch - 'a']++;
        }
        sort(begin(fre) , end(fre), greater());
        int ans = 0;
        for( int  i = 0 ; i < 26 ; i++ ){
             
             int push = ((i + 1 ) / 8) + ( (i + 1) % 8  > 0);
             ans += push * fre[i];
        }
        return ans;
    }
};