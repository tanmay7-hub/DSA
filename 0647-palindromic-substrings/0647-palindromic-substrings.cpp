class Solution {
public:
    bool check(string &s , int i , int j ){
        while(i < j){
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
     int count = 0;
     for(int i = 0 ; i < s.size() ; i++ ){
        for(int j = i ; j < s.size() ; j++ ){
            if(check(s , i , j )){
                count++; 
            }
        }
     }
     return count;
    }
};