#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

void printLIS(int arr[], int pre[], int index)
{
    if (index == -1)
        return;

    printLIS(arr, pre, pre[index]);
    printf("%d ", arr[index]);
}

int lis(int arr[], int n)
{
    if (n == 0)
        return 0;
    else
    {
        int *len = (int *)malloc(n * sizeof(int));
        int *pre = (int *)malloc(n * sizeof(int));
        int maxLis = 1, lastIndex = -1;

        for (int i = 0; i < n; i++)
        {
            len[i] = 1;
            pre[i] = -1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i] && len[j] + 1 > len[i])
                {
                    len[i] = len[j] + 1;
                    pre[i] = j;
                    maxLis = max(maxLis, len[i]);
                }
            }
        }

        // Find the index of the last element of the LIS
        int current = -1;
        for (int i = 0; i < n; i++)
        {
            if (len[i] == maxLis)
            {
                current = i;
                break;
            }
        }

        printf("The Longest Increasing Subsequence is: ");
        printLIS(arr, pre, current);
        printf("\n");

        free(len);
        free(pre);
        return maxLis;
    }
}

int main()
{
    int input[] = {9, 2, 5, 3, 7, 11, 8, 10, 13, 6};
    int n = sizeof(input) / sizeof(int);

    int lisLength = lis(input, n);
    printf("The length of the LIS is %d\n", lisLength);

    return 0;
}
