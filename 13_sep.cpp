class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> ans; // for storing answer

        for (int i = 1; i < arr.size(); i++)
        {
            arr[i] = arr[i] ^ arr[i - 1]; // calculating XOR for the value of arr from 0 to i th index for every i index from 1 -> n-1
        }

        for (int i = 0; i < queries.size(); i++)
        { // this for loop is used for traversing the queries vector
            int s = queries[i][0];
            int e = queries[i][1];

            if (s == 0)
            { //  if s is already zero then the value we already calculated from the above for loop is the answer
                ans.push_back(arr[e]);
            }

            else
            { // otherwiise we have to reduce it using the property of XOR
                ans.push_back(arr[s - 1] ^ arr[e]);
            }
        }
        return ans;
    }
};