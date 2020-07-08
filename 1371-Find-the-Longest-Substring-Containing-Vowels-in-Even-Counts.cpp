class Solution {
public:
// 对于五个元音字母，分别使用一个bit位来分别表示该元音字母是否出现，出现为1，反之为0
// 0-0-0-0-0
// u-o-i-e-a
// 从左往右依次扫描,遇到对应的元音字符，则对应位进行异或操作，5个bit位组成了一个状态，代表了扫描到当前字符时，
// 其左侧子字符串中元音的奇偶情况，如果使用一个数组记录下来，类似于前缀和的概念。
// 同时注意到，
// 1 ^ 偶数个1 = 1; 1^ 奇数个1 = 0; 
// 0 ^ 偶数个1 = 0; 0^ 奇数个1 = 1;
// 也就是说，对于前缀和数组中保存的两个相同的状态，其中间必然包含了偶数个元音字母。
// 进而，我们没必要使用额外的前缀和数组，只用记录指定状态对应的字符下标i和j(hash 表)，
// j - i + 1就是当前时刻的最长子串长度，由于元音有5位，其所有状态为2^5个，即32，因此使用一个32位大小的数组即可。
    int findTheLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;

        vector<int> pos(1<<5, -1);
        pos[0] = 0;

        int ret = 0;
        int status = 0;

        for(int i = 0; i < n; ++i) {
            switch(s[i]) {
                case 'a':
                status ^= (1<<0);
                break;
                case 'e':
                status ^= (1<<1);
                break;
                case 'i':
                status ^= (1<<2);
                break;
                case 'o':
                status ^= (1<<3);
                break;
                case 'u':
                status ^= (1<<4);
                break;
            }
            if(pos[status] != -1) {
                ret = max(ret, i + 1 - pos[status]);
            } else {
                pos[status] = i + 1;
            }
        }
        return ret;
    }
};