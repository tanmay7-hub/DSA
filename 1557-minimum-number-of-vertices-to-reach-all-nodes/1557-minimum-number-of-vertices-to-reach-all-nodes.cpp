class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>inDeg(n , 0 );

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            inDeg[v]++;
        }

        vector<int>res;
        for(int i = 0 ; i < n ; i++ ){
            if(inDeg[i] == 0 )res.push_back(i);
        }
        return res;
    }
};