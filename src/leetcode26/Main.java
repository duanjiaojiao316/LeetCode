package leetcode26;

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int [] nums = {0,0,1,1,5,5,6,6,8,9,9,10,10,11};
        int length = solution.removeDuplicates(nums);
        for (int i = 0; i < length; i++) {
            System.out.print(nums[i] + " ");
        }
    }
}
