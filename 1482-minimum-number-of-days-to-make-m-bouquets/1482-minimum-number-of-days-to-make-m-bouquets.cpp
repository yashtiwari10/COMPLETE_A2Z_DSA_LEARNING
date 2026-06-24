class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int cnt = 0; int nob = 0;
        for(int i = 0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                cnt++;
            }
            else {
                nob += (cnt/k);
                cnt = 0;
            }
        }
        nob += (cnt/k);

        if(nob >= m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if(n < 1LL*m*k) return -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0; i<bloomDay.size(); i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int low = mini; int high = maxi;
        while(low <= high){
            int mid = (low + high)/2;
            if(possible(bloomDay, mid, m, k) == true){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};