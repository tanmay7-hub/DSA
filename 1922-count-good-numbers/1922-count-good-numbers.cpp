class Solution {
public:
    int mod = 1e9 + 7;
    long long power(long long base , long long exp){
        long long ans = 1;

        while(exp > 0){
            if(exp % 2 == 1 ){
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod;
            exp  /= 2;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd = n / 2;
        long long even = (n + 1) / 2;

        long long oddWays = power(4 , odd) % mod;
        long long evenWays = power(5 , even) % mod;


        return (oddWays * evenWays) % mod;
    }
};