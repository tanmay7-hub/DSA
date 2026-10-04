class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s (arr.begin() , arr.end());

        int count = 0;
        int i = 1;
        int ans = -1;
        while(count <= k){
           if(!s.count(i)){
              count ++;
              if(count == k ){
                ans = i;
              }
           }
           i++;
        }
        return ans;
    }
};