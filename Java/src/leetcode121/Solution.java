package leetcode121;

/**
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 *
 * 如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
 */

public class Solution {

    /**
     * 一次遍历
     */
//    public int maxProfit(int[] prices) {
//        int min = Integer.MAX_VALUE;
//        int max = 0;
//        for (int price : prices) {
//            if (min > price) {
//                min = price;
//            } else if (price - min > max) {
//                max = price - min;
//            }
//        }
//        return max;
//    }

    /**
     * 暴力枚举
     */
//    public int maxProfit(int[] prices) {
//        if(prices.length < 2){
//            return 0;
//        }
//        int result = 0;
//        for (int i = 0; i < prices.length; i++) {
//            for (int j = i + 1; j < prices.length; j++) {
//                result = Math.max(result, prices[j] - prices[i]);
//            }
//        }
//        return result;
//    }

    /**
     * 暴力优化
     * 由于当前遍历只需关心之前的最小股价，消除一层循环
     */
    public int maxProfit(int[] prices) {
        int result = 0;
        int min = prices[0];
        for (int i = 1; i < prices.length; i++) {
            result = Math.max(prices[i] - min, result);
            min = Math.min(min,prices[i]);
        }
        return result;
    }


}
