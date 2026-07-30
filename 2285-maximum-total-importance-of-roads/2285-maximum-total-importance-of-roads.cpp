class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>inDeg(n);
        
        for(auto road : roads){
            int u  = road[0];
            int v  = road[1];
            inDeg[u]++;
            inDeg[v]++;
        }
        sort(inDeg.begin() , inDeg.end(), greater());
        long long ans = 0;
        for(int i = 0 ; i < inDeg.size() ; i++){
            ans += inDeg[i] * 1LL * n--;
        }
        return ans;
    }
};