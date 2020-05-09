

#define ABS(N) ((N<0) ? -N : N)

class Solution {
public:

    int firstMissingPositive(vector<int>& nums) {

        int N, m;
        long j, p;
        N = nums.size();
        j = 0;

        for (int i = 0; i < N; i++) {
            if (nums[i] <= 0) {
                nums[i] = nums[j];
                j += 1;
            }
        }

        for (int i = j; i < N; i++) {
            p = j + ABS(nums[i]) - 1;
            if (p < N) {
                nums[p] = nums[p] <= 0 ? nums[p] : -nums[p];
            }
        }

        m = 1;
        for (int i = j; i < N; i++) {
            if (nums[i] > 0) {
                return m;
            }
            m += 1;
        }

        return m;
    }
};
