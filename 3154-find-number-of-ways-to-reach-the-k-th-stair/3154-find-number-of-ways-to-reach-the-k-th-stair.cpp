class Solution {
public:
    int k;
    unordered_map<string , int> mp;
    int solve(int curr  , int jump, bool isCons){  
    if(curr > k + 1) return 0;


    string key = to_string(curr) + "_" + to_string(jump) + "_" + to_string(isCons);

    if(mp.find(key) != mp.end())return mp[key];
    int add = (curr == k);
      int back = 0;
      if(!isCons && curr != 0){
        back = solve( curr - 1 , jump  , true);
      }

      int forward = solve(curr + (1 << jump) , jump + 1 , false);
      return mp[key] = add + back + forward;
    }
    int waysToReachStair(int k) {
        this->k = k;
        return solve(1 , 0 , false);
    }
};