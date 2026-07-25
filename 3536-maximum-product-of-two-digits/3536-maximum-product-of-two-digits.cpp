class Solution {
public:
    int maxProduct(int n) {
        int mx  = 0 , sm = 0;
        
        while( n ){
            int rem = n % 10;
            n /= 10;

            if(rem > mx){
                sm = mx;
                mx = rem;  
            }else if(rem > sm ){
                sm = rem;
            }
        }

        return mx * sm;
    }
};