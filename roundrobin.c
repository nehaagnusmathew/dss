#include <stdio.h>

int main() {
    float wAvg = 0, tAvg = 0;
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bTime[n], wTime[n], tTime[n], remainingTime[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &bTime[i]);
        remainingTime[i] = bTime[i]; 
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    int time = 0, done;

    do {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                done = 0; 
                if (remainingTime[i] > quantum) {
                    time += quantum;
                    remainingTime[i] -= quantum;
                }
                else {
                    time += remainingTime[i];
                    wTime[i] = time - bTime[i]; 
                    remainingTime[i] = 0;
                }
            }
        }
    } while (!done);

    for (int i = 0; i < n; i++) {
        tTime[i] = bTime[i] + wTime[i];
        wAvg += wTime[i];
        tAvg += tTime[i];
    }

    printf("\nPROCESS ID\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (int i = 0; i < n; i++) {
        printf("\n P[%d]\t\t %d\t\t %d\t\t %d", i + 1, bTime[i], wTime[i], tTime[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f ms", wAvg / (float)n);
    printf("\nAverage Turnaround Time = %.2f ms\n", tAvg / (float)n);

    printf("\nGANTT CHART: \n");
    printf("\t ");
    for (int i = 0; i < n; i++) {
        printf("-------- ");
    }
    printf("\n\t|");
    for (int i = 0; i < n; i++) {
        printf("  P[%d]  |", i + 1);
    }
    printf("\n\t ");
    for (int i = 0; i < n; i++) {
        printf("-------- ");
    }

    printf("\n\t0");
    int temp = 0;
    for (int i = 0; i < n; i++) {
        temp += bTime[i];
        printf("\t%d", temp);
    }
    printf("\n");
}
