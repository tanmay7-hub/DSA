class Solution {
public:
    int i = -1, j = -1;
    vector<vector<char>> grid;
    bool isNotValid(int i , int j){
        int n = grid.size() , m = grid[0].size();
        return !(i >= 0 && i < n && j >= 0 && j < m);
    }
    void solve(int row , int col , vector<vector<bool>> &vis){
        vis[row][col] = true;

        char ch = grid[row][col];
        if(ch == 'R'){
            int new_row = row ;
            int new_col = col + 1;  

            if(isNotValid(new_row , new_col) || vis[new_row][new_col]){
                i = row; j = col;
                return ;
            }
            solve(new_row , new_col , vis);
            
            
        }else if(ch == 'U'){
            int new_row = row - 1;
            int new_col = col ; 
            if(isNotValid(new_row , new_col) || vis[new_row][new_col]){
                i = row; j = col;
                return ;
            }
            solve(new_row , new_col , vis);

        }else if(ch == 'D'){
            int new_row = row + 1;
            int new_col = col ; 
            if(isNotValid(new_row , new_col) || vis[new_row][new_col]){
                i = row; j = col;
                return ;
            }
            solve(new_row , new_col , vis);

        }else{  // L
            int new_row = row ;
            int new_col = col - 1; 

            if(isNotValid(new_row , new_col) || vis[new_row][new_col]){
                i = row; j = col;
                return ;
            }
            solve(new_row , new_col , vis);
        }
        return ;
    }
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        this->grid = grid;
        int n = grid.size();
        int m = grid[0].size(); 
        vector<vector<bool>> vis(n ,  vector<bool>(m ,false ));
        solve(0 , 0 , vis);

        return {i , j};
    }
};