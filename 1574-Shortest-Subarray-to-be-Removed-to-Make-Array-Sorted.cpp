class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int size = arr.size();
        if( size <= 1) {
            return 0;
        }

        // get the left-side sorted part
        int left = 0;
        while(left < size - 1 && arr[left] <= arr[left + 1]) {
            left++;
        }
        // left reach end, means arr already sorted
        if(left == size - 1) return 0;

        // get the right-side sorted part 
        // no need to check if right reach the begin, since in this condition, arr are 
        // already sorted, program already return above.
        int right = size - 1;
        while(right > 0 && arr[right - 1] <= arr[right]) {
            right--;
        }

        // possible condtion :   remove [left + 1, size -1]
        //                       remove [0, right - 1]
        int ret = min(size - 1 - left , right);
        
        // since we already get two sorted array, merge them from begin to end.
        int i = 0;
        int j = right;
        while( i <= left && j < size) {
            if(arr[i] <= arr[j]) {
                // range [i+1, j-1] are not sorted, possibly need remove them 
                ret = min(ret, j - i - 1);   
                i++;
            } else {
                // skip the not sorted part.
                j++;
            }
        }
    
        return ret;
    }
};
