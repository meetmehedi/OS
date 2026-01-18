#include <stdio.h>

int main()
{
    int n, i;
    float bt[20], wt[20], tat[20], avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%f", &bt[i]);
    }

    // Waiting time for first process is 0
    wt[0] = 0;

    // Calculating waiting time for each process
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculating turnaround time for each process
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }

    // Calculating average waiting time and turnaround time
    for (i = 0; i < n; i++)
    {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;

    // Displaying results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}