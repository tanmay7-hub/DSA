class Solution {
public:
    vector<int> topo(  unordered_map<int , vector<int>>&adj  ,vector<int>inDeg){
            queue<int>q;
            for(int i = 0 ; i < inDeg.size() ; i++){
                if(inDeg[i] == 0){
                    q.push(i);
                }
            }
            vector<int>ans;
            while(!q.empty()){
                int curr = q.front();
                ans.push_back(curr);
                q.pop(); 
                for(int &v : adj[curr]){
                    inDeg[v]--;
                    if(inDeg[v] == 0){
                        q.push(v);
                    }
                }
            }


            return ans.size() == inDeg.size() ? ans : vector<int>();

        
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i = 0 ; i < group.size() ; i++ ){
            if(group[i] == -1){
                group[i] = m++;
            }
        }
        
        unordered_map<int , vector<int>>itemsAdj;
        vector<int>itemsInDeg(n , 0);
        unordered_map<int , vector<int>>groupAdj;
        vector<int>groupInDeg(m , 0);

        for(int i = 0 ; i < n ; i++ ){
             int curr_group = group[i];
             
             for(int &prev : beforeItems[i]){
                int src_group = group[prev];
                itemsAdj[prev].push_back(i);
                itemsInDeg[i]++;
                if(src_group != curr_group ){
                     groupAdj[src_group].push_back(curr_group);
                     groupInDeg[curr_group]++;
                }
             }
        }

        vector<int>Topoitems  =  topo( itemsAdj , itemsInDeg);
        vector<int>Topogroup  =  topo( groupAdj , groupInDeg);


        if(Topoitems.empty() || Topogroup.empty() )return {};
        unordered_map<int , vector<int>>mp;

        for(int &item : Topoitems){
            int item_group = group[item];
            mp[item_group].push_back(item);
        }

        vector<int>ans;
        
        for(int i = 0 ; i < Topogroup.size() ; i++ ){
            ans.insert(ans.end() , mp[Topogroup[i]].begin() , mp[Topogroup[i]].end());
        }
        return ans;
    }
};