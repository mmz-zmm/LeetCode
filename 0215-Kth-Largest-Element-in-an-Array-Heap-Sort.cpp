class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /* 
        建立一个容量为k的小根堆，随后便利剩余数组，将大于堆顶的元素加入堆中，并进行调整。
        建立最大(小)堆的六个关键概念：
        1. Parent(i)
        2. Left(i)
        3. Right(i)
        4. Max-Heapify(A,i)
        5. Build-Max-Heap(A)
        6. Heapsort(A)
        */
        buildHeap(nums, k);
        int sz = nums.size();
        for(int i = k; i < sz; ++i){
            if(nums[i] > nums[0]){
                swap(nums[i], nums[0]);
                heapAdjust(nums, 0, k);
            }
        }
        return nums[0];
    }

    void buildHeap(vector<int> &nums, int len){
        for(int i = (len - 1)/2; i >=0; --i){
            heapAdjust(nums, i, len);
        }
    }
    // MAX-HEAPIFY
    void heapAdjust(vector<int> &nums, int k, int len){
        int left = k * 2 + 1, right = 2 *k + 2;
        // find the smallest node
        int smallest = k;
        if(left < len && nums[left] < nums[k]){
            smallest = left;
        }
        if(right < len && nums[right] < nums[smallest]){
            smallest = right;
        }
        // swap k with largest and "float down"
        if(smallest != k){
            swap(nums[smallest], nums[k]);
            heapAdjust(nums, smallest, len);
        }
    }
};