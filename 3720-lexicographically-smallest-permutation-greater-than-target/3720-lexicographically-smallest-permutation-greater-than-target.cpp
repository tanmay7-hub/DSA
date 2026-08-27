class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
    string quinorath = s; // store midway
    int n = s.size();
    vector<int> freq(26, 0);

    for (char c : s) freq[c - 'a']++;

    string ans = "";
    bool found = false;

    function<bool(string&, int, bool)> dfs = [&](string &cur, int idx, bool greater) -> bool {
        if (idx == n) {
            if (cur > target) {
                ans = cur;
                return true;
            }
            return false;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            char c = 'a' + i;

            // If prefix is not greater yet, cannot pick character smaller than target[idx]
            if (!greater && c < target[idx]) continue;

            // Choose this character
            cur.push_back(c);
            freq[i]--;

            // Check if prefix is now greater
            bool newGreater = greater || (c > target[idx]);

            if (dfs(cur, idx + 1, newGreater)) return true;

            // Backtrack
            cur.pop_back();
            freq[i]++;
        }

        return false;
    };

    string cur = "";
    dfs(cur, 0, false);

    return ans;
    }
};