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

void JobSequencing(JobDetails *J, int n) {
  quickSort(J, 0, n - 1);
    int maxdeadline=0;
    for(int i=0;i<n;i++)
    {
        maxdeadline=max(maxdeadline,J[i].deadline);
    }
    int *slotarray =new int[maxdeadline]{0};
    int maxprofit=0;
    for(int i=0;i<n;i++){
    for(int j=min(maxdeadline,J[i].deadline)-1;j>=0;j--)
    {
        if(slotarray[j]==0)
        {
            slotarray[j]=J[i].id;
            maxprofit+=J[i].profit;
            break;
        }
    }
    }
    cout<<"sequence";
    for(int i=0;i<maxdeadline;i++)
    {
        cout<<slotarray[i]<<" "<<endl;
    }

    cout<<"profit"<<maxprofit<<endl;
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