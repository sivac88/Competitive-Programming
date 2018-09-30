//DE SHAW Hiring Challenge - Hackerearth Link : https://www.hackerearth.com/problem/algorithm/the-travelling-ant-a41b1d73/description/
//Approach to solve : Matrix Exponentiation , Dynamic Programming
//Useful Resource links : 1) https://math.stackexchange.com/questions/2434064/proof-raising-adjacency-matrix-to-n-th-power-gives-n-length-walks-between
// 2) https://www.hackerearth.com/practice/notes/matrix-exponentiation-1/
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define ll long long int
#define MAX_N 10000001
#define mod 1000000007

/* int dp[5][MAX_N];
 * int visited[5][MAX_N];
 *
 * ll countNumberOfWays(int start,ll steps)
 * {
 *     if(steps < 0) return 0;
 *
 *     if(visited[start][steps])
 *         return dp[start][steps];
 *
 *     visited[start][steps] = 1;
 *
 *    if(steps==0)
 *    {
 *        if(start==0)
 *         dp[start][steps] = 1;
 *        else
 *         dp[start][steps] = 0;
 *
 *        return dp[start][steps];
 *    }
 *
 *     dp[start][steps] =  countNumberOfWays((start+1)%5,steps-1)+countNumberOfWays((start+4)%5,steps-1);
 *
 *     //printf("Start : %d , Steps : %lld ----> Ans : %ld\n",start,steps,dp[start][steps]);
 *     return dp[start][steps];
 *
 * }
 *
 * ll dp1[5][MAX_N];
 *
 * ll countNumberOfWays1(ll n)
 * {
 *     dp1[0][0] = 1;
 *     dp1[1][0] = 0;
 *     dp1[2][0] = 0;
 *     dp1[3][0] = 0;
 *     dp1[4][0] = 0;
 *
 *     for(int i=1;i<=n;i++)
 *         for(int j=0;j<5;j++)
 *             dp1[i][j] = dp1[i-1][(j+4)%5] + dp1[i-1][(j+1)%5];
 *
 *     return dp1[n][0];
 * }
 */

ll b[5][5] = {{0,1,0,0,1},
              {1,0,1,0,0},
              {0,1,0,1,0},
              {0,0,1,0,1},
              {1,0,0,1,0}};

void multiply(ll mat1[5][5],ll mat2[5][5])
{
    ll mat3[5][5];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
              mat3[i][j] = 0;
              for(int k=0;k<5;k++)
                mat3[i][j] += (mat1[i][k]*mat2[k][j])%mod;

              mat3[i][j]%=mod;
        }
    }

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
           mat1[i][j] = mat3[i][j];
}

 void exponent(ll mat[5][5],ll n)
 {
     if(n==0 || n==1) return;

     exponent(mat,n/2);
     multiply(mat,mat);

     if(n%2)
        multiply(mat,b);

 }


 ll countNumberOfWaysByMatrixExponentiation(ll n)
 {
     ll matrix[5][5] = {{0,1,0,0,1},
              {1,0,1,0,0},
              {0,1,0,1,0},
              {0,0,1,0,1},
              {1,0,0,1,0}};
     exponent(matrix,n);
     return matrix[0][0];
 }


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        //memset(visited,0,sizeof(visited[0][0])*2*MAX_N);
        //cout<<countNumberOfWays(0,n)<<endl;
        //cout<<countNumberOfWays1(n)<<endl;
        if(n==0)
            cout<<1<<endl;
        else
        cout<<countNumberOfWaysByMatrixExponentiation(n)<<endl;
    }
    return 0;
}
