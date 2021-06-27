package leetcode28;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 实现 strStr() 函数。
 *
 * 给定一个 haystack 字符串和一个 needle 字符串，
 * 在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
 *
 * 使用kmp算法 动态规划 二维数组记录状态变化
 */
public class Solution {

    public int strStr(String haystack, String needle) {
        if(needle.equals("")){
            return 0;
        }
        if(haystack.equals("")){
            return -1;
        }

        List<Map<Character,Integer>> status = getStatus(needle);//根据needle 得出状态转换

        int M = needle.length();
        int N = haystack.length();

        int j = 0;
        for (int i = 0; i < N; i++) {
            if(status.get(j).get(haystack.charAt(i)) == null){
                j = 0;
                continue;
            }
            j = status.get(j).get(haystack.charAt(i));

            if(j == M){ //到达终止状态
                return i - M + 1;
            }
        }
        return -1;
    }

    private List<Map<Character,Integer>> getStatus(String needle) {
        int length = needle.length();

        List<Map<Character,Integer>> dp = new ArrayList<>();
        for (int i = 0; i < needle.length(); i++) {
            Map<Character,Integer> map = new HashMap<>();
            dp.add(map);
        }
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                dp.get(i).put(needle.charAt(j),0);
            }
        }
        dp.get(0).put(needle.charAt(0),1);//初始化dp，遇到第一个字符串状态转变为1状态
        int X = 0;//初始化影子状态

        for (int i = 1; i < length; i++) {
            dp.get(i).put(needle.charAt(i),i+1);

            Map<Character, Integer> map = dp.get(i);
            for (Map.Entry<Character, Integer> entry : map.entrySet()) {
                if(entry.getKey() != needle.charAt(i)){
                    entry.setValue(dp.get(X).get(entry.getKey()));
                }
            }

            X = dp.get(X).get(needle.charAt(i));//修改影子状态
        }
        return dp;
    }
//    public int strStr(String haystack, String needle) {
//        if(needle.equals("")){
//            return 0;
//        }
//        if(haystack.equals("")){
//            return -1;
//        }
//
//        int[][] status = getStatus(needle);//根据needle 得出状态转换
//
//        int M = needle.length();
//        int N = haystack.length();
//
//        int j = 0;
//        for (int i = 0; i < N; i++) {
//            j = status[j][haystack.charAt(i)]; //计算下一个状态
//
//            if(j == M){ //到达终止状态
//                return i - M + 1;
//            }
//        }
//        return -1;
//    }
//
//    private int[][] getStatus(String needle) {
//        int length = needle.length();
//        int[][]dp = new int[length][256];
//
//        dp[0][needle.charAt(0)] = 1;//初始化dp，遇到第一个字符串状态转变为1状态
//
//        int X = 0;//初始化影子状态
//
//        for (int i = 1; i < length; i++) {
//
//            for (int c = 0; c < 256; c++) {
//                if (needle.charAt(i) == c)
//                    dp[i][c] = i + 1;
//                else
//                    dp[i][c] = dp[X][c];
//            }
//            X = dp[X][needle.charAt(i)];
//        }
//        return dp;
//    }

}
