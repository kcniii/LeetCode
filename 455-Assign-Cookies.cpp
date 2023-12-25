// 455. Assign Cookies
// Link: https://leetcode.com/problems/assign-cookies/
/* Description: Given an array of children's greed factor and an array of cookies' size, 
find the maximum number of content children. */
// Runtime: 19 ms, Memory : 17,82 MB

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i=0,j=0;
        int m=g.size(),n=s.size();

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while(i<m && j<n){
            if(g[i]<=s[j]) i++;
            j++;
        }

        return i;
    }

};
