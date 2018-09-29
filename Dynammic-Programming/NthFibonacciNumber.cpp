// Dynamic programming approach to find the nth fibonacci number.
// https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
// Explanation Video : https://www.youtube.com/watch?v=EEb6JP3NXBI

#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void multiply(int a[2][2],int b[2][2])
{
    int x = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    int y = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    int z = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    int w = a[1][0]*b[0][1] + a[1][1]*b[1][1];

    a[0][0] = x;
    a[0][1] = y;
    a[1][0] = z;
    a[1][1] = w;
}

void power(int f[2][2],int n)
{
    if(n==0 || n==1) return ;

    power(f,n/2);
    multiply(f,f);

    int b[2][2];
    b[0][0] = 1;
    b[0][1] = 1;
    b[1][0] = 1;
    b[1][1] = 0;

    if(n%2)
        multiply(f,b);
}

int getNthFibonacciDP(int n)
{
    int f[2][2];
    f[0][0] = 1;
    f[0][1] = 1;
    f[1][0] = 1;
    f[1][1] = 0;

    power(f,n-1);

    return f[0][0];

 }

 #define MAX_N 1000

 long int fib[MAX_N];

 long int fibonacci(int n)
 {
       if(fib[n] != -1) return fib[n];

       if(n==0 || n==1)
       {
           fib[n] = n;
           return fib[n];
       }

       int k = (n%2) ? (n+1)/2 : n/2;

       if(n%2)
        fib[n] = fibonacci(k)*fibonacci(k) + fibonacci(k-1)*fibonacci(k-1);
       else
        fib[n] = (2*fibonacci(k-1)+fibonacci(k))*fibonacci(k);

       return fib[n];
 }

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        memset(fib,-1,sizeof(fib));
        cin>>n;
        cout<<fibonacci(n)<<endl;
    }

}
