package leetcode122;

/**
 * 可以完成多次交易，但是不能同时进行多个项目
 */
public class Solution {

    /**
     * 暴力法
     */
//    public int maxProfit(int[] prices) {
//        return calculate(prices, 0);
//    }

    public int calculate(int prices[], int s) {
        if (s >= prices.length){
            return 0;
        }

        int max = 0;
        for (int start = s; start < prices.length; start++) {

            int maxProfit = 0;
            for (int i = start + 1; i < prices.length; i++) {
                if (prices[start] < prices[i]) {
                    int profit = calculate(prices, i + 1) + prices[i] - prices[start];
                    if (profit > maxProfit)
                        maxProfit = profit;
                }
            }
            if (maxProfit > max)
                max = maxProfit;
        }
        return max;
    }

    /**
     * 峰谷法
     */
    public int maxProfit(int[] prices) {
        int i = 0;
        int peak = prices[0]; //峰值
        int valley = prices[0]; //谷值
        int maxProfit = 0;
        while (i < prices.length - 1) {
            //找到谷值，跳过连续的股价下降，找到该谷最小值
            while (i < prices.length - 1 && prices[i] >= prices[i + 1]) {
                i++;
            }
            valley = prices[i];

            //找到峰值，跳过连续的股价上升，找到该峰最大值
            while (i < prices.length - 1 && prices[i] <= prices[i + 1]){
                i++;
            }
            peak = prices[i];
            maxProfit += peak - valley;
        }

        return maxProfit;
    }

//    public int maxProfit(int[] prices) {
//        int maxProfit = 0;
//        for (int i = 1; i < prices.length; i++) {
//            if (prices[i] > prices[i - 1])
//                maxProfit += prices[i] - prices[i - 1];
//        }
//        return maxProfit;
//    }

}
