#include <stdio.h>
int main() {
    int arrival[10], burst_time[10], burst_store[10], p[20], i, s, j, sum = 0, c = 0, time, pt[20], n, tat = 0, wt = 0, tat1 = 0, tat2 = 0;
    float avg = 0, t_tat = 0, t_wt = 0, avgwt = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the priority time:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pt[i]);
        p[i] = i;
    }
    printf("Enter the arrival time:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arrival[i]);
        p[i] = i;
    }
    printf("Enter the burst time:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &burst_time[i]);
        p[i] = i;
    }
    printf("\n");
    printf("Process \t Priority Time\t Arrival Time\t Burst Time\n");
    for (i = 0; i < n; i++) {
        printf("p %d \t\t %d\t\t %d\t\t %d\n", p[i], pt[i], arrival[i], burst_time[i]);
    }
    printf("\n");
    printf("\t\t\t\tGantt Chart\t\t\n");
    for (j = 1; j <= n; j++) {
        printf("____________________");
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        burst_store[i] = burst_time[i];
        pt[n] = 50;
    }
    for (time = 0; c != n; time++) {
        s = n;
        for (i = 0; i < n; i++) {
            if (arrival[i] <= time && burst_time[i] > 0 && pt[i] < pt[s]) {
                s = i;
            }
        }
        burst_time[s]--;
        printf("| P%d ", s + 1);

        if (burst_time[s] == 0) {
            c++;
        }
    }
    printf("|\n");
    for (j = 1; j <= n; j++) {
        printf("____________________");
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        sum = sum + burst_store[i];
    }
    for (i = 0; i <= sum; i++) {
        printf(" %d   ", i);
    }
    printf("\n");
    printf("Turnaround time:\n");
    for (i = 0; i < n; i++) {
        tat = tat + burst_store[i];
        tat1 = tat - arrival[i];
        printf("p %d = %d\n", p[i], tat1);
        t_tat = t_tat + tat1;
    }
    avg = t_tat / n;
    printf("\n");
    printf("Waiting time:\n");
    for (i = 0; i < n; i++) {
        tat2 = tat2 + burst_store[i];
        tat1 = tat2 - arrival[i];
        wt = tat1 - burst_store[i];
        printf("p %d = %d\n", p[i], wt);
        t_wt = t_wt + wt;
    }
    avgwt = t_wt / n;
    printf("Total turnaround time = %.2f\n", t_tat);
    printf("Average turnaround time = %.2f\n", avg);
    printf("Average waiting time = %.2f\n", avgwt);
    return 0;
}
