package leetcode26;

/**
 * 删除元素中的重复元素
 *
 */
public class Solution {

//    public int removeDuplicates(int[] nums) {
//        if (nums.length == 0){
//            return 0;
//        }
//        int i = 0;
//        int j = i + 1;
//        while(j != nums.length){
//            if(nums[i] == nums[j]){
//                j++;
//            }else{
//                nums[i+1] = nums[j];
//                i++;
//            }
//        }
//        return i + 1;
//    }

    /**
     * 0 1 2 3 4 5
     * i j
     * 如果不相等，j会在原地复制，不必要的操作
     *
     */

    public int removeDuplicates(int[] nums) {
        if (nums.length == 0){
            return 0;
        }
        int i = 0;
        int j = i + 1;
        while(j != nums.length){
            if(nums[i] == nums[j]){
                j++;
            }else{

                /**
                 * 除了判断j和i之间相差为1也可以先i++，
                 * nums[i]和nums[j]的地址相同，nums[i] = nums[j]赋值不会增加负担
                 * 同时减少if条件判断的开销
                 */
                i++;
                nums[i] = nums[j];
//                if(j - i > 1){
//                    nums[i+1] = nums[j];
//                }
//                i++;
            }
        }
        return i + 1;
    }
}
