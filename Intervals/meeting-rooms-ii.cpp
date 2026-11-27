int rooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }); // Sort the intervals by first value
    priority_queue<int, vector<int>, greater<int>> minHeap; // End times of the meetings that currently hold a room

    // Iterate through each interval
    for (const vector<int>& interval : intervals) {
        int start = interval[0];
        int end = interval[1];
        // If the earliest ending meeting is over before this one starts
        if (!minHeap.empty() && start >= minHeap.top()) {
            minHeap.pop(); // Its room is free, so reuse it
        }
        // Otherwise every room is busy, so this meeting needs an additional room
        minHeap.push(end); // Each iteration add endTime
    }

    return (int)minHeap.size(); // One heap entry per room
}
