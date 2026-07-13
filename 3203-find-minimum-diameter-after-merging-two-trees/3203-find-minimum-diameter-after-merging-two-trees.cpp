class Solution {
public:
    pair<int,int> farthest(int node ,int n , unordered_map<int,vector<int>>&adj){   
       queue<int>q;
       vector<bool>visited(n , false);
       q.push(node);
       int farNode = node , l = 0;
       visited[node] = true;
       while(!q.empty()){
           int size = q.size();

           while( size-- ){
                 int curr = q.front();
                 q.pop();
                 for(auto v : adj[curr]){
                    if(!visited[v]){
                          q.push(v);
                          visited[v] = true;
                    }
                 }
                 farNode = curr;
           }
           l++;
           
       } 
       return make_pair(farNode , l - 1);
    }
    int dia(vector<vector<int>>& edges , int n){

        unordered_map<int,vector<int>>adj;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        int random_node = -1;
        for(auto edge : edges){
            random_node = edge[0];
            break;
        }
        if(random_node == -1)return 0;
        auto end1 = farthest (random_node , n ,  adj);

        auto end2 = farthest( end1.first ,n ,  adj);


        return  end2.second;  
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        // if(edges1.size() == 0 && edges2.size() == 0 )return  1;
        int n = edges1.size() , m = edges2.size();
        int d1 = dia(edges1 , n + 1 );
        int d2 = dia(edges2 , m + 1 );


        int md1 = (d1 % 2 == 0) ? d1 / 2 : ceil(d1 / 2.0);
        int md2 = (d2 % 2 == 0) ? d2 / 2 : ceil(d2 / 2.0);

        return max({d1 , d2 , md1 + md2 + 1});
    }
};