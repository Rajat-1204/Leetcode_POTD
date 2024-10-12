class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        // Sorting the Intervals
        sort(intervals.begin(), intervals.end());
        // Making a Min-Heap for tracking end times
        priority_queue<int, vector<int>, greater<int>> pq;

        // For loop for checking Overlaps
        for (const auto &interval : intervals)
        {
            int start = interval[0], end = interval[1];

            // checking for element coming start is greater than the end or not
            if (!pq.empty() && pq.top() < start)
            {
                pq.pop();
            }
            // if there's an overlap, we need to create a new group for this interval.
            // We add its end time to the heap.
            pq.push(end);
        }
        // Size is the answer
        return pq.size();
    }
};