class Solution {
public:
    int divide(int dividend, int divisor) {
        //特殊情况，避免无意义的计算
        if(divisor == 1)
            return dividend;
        // 特殊情况，除法溢出，返回INT_MAX
        if(divisor == -1 && dividend == INT_MIN)
            return INT_MAX;
        // 判断商的正负
        bool is_negative = (dividend > 0) != (divisor > 0); 
        
        int count = 0;
        /*
        遇到的一个问题时，当使用三目运算符转化为负数时，编译报错，暂时没有弄清楚原因，使用if语句则没问题
         runtime error: negation of -2147483648 cannot be represented in type 'int';
         int dividend_tmp = (dividend > 0)? -dividend: dividend;
         int divisor_start = (divisor > 0)? -divisor: divisor;
        */
        int dividend_tmp = dividend;
        int divisor_start = divisor;
        /*全部转化为负数，避免正数比较时INT_MIN越界*/
        if(dividend > 0)
        {
            dividend_tmp = 0 - dividend;
        }
        
        if(divisor > 0)
        {
            divisor_start = 0 - divisor;
        }
        
           
        while(dividend_tmp < 0)
        {
            int inner_count = 1;
            int divisor_tmp = divisor_start;
            int divisor_last = 0;
           
            while(true)
            {
                // 记录下倍增前divisor_tmp的值，因为可能倍增后就溢出了
                divisor_last = divisor_tmp;
                // 必须是INT_MIN - divisor_tmp，如果将divisor_tmp移到符号右边，可能已经溢出了
                if(INT_MIN - divisor_tmp > divisor_tmp) break;
                divisor_tmp += divisor_tmp;
                if(divisor_tmp < dividend_tmp) break;
                inner_count += inner_count;
            }
            
            dividend_tmp -= divisor_last;
            count += inner_count; 
        }
        // 整除时，没有问题；不整除的时候，因为inner_count的初始值是1，所以count的值会多算一次
        if (dividend_tmp != 0) count--;
        
        return is_negative ? -count: count;
        
    }
};
