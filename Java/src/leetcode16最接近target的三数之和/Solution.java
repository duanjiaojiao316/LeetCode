package leetcode16最接近target的三数之和;

import java.util.Arrays;

public class Solution {

    /**
     * 利用 Arrays.sort(nums) 对数组进行排序。
     * 初始化一个用于保存结果的值 result = nusm[0] + nums[1] + nums[2] （不要自己设初值，直接从数组中抽取三个元素，假设这是最接近的三数之和，然后再更新就是了）。
     * 利用下标 i 对数组进行遍历，此时就是在固定第一个元素，注意，下标 i 的边界为 i < nums.length-2，否则设置指针的时候会出现数组越界。
     * 每次遍历的过程中设置两个指针，分别是 left = i + 1、right = nums.length - 1。
     * 检查 sum = nums[i] + nums[left] + nums[right]与 target 的距离，如果该距离比之前保存的 result 与 target 的距离更小，就更新 result。
     * 然后就是移动双指针。
     * 如果 sum 的值比 target 大,right--，因为数组是有序的，right --会使得下一次的 sum 更小，也就更接近 target 的值
     * 同理，如果 sum 的值 target 小,left++。·
     * left++ 和 right-- 的界限自然是 left == right，如果 left == right，说明我们已经将所有的元素都遍历过一遍了。
     * 重复上面的操作，直到i循环结束为止，返回 result。
     *
     * 注意：遇到重复的数字可以之间跳过，避免重复计算（包括nums[i]，left和right指针所在位置的数字的重复）
     */
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int result = nums[0]+nums[1]+nums[2];
        int sum = 0;
        for (int i = 0; i < nums.length - 2; i++) {
            int left = i+1;
            int right = nums.length - 1;
            if(nums[i] == nums[i+1]){
                continue;
            }
            while(left < right){
                sum = nums[i] + nums[left] + nums[right];
                if(Math.abs(result-target)>Math.abs(sum - target)){
                    result = sum;
                }
                if(sum > target){
                    right--;
                    while (left < right &&nums[right] == nums[right - 1]){
                        right--;
                    }
                }else{
                    left++;
                    while (left < right &&nums[left] == nums[right + 1]){
                        left--;
                    }
                }
            }

        }
        return result;
    }


    /**
     * 关于特殊例子的优化
     *
     * 可能会直接找到三数之和等于 target 的情况，此时直接返回结果即可，不需要在进行之后的循环，因为不可能有数比他自己更接近自己了。
     *
     * 如果 target 的值比 nums[i] + nums[left] + nums[left + 1] 的值还小，那么双指针无论怎么取，最后都会取到 nums[i] + nums[left] + nums[left + 1]。
     * 同理可证 target 的值比nums[i] + nums[right] + nums[right - 1] 的值还大的情况。
     * 所以可以增加一个判断，满足条件的情况下就可以直接取值，而不需要双指针一步步的判断来进行取值，减少了双指针的移动。
     *
     */

    public int threeSumClosest1(int[] nums, int target) {
        Arrays.sort(nums);
        int result = nums[0]+nums[1]+nums[2];
        for (int i = 0; i < nums.length - 2; i++) {
            int left = i+1;
            int right = nums.length - 1;
            while(left < right){
                int min = nums[i] + nums[left] + nums[left+1];
                if(target < min){
                    if(Math.abs(result - target) > Math.abs(min - target))
                        result = min;
                    break;
                }
                int max = nums[i] + nums[right-1]+nums[right];
                if(target > max){
                    if(Math.abs(result - target) > Math.abs(max - target))
                        result = max;
                    break;
                }
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target){
                    return sum;
                }
                if(Math.abs(result- target) > Math.abs(sum - target)){
                    result = sum;
                }
                if(sum > target){
                    right--;
                    while (left < right &&nums[right] == nums[right + 1]){
                        right--;
                    }
                }else{
                    left++;
                    while (left < right &&nums[left] == nums[left - 1]){
                        left++;
                    }
                }
            }
            while (i < nums.length - 2 && nums[i] == nums[i+1]){
                i++;
            }

        }
        return result;
    }

}
