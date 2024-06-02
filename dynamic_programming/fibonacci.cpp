#include<iostream>
using namespace std;

int fib(int n)
{
    int f[n];
    f[0]=0;
    f[1]=1;
    for(int i=2;i<n;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    return f[n-1]; //Since array indexing in C++ starts from 0, the nth Fibonacci number is actually stored at the (n-1)th index of the array f.
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci number at position " << n << " is " << fib(n) << endl;
    return 0;
}