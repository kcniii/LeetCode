// 167. Two Sum II - Input Array Is Sorted (medium)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        int l=0,r=size-1,sum;

        while(l<r){
            sum = numbers[l]+numbers[r];
            if(sum==target) break;

            if(sum<target) ++l;
            else --r;
        }
        return vector<int> {l+1, r+1};
    }
};

// note: the type of the return value is vector<int> {l+1, r+1} not vector<int> (l+1, r+1) or vector<int> [l+1, r+1]