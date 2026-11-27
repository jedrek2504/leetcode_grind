bool attend(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }); // Sort by first element

    for (int i = 1; i < (int)intervals.size(); i++) {
        // If previous meeting end is larger than curr meeting start
        if (intervals[i - 1][1] > intervals[i][0]) {
            return false; // We cannot attend both
        }
    }
    return true; // If we did not return false then we can attend all the meetings
}
