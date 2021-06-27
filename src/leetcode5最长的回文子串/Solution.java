package leetcode5最长的回文子串;

public class Solution {
    /**
     * 动态规划使用dp数组
     */
    public String longestPalindrome(String s) {
        //dp[][]二维数组用于记录dp[i][j]的子串是否是回文子串
        String longestPalindrome = "";
        int strLength = s.length();
        boolean [][]dp = new boolean[strLength][strLength];
        //i<j,且一个字符串也应该回文字符串
        for (int i = 0; i < strLength; i++) {
            dp[i][i] = true;
            if(longestPalindrome.length() < 1){
                longestPalindrome = s.substring(i,i+1);
            }

            if(i + 1 < strLength && s.charAt(i) == s.charAt(i+1)){
                dp[i][i+1] = true;
                longestPalindrome = s.substring(i,i+2);
            }
        }
        for (int i = strLength - 1; i >=0; i--) {
            for (int j = i + 2; j < strLength; j++) {
                if(s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = dp[i + 1][j - 1];
                    if (dp[i][j]&&longestPalindrome.length() < j - i + 1) {
                        longestPalindrome = s.substring(i, j+1);
                    }
                }
            }
        }
        return longestPalindrome;
    }

    /**
     * 方法二：动态规划记录子串起始位置
     */

    /**
     *求得回文子串的长度
     */
    public static int getLength(String s, int left, int right){
        int l = left;
        int r = right;
        while(l >= 0 && r < s.length() && s.charAt(l)==s.charAt(r)){
            l--;
            r++;
        }
        return r-l-1;
    }

    public static String longestPalindrome1(String s){
        if(s.length() < 1 || s == null){
            return "";
        }
        int start = 0;
        int end = 0;
        for(int i = 0; i < s.length(); i++){
            int len1 = getLength(s, i, i) ;//单数长度的回文子串
            int len2 = getLength(s, i, i+1);//双数长度的回文子串
            int len = Math.max(len1, len2);
            if(len > end-start){
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        return s.substring(start,end + 1);
    }
}
