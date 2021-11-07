class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0 || intervals.size() == 1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[0] < b[0];
        });
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int count = 0;
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] <= res[count][1] && intervals[i][1] > res[count][1]){
                res[count][1] = intervals[i][1];
            }else{
                if (intervals[i][0] > res[count][1]){
                    res.push_back(intervals[i]);
                    count++;
                }
            }
        }
        return res;
    }
};
