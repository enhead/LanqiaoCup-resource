#include <iostream>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

struct City {
    int activities;
    int decrease;
    City(int a, int d) : activities(a), decrease(d) {}
    bool operator<(const City& other) const {
        return activities < other.activities;
    }
};

int calculateMaxActivities(int n, int m, vector<int>& travelTimes, vector<int>& initialActivities, vector<int>& activityDecreases) {
    // 全局优先队列，包含所有城市
    priority_queue<City> all_cities;

    // 枚举最后停留的位置城市i
    int maxActivities = 0;
    for (int i = 1; i <= n; i++) {
        // 复制全局队列的前i个元素
        all_cities.push(City(initialActivities[i], activityDecreases[i]));
        priority_queue<City> pq;
        priority_queue<City> temp(all_cities);
        for (int j = 1; j <= i; j++) {
            pq.push(temp.top());
            temp.pop();
        }
        // 计算剩余时间
        m = m - travelTimes[i - 1];
        int remainingTime = m;
        // 用优先队列维护前面i个城市可以停留一分钟可以体验的最多的旅行活动
        int curActivities = 0;
        while (!pq.empty() && remainingTime > 0) {
            City city = pq.top();
            pq.pop();
            // 每次从优先队列取出最大值，更新最大活动数量
            curActivities += city.activities;
            // 更新剩余时间
            remainingTime--;
            // 每次减去活动数量的减少值，再放回队列
            city.activities -= city.decrease;
            if (city.activities > 0) pq.push(city);
        }
        maxActivities = max(maxActivities,curActivities);
    }
    return maxActivities;
}

int main() {

//        auto start = chrono::high_resolution_clock::now();

        int n, m;
        cin >> n >> m;
        vector<int> travelTimes(n);
        for (int i = 1; i < n; i++) {
            cin >> travelTimes[i];
        }
        vector<int> initialActivities(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> initialActivities[i];
        }
        vector<int> activityDecreases(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> activityDecreases[i];
        }

        int maxActivities = calculateMaxActivities(n, m, travelTimes, initialActivities, activityDecreases);
        cout << maxActivities << endl;

//        // 获取当前时间点
//        auto end = chrono::high_resolution_clock::now();
//        // 计算时间差
//        chrono::duration<double> duration = end - start;
//
//        // 打印时间差（以秒为单位）
//        cout << "读入时间: " << duration.count() << " 秒" << endl;
//    }
    return 0;
}
