class Solution {
public:
    int n , m;
    vector<vector<int>>dir={ {0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0} };
    struct node{
        int i ;
        int j ;
        int t ;
        node(int i ,int j ,int t){
            this->i = i;
            this->j = j;
            this->t = t;
        }
    };
    bool isValid(int x , int y){

        return ( x >= 0 && x < n && y >= 0 && y < m);
    }
    int swimInWater(vector<vector<int>>& grid) {
        
        
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        auto comp = [&](node& a , node& b){
            return a.t > b.t;
        };
        priority_queue<node , vector<node> , decltype(comp) >pq(comp);
        pq.push(node(0,0,grid[0][0]));
        int ans = INT_MAX;
        while(!pq.empty()){

            node curr = pq.top();
            int i = curr.i;
            int j = curr.j;
            int t = curr.t;
            pq.pop();
            vis[i][j] = true;
             
            if( i == n - 1 && j == m - 1){
                ans = min(ans , t);
            }
            for(auto v : dir){
                 int x = v[0] , y = v[1];
                 int new_x = i + x;
                 int new_y = j + y;
                 int new_time ;

                 if(isValid(new_x , new_y)  && !vis[new_x][new_y]){
                    new_time = max(t , grid[new_x][new_y]);
                    pq.push(node(new_x , new_y , new_time));
                 }
            }

        }

        return ans;
    }
};