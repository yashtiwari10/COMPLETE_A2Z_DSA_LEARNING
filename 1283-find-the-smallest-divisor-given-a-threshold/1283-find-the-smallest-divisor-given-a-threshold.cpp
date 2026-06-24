class Solution {
public:
    int req_time(vector<int>& nums, int divisor, int threshold){
        int time = 0;
        for(int i = 0; i<nums.size(); i++){
            time += ceil((double)nums[i] / divisor);
        }
        return time;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }
        int low = 1; int high = maxi;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(req_time(nums, mid, threshold) <= threshold){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};