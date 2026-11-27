class Solution {
private:
    // Count valid reverse pairs across two sorted halves in O(n)
    int countPairs(vector<int>& a, int low, int mid, int high) {
        int right = mid + 1;
        int left = low;
        int cnt = 0;

        for (; left <= mid; left++) {
            // Use long long to prevent overflow when multiplying by 2
            while (right <= high && a[left] > 2 * (long long)a[right]) {
                right++;
            }
            cnt += right - (mid + 1);
        }
        return cnt;
    }

    // Standard merge step for two sorted halves
    void mergeOneList(vector<int>& a, int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        int k = 0;
        vector<int> b(high - low + 1);

        while (i <= mid && j <= high) {
            if (a[i] <= a[j]) {
                b[k++] = a[i++];
            } else {
                b[k++] = a[j++];
            }
        }

        while (i <= mid) {
            b[k++] = a[i++];
        }

        while (j <= high) {
            b[k++] = a[j++];
        }

        for (int x = low; x <= high; x++) {
            a[x] = b[x - low];
        }
    }

    // Divide & Conquer recursive Merge Sort
    int recursiveMerge(vector<int>& a, int low, int high) {
        int cnt = 0;
        if (low < high) {
            int mid = low + (high - low) / 2;
            cnt += recursiveMerge(a, low, mid);
            cnt += recursiveMerge(a, mid + 1, high);
            cnt += countPairs(a, low, mid, high);
            mergeOneList(a, low, mid, high);
        }
        return cnt;
    }

    int solve(vector<int>& a, int n) {
        return recursiveMerge(a, 0, n - 1);
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, n);
    }
};