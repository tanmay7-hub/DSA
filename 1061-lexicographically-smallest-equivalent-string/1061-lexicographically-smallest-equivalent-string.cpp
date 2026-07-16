class Solution {
public:
    vector<int>parent;
    int find(int x){
        int par = parent[x];

        if(par == x)return x;

        return parent[x] = find(par);
    }
    void un(int a , int b){

        int parA = find(a);
        int parB = find(b);

        if(parA == parB ) return ;

        if(parA < parB){
            parent[parB] = parA;
        }else{
            parent[parA] = parB;
        }
        return;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        parent.resize(26 );

        iota(parent.begin() , parent.end() , 0);
        for(int i = 0 ; i < n ; i++ ){
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            un( u ,  v);
        } 

        string ans = "";
        for( int i = 0 ; i < baseStr.size() ; i++ ){
             char ch = baseStr[i];
             ans += (find(ch - 'a') + 'a');
        }
        return ans;
    }
};