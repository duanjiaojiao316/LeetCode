package leetcode14最长的公共前缀;

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String[] strs = {"abcehe","absgdh","abcdhd"};
        System.out.println(solution.longestCommonPrefix(strs));
        System.out.println(solution.longestCommonPrefix1(strs));
        System.out.println(solution.longestCommonPrefix2(strs));
    }
}
