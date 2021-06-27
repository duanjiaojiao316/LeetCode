package leetcode491;

import java.util.*;

public class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        HashMap<Integer, Set<LinkedList<Integer>>> hashMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            for (int j = i-1; j > 0; j--) {
                if(nums[j] < nums[i]){
                    //找到小于当前值的数字，创建新的链表
                    LinkedList linkedList = new LinkedList<>();
                    linkedList.add(nums[j]);
                    linkedList.add(nums[i]);
                    //创建该位置的set容器
                    Set<LinkedList<Integer>> set = new HashSet<>();
                    //将新创建的链表加入该容器
                    set.add(linkedList);
                    //如果小于当前值的数字的set容器中存在链表将当前值加入到链表的末尾创建新的链表加入到当前值的set容器中
                    Set<LinkedList<Integer>> setTemp = hashMap.get(j);
                    if( setTemp != null &&setTemp.size()>0){
                        //获取小于当前值的数字的set容器
                        //LinkedList<Integer> listTemp = new LinkedList<>();
                        for (LinkedList<Integer> l:setTemp) {
                            LinkedList<Integer> listTemp = new LinkedList<>();

                            for (Integer integer:l) {
                                listTemp.add(integer);
                            }

                            listTemp.add(nums[i]);
                            set.add(listTemp);
                        }
                    }
                    hashMap.put(i,set);
                }
            }

        }

        System.out.println();
        List<List<Integer>> result = new LinkedList<>();
        for (int i = 0; i < nums.length; i++) {
            Set<LinkedList<Integer>> set = new HashSet<>();
            set = hashMap.get(i);
            if (set != null){
                for (LinkedList<Integer> linkedList:set) {
                    result.add(linkedList);
                }
            }
        }
        return result;
    }
}
