#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(char str1[], char str2[])
{
    // length of the strings
    int x = strlen(str1);
    int y = strlen(str2);

    int table[x + 1][y + 1];
    int i, j;

    for (i = 0; i <= x; i++)
    {
        for (j = 0; j <= y; j++)
        {
            if (i == 0 || j == 0)
            {
                table[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                // Diagonal value + 1
                table[i][j] = 1 + table[i - 1][j - 1];
            }
            else
            {
                // max(Left, Top)
                table[i][j] = max(table[i][j - 1], table[i - 1][j]);
            }
        }
    }

    // Print the table
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            printf("%d  ", table[i][j]);
        }
        printf("\n");
    }

    // Printing process of the LCS
    int length = table[x][y]; // LCS length
    char ans[length];         // Array for storing LCS
    int index = length - 1;   // Taking last index of the array
    i = x, j = y;             // Taking max value for starting from the end

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            ans[index] = str1[i - 1];
            i--, j--, index--; // Decreasing i,j access the diagonal box
        }
        else if (table[i][j - 1] < table[i - 1][j]) // left < top
            i--;                                    // Decreasing only i to access the top box
        else
            j--; // Decreasing only j to access the left box
    }
    printf("The LCS is: %s\n", ans);

    return length;
}

int main()
{
    char X[] = "bcd"; // PROVIDENCE
    char Y[] = "bck"; // PRESIDENT

    printf("And the LCS length is: %d\n", lcs(X, Y));
    return 0;
}
