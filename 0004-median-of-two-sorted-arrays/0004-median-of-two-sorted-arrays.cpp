class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /* TC ----> O(N)
           SC -----
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
    return double((double)nums3[n/2] + (double)nums3[(n/2) - 1])/2.0; */

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
    return double(((double)el1 + (double)el2)/2); 
    }
};