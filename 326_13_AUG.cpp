class Solution {
public:
    bool isPowerOfThree(int n) {
        /// ************** Approach 1 - Iterative division **********************

        // edge case when n is less than or equal to 0  -> return false
        if(n <= 0){
            return false;
        }

        // traverse using while loop continously divide krenge n ko 3 se jbb tkk remainder 0 aaarha hooga
        while(n % 3 == 0){
            n = n/3;
        }

        // return true if at last n is equal to 1
        return (n==1);



        // ************** Approach 2 - Without loop **********************
        // find krenge maximum power aur uske coresponding value
        int e = log(INT_MAX)/log(3);
        int N = pow(3,e);

        // return true krenge jbbb n > 0 aur 
        // saath hi saath value ka n se remainder krane k baad 0 aaya toh (N % n == 0)

        return ((n > 0) && (N % n == 0));
    }
};
