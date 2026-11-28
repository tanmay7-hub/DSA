class Solution {
public:

    int find(int x , vector<int>& par){
        if(par[x] == x)return x;
        return par[x] = find(par[x] , par);
    }
    void unite(int a , int b , vector<int>& rank , vector<int>& par){
        int par_a = find(a , par);
        int par_b = find(b , par);

        if(par_a == par_b) return;

        if(rank[par_a] > rank[par_b]){
            par[par_b] = par_a;
        }else if(rank[par_b] > rank[par_a]){
            par[par_a] = par_b;
        }else{
            rank[par_a]++;
            par[par_b] = par_a;
        }
    }  
    bool check(int k , int n , long long t ,vector<vector<int>> &edges  ){
        vector<int> rank(n , 1);
        vector<int> par(n);
        iota(par.begin() , par.end() , 0);
        for(auto edge : edges){
            int u = edge[0] , v = edge[1] , tm = edge[2];

            if(tm <= t){
                continue;
            }
            unite(u , v , rank , par);
        }


        int count = 0;
        for(int i = 0 ; i < n ; i++ ){
            if(par[i] == i) count++;
        }

        return count >= k;
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>> adj;
        long long st = 0 , end = 0;
        for(auto edge : edges ){
            end = max(end ,(long long) edge[2]);
        }
        long long ans = end;
        while(st <= end){
            long long mid = st + (end - st) / 2;

            if(check( k , n , mid , edges ) ){
               ans = min(ans , mid);
               end = mid - 1;
            }else{
               st = mid + 1;
            }
        }

        return ans;
    }
};