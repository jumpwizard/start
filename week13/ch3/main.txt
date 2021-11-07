class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0 || intervals.size() == 1){
            return 0;
        }
        //排序
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        int cur = intervals[0][1];
        int count = 0;
        for (int i = 1; i < intervals.size(); i++){
            if (cur > intervals[i][0]){
                count++;
            }else{
                cur = intervals[i][1];
            }
        }
        return count;
    }
};
