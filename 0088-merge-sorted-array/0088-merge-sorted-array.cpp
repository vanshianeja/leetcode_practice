class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n;
        vector<int> temp(k);
        for(int i = 0; i<m; i++){
            temp[i] = nums1[i];
        }
        for(int j = 0; j<n;j++){
            temp[m+j] = nums2[j];
        }
        for(int i = 0; i<k-1; i++){
            for(int j = 0; j<k-1-i; j++){
                if(temp[j]>temp[j+1]){
                    int t = temp[j];
                    temp[j] = temp[j+1];
                    temp[j+1] = t;
                }
            }
        }
        for(int x=0; x<k; x++){
            nums1[x]=temp[x];
        }
        
    }
};