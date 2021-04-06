/** 使用两个游标，一个指向原始数组的位置p1，一个指向最终结果的位置p2，由于是删除元素，所以前者总是比后者
 * 跑的快。由于数组已经是有序的，相同的元素都聚集在一起，只需比较nums[i] == nums[i - 2]，即可知道
 * 当前的结果是否保留，如果相同，则不保留，p1++;如果不同，则需要保留，p1++, p2++；
 * */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 3) {
            return len;
        }

        int i = 0;
        for(auto num : nums) {
            if(i < 2 || num != nums[i - 2]) {
                nums[i++] = num;
            }
        }
        return i ;
    }
};