package leetcode33搜索旋转排序数组;

public class Solution {

    int search(int[] nums, int target) {
        if (nums.length == 0){
            return -1;
        }
        if(nums.length == 1){
            return target == nums[0] ? 0 : -1;
        }
        int rotateIndex = getRotateIndex(nums,0,nums.length - 1);//分界
        if(rotateIndex == 0){//分界为0说明没有旋转
            return binarySearch(nums,0,nums.length - 1,target);
        }else if(target > nums[nums.length - 1]){//target大于最后一个数，说明在前半部分
            return binarySearch(nums,0,rotateIndex - 1,target);
        }else if (target < nums[0]){//后部分
            return binarySearch(nums,rotateIndex,nums.length - 1,target);
        }
        return rotateIndex;

    }

    /**
     * 二分查找
     * @param nums 二分查找数组
     * @param l 起始位置
     * @param r 结尾位置
     * @param target 查找元素
     * @return target元素所在下标
     */
    private int binarySearch(int[] nums, int l, int r, int target){
        if(nums.length == 0){
            return -1;
        }
        int left = l;
        int right = r;
        int mid = (left + right) / 2;
        while(left <= right){
            if(target == nums[mid]){
                return mid;
            }
            else if(target < nums[mid]){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }
        return -1;
    }

    private int getRotateIndex(int[] nums, int left, int right){
        if(nums[left]<nums[right]){
            return 0;
        }
        while(left <= right){
            int pivot = (left + right)/2;
            if(nums[pivot] > nums[pivot+1]){
                return pivot + 1;
            }else{
                if (nums[pivot] < nums[left]){
                    right = pivot - 1;
                }else {//nums[pivot] > nums[left]
                    left = pivot + 1;
                }
            }
        }
        return 0;
    }
}
