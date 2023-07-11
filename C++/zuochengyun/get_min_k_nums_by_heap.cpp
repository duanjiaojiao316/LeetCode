#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (k < 1) {
            return vector<int>();
        }
        if (k > arr.size()) {
            return arr;
        }
        vector<int> k_heap = vector<int>(k);
        for (int i = 0; i != k; i++) {
            heapInsert(k_heap, arr[i], i);
        }

        for (int i = k; i != arr.size(); i++) {
            if (arr[i] < k_heap[0]) {
                k_heap[0] = arr[i];
                heapify(k_heap, 0, k);
            }
        }
        return k_heap;
    }
    /**
     * 当堆的元素小于K个
     * 往堆底部加入元素，比较其与父节点的关系
     * 如果父节点小于该节点，则交换两个节点的位置
     * 循环往复，之道父节点大于该节点
    */
    void heapInsert(vector<int>& k_heap, int value, int index) {
        k_heap[index] = value; // 将arr[i]置于堆顶
        while (index != 0) {
            int parent = (index - 1) / 2;
            if (k_heap[parent] < k_heap[index]){
                swap(k_heap, parent, index);
                index = parent;
            } else {
                break;
            }
        }     

    }
    /**
     * 当堆的元素超过K个，且该元素小于堆顶元素
     * 使用该元素替换堆顶的元素
     * 判断左右子节点是否小于该元素，选择左右子节点和该元素最大的元素放置在父节点
     * 循环往复
     * 
    */
    void heapify(vector<int>&k_heap, int index, int heap_size) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int largest = index;
        while (left < heap_size) {
            if (k_heap[left] > k_heap[index]) {
                largest = left;
            }
            if (right < heap_size && k_heap[right] > k_heap[largest]){
                largest = right;
            }

            if (largest != index) {
                swap(k_heap, largest, index);
            } else {
                break;
            }
            index = largest;
            left = index * 2 + 1;
            right = index * 2 + 2;
        }

    }
    void swap(vector<int>& k_heap, int parent, int index) {
        int tmp = k_heap[parent];
        k_heap[parent] = k_heap[index];
        k_heap[index] = tmp;
    }


};

int main() {
    Solution solution = Solution();
    vector<int> arr = {9,8,7,6};
    solution.smallestK(arr, 2);
}