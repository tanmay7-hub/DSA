class Solution {
public:
    int minRotations(string s) {

       int ans = 0 , prev = 0;
       for(int i = 0 ; i < s.size() ; i++ ){
            int curr = s[i] - '0';
            
            int front = abs(curr - prev);
            int back = abs(9 - front + 1);
            ans += min(front , back );
            prev = curr;
       }  
        
        return ans;

    }
};