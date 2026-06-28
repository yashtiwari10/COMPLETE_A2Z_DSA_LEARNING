class Solution {
public:
    int function(vector<int>& nums, int a){
        int stu = 1; int pagestudent = 0;
        for(int i = 0; i<nums.size(); i++){
            if(pagestudent + nums[i] <= a){
                pagestudent += nums[i];
            }
            else{
                stu++;
                pagestudent = nums[i];
            }
        }
        return stu;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k > nums.size()) return -1;
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
            sum = sum + nums[i];
        }
        int low = maxi; int high = sum;
        while(low <= high){
            int mid = (low + high)/2;
            int nostudent = function(nums, mid);

            if(nostudent > k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};