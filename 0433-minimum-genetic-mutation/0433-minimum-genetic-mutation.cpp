class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        unordered_set<string>s;
        s.insert(begin(bank) , end(bank));

        if(!s.count(endGene))return -1;

        queue<string>q;
        q.push(startGene);
        int level = 0;
        while(!q.empty()){
            int sz = q.size();

            while( sz-- ){
               string curr = q.front();
               q.pop();
               if(curr == endGene)return level;
               for(int i = 0 ; i < curr.size() ; i++){
                   char ch = curr[i];

                   vector<int>chr = {'A' ,'C' , 'G' , 'T'};

                   for(auto currChar : chr ){
                       curr[i] = currChar;

                       if(s.count(curr)){
                        q.push(curr);
                        s.erase(curr);
                       }
                       
                   }
                   curr[i] = ch;
               }
            }
            level++;
        }
        return -1;
    }
};