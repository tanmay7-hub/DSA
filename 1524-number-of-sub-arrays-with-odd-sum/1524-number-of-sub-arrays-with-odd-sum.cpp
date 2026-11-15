class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
         // prefix done of sum;
         for(int i = 1 ; i < arr.size() ; i++ ){
                arr[i]  = arr[i] + arr[i - 1];
         }

         int countOdd = 0  , countEven = 0;
         int mod = 1e9 + 7;
         long long ans = 0;
         for(int i = 0 ; i < arr.size() ; i++ ){
             if(arr[i] % 2 == 0 ){
                ans = (ans + countOdd) % mod ;
                countEven ++ ;
            }else{
                ans =  ans + (1 +  countEven) % mod ;
              
                countOdd++;
             }
         }
         return ans;


    }
};