class Solution
{
public:
    long long minimumSteps(string s)
    {
        // We are using two pointer approach only
        int prev = 0;        // storing the starting index
        int i = 0;           // for traversing
        long long count = 0; // for count;
        int n = s.length();
        while (i < n)
        {
            // if(zero meets thenn we can increase the count by the index diff.)
            if (s[i] == '0')
            {
                count = count + (i - prev);
                prev++;
            }
            i++;
        }
        // returning count
        return count;
    }
};