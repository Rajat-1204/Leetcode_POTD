class Solution
{
public:
    int timeToMinutes(const string &tp)
    {
        int h = (tp[0] - '0') * 10 + (tp[1]);
        int m = (tp[3] - '0') * 10 + (tp[4]);
        return h * 60 + m;
    }
    int findMinDifference(vector<string> &timePoints)
    {
        int ans = INT_MAX;

        // Convert each time in "HH:MM" format to total minutes and add to the list
        vector<int> minutes;
        for (const string &time : timePoints)
        {
            minutes.push_back(timeToMinutes(time));
        }

        // Sort the list of minutes
        sort(minutes.begin(), minutes.end());

        // Calculate the minimum difference between adjacent time points
        for (int i = 1; i < minutes.size(); i++)
        {
            ans = min(ans, minutes[i] - minutes[i - 1]);
        }

        // Consider the wrap-around case between the last and the first time points
        ans = min(ans, 1440 + minutes[0] - minutes.back());

        return ans;
    }
};