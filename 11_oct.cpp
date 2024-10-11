class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        //  Storing the arrival time of the target friend
        int t = times[targetFriend][0];
        int n = times.size();

        // Sorting the whole times array
        sort(times.begin(),times.end());
        
        // Priority Queue for storing the chair indexes in min heap
        priority_queue<int,vector<int>,greater<int>> pq_chair;
        
        // for loop for push indexes in min heap
        for(int i = 0;i<n;i++){
            pq_chair.push(i);
        }
        
        // THis priority queue is used for elements which are on the chairs 
        // {Departure time,chair index}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq_dep;

        for(auto i : times){
            int arr = i[0];
            int dep = i[1];

            // popping out the top element until the top element should be greater than arriving
            while(!pq_dep.empty() && pq_dep.top().first <= arr){
                pq_chair.push(pq_dep.top().second);
                pq_dep.pop();
            }

            // Acquiring the chair with the index pq_chair.top()
            int chair = pq_chair.top();
            pq_chair.pop();
            pq_dep.push({dep,chair});

            // if arriving time is equal to the target one then returning the index of chair
            if(arr == t){
                return chair;
            }
        }
        return -1;
    }
};