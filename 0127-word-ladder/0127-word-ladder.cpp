class Solution {
public:
    //    string comp(string s1 , string s2){
    //       int diff = 0;

    //       for(int i = 0 ; i < s1.size() ; i++ ){
    //         if(s1[i] != s2[i]){
    //             diff++;
    //         }
    //       }
    //       return diff == 1;
    //    }
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> s;
        s.insert(begin(wordList), end(wordList));
        queue<string> q;
        q.push(beginWord);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {

                string curr = q.front();
                q.pop();

                if (curr == endWord)
                    return level + 1;
                for (int i = 0; i < curr.size(); i++) {
                    char ch = curr[i];

                    for (int j = 0; j < 26; j++) {
                        char new_ch = 'a' + j;
                        if (ch == new_ch)
                            continue;

                        curr[i] = new_ch;

                        if (s.count(curr)) {
                            q.push(curr);
                            s.erase(curr);
                        }
                    }
                    curr[i] = ch;
                }
            }
            level++;
        }

        return 0;
    }
};