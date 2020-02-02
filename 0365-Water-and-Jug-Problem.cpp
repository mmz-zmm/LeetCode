class Solution {
public:
    // bezouts-identity 裴蜀定理
    // a * x + b * y = m * d, 其中d是a和b的最大公约数
    bool canMeasureWater(int x, int y, int z) {
        if( x < 0 || y < 0 || x + y < z) return false;
        if( z == 0 ) return true;
        // make sure x >= y
        int tmp = 0;
        if(x < y) {
            tmp = x ;
            x = y;
            y = tmp;
        }
        // find gcd
        while(y){
            tmp = x % y;
            x = y;
            y = tmp;
        }
        return z % x == 0;  
    }
};