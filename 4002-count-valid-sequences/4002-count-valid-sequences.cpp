class Solution {
public:
    vector<long long >fact;
    vector<long long >infac;
    const int MOD = 1e9 + 7;
    
    long long power(long long a , long long b){
        long long ans = 1;

        while(b){
            if(b & 1){
                ans  = (ans * a) % MOD;
            }
            a = a * a % MOD;
            b >>= 1; 
        }
        return ans;
    }
    long long nCr(int n , int r){

         if(r < 0 || r > n)return 0LL;      
         return ((fact[n] * infac[r] % MOD * infac[n - r] ) + MOD ) % MOD;
    }
    int countValidSequences(int n, int k) {
        if( k > n )return 0;
        fact.resize(n + 1  );
        infac.resize(n + 1);
        fact[0] = 1;

        for(int i = 1; i < fact.size() ; i++){
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        infac[n] = power(fact[n] , MOD - 2);

        for(int i = n ; i >= 1 ; i--){
            infac[i - 1] = (infac[i] * i) % MOD;
        }

        long long total = nCr( n - 1 , k - 1 );

        long long odd = 0;

        if( ( n - k) % 2 == 0){
        
            int curr = ( n - k ) / 2;
            odd = nCr(curr + k -1 , k -1 );
        }
        return (total - odd  + MOD) % MOD;

    }
};