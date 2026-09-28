class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        int j = 0;
        for(int i = 0 ; i < s.size() ; i++ ){
            string curr = "";
            int j = i;
            while(j < s.size() && s[j] != ' ' ){
                curr += s[j];
                j++;
            }
            i = j;
            if(curr != ""){
                words.push_back(curr);
            }
        }

        unordered_map<string , char> stp;
        unordered_map<char   , string> pts;

        if(words.size() != pattern.size()) return 0;


        for(int i = 0 ; i < words.size() ; i++ ){

            if(stp.count(words[i]) == 0 )stp[words[i]] = pattern[i]; 
            if(pts.count(pattern[i]) == 0) pts[pattern[i]] = words[i];


            if(stp[words[i]] != pattern[i] || pts[pattern[i]] != words[i])return false;
        }

        return true;
    }
};