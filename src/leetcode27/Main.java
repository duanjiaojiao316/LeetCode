package leetcode27;

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums1 = {1,2,3,5,2,7,2};
        int len = solution.removeElement(nums1, 2 );
        for (int i = 0; i < len; i++) {
            System.out.print(nums1[i] + " ");
        }
    }
}
