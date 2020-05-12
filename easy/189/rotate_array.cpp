
class Solution {
public:
    void perform_rotation(vector<int>& nums, int s, int e) {

        int temp;
        for (;s < e; s++, e--) {
            temp = nums[s];
            nums[s] = nums[e];
            nums[e] = temp;
        }    
    }
    
    void rotate(vector<int>& nums, int k) {
        
        int N = nums.size();
        k = k % N;
        perform_rotation(nums, 0, N - 1);
        perform_rotation(nums, 0, k - 1);
        perform_rotation(nums, k, N - 1);       
    }
};
