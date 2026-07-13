class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> list;
        for(int start = 1; start<= 9; start++){
            int num = start;
            for(int next = start + 1; next<=9; next++){
                num = num * 10 + next;
                if(num >= low && num<=high){
                    list.push_back(num);
                }
            }
        }
        sort(list.begin(), list.end());
        return list;
    }
};