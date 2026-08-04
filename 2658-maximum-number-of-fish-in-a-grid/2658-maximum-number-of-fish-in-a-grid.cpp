class Solution {
public:
    void solve(int row,int col,int n,int m,vector<vector<bool>>&vis,vector<vector<int>>& grid,int &curr){
         vis[row][col]=true;
         curr += grid[row][col];
       
         //up
         if(row - 1 >= 0  &&  !vis[row-1][col]  && grid[row-1][col] != 0){
            solve(row-1,col,n,m,vis,grid,curr);
         }
         //down
         if( row + 1 < n && !vis[row+1][col] && grid[row+1][col] != 0){
            solve(row + 1 , col , n , m , vis , grid , curr );
         }
         //left
         if(col - 1 >= 0 && !vis[row][col - 1] && grid[row][col - 1] != 0){
            solve(row , col - 1 , n , m , vis , grid , curr);
         }
         //right
         if(col+1<m&&!vis[row][col+1]&&grid[row][col+1]!= 0){
             solve(row,col+1,n,m,vis,grid,curr);
         }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans=0;
        for(int i = 0 ; i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] != 0 && !vis[i][j]){
                    int curr = 0;
                    solve(i,j,n,m,vis,grid,curr);
                    ans=max(ans,curr);
                }
            }
        }
      
            return ans;
    }
};