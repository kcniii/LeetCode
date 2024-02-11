// 452. Minimum Number of Arrows to Burst Balloons
// Runtime 276 ms Beats 73.39% of users with C++
// Memory 93.31 MB Beats 35.78% of users with C++

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b){return a[1]<b[1];}); 

        int size = intervals.size();
        int total=0, prev = intervals[0][1];

        for(int i=1;i<size;++i){
            if(intervals[i][0]<prev){
                ++total;
            }
            else{
                prev = intervals[i][1];
            }
        }

        return total;
    }
};
