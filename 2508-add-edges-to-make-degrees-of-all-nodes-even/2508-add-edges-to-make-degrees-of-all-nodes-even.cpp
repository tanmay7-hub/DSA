class Solution {
public:
    unordered_map<int , vector<int>> adj;
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> deg(n + 1 , 0);
        map<pair<int,int> , bool> isConnected;

         for(auto edge : edges){
             int u = edge[0] , v = edge[1]; 
             deg[u]++;
             deg[v]++;
             isConnected[{u,v}] = true;
             isConnected[{v,u}] = true;
         }
         int count = 0;
         vector<int> vec;
         for(int i = 1 ; i < n + 1 ; i++ ){
            if(deg[i] % 2 != 0 ){
                count++;
                vec.push_back(i);
            }
         }

         if(count == 0 )return true;
         else if(count > 4)  return false;

         if(count == 2){
            int a = vec[0] , b = vec[1]; 
            if( !isConnected[{a , b}] )return true;


            for(int i = 1 ; i < n + 1 ; i++ ){    
                    if(i == a || i == b) continue;
                    if(!isConnected[{i , a}] && !isConnected[{i , b}]){
                        return true;
                    }     
            }

         }else if(count == 4){
             int a = vec[0] ,  b = vec[1] , c = vec[2] , d = vec[3];

             if( !isConnected[{a , b}] && !isConnected[{c , d}])return true;
             else if(!isConnected[{a , c}] && !isConnected[{b , d}])return true;
             else if(!isConnected[{a , d}] && !isConnected[{b , c}])return true;

         }

         return false;
    }
};