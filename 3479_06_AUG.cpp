class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // intialize variables
        int n = fruits.size();
        int root = floor(sqrt(n)); // size of each block
        int numblock = (n + root - 1)/root; //total no. of blocks
        int ans = 0;
        vector<int> blockMax(numblock,0);

        // compute maximum value of each block of basket
        for(int i = 0;i<n;i++){
            int blockIndex = i/root;
            blockMax[blockIndex] = max(blockMax[blockIndex],baskets[i]);
        }

        // Trying to place fruits block wise
        for(int i = 0;i<n;i++){
            int fruit = fruits[i];
            int targetBlock = -1;

            // finding the first block the fruit will hold
            for(int j = 0;j<numblock;j++){
                if(blockMax[j] >= fruit){
                    targetBlock = j;
                    break;
                }
            }

            // if no target found then ans++
            if(targetBlock == -1){
                ans++;
                continue;
            }

            // scan within the block to find the basket 
            int start = targetBlock * root; //1*2 = 2
            int end = min(n,(targetBlock+1)*root);

            for(int j = start;j<end;j++){
                if(baskets[j] >= fruit){
                    baskets[j] = 0;
                    break;
                }
            }

            // recompute krenge maximum value for that block
            blockMax[targetBlock] = 0;
            for(int j = start;j<end;j++){
                blockMax[targetBlock] = max(blockMax[targetBlock],baskets[j]);
            }

        }
        // return ans 
        return ans;
    }
};
