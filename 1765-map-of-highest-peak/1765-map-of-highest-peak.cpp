class Solution {
public:
    int n , m ;
    struct node{
        int i , j;
        int d;

        node(int i , int j , int d ){
            this->i = i; 
            this->j = j;
            this->d = d;
        }
    };
    vector<vector<int>>dir = {
        {0 , 1},
        {0 , -1},
        {1 , 0},
        {-1 , 0}
    };
    bool isValid(int x , int y ){

        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
         n = isWater.size() ;
         m = isWater[0].size();
        vector<vector<int>>ans(n , vector<int>(m , 0));

        queue<node>q;
        vector<vector<bool>>visited(n , vector<bool>( m , false));
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ; j++ ){
             if(isWater[i][j] == 1){
                q.push(node(i , j , 0));
                visited[i][j] = true;
             }
            }
        }
        while(!q.empty()){

            int sz = q.size();

            while( sz-- ){
                 node curr = q.front();
                 q.pop();
                  
                  int x = curr.i ;
                  int y = curr.j ;
                  int d = curr.d ;


                  
                  ans[x][y] = d;
                  
                 for(auto v : dir){
                    
                    int new_x = x + v[0];
                    int new_y = y + v[1];


                    if(isValid(new_x , new_y) && !visited[new_x][new_y]){

                             q.push(node(new_x , new_y , d + 1));
                             visited[new_x][new_y] = true;
                    }
                 }

            }
        }
        return ans;
    }
};