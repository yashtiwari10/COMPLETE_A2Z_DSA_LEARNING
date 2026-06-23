class Solution {
public:
    int max_element(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i = 0; i<piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }
    long long req_time(vector<int>& piles, int hourly){
        long long totalhrs = 0;
        for(int i = 0; i<piles.size(); i++){
            totalhrs += ceil((double)piles[i] / (double)hourly);
        }
        return totalhrs;
    } 
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1; int high = max_element(piles);

        while(low <= high){
            int mid = low + (high - low)/2;
            long long totalhrs = req_time(piles, mid);

            if(totalhrs <= h) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};