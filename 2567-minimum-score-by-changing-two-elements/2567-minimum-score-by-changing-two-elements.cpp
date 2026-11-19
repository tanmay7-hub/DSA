class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int mn = INT_MAX , s_min = INT_MAX , t_min = INT_MAX;
        int mx = INT_MIN , s_max = INT_MIN , t_max = INT_MIN;
        int n = nums.size();
        for(int i = 0 ; i < nums.size() ; i++ ){
            int num = nums[i];

            if(num < mn){
                t_min = s_min;
                s_min = mn;
                mn = num;
            }else if(num < s_min){
                 t_min = s_min;
                 s_min = num;
            }else if(num < t_min){
                t_min = num;
            }

            if(num > mx){
                t_max = s_max;
                s_max = mx;
                mx = num;
            }
            else if(num > s_max){
                t_max = s_max;
                s_max = num;
            }else if(num > t_max){
                t_max = num;
            }
        }
        return min({(mx - t_min) , (t_max - mn) , (s_max - s_min)});
    }
};