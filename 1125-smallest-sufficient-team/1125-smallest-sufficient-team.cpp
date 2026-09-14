class Solution {
public:    
    int dp[61][65537];
    int choice[61][65537];
    long long solve(vector<int>& people , int n , int idx , int mask){

        if(mask == (1 << n) -1) return 0;
        if(idx == people.size()) return INT_MAX;

        if(dp[idx][mask] != -1 )return dp[idx][mask];
        long long take =  solve(people , n ,  idx + 1 , mask | people[idx]);
        if(take != INT_MAX){
            take += 1;
        }
        long long not_take = solve(people , n , idx + 1 , mask );

        if(take < not_take){
            choice[idx][mask] = 1;
        }else{
            choice[idx][mask] = 0;
        }

        return dp[idx][mask] = min(take , not_take);
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people){
         memset(dp , -1 , sizeof(dp)); 
         int n = people.size();  
         unordered_map<string , int >mp;
          for(int i = 0 ; i < req_skills.size() ; i++ ){
              mp[req_skills[i]] = i;
          } 
          
          vector<int> peopleMask(n , 0);
          for(int i = 0 ; i < people.size() ; i++ ){
            int mask = 0;
             for(auto skill : people[i]){
             mask |= (1 << mp[skill]);
             }
             peopleMask[i] = mask;
          }

          int count =  solve(peopleMask , req_skills.size() ,  0  , 0);         
          vector<int> ans;
          int idx = 0 , mask = 0;
          while(idx != people.size()){
              
              if(choice[idx][mask] == 1){
                 mask |= peopleMask[idx];
                 ans.push_back(idx);
              }
              idx++;
          } 

          return ans;
    }
};