
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();
        int out = N;
        
        for (int i = 0; i < N; i++)
            out -= nums[i] - i;
        
        return out;
    }
};
