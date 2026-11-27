def attend(intervals: list[list[int]]) -> bool:
    intervals.sort(key=lambda i: i[0])  # Sort by first element

    for i in range(1, len(intervals)):
        # If previous meeting end is larger than curr meeting start
        if intervals[i - 1][1] > intervals[i][0]:
            return False  # We cannot attend both
    return True  # If we did not return False then we can attend all the meetings
