// 435. Non-overlapping Intervals
//Given an array of intervals intervals where intervals[i] = [starti, endi], 
//return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

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


// notes:
// (vector<int>& a, vector<int>& b), not (vector<int> a, vector<int> b)
// use reference to avoid copying and save memory