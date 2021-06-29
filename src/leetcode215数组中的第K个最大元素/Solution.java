package leetcode215数组中的第K个最大元素;


import java.util.Random;

public class Solution {
    /**
     * 方法1：最小堆方法
     * 维护一个容量为k的最小堆,堆顶是这k个元素的最小值
     */
    public int findKthLargest(int[] nums, int k) {
        // 初始化使用前k个元素创建一个最小堆
        buildMinHeap(nums, k);
        for (int i = k; i < nums.length; i++) {
            if (nums[i] > nums[0]) {
                nums[0] = nums[i];

                downAdjust(nums, 0, k);
            }
        }
        return nums[0];
    }

    /**
     * 创建最小堆 先从最后一个非叶子结点开始，判断其是否需要进行调整
     *
     * @param nums   待调整的堆
     * @param length 堆的容量大小
     */
    public void buildMinHeap(int[] nums, int length) {
        for (int i = (length - 2) / 2; i >= 0; i--) {
            downAdjust(nums, i, length);
        }
    }

    /**
     * 最小堆调整
     *
     * @param nums   待调整的堆
     * @param index  调整元素索引
     * @param length 堆的大小
     */
    public void downAdjust(int[] nums, int index, int length) {
        // 记录待调整元素
        int temp = nums[index];
        int childIndex = 2 * index + 1;

        while (childIndex < length) {
            if (childIndex + 1 < length && nums[childIndex + 1] < nums[childIndex]) {
                childIndex++;
            }
            if (temp <= nums[childIndex]) {
                break;
            }
            nums[index] = nums[childIndex];
            index = childIndex;
            childIndex = 2 * index + 1;
        }
        nums[index] = temp;
    }


    /**
     * 方法2：使用快速排序思想
     */


    Random random = new Random();

    public int findKthLargest1(int[] nums, int k) {
        return quickSelect(nums, 0, nums.length - 1, nums.length - k);
    }

    public int quickSelect(int[] a, int l, int r, int index) {
        // 获取随机基准
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    /**
     * @param array
     * @param start
     * @param end
     * @return
     */
    public int randomPartition(int[] array, int start, int end) {
        // 获取一个随机数
        int randomIndex = random.nextInt(end - start + 1) + start;
        // 将随机数index的值与数组最右端数字进行交换，以交换后的最右端数字进行交换
        swap(array, randomIndex, end);

        return partition(array, start, end);
    }

    /**
     *
     * @param array
     * @param start
     * @param end
     * @return
     */
    public int partition(int[] array, int start, int end) {
        int pivot = array[end];
        int mark = start;
        for (int j = start + 1; j < end; ++j) {
            if (array[j] <= pivot) {
                mark++;
                swap(array, mark, j);
            }
        }
        swap(array, mark, end);
        return mark;
    }

    /**
     * 交换数组的位置
     *
     * @param array
     * @param i
     * @param j
     */
    public void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }


}
