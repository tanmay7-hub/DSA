class Solution {
public:
   class unionFind{
     public:
            vector<int>par;
            vector<int>rank;
            unionFind(int n){
                par.resize(n);
                iota(begin(par) , end(par) , 0);
                rank.resize(n , 0);
            }  
            int find(int x){
                if(par[x] == x)return x;
                return par[x] = find(par[x]);
            }
            void unite(int a , int b){
                int par_a = find(a);
                int par_b = find(b);
                if(par_a == par_b)return;

                if(rank[par_a] > rank[par_b]){
                    par[par_b] = par_a;
                }else if(rank[par_b] > rank[par_a]){
                    par[par_a] = par_b;
                }else{
                par[par_b] = par_a;
                rank[par_a]++;
                }
            }
    };
   int N;
   int krushkul(vector<vector<int>>& edges , int add , int remove){
       unionFind uf(N);
       int sum = 0;
       int  edgeCount = 0;
       if(add != -1){
          sum += edges[add][2];
          uf.unite(edges[add][0] , edges[add][1]);
          edgeCount = 1;
       }

       for(int i = 0 ; i < edges.size() ; i++){
          int u = edges[i][0];
          int v = edges[i][1];
          int wt = edges[i][2];
          if( remove == i )continue;
          int par_a = uf.find(u);
          int par_b = uf.find(v);

          if(par_a != par_b){
            uf.unite(u , v);
            edgeCount++;
            sum += wt; 
          }
       }
       if(edgeCount != N - 1)return INT_MAX;
       return sum;
   }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;
        int m = edges.size();
        for(int i = 0 ; i < m ; i++ ){
            edges[i].push_back(i);
        }
        auto comp = [&](vector<int>&a , vector<int>&b){
            return a[2] < b[2];
        };
        sort(begin(edges) , end(edges) , comp);

        int mst_wt = krushkul(edges , -1 , -1 ); // add , remove
        vector<int>cri;
        vector<int>pseudo_cric;
        for(int i = 0 ; i < m ;i++ ){
            int idx = edges[i][3];
            if(krushkul(edges , -1 , i ) > mst_wt){
                cri.push_back(idx);
            }else if(krushkul(edges ,  i , -1 ) == mst_wt){
                pseudo_cric.push_back(idx);
            }
        }
        return {cri , pseudo_cric};
    }
};