// 135. Candy(hard)
// // There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
// You are giving candies to these children subjected to the following requirements:
// 1. Each child must have at least one candy.
// 2. Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.


class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if(size<2) return size;

        vector<int> num(size,1);
        for(int i=1;i<size;i++){
            if(ratings[i]>ratings[i-1]){
                num[i]=num[i-1]+1;
            }
        }

        for(int i=1;i<size;i++){
            if(ratings[size-i-1]>ratings[size-i] ){
                num[size-i-1]=max(num[size-i-1],num[size-i]+1);
            }
        }

        return accumulate(num.begin(),num.end(),0);
    }
};