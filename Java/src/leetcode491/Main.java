package leetcode491;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {3,1,2,1,3,4};
        List<List<Integer>> lists= solution.findSubsequences(nums);
        for (List<Integer> list:lists
             ) {
            for (int i = 0; i < list.size(); i++) {
                System.out.print("->"+list.get(i));
            }
            System.out.println();
        }
    }
}
