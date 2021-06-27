package leetcode5最长的回文子序列;

/**
 * 求最长的回文子序列的长度
 */
public class Solution {
    public int longestPalindromeSubseq(String str){
        //了解dp数组的含义，dp[i][j]表示字符串str从索引i到j最长回文子序列的长度
        int strLength = str.length();
        int [][]dp = new int[strLength][strLength];//初始化状态下dp数组中的数据全部为0
        for (int i = 0; i < strLength; i++) {//只有一个字符的情况下也是回文子序列，长度为1
            dp[i][i] = 1;
        }
        //由于不存在i>j的情况所以二维数组的一半由于初始化就为0不做操作
        //dp[i][j]的结果与dp[i+1][j-1],dp[i][j-1],dp[i+1][j]有关所以在求dp[i][j]的结果，
        // 这三项必须得出结果，所以采用i先倒序遍历，j正序遍历来就得结果
        for (int i = strLength - 1; i >=0 ; i--) {
            for (int j = i+1; j < strLength; j++) {
                if(str.charAt(i) == str.charAt(j)){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }else{
                    dp[i][j] = Math.max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][strLength - 1];
    }
}
