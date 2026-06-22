class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;

        if(n == 1) return 1;
        while(j < n){
            if(nums[i] == nums[j]) j++;
            else if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
                j++;
            }
        }
        return i + 1;
    }
};