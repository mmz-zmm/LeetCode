class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int sz = nums.size();
        int left = 0;
        int right = sz -1;
        
        srand(time(0));

        int target = sz - k;

        while(true){
            int index = partition(nums, left, right);
            if(index == target){
                return nums[index];
            }else if(index < target){
                left = index + 1;
            }else{
                right = index - 1;
            }
        }
    }

    int partition(vector<int> &nums, int left, int right){
        // 随机取一个数值作为pivot
        swap(nums,left, left + rand()%(right - left + 1));

        int pivot = nums[left];
        int j = left;
        for(int i = left + 1; i <=right;++i)
        {
            if(nums[i] < pivot){
                j++;
                swap(nums, j, i);
            }
        }
        swap(nums,j,left);
        return j;
    }
    void swap(vector<int> &nums, int index1, int index2){
        if(index1 == index2)
            return;
        int tmp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = tmp;
    }
};
