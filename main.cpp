// for testing
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        unordered_map<char,int> window;
        int start=0, end=0;
        int len=s.length();
        int max=0;
        string max_str;
        // a
        if(len==1){
            return s;
        }

        while(end<len){
            window[s[end]]++;
            // babad cbbd
            if(window[s[end]]>1){
                for(int i=0; end+i<len && end-2-i>0; i++){

                    if(s[end+i]==s[end-2-i]){
                        if(2*i+3>max){
                            max = 2*i+3;
                            max_str = s.substr(end-2-i,end+i+1);
                        }
                        continue;
                        }

                    else{ 
                        break;
                        }
                }
                // babad cbbd bb
                for(int i=0; end+i<len && end-1-i>0; i++){

                    if(s[end+i]==s[end-1-i]){
                        if(2*i+2>max){
                            max = 2*i+2;
                            max_str = s.substr(end-1-i,end+i+1);
                        }
                        continue;
                        }

                    else{ 
                        break;
                        }
                }
            }
            else{
                if(max<2)
                    max_str = s[0];
            }
            end++;
        }
        return max_str;
    }
};

int main(){
    Solution s;
    string test = "bb";
    cout<<s.longestPalindrome(test)<<endl;
    return 0;
}
