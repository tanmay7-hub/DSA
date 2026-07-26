class Solution {
public:
    vector<int>par;
    vector<int>rank;
    int comp;
    int find(int x){
        if(par[x] == x)return x;
        return par[x] = find(par[x]);
    }
    bool unite(int a , int b){
        int par_a = find(a);
        int par_b = find(b);

        if(par_a == par_b)return true;

        if(rank[par_a] > rank[par_b]){
            par[par_b] = par_a;

        }else if(rank[par_a] < rank[par_b]){
            par[par_a] = par_b;
        }else{
             par[par_b] = par_a;
             rank[par_a]++;
        }
        comp--;
        return false;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        comp = n;
        rank.resize(n , 0);
        par.resize(n );
        iota(par.begin() , par.end() , 0);
        vector<int>treeParent(n , -1);
        for(int i = 0 ; i < n ; i++ ){
            bool check = false;
            if(leftChild[i] != -1){ 
              if(treeParent[leftChild[i]] != -1)return false;

               treeParent[leftChild[i]] = i;
              check = check || unite(i , leftChild[i]);
            }
            if(rightChild[i] != -1){
               if(treeParent[rightChild[i]] != -1)return false;

               treeParent[rightChild[i]] = i;
              check = check || unite(i , rightChild[i]);
            }

            if(check)return false;
        } 

        return ( comp == 1 );
    }
};