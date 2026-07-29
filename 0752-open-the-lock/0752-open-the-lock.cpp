class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        queue<string>q;
        unordered_set<string>s;
        s.insert(begin(deadends) , end(deadends));
        if(s.count("0000"))return -1;
        q.push("0000");
        int level = 0;
        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                
                string curr = q.front();
                q.pop();
                if(curr == target)return level;
                for(int  i = 0 ; i < 4 ; i++){
                    char ch = curr[i];

                    char inc = ch == '9' ? '0' : ch + 1  ;
                    char dec = ch == '0' ? '9' : ch - 1  ;

                    curr[i] = inc;
                    if(!s.count(curr)){
                        q.push(curr);
                        s.insert(curr);
                    }
                    curr[i] = dec;
                    if(!s.count(curr)){
                        q.push(curr);
                        s.insert(curr);
                    }

                    curr[i] = ch;
                }
            }
            level++;
        }
        return -1;
    }
};