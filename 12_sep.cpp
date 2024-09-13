class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        unordered_map<char, int> m; // creating map for storing characters that are there in allowed for easy find functionality

        for (int i = 0; i < allowed.size(); i++)
        {
            m[allowed[i]] = 1;
        }

        int count = 0; // count variable for consistent strings
        int n = words.size();

        for (int i = 0; i < n; i++)
        {                 // for loop for traversing vector words
            int flag = 0; // flag variable for checking whether any character is missing or not
            for (char ch : words[i])
            { // traversing the string present in words
                if (m[ch] == 0)
                {
                    flag = 1; // if any character is missing then we should change the flag
                    break;
                }
            }
            if (flag == 0)
            { // if there is all character present then we will increase the count
                count++;
            }
        }
        return count; // returning count
    }
};