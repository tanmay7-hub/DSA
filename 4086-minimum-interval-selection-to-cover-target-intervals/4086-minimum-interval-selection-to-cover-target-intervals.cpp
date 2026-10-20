class Solution {
public:
    int MAXLEN = 100000;
    int minSelection(vector<vector<int>>& avail, vector<vector<int>>& tar) {
        sort(begin(tar) , end(tar) );      
        vector<pair<int , int>> merged;

        for(auto &t : tar){
            if(!merged.empty() && t[0] <= merged.back().second){
                  merged.back().second = max(merged.back().second , t[1]);
            }else{
               merged.push_back({t[0] , t[1]});    
            }
        }
        vector<int> maxEnd(MAXLEN+2, 0);
        for(auto& a: avail){
            maxEnd[a[0]] = max(maxEnd[a[0]], a[1]);
        }

        for(int i = 1; i <= MAXLEN+1; i++){
            maxEnd[i] = max(maxEnd[i], maxEnd[i-1]);
        }


        int e = 0 , cnt = 0;

        for(auto& [l , r] : merged){
            if(e >= r)continue;
            if(e < l ){
                if(maxEnd[l] < l) return -1;
                e = maxEnd[l];
                cnt++;
            }

            while(e < r){
              int nr = maxEnd[e];
              if(nr <= e ) return -1;
              e = nr;
              cnt++;
            }
        }
        return cnt;

        
    }
};