class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        
        int length = nums.size();
        // 数组长度要求
        if( length < 3){
            return ret;
        }
        // 需要先进行排序
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < length; ++i){
            // 最小值>0，则3个数的和必定大于0 
            if(nums[i] > 0){
                break;
            }
            // 本次的起始值与上一次的相同，则存在重复，需要跳过，如 -4,-1,-1,0,1,2
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
                
            int left = i + 1;  // 双指针法
            int right = length -1;
            int sum = 0;
            while(left < right){              
                sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    ret.push_back({nums[i], nums[left], nums[right]});
                    /*
                     注意这个循环去重的位置，必须是在找到了一个组合的情况下，才进行去重，保证多个重复的组合时，至少有一个被记录下来。
                    */
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if(sum < 0){
                    left++; // 当前组合<0，左边界右移，使组合值增大
                }
                else{
                    right--; // 当前组合>0，右边界左移，使组合值减小。此处可以体会一开始需要排序的原因
                }    
            }
        }
        
        return ret;
    }
};