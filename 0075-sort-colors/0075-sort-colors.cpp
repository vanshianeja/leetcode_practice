class Solution {
public:
    void sortColors(vector<int>& nums) {
        int k = nums.size();
        for(int i = 0; i<k-1; i++){
            for(int j = 0; j<k-1-i; j++){
                if(nums[j]>nums[j+1]){
                    int t = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = t;
                }
            }
        }
    }
};