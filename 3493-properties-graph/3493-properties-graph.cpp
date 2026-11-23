class Solution {
public:
    vector<int> par;
    vector<int> rank;
    int intersect(vector<int> &a , vector<int> &b){
         unordered_map<int , int> mp;

         for(auto num : a ){
             mp[num] = 1;
         }
         int ans = 0 ;
         for(int i = 0 ; i < b.size() ;i++ ){
             int num = b[i];

             if(mp[num] != 0){
                ans ++;
                mp[num]--;
             }
         }

         return ans;
    }
    int find(int x){
        if(par[x] == x)return x;
        return par[x] = find(par[x]);
    }
    void unite(int a , int b){
        int par_a = find(a);
        int par_b = find(b);

        if(par_a == par_b)return;

        if(rank[par_a] > rank[par_b]){
            par[par_b] = par_a;
        }else if(rank[par_a] < rank[par_b]){
            par[par_a] = par_b;
        }else{
            par[par_b] = par_a;
            rank[par_a]++;
        }
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size() , m = properties[0].size();
        par.resize(n);
        rank.resize(n , 0);
        iota(par.begin() , par.end() , 0);

        for(int i = 0 ; i < n ; i++ ){
             for(int j = i + 1 ; j < n ; j++ ){
                if(par[i] == par[j]) continue;
                if(intersect(properties[i] , properties[j]) >= k){
                    unite(i , j);
                }
             }
        }
        int ans = 0;

        for(int i = 0 ; i < n ; i++ ){
            if(par[i] == i)ans++;
        }

        return ans;
    }
};