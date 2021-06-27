package leetcode121;

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        //int [] prices =  {7,1,5,3,6,4}; //5
        //int [] prices = {7,6,4,3,1}; //0
        int [] prices = {10,2,9,1,2,1,3,1}; //7

        System.out.println(solution.maxProfit(prices));
    }
}
