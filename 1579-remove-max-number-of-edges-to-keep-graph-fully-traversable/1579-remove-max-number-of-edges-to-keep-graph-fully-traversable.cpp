class DSU{
  public:
    vector<int>par;
    vector<int>rank;
    int comp = 0;
    DSU(int n ){
        par.resize(n + 1 );
        iota(begin(par) , end(par) , 0 );
        rank.resize(n + 1 , 0 );
        comp = n;
    }
    int find(int x ) {
        if(par[x] == x) return x;


        return par[x] = find(par[x]);
    }

    void unite(int a , int b){
        int par_a = find(a);
        int par_b = find(b);

        if(par_a == par_b) return;

        if(rank[par_a] > rank[par_b]){
            par[par_b] = par_a;

        }else if(rank[par_b] > rank[par_a]){
            par[par_a] = par_b;
        }else{
            rank[par_a]++;
            par[par_b] = par_a;
        }
        comp-- ;
    }
};
class Solution {
  public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n);
        DSU bob(n);
        
        auto comp = [](vector<int>&vec1 ,  vector<int>&vec2 ){
             return vec1[0] > vec2[0];
        };
        sort(begin(edges) , end(edges), comp);


        int edgeCount = 0 ;

        for(auto vec : edges){
            int type = vec[0];
            int u    = vec[1];
            int v    = vec[2];


            if(type == 3){
                bool added = false;
                if(alice.find(u) != alice.find(v)){
                        alice.unite( u , v );
                        added = true;
                }

                if(bob.find(u) != bob.find(v) ){
                        bob.unite( u , v );
                        added = true;
                }

                edgeCount += added;
            }else if(type == 2){
                 if(bob.find(u) != bob.find(v) ){
                        bob.unite( u , v );
                        edgeCount++;
                  }   
            }else{
                  if(alice.find(u) != alice.find(v)){
                        alice.unite( u , v );
                        edgeCount++;
                }
            }
        }
        

        if(alice.comp == 1 && bob.comp == 1){
          return  edges.size() - edgeCount;
        }
        return -1;
    }
};