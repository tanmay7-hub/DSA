class Solution{
    public:
    int result;  
    int DFS(unordered_map<int, vector<int>> &adj, int curr, int parent, string& s) {
        int longest = 0 ; 
        int second_longest = 0;

        for(int child : adj[curr]){

            if(child == parent) continue;

            int bestFromChild = DFS(adj , child , curr , s);
            if(s[curr] == s[child])continue;          
            if(bestFromChild > second_longest){
                second_longest = bestFromChild;
            }
            if(second_longest > longest ){
                swap( second_longest , longest );
            }
        }

        result = max({ result , longest + second_longest + 1 , longest + 1, second_longest + 1 , 1});


        return max({ 1 , longest + 1, second_longest + 1}) ;
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        result = 0;
        unordered_map<int, vector<int>> adj;
        
        for(int i = 1; i<n; i++) {
            int u = i;
            int v = parent[i];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        DFS(adj, 0, -1, s);
        
        return result;
    }
};