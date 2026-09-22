class Solution {
public:
    vector<int> LeftMax(vector<int>& height, int n){
        vector<int> leftmax(n);
        leftmax[0] = height[0];
        for(int i = 1; i<n; i++){
            leftmax[i] = max(leftmax[i - 1], height[i]);
        }
        return leftmax;
    }

    vector<int> RightMax(vector<int>& height, int n){
        vector<int> rightmax(n);
        rightmax[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--){
            rightmax[i] = max(rightmax[i + 1], height[i]);
        }
        return rightmax;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        if(n < 3){
            return 0;
        }

        vector<int> leftmax = LeftMax(height, n);
        vector<int> rightmax = RightMax(height, n);
        
        for(int i = 0; i<n; i++){
            int water = min(leftmax[i], rightmax[i]) - height[i];
            
            if(water > 0) ans += water;
        }
        return ans;
    }
};