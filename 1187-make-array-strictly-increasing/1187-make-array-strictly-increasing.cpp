class Solution {
public:
    vector<int> arr1 , arr2;
    map<pair<int,int>, int> dp;
    long long solve( int i , int prev ){
        if(i == arr1.size()) return 0;
        long long ans = INT_MAX;


        if(dp.count({i , prev}))return dp[{i , prev}];
        if(arr1[i] > prev){
            ans = min (ans , solve(i + 1 , arr1[i]));
        }

            int low = INT_MAX;
            for(int j : arr2){
                if(j > prev){
                   low = min(low , j);
                }
            }

            if(low != INT_MAX){
               ans = min(ans ,  1 +  solve(i + 1 , low));
            }
        return dp[{i , prev}] = ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        this->arr1 = arr1;
        this->arr2 = arr2;
        int ans = solve(0 , -1);
        return  ans == INT_MAX ? -1 : ans;
    }
};