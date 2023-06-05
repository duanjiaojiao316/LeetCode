package leetcode1两数之和;

import java.util.HashMap;

public class Solution {

    /**
     * 暴力法
     */
    public int[] twoSum(int[] num,int target){
        for (int i = 0; i < num.length; i++) {
            for (int j = i + 1; j < num.length; j++) {
                if(num[j] == target - num[i]){
                    return new int [] {i,j};
                }
            }

        }
        throw new IllegalArgumentException("No two sum solution");
    }

    /**
     * 借助hashMap数据结构，减少内嵌查找
     */
    public int[] twoSum1(int []num, int target){

        HashMap<Integer,Integer> hashMap = new HashMap<>();
        for (int i = 0; i < num.length; i++) {
            hashMap.put(num[i],i);
        }

        for (int i = 0; i < num.length; i++) {
            if(hashMap.containsKey(target-num[i]) && hashMap.get(target-num[i]) != i){
                return new int[] {i,hashMap.get(target-num[i])};
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }

    /**
     * 借助hashMap数据结构，一边往hashMap中插入数据，一边判断是否存在和为target的两个数
     */
    public int[] twoSum2(int []num, int target){

        HashMap<Integer,Integer> hashMap = new HashMap<>();
        for (int i = 0; i < num.length; i++) {

            if(hashMap.containsKey(target-num[i])){
                return new int[] {hashMap.get(target-num[i]),i};
            }
            hashMap.put(num[i],i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }

}
