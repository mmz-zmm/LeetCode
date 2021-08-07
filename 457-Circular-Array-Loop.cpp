class Solution {
public:
    bool circularArrayLoop(vector<int> &nums) {
        int n = nums.size();

        auto next = [&](int cur) {
            // nums[curr]可能为很大的负值，因此需要求余后，加n再求余
            return ((cur + nums[cur]) % n + n) % n;
        };

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                continue;
            }
            int slow = i;
            int fast = next(slow);
            // 判断非零且方向相同
            while (nums[slow] * nums[fast] > 0 &&
                   nums[slow] * nums[next(fast)] > 0) {
                if (slow == fast) {
                    // 环的长度不为1
                    if (slow != next(slow)) {
                        return true;
                    } else {
                        break;
                    }
                }
                // 更新快慢指针
                slow = next(slow);
                fast = next(next(fast));
            }
            // 将历史路径都标记为已经访问
            int curr = i;
            int curr_next = next(curr);
            while (nums[curr] * nums[curr_next] > 0) {
                nums[curr] = 0;
                curr = curr_next;
                curr_next = next(curr);
            }
        }
        return false;
    }
};