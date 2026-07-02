class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /* TC ----> O(N1 + N2)
           SC ----> O(N1 + N2)
        vector<int> nums3;
        int i = 0; int j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]) nums3.push_back(nums1[i++]);
            else nums3.push_back(nums2[j++]);
        }
        while(i < n1) nums3.push_back(nums1[i++]);
        while(j < n2) nums3.push_back(nums2[j++]);

        int n = n1 + n2;
        if(n % 2 == 1) return nums3[n/2];
    return double((double)nums3[n/2] + (double)nums3[(n/2) - 1])/2.0; 

        TC ----> O(N1 + N2)
        SC ----> O(1)
        int n1 = nums1.size(); int n2 = nums2.size();
        int n = n1 + n2;
        int ind1 = n/2; int ind2 = ind1 - 1;
        int cnt = 0;
        int i = 0; int j = 0;
        int el1 = -1; int el2 = -1;
        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                if(cnt == ind1) el1 = nums1[i];
                if(cnt == ind2) el2 = nums1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt == ind1) el1 = nums2[j];
                if(cnt == ind2) el2 = nums2[j];
                cnt++;
                j++;
            }
        }

        while(i < n1){
            if(cnt == ind1) el1 = nums1[i];
            if(cnt == ind2) el2 = nums1[i];
            cnt++;
            i++;
        }

        while(j < n2){
            if(cnt == ind1) el1 = nums2[j];
            if(cnt == ind2) el2 = nums2[j];
            cnt++;
            j++;
        }
    if(n % 2 == 1) return el1;
    return double(((double)el1 + (double)el2)/2); */

    int n1 = nums1.size();
        int n2 = nums2.size();

        // Always binary search on the smaller array
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2;

        int low = 0, high = n1;

        while (low <= high) {

            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 > 0)
                l1 = nums1[mid1 - 1];
            if (mid2 > 0)
                l2 = nums2[mid2 - 1];

            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];

            if (l1 <= r2 && l2 <= r1) {

                if (n % 2 == 1)
                    return max(l1, l2);

                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            else if (l1 > r2) {
                high = mid1 - 1;
            }

            else {
                low = mid1 + 1;
            }
        }

        return 0.0;
    }
};