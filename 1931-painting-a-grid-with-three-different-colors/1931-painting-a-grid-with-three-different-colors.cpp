class Solution {
public:
    int m, n;
    int mod = 1e9 + 7;
    vector<vector<int>> patterns;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    bool check(int i, int j) {
        int a = 0;
        while (a < m) {
            if (patterns[i][a] == patterns[j][a]) {
                return false;
            }
            a++;
        }
        return true;
    }
    int dp[1001][50];
    long long solve(int curr_idx, int prev_col_idx) {
        if (curr_idx == n)
            return 1;

        if (prev_col_idx != -1 && dp[curr_idx][prev_col_idx] != -1)
            return dp[curr_idx][prev_col_idx];
        long long ans = 0;
        if (prev_col_idx == -1) {
            for (int i = 0; i < patterns.size(); i++) {
                ans += solve(curr_idx + 1, i) % mod;
            }
            if (prev_col_idx != -1)
                return dp[curr_idx][prev_col_idx] = ans % mod;
            return ans % mod;
        }

        for (int i = 0; i < patterns.size(); i++) {
            if (check(i, prev_col_idx)) {
                ans += solve(curr_idx + 1, i) % mod;
            }
        }

        return dp[curr_idx][prev_col_idx] = ans % mod;
    }
    void generate(int row, int r, vector<int>& curr,
                  vector<vector<int>>& patterns) {
        if (row == r) {
            patterns.push_back(curr);
            return;
        }

        for (int color = 0; color < 3; color++) {
            if (row > 0 && curr[row - 1] == color)
                continue;
            curr[row] = color;
            generate(row + 1, r, curr, patterns);
        }
    }
    int colorTheGrid(int m, int n) {
        memset(dp, -1, sizeof(dp));
        vector<int> curr(m);
        generate(0, m, curr, patterns);
        this->m = m;
        this->n = n;
        return solve(0, -1);
    }
};