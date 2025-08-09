class Solution {
public:
    bool isPowerOfTwo(int n) {
        //------------------------ Approach - 1 -------------------------

        // traverse thru the values from 0 to 30
        for(int i = 0;i<=30;i++){
            // finding power of 2 of index i
            int digit = pow(2,i);
            // compare krenge then n se
            if(n == digit){
                return true;
            }
        }
        //return false
        return false;


        //------------------------ Approach - 2 -------------------------
        // set bit count approach

        // intialize variables
        int count = 0;

        // applying base case
        if(n<0){
            return false;
        }

        // traverse n from right to left
        while(n != 0){
            // calculating bit and of n & 1 and increase count if it is set bit
            if((n & 1) == 1){
                count++;
            }
            // right shift n
            n = n >> 1;
        }

        // check no. of set bit if it is 1 then true
        if(count == 1){
            return true;
        }

        // otherwise false
        return false;

        //------------------------ Approach - 3 -------------------------
        // checking the and operation of current and previous value 
        // if it is coming out to be zero then it is definetly a power of 2
        // otherwise not

        return (n > 0) && ((n & (n-1)) == 0);
    }
};
