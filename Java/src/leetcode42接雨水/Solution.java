package leetcode42接雨水;

public class Solution {
    public int trap(int[] height) {
        if (height.length == 0){
            return 0;
        }
        int result = 0;

        int leftHeightMax = 0;
        int rightHeightMax = 0;

        for (int i = 0; i < height.length; i++) {
            //向左扫描
            for (int j = i - 1; j >= 0 ; j--) {
                leftHeightMax = Math.max(leftHeightMax,height[j]);
            }

            //向右扫描
            for (int j = i + 1; j < height.length ; j++) {
                rightHeightMax = Math.max(rightHeightMax,height[j]);
            }

            result += Math.min(leftHeightMax,rightHeightMax)-height[i];
        }

        return result;
    }

    public int trap1(int[] height) {
        if (height.length == 0){
            return 0;
        }
        int [] leftMax = new int[height.length];
        leftMax[0] = height[0];

        for (int i = 1; i < height.length; i++) {
            leftMax[i] = Math.max(height[i],leftMax[i - 1]);
        }

        int [] rightMax = new int[height.length];
        rightMax[height.length - 1] = height[height.length - 1];

        for (int i = height.length - 2; i >= 0 ; i--) {
            rightMax[i] = Math.max(rightMax[i+1],height[i]);
        }
        int result = 0;

        for (int i = 0; i < height.length; i++) {
            result += Math.min(leftMax[i],rightMax[i]) - height[i];
        }

        return result;
    }
}
