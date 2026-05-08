class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int mx = *max_element(nums.begin(), nums.end());

        // sieve
        vector<bool> isPrime(mx + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= mx; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= mx; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // prime -> indices divisible by prime
        unordered_map<int, vector<int>> divisible;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            // factorize
            for (int p = 2; p * p <= x; p++) {
                if (x % p == 0) {
                    if (isPrime[p]) {
                        divisible[p].push_back(i);
                    }

                    while (x % p == 0) x /= p;
                }
            }

            if (x > 1) {
                divisible[x].push_back(i);
            }
        }

        vector<int> dist(n, -1);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        unordered_set<int> usedPrime;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int d = dist[i];

            if (i == n - 1) return d;

            // i-1
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = d + 1;
                q.push(i - 1);
            }

            // i+1
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = d + 1;
                q.push(i + 1);
            }

            // teleport
            int val = nums[i];

            if (isPrime[val] && !usedPrime.count(val)) {
                usedPrime.insert(val);

                for (int nxt : divisible[val]) {
                    if (dist[nxt] == -1) {
                        dist[nxt] = d + 1;
                        q.push(nxt);
                    }
                }
            }
        }

        return -1;
    }
};
