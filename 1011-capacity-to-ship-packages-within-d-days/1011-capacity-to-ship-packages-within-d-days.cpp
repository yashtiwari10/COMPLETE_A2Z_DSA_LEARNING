class Solution {
public:
    int req_days(vector<int>& weights, int capacity){
        int days = 1; int load = 0;
        for(int i = 0; i<weights.size(); i++){
            if(load + weights[i] > capacity){
                days = days + 1;
                load = weights[i];
            }
            else load += weights[i];
        }
        return days;
    } 
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i<weights.size(); i++){
            maxi = max(maxi, weights[i]);
            sum += weights[i];
        }
        int low = maxi; int high = sum;
        while(low <= high){
            int mid = low + (high - low)/2;

            int reqdays = req_days(weights, mid);
            if(reqdays <= days){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};