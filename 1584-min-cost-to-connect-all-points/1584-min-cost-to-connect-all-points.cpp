class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ans=0;
        int V=points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<bool>vis(V,false);
        int src=0;
        pq.push(make_pair(0,src));
        while(pq.size()>0){
            int u=pq.top().second;
            int cost=pq.top().first;
            pq.pop();
            if(!vis[u]){
                vis[u]=true;
                ans+=cost;
                for(int v=0;v<V;v++){
                    if(u!=v){
                        int wt=abs(points[v][0]-points[u][0])+abs(points[v][1]-points[u][1]);
                        pq.push(make_pair(wt,v));
                    }
                }
            }
        }
        return ans;
    }
};