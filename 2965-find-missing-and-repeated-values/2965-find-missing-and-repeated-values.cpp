class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int, int> mpp;
        int a;
        int b;
        int n = grid.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                mpp[grid[i][j]]++;
            }
        }
        for(auto it : mpp){
            if(it.second > 1){
                a = it.first;
            }
        }
        for(int i = 0; i<=n*n; i++){
            if(mpp[i] == 0){
                b = i;
            }
        }
        return {a, b};
    }
};