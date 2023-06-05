package leetcode17电话号码的字母组合;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Solution {

    public List<String> letterCombinations(String digits) {
        HashMap<Integer,String> hashMap = new HashMap<>();
        hashMap.put(2,"abc");
        hashMap.put(3,"def");
        hashMap.put(4,"ghi");
        hashMap.put(5,"jkl");
        hashMap.put(6,"mno");
        hashMap.put(7,"pqrs");
        hashMap.put(8,"tuv");
        hashMap.put(9,"wxyz");

        List<String> list = new ArrayList<>();
        for (int i = 0; i < digits.length(); i++) {

        }
        return list;
    }
}
