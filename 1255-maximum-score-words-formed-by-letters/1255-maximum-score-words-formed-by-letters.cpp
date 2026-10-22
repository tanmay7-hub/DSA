class Solution {
public:
    unordered_map<string , int> sc;
    bool check (string s , vector<int>& fre){
        vector<int> fre1(26 , 0);

        for(auto ch : s){
            fre1[ch - 'a'] ++;
        }

        for(int i = 0 ; i < 26 ; i++ ){
            if(fre1[i] > fre[i]){
               return false;
            }
        }
        return true;
    }
    int solve(int idx , vector<int> fre , vector<string>& words){
        if(idx == words.size())return 0;
        int not_take = solve(idx + 1  , fre , words);

        int take = 0;

        if( check(words[idx] , fre) ){
            vector<int>fr1 = fre;

            for(auto ch : words[idx]){
                fr1[ch - 'a'] --;
            }
            
            take += sc[words[idx]] + solve(idx + 1, fr1 , words);
        }

        return max(not_take , take);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
       
       vector<int> fre(26 , 0);
       for(auto word : words){
          int curr = 0;
          for(auto ch : word){
              curr += score[ch -'a'];
          }
          sc[word] = curr;
       }
       for(auto ch : letters){
        fre[ch - 'a']++;
       }
       return solve(0 , fre , words ); 
    }
};