class Solution {
public:
    int maxElement(vector<vector<int>>& mat, int n, int m, int col){
        int maxi = -1;
        int ind = -1;
        for(int i = 0; i<n; i++){
            if(mat[i][col] > maxi){
                maxi = mat[i][col];
                ind = i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat[0].size();
        int n = mat.size();

        int low = 0; int high = m - 1;
        while(low <= high){
            int mid = (low + high)/2;
            int row = maxElement(mat, n, m, mid);
            int left;
            int right;

            if(mid - 1 >= 0){
                left = mat[row][mid - 1];
            }
            else left = -1;

            if(mid + 1 < m){
                right = mat[row][mid + 1];
            }
            else right = -1;

            if(mat[row][mid] > left && mat[row][mid] > right) return {row, mid};
            else if(mat[row][mid] < left) high = mid - 1;
            else low = mid + 1;
        }
        return {-1, -1};
    }
};