class Solution {
public:
    // 动态规划
    // buy[i]: 第i天操作为buy或cooldown时的最大利润
    // sell[i]: 第i天操作为sell或cooldown时的最大利润
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if (sz <= 1) return 0;
        vector<int> buy(sz, 0);
        buy[0] = -prices[0];  // 第一天就买
        buy[1] = max(-prices[0], -prices[1]); // 哪一天股票低，哪一天买
        
        vector<int> sell(sz, 0);
        sell[0] = 0;
        sell[1] = max(0, prices[1] - prices[0]);
        for (int i = 2; i < sz; ++ i) {
            // 状态转移方程
            // 第i天 cooldown，取前一天的最大利润值
            // 第i天 buy,由于有冷却期，需要取n-2天时为sell的利润减去当前buy所需的money
            // 第i天 sell,则取前一天为buy的利润加上今天的股票市值
            buy[i] = max(buy[i- 1], sell[i - 2] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }

        return max(buy[sz - 1], sell[sz - 1]);
    }
};