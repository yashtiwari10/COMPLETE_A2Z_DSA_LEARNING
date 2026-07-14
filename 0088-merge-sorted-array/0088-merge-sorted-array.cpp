class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int low = m - 1;
        int mid = n - 1;
        int last = m + n - 1;
        while (mid >= 0) {
            if (low >= 0 && nums1[low] > nums2[mid]) {
                nums1[last] = nums1[low];
                low--;
            } else {
                nums1[last] = nums2[mid];
                mid--;
            }

            last--;
        }
        return;
    }
};