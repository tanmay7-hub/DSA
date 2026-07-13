class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
       
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>inDeg , outDeg;
        for(auto p : pairs){
            int u = p[0];
            int v = p[1];

            mp[u].push_back(v);

            outDeg[u]++;
            inDeg[v]++;
        }

        int startNode = pairs[0][0];
        for(auto& it : mp){
           int node = it.first;

           int diff = outDeg[node] - inDeg[node];

           if(diff == 1){
            startNode = node;
            break;
           }
        }
        
        stack<int>s;
        vector<int>EulerPath;

        s.push(startNode);

        while(!s.empty()){

            int node = s.top();

            if(mp[node].size() > 0 ){
                int new_node = mp[node].back();
                mp[node].pop_back();
                s.push(new_node);
            }else{
                EulerPath.push_back(node);
               s.pop();
            }
        }

        reverse(begin(EulerPath) , end(EulerPath));

        vector<vector<int>>ans;

        for(int i = 0 ; i + 1 < EulerPath.size() ; i++ ){

            ans.push_back({EulerPath[i] , EulerPath[i + 1]});
        }
       return ans;
    }
};