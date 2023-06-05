package leetcode34在排序数组中查找元素的第一个和最后一个位置;

public class Solution {
    public int[] searchRange(int[] nums, int target) {
        //二分查找返回查找位置索引
        int mid = binarySearch(nums, target);
        if(mid >= 0){
            boolean leftBound = false;
            boolean rightBound = false;
            int left = mid;
            int right = mid;
            while(!leftBound && left > 0){
                left--;
                if (nums[left] < target){
                    leftBound = true;
                    left++;
                }
            }
            while(!rightBound && right < nums.length - 1){
                right++;
                if(nums[right] > target){
                    rightBound = true;
                    right--;
                }
            }
            return new int[]{left, right};
        }else {
            return new int[]{-1,-1};
        }
    }
    public int binarySearch(int [] nums, int target){
        int left = 0;
        int right = nums.length;
        int mid = (left + right) / 2;
        while(left < right){
            if(target == nums[mid]){
                return mid;
            }
            else if(target < nums[mid]){
                right = mid;
            } else {
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }
        return -1;
    }
}
