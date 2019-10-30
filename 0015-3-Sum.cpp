class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        
        int length = nums.size();
        
        if( length < 3){
            return ret;
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < length; ++i){
            
            if(nums[i] > 0){
                break;
            }
            
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
                
            int left = i + 1;
            int right = length -1;
            int sum = 0;
            while(left < right){              
                sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    ret.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if(sum < 0){
                    left++;
                }
                else{
                    right--;
                }    
            }
        }
        
        return ret;
    }
};