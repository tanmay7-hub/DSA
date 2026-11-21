class Solution {
public:
    bool isPrime(int n) {
        if (n < 2)
            return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    int minOperations(int n, int m) {
        if (isPrime(n) || isPrime(m)) {
            return -1;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> dist(10000, INT_MAX);

        dist[n] = n;
        pq.push({n, n});

        while (!pq.empty()) {

            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u])
                continue;

            if (u == m)
                return cost;

            string s = to_string(u);

            for (int i = 0; i < s.size(); i++) {

                int digit = s[i] - '0';

                if (digit > 0) {
                    string curr = s;
                    curr[i] = char(digit - 1 + '0');

                    if (curr[0] != '0') {
                        int nextNumber = stoi(curr);

                        if (!isPrime(nextNumber)) {
                            int newCost = cost + nextNumber;

                            if (newCost < dist[nextNumber]) {
                                dist[nextNumber] = newCost;
                                pq.push({newCost, nextNumber});
                            }
                        }
                    }
                }

                if (digit < 9) {

                    string curr = s;
                    curr[i] = char(digit + 1 + '0');

                    int nextNumber = stoi(curr);

                    if (isPrime(nextNumber))
                        continue;

                    int newCost = cost + nextNumber;

                    if (newCost < dist[nextNumber]) {
                        dist[nextNumber] = newCost;
                        pq.push({newCost, nextNumber});
                    }
                }
            }
        }

        return -1;
    }
};