class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ans = 0;
        
        int v = points.size();


        unordered_map<int,vector<pair<int,int>>>mp;


        for(int i = 0 ; i < points.size() ; i++ ){
            for(int j = i + 1 ; j < points.size() ; j++){
                 int  u = i ;
                 int  v = j ;

                 int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                 mp[u].push_back({v,wt});
                 mp[v].push_back({u,wt});
            }
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        vector<bool>vis(v , false);
         
         pq.push({0 , 0});

        int sum = 0;          
        while( !pq.empty() ){

            auto [ wt , node ] = pq.top();
            pq.pop();

            if(vis[node] )continue;

            vis[node] = true;
            sum += wt;
            for(auto [v , wt] : mp[node]){
                
                if(!vis[v]){

                    pq.push({wt , v});

                }

            }
        }
        return sum;
    }
};