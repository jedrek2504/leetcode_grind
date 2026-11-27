import heapq


def rooms(intervals: list[list[int]]) -> int:
    intervals.sort(key=lambda i: i[0])  # Sort the intervals by first value
    minHeap = []  # End times of the meetings that currently hold a room

    # Iterate through each interval
    for start, end in intervals:
        # If the earliest ending meeting is over before this one starts
        if minHeap and start >= minHeap[0]:
            heapq.heappop(minHeap)  # Its room is free, so reuse it
        # Otherwise every room is busy, so this meeting needs an additional room
        heapq.heappush(minHeap, end)  # Each iteration add endTime

    return len(minHeap)  # One heap entry per room
