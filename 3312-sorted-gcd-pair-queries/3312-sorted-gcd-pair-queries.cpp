class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        unordered_map<int,int>freq;
        int m = *max_element(begin(nums) , end(nums));
        for(int i = 0 ; i < n ; i++ ){
            int num = nums[i];
            freq[num]++;
        }

        vector<long long>cnt(m  + 1, 0);
        for(int i = 1 ; i <= m ; i++ ){
           for(int mul = i ; mul <= m ;mul += i){
                 cnt[i] += freq[mul];
           }
        }

        vector<long long >exact( m + 1 , 0 );

        for(int i = m ; i >= 1 ; i-- ){
            exact[i] = cnt[i] *1LL* ( cnt[i] - 1 ) / 2 ;

            for(int k = 2 * i ; k <= m ;k += i){
                exact[i] -= exact[k];
            }
        }

        vector<long long > prefix( m + 1 , 0);

        for(int i = 1 ; i <= m ;i++ ){
            prefix[i] = prefix[i - 1] + exact[i];
        }

        vector<int>ans;

        for(long long q : queries){
            int curr = lower_bound(prefix.begin() + 1 , prefix.end() , q + 1 ) - prefix.begin();
            ans.push_back(curr);
        }
        return ans;
    }
};