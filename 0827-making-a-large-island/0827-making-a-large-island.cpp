class Solution {
public:
    int n;
    vector<vector<int>> dir = {{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1}};
    bool valid(int i , int j , int n){
        return ( i >= 0 && i < n && j >= 0 && j < n);
    }
    int dfs(vector<vector<int>>& grid , int i , int j , int id){
        if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1){
            return 0;
        }
       grid[i][j] = id;
       int ans = 1;
       for(auto vec : dir){
            int new_i = i + vec[0];
            int new_j = j + vec[1];

            ans += dfs(grid , new_i , new_j , id);
       }  
       return ans;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int ans = 0 , uniId = 2;
        unordered_map<int , int> mp;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++ ){
                if(grid[i][j] == 1){
                    int sz = dfs(grid ,i , j , uniId );
                    ans = max(ans , sz);
                    mp[uniId] = sz;
                    uniId++; 
                }
            }
        }

        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < n ; j++ ){
                if(grid[i][j] == 0){
                    unordered_set<int> s;
                    for(auto vec : dir ){
                        int new_i = i + vec[0];
                        int new_j = j + vec[1];

                        if(valid(new_i , new_j ,n)){
                            s.insert(grid[new_i][new_j]);
                        }
                    }
                    int curr = 1;
                    for(auto it : s){
                        curr += mp[it];
                    }
                    ans = max(ans , curr);
                }
            }
        }
        return ans;
    }
};