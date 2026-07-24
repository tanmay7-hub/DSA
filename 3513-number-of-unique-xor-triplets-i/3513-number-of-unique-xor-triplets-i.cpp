class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return n;

        int mask = 0;
        for (int i = 1 ; i <= n ; i++ ) {
            mask |= i;
        }

        return mask + 1;

    }
};