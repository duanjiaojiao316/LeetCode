package leetcode34在排序数组中查找元素的第一个和最后一个位置;

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int [] nums = new int[]{1,1,2,3,4,5,6,6,6,6,7,7};
        int [] result = solution.searchRange(nums,5);
        for (int i:result
             )
            System.out.print(i + " ");
        System.out.println();
        result = solution.searchRange(nums,3);
        for (int i:result
        )
            System.out.print(i + " ");
        System.out.println();

        result = solution.searchRange(nums,1);
        for (int i:result
        )
            System.out.print(i + " ");
        System.out.println();
        result = solution.searchRange(nums,6);
        for (int i:result
        )
            System.out.print(i + " ");
        System.out.println();
        result = solution.searchRange(nums,7);
        for (int i:result
        )
            System.out.print(i + " ");
    }
}
