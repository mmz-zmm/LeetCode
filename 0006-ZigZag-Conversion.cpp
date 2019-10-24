class Solution {
public:
    string convert(string s, int numRows) {
        // trival case: 空字符串 或 numRows==1
        if( s.empty() || numRows == 1){
            return s;
        }
        int s_len = s.size();
        string tmp(s_len, ' ');
        int interval = numRows *2 - 2;  // Zigzag分解为V型，两个V型之间的间隔为interval
        int index = 0;
        /*
        a           g
        b       f   h       l
        c   e       i   k
        d           j
        
        */
        for(size_t i = 0; i < numRows && i < s.size(); ++i){
            size_t j = i;
            while( j < s_len){
                if( i == 0 || i == numRows - 1){ //首尾两行的间隔是固定的, a-->g, d-->j
                    tmp[index++] = s[j];
                    j += interval;
                }else{
                    tmp[index++] = s[j];     // 中间行的间隔会存在一个变化， b-->f-->h
                    j += interval - 2 * i;
                    if( j < s_len){         // 注意，此处要判断j是否已经超过字符串的长度，可能会出现b-->f但没有h的场景
                        tmp[index++] = s[j];
                        j += 2 * i;
                    }
                }
            }
        }     
        return tmp;
    }
};