class Solution {
public:
   const int mod = 1e9+7;
   struct node {
       long long count;
       long long sum ; 
       long long num;
       node(){
        sum = 0;
        count = 0;
        num = 0;
       }
       node(long long count ,long long sum , long long num ){
        this->sum = sum ;
        this->count = count;
        this->num = num;
       }
   };
   long long power(long long x ,long long y){
     long long ans = 1;

      while(y){
        if( y & 1 ){
             ans *= x; 
             ans %= mod;    
        }
        x *= x;
        x %= mod;
        y /= 2;
      }
      return ans % mod;
   }
    void build (vector<node>&sgt , string &s , int idx , int l ,int r ){
        if(l == r){
            int sum  = s[l] =='0' ? 0: s[l] - '0';
            sgt[idx].sum = sum;
            sgt[idx].count = sum > 0;
            sgt[idx].num = sum ; 
            return ;
        }

        int mid = l + ( r - l  ) / 2;

        int leftidx  = 2 * idx + 1;
        int rightidx = 2 * idx  + 2; 

        build(sgt , s , leftidx , l , mid );
        build(sgt , s , rightidx , mid + 1 , r);

        long long sum   = sgt[leftidx].sum + sgt[rightidx].sum;
        long long count = sgt[leftidx].count + sgt[rightidx].count;
        long long num   = (sgt[leftidx].num *  power(10 , sgt[rightidx].count) + sgt[rightidx].num)% mod;
        

        sgt[idx].sum = sum;
        sgt[idx].count = count;
        sgt[idx].num = num ; 
    }
    node search (vector<node>& sgt , int idx , int st, int end , int l , int r){
        if(l > end || r < st ) return  node(0 , 0, 0 );
        if(l <= st && end <= r)return sgt[idx];

        int mid = st  + (end - st) / 2;

        int leftidx  = 2 * idx + 1;
        int rightidx = 2 * idx  + 2; 

        node left = search(sgt , leftidx , st , mid , l , r);
        node right = search(sgt, rightidx , mid + 1 ,end, l , r);


        long long sum = left.sum + right.sum;
        long long count  = left.count + right.count;
        long long num = (left.num *  power(10,right.count)  + right.num)% mod;
       
        node curr(count , sum , num);
        return curr;

    }
   
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        
        int n = s.size() ;
        vector<node>sgt( 4 * n , node());
        vector<int>ans;
        build(sgt , s , 0 , 0 , n - 1 );

        for(auto& q : queries){
               int left  = q[0];
               int right = q[1];

               node curr = search(sgt , 0 , 0 , n - 1 , left ,right );
               long long num = curr.num;
               long long res = (num * curr.sum ) ;
               res %= mod;
               ans.push_back(res);
        }

        return ans;
    }
};