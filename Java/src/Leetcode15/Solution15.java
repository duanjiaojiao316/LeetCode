import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution15 {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int sum = 0;
        List<List<Integer>> res = new ArrayList<>();
        int size = nums.length;
        if(size < 3) {
            return res;
        }
        for(int i = 0; i < size; i++){
            if(nums[i] > 0){
                break;
            }
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i + 1;
            int right = size - 1;
            while(left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if(sum > 0) {
                    right--;
                }else if (sum < 0) {
                    left++;
                }else {
                    res.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
        return res;
    }
}
