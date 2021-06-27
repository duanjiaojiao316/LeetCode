package leetcode28;

public class Main {
    public static void main(String[] args) {
        String hello = "aaacaaab";
        String need = "aaab";

        Solution solution = new Solution();
        System.out.println(solution.strStr(hello, need));//10
    }
}
