//CodeForces Problem : http://codeforces.com/contest/166/problem/E
//Tutorial : https://www.youtube.com/watch?v=TTtOpv6Hrcg&list=PLfBJlB6T2eOtMXgK3FLUTawHjzpIEySHF&index=3
//My accepted submissions : http://codeforces.com/contest/166/submission/43600337 , http://codeforces.com/contest/166/submission/43599048
#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long int
#define MAX_STEPS 10000002

/* ll countNumberOfWays(int src,int dest,int steps)
 * {
 *     if(steps==0)
 *     {
 *         if(src==dest)
 *             return 1;
 *         return 0;
 *     }
 *     ll ans = 0;
 *     for(int i=0;i<=3;i++)
 *     {
 *         if(i==src) continue;
 *         ans+=countNumberOfWays(i,dest,steps-1);
 *         ans%=mod;
 *     }
 *     return ans%mod;
 * }
 *
 * int dp[4][4][MAX_STEPS];
 * int visited[4][4][MAX_STEPS];
 *
 * int countNumberOfWaysDP(int src,int dest,int steps)
 * {
 *     if(visited[src][dest][steps])
 *         return dp[src][dest][steps];
 *
 *     visited[src][dest][steps] = 1;
 *
 *     if(steps==0)
 *     {
 *         if(src==dest)
 *             dp[src][dest][steps] = 1;
 *         else
 *             dp[src][dest][steps] = 0;
 *         return dp[src][dest][steps];
 *     }
 *
 *     ll ans = 0;
 *     for(int i=0;i<=3;i++)
 *     {
 *         if(i==src) continue;
 *         ans+=countNumberOfWaysDP(i,dest,steps-1);
 *         ans%=mod;
 *     }
 *
 *     dp[src][dest][steps] = ans%mod;
 *
 *     return dp[src][dest][steps];
 *
 * }
 *
 * int dp1[4][MAX_STEPS];
 * int visited1[4][MAX_STEPS];
 *
 * int countNumberOfWaysDP1(int src,int steps)
 * {
 *     if(visited1[src][steps])
 *         return dp1[src][steps];
 *
 *     visited1[src][steps] = 1;
 *
 *     if(steps==0)
 *     {
 *         if(src==3)
 *             dp1[src][steps] = 1;
 *         else
 *             dp1[src][steps] = 0;
 *         return dp1[src][steps];
 *     }
 *
 *     ll ans = 0;
 *     for(int i=0;i<=3;i++)
 *     {
 *         if(i==src) continue;
 *         ans+=countNumberOfWaysDP1(i,steps-1);
 *         ans%=mod;
 *     }
 *
 *     dp1[src][steps] = ans%mod;
 *
 *     return dp1[src][steps];
 * }
 */

/*ll dp2[2][MAX_STEPS];

ll countNumberOfWaysDP2(ll steps)
{

   dp2[0][0] = 0;
   dp2[1][0] = 1;

   for(ll i=1;i<=steps;i++)
   {
       dp2[0][i] = (2*dp2[0][i-1] + dp2[1][i-1])%mod;
       dp2[1][i] = (3*dp2[0][i-1])%mod;
   }

   return dp2[1][steps];

}*/

void multiply(ll mat1[2][2],ll mat2[2][2])
{
    ll x = (mat1[0][0]*mat2[0][0] + mat1[0][1]*mat2[1][0])%mod;
    ll y = (mat1[0][0]*mat2[0][1] + mat1[0][1]*mat2[1][1])%mod;
    ll z = (mat1[1][0]*mat2[0][0] + mat1[1][1]*mat2[1][0])%mod;
    ll t = (mat1[1][0]*mat2[0][1] + mat1[1][1]*mat2[1][1])%mod;

    mat1[0][0] = x;
    mat1[0][1] = y;
    mat1[1][0] = z;
    mat1[1][1] = t;

}

void matrixExponentiation(ll mat[2][2],int n)
{
    if(n==0 || n==1) return;

    matrixExponentiation(mat,n/2);
    multiply(mat,mat);

    ll b[2][2] = {{2,1},{3,0}};

    if(n%2)
        multiply(mat,b);
}

ll getAnswer(ll n)
{
    int src  = 3;
    int dest = 3;
    ll steps = n;

    //return countNumberOfWaysDP(src,dest,steps);
    //return countNumberOfWaysDP1(src,steps);
    //return countNumberOfWaysDP2(steps);
    ll mat[2][2] ={{2,1},{3,0}};
    matrixExponentiation(mat,steps);

    return mat[1][1];

}

int main()
{
    ll n;
    cin>>n;
    cout<<getAnswer(n)<<endl;
}
