#include <stdio.h>

struct process
{
    char pid[10];
    int at, bt, pr;
    int ct, wt, tat;
    int done;
};

int main()
{
    int n, i, time = 0, completed = 0, idx;
    float avg_wt = 0, avg_tat = 0;
    struct process p[20];

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", p[i].pid, &p[i].at, &p[i].bt, &p[i].pr);
        p[i].done = 0;
    }

    while(completed != n)
    {
        idx = -1;
        for(i = 0; i < n; i++)
        {
            if(p[i].done == 0 && p[i].at <= time)
            {
                if(idx == -1 || p[i].pr < p[idx].pr)
                    idx = i;
            }
        }

        if(idx == -1)
        {
            time++;
            continue;
        }

        time += p[idx].bt;
        p[idx].ct  = time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt  = p[idx].tat - p[idx].bt;
        p[idx].done = 1;

        avg_wt  += p[idx].wt;
        avg_tat += p[idx].tat;
        completed++;
    }

    printf("Waiting Time: ");
    for(i = 0; i < n; i++)
        printf("%s %d ", p[i].pid, p[i].wt);

    printf("\nTurnaround Time: ");
    for(i = 0; i < n; i++)
        printf("%s %d ", p[i].pid, p[i].tat);

    printf("\nAverage Waiting Time: %.2f\n", avg_wt / n);
    printf("Average Turnaround Time: %.2f\n", avg_tat / n);

    return 0;
}