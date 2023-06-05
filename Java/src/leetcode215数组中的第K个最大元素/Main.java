package leetcode215数组中的第K个最大元素;

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] array = new int[] {7,5,15,3,17,2,20,24,1,9,12,8};
        System.out.println(solution.findKthLargest(array, 5));
    }
}
