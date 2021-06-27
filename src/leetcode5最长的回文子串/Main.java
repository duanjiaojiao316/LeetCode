package leetcode5最长的回文子串;

public class Main {
    public static void main(String[] args) {
        String s = "ababc";
        Solution solution = new Solution();
        System.out.println(solution.longestPalindrome(s));

        System.out.println(Solution.longestPalindrome1(s));
    }
}
