class Solution {
public:
    typedef pair<double , int > P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
       
       unordered_map<int , vector<P>> adj;
       vector<double>result(n , 0.00);
       for(int i = 0 ; i < edges.size(); i++ ){
          int u = edges[i][0];
          int v = edges[i][1];
          double pb = succProb[i];

          adj[u].push_back({  pb  , v});
          adj[v].push_back({  pb , u});
       }

       result[start_node] = 1;
       priority_queue<P >pq;
       pq.push({1.0 , start_node});

       while(pq.size() > 0){
           
             P curr = pq.top();
             pq.pop();
             
             int curr_node = curr.second;
             double curr_prob = curr.first;
             for(auto &temp : adj[curr_node]){
                  int v  = temp.second;
                  double pb = temp.first;
                  if(result[v] < curr_prob * pb){
                     result[v]  = curr_prob * pb;
                     pq.push({ result[v] , v });
                  }
             }

        
       }
       return result[end_node] ;  

    }
};