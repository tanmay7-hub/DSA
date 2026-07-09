class Solution {
public:
    int find(vector<int>& par,int x){
          if(par[x] == x)return x;
          return par[x] = find(par,par[x]);
    }
    void unin(vector<int>&par,vector<int>&rank , int a ,int b){
        if(par[a] == par[b]) return;


        int parA = find(par , a);
        int parB = find(par , b);

        if(rank[parA] > rank[parB]){
              rank[parA]++;
              par[parB] = parA;
        }else if( rank[parA] < rank[parB]){
              rank[parB]++;
              par[parA] = parB;
        }else{
              rank[parA]++;
              par[parB] = parA;
        }

        return ;
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
       
        vector<int>rank(n);
        vector<int>par(n);
        iota(par.begin() , par.end() , 0);

        
        for(int i = 0 ; i + 1  < nums.size()  ; i++ ){
                if(abs(nums[i + 1] - nums[i])  <= maxDiff){
                    unin(par , rank, i , i + 1);
                }
        }

        vector<bool>ans;

        for(auto q:queries){
            int left  = q[0];
            int right = q[1];
            int parL = find(par,left);
            int parR = find(par,right);
            if( parL == parR  ){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};