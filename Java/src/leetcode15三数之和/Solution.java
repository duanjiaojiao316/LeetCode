package leetcode15三数之和;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {

    /**
     * 首先对数组进行排序，排序后固定一个数 nums[i]nums[i]，再使用左右指针指向 nums[i]nums[i]后面的两端，数字分别为 nums[L]nums[L] 和 nums[R]nums[R]，计算三个数的和 sumsum 判断是否满足为 00，满足则添加进结果集
     * 如果 nums[i]大于 00，则三数之和必然无法等于 00，结束循环
     * 如果 nums[i] == nums[i-1]，则说明该数字重复，会导致结果重复，所以应该跳过
     * 当 sum == 0 时，nums[L] == nums[L+1] 则会导致结果重复，应该跳过，L++
     * 当 sum == 0 时，nums[R] == nums[R-1] 则会导致结果重复，应该跳过，R--
     */
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int sum = 0;
        List<List<Integer>> lists = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if(nums[i]>0){
                break;
            }
            if(i>0&&nums [i] == nums[i - 1]){
                continue;
            }
            int L = i+1;
            int R = nums.length - 1;
            while(L<R){
                sum = nums[i] + nums[L] + nums[R];
                if(sum == 0){
                    lists.add(Arrays.asList(nums[i],nums[L],nums[R]));
                    while(L<R && nums[L] == nums[L+1]){
                        L++;
                    }
                    while(L<R&&nums[R] == nums[R-1]){
                        R--;
                    }
                    L++;
                    R--;
                }
                else if (sum < 0){
                    L++;
                }
                else if (sum > 0){
                    R--;
                }
            }
        }
        return lists;
    }
}
