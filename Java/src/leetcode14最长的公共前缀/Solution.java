package leetcode14最长的公共前缀;

public class Solution {
    /**
     * 模板字符串从后往前
     * 以第一个字符串为模板，使用indexOf函数查找指定字符或字符串在字符串中第一次出现地方的索引，未找到的情况返回 -1.
     * 如果返回值为-1表示字符串不含该模板，所以模板从尾端减去一位字符
     * 一次判断每一个字符串，最后返回的模板就是最长公共前缀
     * @param strs 字符串数组
     * @return 最长的公共前缀
     */
    public String longestCommonPrefix(String[] strs) {
        if (strs == null||strs.length == 0) return "";
        String prefix = strs[0];
        for (int i = 1; i < strs.length; i++)
            while (strs[i].indexOf(prefix) != 0) {
                prefix = prefix.substring(0, prefix.length() - 1);
                if (prefix.isEmpty()) return "";
            }
        return prefix;
    }

    /**
     * 模板字符串从前往后
     */
    public String longestCommonPrefix1(String[] strs){
        if (strs == null||strs.length == 0) return "";

        for (int i = 0; i < strs[0].length(); i++) {
            char curChar = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if(i == strs[j].length() || strs[j].charAt(i) != curChar){
                    return strs[0].substring(0,i);
                }
            }
        }
        return strs[0];
    }


    /**
     * 分治法
     *
     */

    public String longestCommonPrefix2(String [] strs){
        if (strs == null || strs.length == 0) return "";
        return longestCommonPrefix2(strs,0, strs.length - 1);
    }
    public String longestCommonPrefix2(String [] strs,int left, int right){
        if(left == right){
            return strs[left];
        }
        int mid = (left + right)/2;
        String leftString = longestCommonPrefix2(strs,left ,mid);
        String rightString = longestCommonPrefix2(strs,mid + 1,right);

        return longestCommonPrefix2(leftString,rightString);
    }

    public String longestCommonPrefix2(String leftString,String rightString){
        int minLength = Math.min(leftString.length(),rightString.length());
        for (int i = 0; i < minLength; i++) {
            if(leftString.charAt(i) != rightString.charAt(i)){
                return leftString.substring(0,i);
            }
        }
        return leftString.substring(0,minLength);
    }


}
