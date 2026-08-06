class Solution {
public:
    int solve(int x){
        int ans = 1;
        while(x){
            int curr = x % 10;
            x /= 10;
            ans *= curr;
            if(curr == 0) return 0;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        int i = n ;
        while(1){
            int pro = solve(i);

            if(pro % t == 0){            
                return i;
            }
            i++;
           
        }
        return -1;
    }
};