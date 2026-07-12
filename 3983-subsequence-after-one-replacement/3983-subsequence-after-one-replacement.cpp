class Solution {
public:
    
    bool canMakeSubsequence(string s, string t) {
        int n = s.size() , m = s.size();

        int  i = 0 , j = 0;
        for(char ch : t){
            if(s[i] == ch)i++;
            i = max(i , j + 1);
            if(s[j] == ch) j++;  
            if(i >= m || j >= m  ) return true;
        } 
        return false;
    }
};