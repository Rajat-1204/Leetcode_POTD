class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //Intialize variables
        unordered_map<int, int> m;
        int i = 0;
        int j = 0;
        int ans = 0;

        // traverse krenge full vector ko
        while(j<fruits.size()){
            //map ki values ko continue increase krte jayenge
            m[fruits[j]]++;

            //if any time map size increases and become more than 2 then we need to shrink from left
            while(m.size() > 2){
                m[fruits[i]]--;
                //if any time value reduce hoote hoote 0 hojayga toh usse erase krna pdega
                if(m[fruits[i]] == 0){
                    m.erase(fruits[i]);
                }
                i++;
            }
            // update ans
            ans = max(ans,j-i+1);
            j++;
        }
        
        // return ans
        return ans;
    }
};
