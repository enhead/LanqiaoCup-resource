#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct City {
    int activities;
    int decrease;
} City;

typedef struct HeapStruct {
    int capacity;
    int size;
    City *cities;
} PriorityQueue;

PriorityQueue *init_PQ(int maxEleNum) {
    PriorityQueue *pq = NULL;
    if(maxEleNum <= 0 )
        return NULL;
    pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    if(NULL == pq) {
        printf("malloc failed\n");
        return NULL;
    }

    pq->cities = (City *)malloc((maxEleNum + 1)*sizeof(City));
    if(NULL == pq->cities) {
        printf("malloc failed\n");
        free(pq);
        return NULL;
    }

    memset(pq->cities, 0, (maxEleNum + 1)*sizeof(City));
    pq->capacity = maxEleNum;
    pq->size = 0;
    return pq;
}

int pq_is_full(PriorityQueue *pq) {
    if(NULL == pq)
        return 0;
    if(pq->capacity == pq->size)
        return 1;
    else
        return 0;
}

int pq_is_empty(PriorityQueue *pq) {
    if(NULL == pq)
        return 0;
    if(0 == pq->size)
        return 1;
    else
        return 0;
}

int insert_pq(City value, PriorityQueue *pq) {
    int i;

    if(pq_is_full(pq)) {
        printf("priorityQueue is full\n");
        return 1;
    }

    for(i = pq->size+1; pq->cities[i/2].activities < value.activities && i > 1; i /= 2) {
        pq->cities[i] = pq->cities[i/2];
    }

    pq->cities[i] = value;
    pq->size++;
    return 0;
}

int delete_max(PriorityQueue *pq, City *max) {
    int i;
    int maxChild;
    if(pq_is_empty(pq)) {
        printf("priorityqueue is empty\n");
        return 1;
    }

    *max = pq->cities[1];

    City last = pq->cities[pq->size];
    pq->size--;

    for(i = 1; i * 2 <= pq->size; i = maxChild) {
        maxChild = i * 2;
        if(maxChild != pq->size && pq->cities[maxChild+1].activities > pq->cities[maxChild].activities)
            maxChild += 1;
        if(last.activities < pq->cities[maxChild].activities)
            pq->cities[i] = pq->cities[maxChild];
        else
            break;
    }

    pq->cities[i] = last;
    return 0;
}

int destroy_pq(PriorityQueue *pq) {
    if(NULL == pq) {
        return 1;
    }
    free(pq->cities);
    pq->cities = NULL;
    free(pq);
    pq = NULL;
//    printf("destroy pq success\n");
    return 0;
}

int calculateMaxActivities(int n, int m, int* travelTimes, int* initialActivities, int* activityDecreases) {
    PriorityQueue* all_cities = init_PQ(n);
    int maxActivities = 0;
//    printf("m = %d\n",m);
    for (int i = 1; i <= n; i++) {
        City city;
        city.activities = initialActivities[i];
        city.decrease = activityDecreases[i];
        insert_pq(city, all_cities);

        PriorityQueue* temp = init_PQ(i + 1);
        for (int j = 0; j < i; j++) {
            temp->cities[j + 1] = all_cities->cities[j + 1];
//            printf("!!! %d %d\n",temp->cities[j+1].activities,temp->cities[j+1].decrease);
            temp->size++;
        }

        m = m - travelTimes[i-1];
        int remainingTime = m;
        int curActivities = 0;
//        printf("i = %d %d %d\n",i,temp->size,remainingTime);
        while (!pq_is_empty(temp) && remainingTime > 0) {
            City city;
            delete_max(temp, &city);
//            printf("act = %d de = %d\n",city.activities,city.decrease);
            curActivities += city.activities;
            remainingTime--;
            city.activities -= city.decrease;
            if (city.activities > 0) insert_pq(city, temp);
        }

        maxActivities = maxActivities > curActivities ? maxActivities : curActivities;
        destroy_pq(temp);
    }

    destroy_pq(all_cities);
    return maxActivities;
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    int* travelTimes = (int*)malloc(n * sizeof(int));
    int* initialActivities = (int*)malloc((n + 1) * sizeof(int));
    int* activityDecreases = (int*)malloc((n + 1) * sizeof(int));

    for (int i = 1; i < n; i++) {
        scanf("%d", &travelTimes[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &initialActivities[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &activityDecreases[i]);
    }

    int maxActivities = calculateMaxActivities(n, m, travelTimes, initialActivities, activityDecreases);
    printf("%d\n", maxActivities);

    free(travelTimes);
    free(initialActivities);
    free(activityDecreases);

    return 0;
}
