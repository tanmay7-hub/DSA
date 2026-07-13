class Solution {
public:
   int n , m;
   struct node{
     // i , j  is of source while x , y is of destination
        int i ;
        int j ;
        int d ;
       
        node(int i , int j , int d){
            this->i = i ; 
            this->j = j ; 
            this->d = d;
        }
   };
   vector<vector<int>>dir = {
       {0 ,  1},
       {0 , -1},
       {1 ,  0},
       {-1 , 0}
   };
   int dist (int i , int j ,int x , int y){
       return abs(x - i )+ abs( y - j);
   }
   bool isValid(int x ,int y){
       if(x >= 0 && x < n && y >= 0 && y < m )return true;

       return false;
   }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         n = mat.size() ;
         m = mat[0].size();
        queue<node>q;
        vector<vector<int>>ans(n ,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ; j++ ){

                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push(node(i , j , 0 ));
                }
            }
        }

        vector<vector<bool>>visited(n , vector<bool>(m , false));
        while(!q.empty()){

            int sz = q.size() ;

            while(sz -- ){

                node curr = q.front();
                q.pop();
                
                int x = curr.i , y = curr.j;
                int d = curr.d;
                
                if(mat[x][y] == 1){
                    ans[x][y] = d;
                }
                    for(auto vec : dir ){
                        int new_x  = x + vec[0];
                        int new_y  = y + vec[1];

                        if(isValid(new_x , new_y) && !visited[new_x][new_y] ){
                              q.push(node(new_x , new_y , d + 1));
                              visited[new_x][new_y] = true;

                        }
                    } 
                
            }
        }


        return ans;
    }
};