class Solution {
public:
    unordered_map<int , int > mp;
    vector<int> tin;
    vector<int> tout;
    int timer = 0;
    int Precalc(unordered_map<int , vector<int>> &adj ,vector<int> &nums , int src , int par){
       
        int x = 0 ;
        for(auto v : adj[src]){
            if(par != v)
               x ^=  Precalc( adj ,nums , v , src);
        }
        mp[src] = nums[src] ^ x;
        return mp[src];
    }
    void ancestor( unordered_map<int , vector<int>> &adj , int src , int par){ 
        tin[src] = timer++;
        
        for(auto v : adj[src]){
            if(v == par ) continue;
            ancestor(adj , v , src );
        }
           
        tout[src] = timer++;   
    } 
    bool isAncestor(int u , int v){
        return (tin[u] <= tin[v] && tout[v] <= tout[u]);
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = edges.size();
        tin.resize(n + 1 );
        tout.resize(n + 1 );
        unordered_map<int , vector<int>> adj;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int total_xor = Precalc(adj ,nums, 0 , -1);
        ancestor( adj , 0 , -1);

        int ans = INT_MAX;
        for(int i = 1 ; i <= n ; i++ ){
            for(int j = i + 1 ; j <= n ; j++){
                 int x1 = mp[i];
                 int x2 = mp[j];
                  
                 int a , b , c;
                 if(isAncestor(i, j)){ // i ancestor
                    a = x2;
                    b = x1 ^ x2;
                    c = total_xor ^ x1;
                 }
                 else if(isAncestor(j , i )){ // j ancestor
                    a = x1 ;
                    b = x2 ^ a;
                    c = total_xor ^ x2;
                 }else{
                    a = x1 ;
                    b = x2 ;
                    c = total_xor ^ a ^ b;
                 }
                 int curr = max({a , b , c}) - min({a , b , c});
                 ans = min(ans , curr);
            }
        }
        return ans;
    }
};