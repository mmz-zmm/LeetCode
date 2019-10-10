class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        #ifdef VERSION_1 //频次法
       /* 
        该方法与方法2思路是一致的，是我采用的第一个版本。区别的地方在于：方法2在移动左边界时直接跳到了上一次
        出现的地方。而方法1中freq记录的字符出现的频次，移动左边界时是一步一步的。当右边界处出现重复字符时，它会
        一直移动左边界，直到去除掉重复的字符。这样保证了窗口内都是非重复的字符。
       */
        int freq[256] = {0};
        int L = 0;
        int R = 0;
        int res = 0;
        
        while(L < s.size())
        {
            if( R < s.size() && freq[s[R]] == 0)
            {
                freq[s[R]]++;
                R++;
            }
            else
            {
                freq[s[L]]--;
                L++;
            }
            res = max(res, R - L);
        }
        return res;
        #endif

        #ifdef VERSION_2 //位置法
        int pos[256] = {0}; // 记录当前每个字符最后一次出现的位置，从1开始。0表示从未出现。
        int left = 0; // 滑动窗口，内部均为不重复的字串
        int right = 0;
        int res = 0;
        while(right < s.size()){
            // 窗口扩大的场景 1. 右边这个字符没有出现过 2. 右边这个字符出现过，但不在当前的窗口内
            if(pos[s[right]] == 0 || pos[s[right]] < left){
                res = max(res, right - left + 1);
            }
            else{
                left = pos[s[right]]; // 窗口缩小；更新窗口的左边界，直接移到该字符上次出现的位置
            }
            pos[s[right]] = right + 1;
            right ++;

        }
        return res;
        #endif
    }
};