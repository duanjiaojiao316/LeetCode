package leetcode13罗马数字转化为整数;

/**
 * 首先建立一个HashMap来映射符号和值，
 * 然后对字符串从左到右来，
 * 如果当前字符代表的值不小于其右边，就加上该值；
 * 否则就减去该值。
 */

import java.util.HashMap;
import java.util.Map;

public class Solution {

    public int romanToInt(String s) {
        Map<Character, Integer> map = new HashMap<>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);

        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            int curVal = map.get(s.charAt(i));//获取当前罗马数字对应的数字
            int nextVal = i < s.length() - 1?map.get(s.charAt(i + 1)):0;//判断获取字符串的字符是否会越界
            result += curVal < nextVal?-curVal:curVal;//如果当前的值比下一个罗马数字的值小，那么减去该值
        }
        return result;
    }
}
