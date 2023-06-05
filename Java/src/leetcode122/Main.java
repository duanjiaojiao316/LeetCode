package leetcode122;

public class Main {
    public static void main(String[] args) {

        Solution solution = new Solution();
        int[] prices = {7,1,5,3,6,4};//7
        int[] prices1 = {1,2,3,4,5};//4
        System.out.println(solution.maxProfit(prices));
        System.out.println(solution.maxProfit(prices1));
    }
}
