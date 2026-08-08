class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();

        vector<int> haveBox(n , false);
        vector<int> haveKey(n , false);
        vector<int> opened(n , false);

        queue<int> q;
        for(int box : initialBoxes){
            haveBox[box] = true;

            if(status[box] == 1){
                q.push(box);
            }
        }
        int ans = 0; 

        while(!q.empty()){

            int curr = q.front();
            q.pop();
            if(opened[curr] == 1)continue;

            if(!haveKey[curr] && status[curr] == 0)continue;

            opened[curr] = 1;
            ans += candies[curr];

            for(int key : keys[curr]){
                haveKey[key] = true;
                if(haveBox[key] && !opened[key]){
                    q.push(key);
                }
            }

            for(int box : containedBoxes[curr]){
                haveBox[box] = true;

                if(( status[box] == 1 || haveKey[box]) && !opened[box]){
                    q.push(box);
                }
            }
        }
        return ans;
    }
};