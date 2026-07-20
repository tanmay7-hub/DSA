class Solution {
public:
    vector<int>par;
    vector<int>rank;
    struct node{
        int idx ;
        int u ;
        int v ;
        int dis;

        node(int idx , int u , int v , int dis){
            this->idx = idx;
            this->u = u;
            this->v = v;
            this->dis = dis;
        }
        node(){
            
        }
    };
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
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
          int m = queries.size();
      par.resize(n);
      iota(begin(par) , end(par) , 0 );
      rank.resize(n , 0 );


      sort(begin(edgeList) , end(edgeList) , [](const auto &a , const auto &b){
         return a[2] < b[2]; 
      });
      vector<node>nodes(m);
    
      for(int i = 0 ; i < m ; i++ ){
           int idx = i;
           int u = queries[i][0];
           int v = queries[i][1];
           int dis = queries[i][2];

           node curr = node(idx , u , v , dis);

           nodes[i] = curr;
      }
      auto comp = [&](const node &a , const node &b){
         return a.dis < b.dis;
      };
      sort(nodes.begin()  , nodes.end() , comp);
       
      int prev = 0;
      vector<bool>result(m);
      for(int i = 0 ; i < m ; i++ ){
           int limit = nodes[i].dis;
           int idx = nodes[i].idx;
           int u = nodes[i].u;
           int v = nodes[i].v;
           while(prev < edgeList.size() && edgeList[prev][2] < limit ){
                   int x = edgeList[prev][0];
                   int y = edgeList[prev][1];
                   unite(x , y);
                   prev ++;
           }


          int par_a = find(u);
          int par_b = find(v);


          result[idx] = par_a == par_b;
      }
       return result;
    }
};