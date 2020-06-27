class Solution {
public:
// 动态规划： 
// dp0[i]表示前i个数中可被3整除的最大和，
// dp1[i]表示前i个数中可被3整除余1的最大和，
// dp2[i]表示前i个数中可被3整除余2的最大和，
// 如果 num[i] % 3 == 0, 三者直接更新
// 如果 num[i] % 3 == 1, dp0[i] = max(dp0[i-1], dp2[i-1] + num)
//      dp1[i] = max(dp1[i-1], dp0[i-1] + num),dp2[i] = max(dp2[i-1], dp1[i-1] + num)
// 如果 num[i] % 3 == 2, dp0[i] = max(dp0[i-1], dp1[i-1] + num)
//      dp1[i] = max(dp1[i-1], dp2[i-1] + num),dp2[i] = max(dp2[i-1], dp0[i-1] + num)
    int maxSumDivThree(vector<int>& nums) {
        int state[] = {0, INT_MIN, INT_MIN};

        for(auto num : nums){
            int ret = num % 3;
            int a, b, c;
            if (ret == 0) {
                state[0] += num;
                state[1] += num;
                state[2] += num;
            } else if(ret == 1) {
                a = max(state[0], state[2] + num);
                b = max(state[1], state[0] + num);
                c = max(state[2], state[1] + num);
                state[0] = a;
                state[1] = b;
                state[2] = c;               
            } else if(ret == 2) {
                a = max(state[0], state[1] + num);
                b = max(state[1], state[2] + num);
                c = max(state[2], state[0] + num); 
                state[0] = a;
                state[1] = b;
                state[2] = c;                  
            }
            cout << state[0] <<" "<<state[1]<<" "<<state[2]<<endl; 
        }
        return state[0];
    }
};