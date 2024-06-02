#include <iostream>

using namespace std;

class JobDetails {
public:
  int id;
  int deadline;
  int profit;
};

int partition(JobDetails jobs[], int low, int high) {
  JobDetails pivot = jobs[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (jobs[j].profit > pivot.profit) {
      i++;
      swap(jobs[i], jobs[j]);
    }
  }
  swap(jobs[i + 1], jobs[high]);
  return (i + 1);
}

void quickSort(JobDetails jobs[], int low, int high) {
  if (low < high) {
    int pi = partition(jobs, low, high);
    quickSort(jobs, low, pi - 1);
    quickSort(jobs, pi + 1, high);
  }
}

void JobSequencing(JobDetails *jobDetails, int n) {
  quickSort(jobDetails, 0, n - 1);

  int maxDeadline = 0;
  for (int i = 0; i < n; i++) {
    maxDeadline = max(maxDeadline, jobDetails[i].deadline);
  }
  int *slotArray = new int[maxDeadline]{0};

  int maxProfit = 0;
  for (int i = 0; i < n; i++) {
    for (int j = min(maxDeadline, jobDetails[i].deadline) - 1; j >= 0; j--) {
      if (slotArray[j] == 0) {
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
  JobDetails *jobs = new JobDetails[n];
  for (int i = 0; i < n; i++) {
    int deadline, profit;
    cout << "Enter the deadline of the job " << i + 1 << endl;
    cin >> deadline;
    cout << "Enter the profit of the job " << i + 1 << endl;
    cin >> profit;
    jobs[i].id = i + 1;
    jobs[i].deadline = deadline;
    jobs[i].profit = profit;
  }

  JobSequencing(jobs, n);

  delete[] jobs;
  return 0;
}