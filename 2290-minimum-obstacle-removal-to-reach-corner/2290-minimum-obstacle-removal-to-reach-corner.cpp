class Solution {
public:
    vector<vector<int>> dir = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };
    bool valid(int i , int j ,int n , int m){
        return ( i >= 0 && i < n  && j >= 0 && j < m);
    }
    int zero1dfs(vector<vector<int>>& grid){
        int n = grid.size() , m = grid[0].size();
        deque<pair<int,int>>dq;
        dq.push_front({0 , 0});
        vector<vector<int>>dist(n , vector<int>(m , INT_MAX));
        dist[0][0] = 0;

        while(!dq.empty()){
            
             auto [i , j] = dq.front();
             dq.pop_front();
             if(i == n - 1 && j == m - 1)
                     return dist[i][j];
             for(auto vec : dir){
                 int new_i = i + vec[0];
                 int new_j = j + vec[1];
                 if(valid(new_i , new_j , n , m)){
                       
                    int cost = grid[new_i][new_j];

                    if(dist[i][j] + cost < dist[new_i][new_j]){
                        
                        dist[new_i][new_j] = dist[i][j] + cost;

                        if(cost == 0){
                            dq.push_front({new_i , new_j});
                        }else{
                            dq.push_back({new_i , new_j});
                        }
                    }
                 }
             }

        }
        return dist[n - 1][m - 1] == INT_MAX ? -1 :  dist[n - 1][m - 1];
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        return zero1dfs(grid);
    }
};