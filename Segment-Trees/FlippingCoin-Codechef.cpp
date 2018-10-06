//Flipping Coin Codechef Problem : https://www.codechef.com/problems/FLIPCOIN/
//Successful subsmission : https://www.codechef.com/viewsolution/7274698 
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

int lazy[500010];
int segTree[500010];

int query(int s,int e,int x,int y,int segIdx)
{
     if(lazy[segIdx] != 0)
     {
         segTree[segIdx] = (e-s+1) - segTree[segIdx];
         if(s!=e)
         {
             lazy[2*segIdx + 1] ^= 1;
             lazy[2*segIdx + 2] ^= 1;
         }
         lazy[segIdx] = 0;
     }
     if(x>e || y<s) return 0;

     if(s>=x && e<=y) return segTree[segIdx];

     int mid = s + (e-s)/2;

     return query(s,mid,x,y,2*segIdx + 1) +
            query(mid+1,e,x,y,2*segIdx + 2);

}

int update(int s,int e,int x,int y,int segIdx)
{
    if(lazy[segIdx] != 0)
    {
      segTree[segIdx] = (e-s+1) - segTree[segIdx];
      if(s!=e)
      {
         lazy[2*segIdx + 1] ^= 1;
         lazy[2*segIdx + 2] ^= 1;
      }
      lazy[segIdx] = 0;
    }

    if(x>e || y<s) return segTree[segIdx];

    if(s>=x && e<=y)
    {
        segTree[segIdx] = (e-s+1) - segTree[segIdx];
        if(s!=e)
        {
            lazy[2*segIdx + 1] ^= 1;
            lazy[2*segIdx + 2] ^= 1;
        }
        return segTree[segIdx];
    }

    int mid = s + (e-s)/2;

    segTree[segIdx] = update(s,mid,x,y,2*segIdx + 1) +
                      update(mid+1,e,x,y,2*segIdx + 2);

    return segTree[segIdx];
}

int main()
{
    int n,q,x,y,ch;
    cin>>n>>q;
    while(q--)
    {
        cin>>ch>>x>>y;
        if(ch==1)
            cout<<query(0,n-1,x,y,0)<<endl;
        else
            update(0,n-1,x,y,0);
    }
    return 0;
}
