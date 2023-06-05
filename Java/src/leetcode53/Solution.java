package leetcode53;

/**
 * 求连续子数组的最大和
 */

public class Solution {
    /**
     * 使用数字规律
     * 如果累加和小于0则抛弃之前的累加和，累加和从当前元素开始计算
     * 如果累加和大于之前的累加和，更新记录最大累加和的max
     * @param nums 数组
     * @return 最大累加和
     */
    public int maxSubArray(int[] nums) {
        int count = 0;
        //最大值初始化为Integer的最小值，防止数组头部元素的值很小。比如初始化为0
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            if(count < 0){
                count = nums[i];
            }else{
                count+=nums[i];
            }
            if(count > max){
                max = count;
            }
        }
        return max;
    }


}
