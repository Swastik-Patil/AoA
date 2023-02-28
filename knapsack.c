#include <stdio.h>
int main()
{
    int maxWeight = 60;
    int weight[5] = {5, 10, 15, 22, 25};
    int value[5] = {30, 40, 45, 77, 90};
    float ratio[5];

    for (int i = 0; i < 5; i++)
    {
        ratio[i] = (float)value[i] / weight[i];
    }

    float temp1;
    int temp;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp1 = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp1;

                temp = value[i];
                value[i] = value[j];
                value[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }
    int w = maxWeight;
    int res = 0;

    for (int j = 0; j < 5; j++)
    {
        if (w > weight[j])
        {
            res += value[j];
            w -= weight[j];
        }
        else
        {
            res = res + ((w * value[j]) / weight[j]);
            w = 0;
        }
    }

    printf("%d", res);
    return 0;
}