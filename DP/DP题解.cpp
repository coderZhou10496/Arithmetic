
322 零钱兑换:给定一个价值amount和一些面值，假设每个面值的硬币数都是无限的，问我们最少能用几个硬币组成给定的价值
int coinChange(vector<int>& coins, int amount) {
    vector<int>dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= coins.size(); i++)
        for(int j = coins[i-1]; j <= amount; j++){
            // 下行代码会在 1+INT_MAX 时溢出
            // dp[j] = min(dp[j], 1 + dp[j - coins[i-1]]); 
            if(dp[j] - 1 > dp[j - coins[i-1]])
                dp[j] = 1 + dp[j - coins[i-1]];   
        }
    return dp[amount] == INT_MAX ? -1 : dp[amount];   
}


377 组合总和：给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数
int combinationSum4_solution1(vector<int>& nums, int target) {
    if(nums.size() == 0) {
        return 0;
    }
    
    int minNumber = INT_MAX;
    for(int num : nums) {
        minNumber = min(minNumber, num);
    }
    if(minNumber > target) {
        return 0;
    }
    
    vector<unsigned long long> dp(target+1);
    dp[0] = 1;
    for(int i = 1; i <= target; i++) {
        for(int num : nums) {
            if(i >= num) {
                dp[i] = dp[i] + dp[i-num];
            }
        }
    }
    return (int)dp[target];
}


416 分割等和子集:
bool canPartition(vector<int>& nums) {
    int sum = 0, n = nums.size();
    for(int &num: nums) sum += num;
    if(sum % 2) return false;

    int capacity = sum / 2;
    vector<bool>dp(capacity + 1, false);
    dp[0] = true;
    for(int i = 1; i <= n; i++)
        for(int j = capacity; j >= nums[i-1]; j--)
            dp[j] = dp[j] || dp[j - nums[i-1]];

    return dp[capacity];
}


474 一和零:给定一个仅包含 0 和 1 字符串的数组。任务是从数组中选取尽可能多的字符串，使这些字符串包含的0和1的数目分别不超过m和n
int findMaxForm(vector<string>& strs, int m, int n) {
    int num = strs.size();
    int w0, w1;

    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

    for(int i = 1; i <= num; i++){
        w0 = 0; w1 = 0;
        // 计算第i-1个字符串的两个重量
        for(char &c: strs[i - 1]){
            if(c == '0') w0 += 1;
            else w1 += 1;
        }

        // 01背包, 逆向迭代更新dp
        for(int j = m; j >= w0; j--)
            for(int k = n; k >= w1; k--)
                dp[j][k] = max(dp[j][k], 1+dp[j-w0][k-w1]);
    }

    return dp[m][n];
}


494 目标和:一个数组（元素非负），和一个目标值，要求给数组中每个数字前添加正号或负号所组成的表达式结果与目标值S相等，求有多少种情况
int findTargetSumWays(vector<int>& nums, int S) {
    int sum = 0;
    // for(int &num: nums) sum += num;
    sum = accumulate(nums.begin(), nums.end(), 0);
    if(S > sum || sum < -S) return 0; // 肯定不行
    if((S + sum) & 1) return 0; // 奇数
    int target = (S + sum) >> 1;

    vector<int>dp(target + 1, 0);

    dp[0] = 1;
    for(int i = 1; i <= nums.size(); i++)
        for(int j = target; j >= nums[i-1]; j--)
            dp[j] = dp[j] + dp[j - nums[i-1]];

    return dp[target];
}
