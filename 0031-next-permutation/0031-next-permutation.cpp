class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (is_sorted(nums.rbegin(), nums.rend())) {
            reverse(nums.begin(), nums.end());
            return;
        }

        next_permutation(nums.begin(), nums.end());
    }
};