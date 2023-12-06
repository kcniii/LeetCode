// 5. Longest Palindromic Substring
// kcniii
// runtime: 23 ms
// memory: 20.10 mb
class Solution {
public:
    string longestPalindrome(string s) {
        unordered_map<char, int> window;
        int start = 0, end = 0;
        int len = s.length();
        int max = 0;
        string max_str;
        // a
        if (len == 1) {
            return s;
        }

        while (end < len) {
            window[s[end]]++;
            // babad cbbd
            if (window[s[end]] > 1) {
                for (int i = 0; end + i < len && end - 2 - i>=0; i++) {

                    if (s[end + i] == s[end - 2 - i]) {
                        if (2 * i + 3 > max) {
                            max = 2 * i + 3;
                            max_str = s.substr(end - 2 - i, max);
                        }
                        continue;
                    }

                    else {
                        break;
                    }
                }
                // babad cbbd bb
                for (int i = 0; end + i < len && end - 1 - i>=0; i++) {

                    if (s[end + i] == s[end - 1 - i]) {
                        if (2 * i + 2 > max) {
                            max = 2 * i + 2;
                            max_str = s.substr(end - 1 - i, max);
                        }
                        continue;
                    }

                    else {
                        break;
                    }
                }
            }
            else {
                if (max < 2)
                    max_str = s[0];
            }
            end++;
        }
        return max_str;
    }
};


// learned method
// class Solution{
//     public:
//         string longestPalindrome(string s){
//             string res="";
//             unordered_map<char, int> window;
//             for(int i=0;i<s.length();i++){
//                 string s1 = palindrome(s,i,i);
//                 string s2 = palindrome(s,i,i+1);
//                 res = res.length()>s1.length()? res:s1;
//                 res = res.length()>s2.length()? res:s2;
//             }
//             return res;
//         }

//         string palindrome(string s, int l, int r){
//             int len = s.length();
//             while(l>=0 && r<len &&s[l]==s[r]){
//               l--;
//               r++;
//             }
                
//             return s.substr(l+1, r-l-1);
//         }
// };