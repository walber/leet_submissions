
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num_len = nums.size();
        int out = 0;
        
        for (int i = 0; i <= num_len; i++)
            out += i < num_len ? nums[i] - i : -i;
        
        return -out;
    }
};
