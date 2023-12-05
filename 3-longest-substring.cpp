class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0,end=0,res=0;
        int len = s.length();
        unordered_map<char,int> window;
        while(end<len){
            char right = s[end];
            end++;
            window[right]++;
            while(window[right]>1){
                char left = s[start];
                start++;
                window[left]--;
            }
            int sub_len = end - start;
            res = max(res,sub_len);
        }
        return res;
    }
};