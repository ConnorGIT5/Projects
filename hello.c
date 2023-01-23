#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NEGATIVES 100

double calculateMean(int numbers[], int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += numbers[i];
    }
    return (double)sum / length;
}

double calculateMedian(int numbers[], int length)
{
    // sort the array
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (numbers[i] > numbers[j])
            {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    if (length % 2 == 0)
    {
        return (double)(numbers[length / 2] + numbers[length / 2 - 1]) / 2;
    }
    else
    {
        return (double)numbers[length / 2];
    }
}

double calculateMode(int numbers[], int length)
{
    int maxCount = 0;
    int mode = numbers[0];
    for (int i = 0; i < length; i++)
    {
        int count = 0;
        for (int j = 0; j < length; j++)
        {
            if (numbers[j] == numbers[i])
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
            mode = numbers[i];
        }
    }
    return mode;
}

int main()
{
    int negatives[MAX_NEGATIVES];
    int negative_count = 0;
    int i;
    char input[10];
    while (1)
    {
        printf("Please enter a negative number: ");
        if (scanf("%d", &i) != 1)
        {
            printf("Invalid input. Please enter a negative number.\n");
            scanf("%*s"); // clear the input buffer
            continue;
        }
        if (i >= 0)
        {
            printf("Positive number entered. Exiting program.\n");
            break;
        }
        negatives[negative_count++] = i;
        printf("You entered: %d\n", i);
    }
    printf("Enter 'list' to see a list of all the collected negative integers: ");
    scanf("%s", input);
    if (strcmp(input, "list") == 0)
    {
        printf("Negative numbers entered: \n");
        for (int j = 0; j < negative_count; j++)
        {
            printf("%d\n", negatives[j]);
        }
        while (1)
        {
            printf("Enter 'mean', 'med' or 'mode' to calculate the mean, median, or mode respectively of the negative numbers entered or enter 'q' to quit: ");
            scanf("%s", input);
            if (strcmp(input, "mean") == 0)
            {
                printf("Mean: %lf\n", calculateMean(negatives, negative_count));
            }
            else if (strcmp(input, "med") == 0)
            {
                printf("Median: %lf\n", calculateMedian(negatives, negative_count));
            }
            else if (strcmp(input, "mode") == 0)
            {
                printf("Mode: %lf\n", calculateMode(negatives, negative_count));
            }
            else if (strcmp(input, "q") == 0)
            {
                printf("Exiting program\n");
                break;
            }
            else
            {
                printf("Invalid input.\n");
            }
        }
    }
    return 0;
}