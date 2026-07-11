class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        vector<int>numeric(n);

        for(int i = 0 ; i < n ; i++ ){
            int val = 0;

            for(char ch : words[i]){
                int currBit =  ch -'a';

                val |= 1 << currBit;
            }
            numeric[i] = val;
        }
        for( int i = 0 ; i < words.size() ; i++ ){
            for(int  j = i + 1 ; j < words.size() ; j++ ){
                string s1 = words[i];
                string s2 = words[j];
                

                if(( numeric[i] & numeric[j] )== 0){
                    int sz = s1.size() *  s2.size();
                    ans = max(ans , sz );
                }
            
            }
        }

        return ans;
    }
};