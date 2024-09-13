class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int count = 0; // count variable for storing the minimum number of flips needed
        while (goal != 0 && start != 0)
        { // traversing the numbers until one of them is zero
            if ((goal & 1) != (start & 1))
            { // if their bit is different then we should increase the count
                count++;
            }
            goal = goal >> 1;
            start = start >> 1;
        }

        while (goal != 0)
        { // checking for the remaining left number
            if (goal & 1)
            { // if there is a bit whose value is one needs to be flipped
                count++;
            }
            goal = goal >> 1;
        }
        while (start != 0)
        { // Same here
            if (start & 1)
            {
                count++;
            }
            start = start >> 1;
        }
        return count; // returning the answer
    }
};