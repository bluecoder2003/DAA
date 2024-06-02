#include <iostream>

using namespace std;

struct Knap
{
    int profit, weight;
    double ratio;
};

void initialise(Knap arr[], int n, int p[], int wt[])
{
    for (int i = 0; i < n; i++)
    {
        arr[i].profit = p[i];
        arr[i].weight = wt[i];
        arr[i].ratio = 1.0 * p[i] / wt[i];
    }
}

void display(Knap arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "(" << arr[i].profit << ", " << arr[i].weight << ") ";
    }
    cout << endl;
}

void sort(Knap arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j].ratio < arr[j + 1].ratio)
            {
                Knap temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void fractKnapsack(Knap arr[], int n, int w)
{
    double x[n] = {0};
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight > w)
        {
            x[i] = 1.0 * w / arr[i].weight;
            ans += x[i] * arr[i].profit;
            break;
        }
        else
        {
            x[i] = 1.0;
            ans += x[i] * arr[i].profit;
            w -= arr[i].weight;
        }
    }
    cout << "Total profit: " << ans << endl;
}

int main()
{
    int n, w;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight: ";
    cin >> w;

    Knap arr[n];
    int p[n], wt[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> p[i] >> wt[i];
    }

    initialise(arr, n, p, wt);
    display(arr, n);
    sort(arr, n);
    display(arr, n);
    fractKnapsack(arr, n, w);

    return 0;
}