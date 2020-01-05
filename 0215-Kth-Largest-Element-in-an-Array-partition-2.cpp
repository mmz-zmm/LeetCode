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
        swap(nums[left],nums[left + rand()%(right - left + 1)]);

        int pivot = nums[left];
        while(left < right){
            while(left < right && nums[right] >= pivot){
                right--;
            }
            nums[left] = nums[right];
            while(left < right && nums[left] < pivot){
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
        
    }

};
