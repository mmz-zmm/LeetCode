class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
        双指针法，从两端到中间进行扫描
        */
        int left = 0;
        int right = height.size() - 1;
        int max_area =  0;
        while(left < right){
            max_area = max(max_area, min(height[left], height[right]) *(right - left));
            (height[left] < height[right])? ++left : --right;
        }
        return max_area;
        
    }
};