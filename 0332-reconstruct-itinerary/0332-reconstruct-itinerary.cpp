class Solution {
public:
    unordered_map<string , vector<string>>mp;
    vector<string>ans; 
    void dfs(string from , vector<string>&path){
         vector<string>&ngh = mp[from];
        while(!ngh.empty()){

            string to = ngh[0];
            ngh.erase(ngh.begin());
            dfs(to ,path);   
               
        }
        path.push_back(from);

    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &vec : tickets){
              string u = vec[0];
              string v = vec[1];
              mp[u].push_back(v);
        }

        
        for(auto &edges : mp){
            sort(begin(edges.second) , end(edges.second));
        }

       vector<string>path;
       dfs("JFK" , path);
       reverse(begin(path) , end(path));
       return path; 
    }
};