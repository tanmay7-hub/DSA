class Solution {
public:
    bool check (long long mid , vector<long long>& diffArr , vector<int>& monsters ){

        for(int i = 0 ; i < monsters.size() ; i++ ){
            if(mid + diffArr[i] >= monsters[i]){
                 mid -= monsters[i];
                 if(mid < 0 ) mid = 0; 
            }else return false;
        }

        return mid >= 0 ;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<long long> arr(n + 1, 0);

        for(auto boost : boosts ){ 
            int st  = boost[0];
            int end = boost[1];
            int add = boost[2];
            arr[st]  += add ;
            arr[end + 1] -= add; 
        }      
        for(int i = 1 ; i <= n ; i++ ){
            arr[i] += arr[i - 1];
        }
        long long sum = 0;
        for(auto num : monsters)sum += num;
        
        long long low = 0 , high = sum;
        long long ans = high;
        while(low <= high){
            long long mid = low + (high - low) / 2;

            if(check(mid , arr , monsters)){
                 ans = mid;
                 high = mid - 1;
            }else{
                 low = mid + 1;
            }
        }
        return ans;

    }
};