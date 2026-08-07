class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<string, int> Stn;
    vector<bool> topo(vector<long long>& inDeg, int n) {
        vector<bool> ans(n, false);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            ans[curr] = true;
            q.pop();
            for (auto v : adj[curr]) {
                inDeg[v]--;
                if (inDeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return ans;
    }
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        int n = recipes.size();

        unordered_set<string> s;
        s.insert(supplies.begin(), supplies.end());
        for (int i = 0; i < n; i++) {
            Stn[recipes[i]] = i;
        }

        vector<long long> inDeg(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto ing : ingredients[i]) {
                if(s.count(ing)){
                }
                else if (Stn.count(ing)) {
                    adj[Stn[ing]].push_back(i);
                    inDeg[i]++;
                } else {
                    inDeg[i] = INT_MAX; 
                }
            }
        }

        vector<bool> Topo = topo(inDeg, n);
        vector<string> ans;

        for (int i = 0; i < n; i++) {
            if (Topo[i]) {
                ans.push_back(recipes[i]);
            }
        }
        return ans;
    }
};