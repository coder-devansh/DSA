class Solution {
public:
    const int mod = 1000000007;

    long long power(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    void find_prime(vector<int>& prime) {
        int N = 1e5;
        vector<bool> isPrime(N, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= N; i++) {
            if (isPrime[i]) {
                for (int k = i * i; k < N; k += i) {
                    isPrime[k] = false;
                }
            }
        }
        for (int i = 2; i < N; i++) {
            if (isPrime[i]) {
                prime.push_back(i);
            }
        }
    }

    int maximumScore(vector<int>& nums, int k) {
        vector<int> prime;
        find_prime(prime);
        vector<int> prime_score(nums.size(), 0);

        // Prime factorization score
        map<int,int>mp;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i], cnt = 0, j = 0;
            int value=num;
            if(mp.find(num)!=mp.end()){
                prime_score[i]=mp[num];
                continue;
            }
            while (num != 1 && j < prime.size()) {
                if (num % prime[j] == 0) {
                    cnt++;
                    while (num % prime[j] == 0) {
                        num /= prime[j];
                    }
                }
                j++;
            }
            mp[value]=cnt;
            prime_score[i] = cnt;
        }

        // Finding previous greater elements
        stack<int> st;
        vector<int> prev_greater(nums.size(), -1);
        for (int i = 0; i < prime_score.size(); i++) {
            while (!st.empty() && prime_score[st.top()] < prime_score[i]) {
                st.pop();
            }
            prev_greater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clearing stack for next usage
        while (!st.empty()) st.pop();

        // Finding next greater elements
        vector<int> next_greater(nums.size(), nums.size());
        for (int i = prime_score.size() - 1; i >= 0; i--) {
            while (!st.empty() && prime_score[st.top()] <= prime_score[i]) {
                st.pop();
            }
            next_greater[i] = st.empty() ? nums.size() : st.top();
            st.push(i);
        }

        long long max_score = 1;
        priority_queue<pair<long long, long long>> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        while (!pq.empty() && k > 0) {
            auto it = pq.top();
            pq.pop();
            long long val = it.first;
            long long index = it.second;
            long long start_index = (long long)(index - prev_greater[index]);
            long long end_index = (long long)(next_greater[index] - index);
            long long no = start_index * end_index;
            long long min_val = min((long long)k, no);

            max_score = (max_score * power(val, min_val)) % mod;
            k -= min_val;
        }

        return (long long)max_score;
    }
};