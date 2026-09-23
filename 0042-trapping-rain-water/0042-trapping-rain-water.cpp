class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxLeft = height[0]; int maxRight = height[n - 1];
        int l = 0; int r = n - 1;
        int ans = 0;

        if(n < 3){
            return 0;
        }
        while(l < r){
            if(maxLeft < maxRight){
                l += 1;
                maxLeft = max(maxLeft, height[l]);
                ans += maxLeft - height[l];
            }
            else{
                r -= 1;
                maxRight = max(maxRight, height[r]);
                ans += maxRight - height[r];
            }
        }
        return ans;
    }
};