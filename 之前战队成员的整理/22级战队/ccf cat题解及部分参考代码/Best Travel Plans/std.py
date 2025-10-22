import heapq
import time


def calculate_max_activities(n, m, travel_times, initial_activities, activity_decreases):
    # Create a list of city activities and decreases only once
    cities = [(initial_activities[i], activity_decreases[i]) for i in range(n + 1)]
    max_activities = 0
    for i in range(1, n + 1):
        pq = []
        for j in range(1, i + 1):
            activities, decrease = cities[j]
            heapq.heappush(pq, (-activities, decrease))

        # print("size = ",len(pq))
        m -= travel_times[i-1]
        remaining_time = m
        cur_activities = 0
        while pq and remaining_time > 0:
            activities, decrease = heapq.heappop(pq)
            # print("activities = ",activities," decrease = ",decrease)
            cur_activities -= activities
            remaining_time -= 1
            activities += decrease
            if activities < 0:
                heapq.heappush(pq, (activities, decrease))
        # print("i = ",i," cur_activities = ",cur_activities)
        max_activities = max(max_activities, cur_activities)

    return max_activities





# start_time = time.time()

n, m = map(int, input().split())
travel_times = [0] + list(map(int, input().split()))
initial_activities = [0] + list(map(int, input().split()))
activity_decreases = [0] + list(map(int, input().split()))

max_activities = calculate_max_activities(n, m, travel_times, initial_activities, activity_decreases)
print(max_activities)
end_time = time.time()

# # 计算执行时间
# execution_time = end_time - start_time
# print(f"代码执行时间为: {execution_time} 秒")

