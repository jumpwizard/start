class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.size() == 0){
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int indexg = 0, indexs = 0;
        int count = 0;
        while (indexs < s.size() && indexg < g.size()){
            if (s[indexs] >= g[indexg]){
                count++;
                indexg++;
            }
            indexs++;
        }
        return count;
    }
};
