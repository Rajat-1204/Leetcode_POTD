class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        vector<int> res = {-100000, 100000};
        int k = nums.size();
        int maxi = INT_MIN;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        for (int i = 0; i < k; i++)
        {
            int num = nums[i][0];
            vector<int> vec{num, 0, i};
            // 0th minimum element of list
            // 1st index of element from the vector
            // 2nd index of the vector
            // 1st <4,0,0> 2nd <0,0,1> 3rd <5,0,2>
            maxi = max(maxi, num); // took the max of members //5
            pq.push(vec);
            //<0,0,1><4,0,0><5,0,2>
        }
        while (true)
        {                                  // until condition breaks
            vector<int> minval = pq.top(); //<0,0,1>
            pq.pop();                      //<4,0,0><5,0,2>
            if (res[1] - res[0] > maxi - minval[0])
            {                       // 5-0=5
                res[0] = minval[0]; // res[0]=0
                res[1] = maxi;      // res[1]=5
            }
            minval[1]++; //<0,1,1>,now from which we poped element in queue that
                         // min element containing vector , we should choose
                         // another element
            vector<int> vec2 = nums[minval[2]]; // minval[2]=1,so <0,9,12,20>
            if (minval[1] == vec2.size())
            { // 1!=4
                break;
            }
            else
            {
                minval[0] = vec2[minval[1]];       // minival[0]=vec2[1]=9
                maxi = max(maxi, vec2[minval[1]]); // maxi=max(5,9)=9
                pq.push(minval);                   // push <9,1,1>
            }
        }
        return res;
    }
};