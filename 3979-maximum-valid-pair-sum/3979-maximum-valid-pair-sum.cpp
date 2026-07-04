class Solution {
public:

    void build (vector<int>&sgt ,vector<int>&nums,int idx,int l , int r ){
        if( l ==  r ){
            sgt[idx] = nums[l];
            return ;
        }
        int leftIdx  = 2 * idx + 1;
        int rightIdx = 2 * idx + 2; 
        int mid =  ( l + r ) / 2;

        build(sgt , nums , leftIdx  , l , mid );
        build(sgt , nums , rightIdx , mid + 1, r);

        sgt[idx] = max(sgt[leftIdx] , sgt[rightIdx]);
        return;
    }
    int sgtQ(vector<int>&sgt ,int idx, int start ,int end , int ql , int qr){
        if(ql <= start && qr <= qr ) return sgt[idx];

        if(end < ql || start > qr)return INT_MIN;

        int mid = (start  + end )/2;
        int left = sgtQ(sgt , 2 * idx + 1, start , mid , ql , qr);
        int right = sgtQ(sgt , 2 * idx + 2 , mid + 1 , end , ql , qr);
        return max(left,right);
    
    }
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MIN;
        
        vector<int>sgtBuild(4 * n  );
        build(sgtBuild , nums , 0 , 0 , n - 1 );
        for(int i = 0 ; i < nums.size() ; i++ ){
            if(i + k >= n)continue;
            int curr = sgtQ(sgtBuild , 0 , 0, n - 1,i + k , n ) ;
            ans = max(ans , curr + nums[i]);
            
        }
        return ans;
    }
};