package leetcode15三数之和;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        int[] nums = {-1,0,1,2,-1,-4};
        Solution solution = new Solution();
        List<List<Integer>> lists = solution.threeSum(nums);
        for (List<Integer> l:lists
             ) {
            for (Integer i:l
                 ) {
                System.out.print(i+" ");
            }
            System.out.println();
        }
    }
}
