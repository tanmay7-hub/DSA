class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool is_sorted = true;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] < s[i - 1]) {
                is_sorted = false;
                break;
            }
        }
        if (is_sorted)
            return 0;
        if (s.size() == 2)
            return -1;

        char minChar = s[0], maxChar = s[1];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] < minChar)
                minChar = s[i];
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] > maxChar)
                maxChar = s[i];
        }
        if (s[0] <= minChar || s[n - 1] >= maxChar)
            return 1;

        char min12 = s[0], max12 = s[1];
        for (int i = 0; i < n - 1; i++) {
            if (s[i] < min12)
                min12 = s[i];
        }
        for (int i = 1; i < n; i++) {
            if (s[i] > max12)
                max12 = s[i];
        }
        if (min12 <= s[n - 1] || max12 >= s[0])
            return 2;
        return 3;
    }
};