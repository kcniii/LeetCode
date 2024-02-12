// 605. Can Place Flowers (easay)

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int size= flowerbed.size();
       int flowers = 0;
       flowerbed.insert(flowerbed.begin(),0);
       flowerbed.push_back(0);

       for(int i=1;i<=size;i++){
           if(flowerbed[i]==1){
               i++;
           }
           else if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
               flowerbed[i] = 1;
               flowers++;
               
           }
       }
       return flowers>=n;
    }
};