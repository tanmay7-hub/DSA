class Solution {
public:
    unordered_map<string , vector<pair<string, double>>>adj;
    void dfs(string src , string des ,unordered_set<string>&vis , double &ans ,  double mul ){
       
       if(vis.find(src) != vis.end()) return;
       vis.insert(src);

       if(src == des){
         ans  = mul ;
         return;
       }
       for(auto &p : adj[src] ){
            string v = p.first;
            double val = p.second;
 
            dfs(v , des , vis , ans , mul * val);
       }

    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    int n = equations.size();

    for( int i = 0 ; i < n ; i++ ){
         string u = equations[i][0];
         string v = equations[i][1];

         double val = values[i];

         adj[u].push_back({v , val});
         adj[v].push_back({u , 1.0 / val});
    }

    vector<double>result;

    for(auto q : queries){
        string src = q[0];
        string des = q[1];

        double ans = - 1.0;
        double mul = 1.0;
        if(adj.find(src) != adj.end()){
            unordered_set<string>vis;
            dfs(src , des ,vis , ans , mul );
        }

        result.push_back(ans);
    }
    return result;
        
    }
};