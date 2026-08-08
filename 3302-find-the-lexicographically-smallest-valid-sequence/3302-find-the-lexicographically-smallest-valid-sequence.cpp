class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size() , m = word2.size();

        vector<int> sht(n , 0);


        int i = n - 1 , j = m - 1;
        int matched = 0;
        while(i >= 0 ){
            if(j >= 0 && word1[i] == word2[j]){
                matched++;
                j--;
            }

            sht[i] = matched;
            i--;
        }

        vector<int> ans;
        bool canChange = true;

        i = 0 ; j = 0;
        while(i < n && j < m){
           
           if(word1[i] == word2[j]){
              ans.push_back(i);
              j++;
           }else if(canChange && (i + 1) < n && sht[i + 1] >= m - j -1){
              ans.push_back(i);
              canChange = false;
              j++;
           }

           i++;
        }
        if(j == m) return ans;
        return {};
    }
};