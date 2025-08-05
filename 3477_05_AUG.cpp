class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // intialize variables
        int n = fruits.size();
        int count = 0;

        // outer loop for fruits array
        for(int i = 0;i<n;i++){
            // inner loop for basket array
            for(int j = 0;j<n;j++){
                //checking if fruit is suitable for basket or not
                if(fruits[i] <= baskets[j]){
                    baskets[j] = -1; // mark krre hh jisse dobara isse consider naah krre
                    count++;
                    break; 
                }
            }
        }
        // return rest (total - cnt)
        return n - count;
    }
};
