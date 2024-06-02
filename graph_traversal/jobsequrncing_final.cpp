#include <iostream>

using namespace std;

struct JobDetails {
public:
  int id;
  int profit;
  int deadline;
};

int partition(JobDetails J[], int lb, int ub) {
  int pivot=J[lb].profit;
  int start=lb;
  int end=ub;
  while(start<end)
  {
    while(J[start].profit>=pivot)
    {
        start++;
    }
    while(J[end].profit<pivot)
    {
        end--;
    }
    if(start<end)
    {
        swap(J[start],J[end]);
    }
  }
  swap(J[end],J[lb]);
  return end;
}

void quickSort(JobDetails J[], int lb, int ub) {
  if (lb < ub) {
    int pi = partition(J, lb, ub);
    quickSort(J, lb, pi - 1);
    quickSort(J, pi + 1, ub);
  }
}

void JobSequencing(JobDetails *jobDetails, int n) {
  quickSort(jobDetails, 0, n - 1);

  int maxDeadline = 0;
  for (int i = 0; i < n; i++) {
    maxDeadline = max(maxDeadline, jobDetails[i].deadline);
  }
  int *slotArray = new int[maxDeadline]{0};//for printing sequence

  int maxProfit = 0;
  for (int i = 0; i < n; i++) {//iterates through each job details
    for (int j = min(maxDeadline, jobDetails[i].deadline) - 1; j >= 0; j--) {//for the slot number 
      if (slotArray[j] == 0) {//checks if the slot is available
        slotArray[j] = jobDetails[i].id;
        maxProfit += jobDetails[i].profit;
        break;
      }
    }
  }

  cout << "The sequence of the job is as follows :: " << ' ' << endl;
  for (int i = 0; i < maxDeadline; i++) {
    if (slotArray[i] != 0) {
      cout << slotArray[i] << ' ';
    }
  }

  cout << "\nThe max profit for the given sequence is :: " << maxProfit << endl;

  delete[] slotArray;
}

int main(int argc, char *argv[]) {
  int n;
  cout << "Enter the number of jobs" << endl;
  cin >> n;
  JobDetails *J = new JobDetails[n];
  for (int i = 0; i < n; i++) 
  {
    J[i].id = i + 1; 
    int deadline, profit;
    cout << "Enter the deadline and profit of the job " << i + 1 << endl;
    cin >> J[i].deadline;
    cin >> J[i].profit;
  }
  JobSequencing(J, n);
  return 0;
}