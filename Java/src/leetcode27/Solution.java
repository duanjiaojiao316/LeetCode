package leetcode27;

/**
 * 删除数组中值为val的某个值，可以改变数组其他元素的相对位置
 */

public class Solution {
    public int removeElement(int[] nums, int val) {
        int length = nums.length;
        int i = 0;
        while (i < length) {
            if(nums[i] == val) {
                /**
                 * 如果length-1索引所在的数字也是val，交换到i，由于i不自增下一个循环还会判断
                 */
                nums[i] = nums[length - 1];
                length--;
            }else{
                i++;
            }
        }
       return length;
    }
}
