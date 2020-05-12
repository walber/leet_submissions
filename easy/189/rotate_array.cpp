
class Solution {
public:
    void perform_rotate(vector<int>& nums, int s, int e) {

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
        perform_rotate(nums, 0, N - 1);
        perform_rotate(nums, 0, k - 1);
        perform_rotate(nums, k, N - 1);       
    }
};
