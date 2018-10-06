// GFG Link : https://www.geeksforgeeks.org/lazy-propagation-in-segment-tree/
/*  I/P format :
6 3
1 3 5 7 9 11
q 1 3
u 1 5 10
q 1 3
*/
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

int* lazy;

int buildSegmentTreeUtil(int* a,int start,int end,int* segTree,int segIdx)
{
    if(start==end)
    {
        segTree[segIdx] = a[start];
        return segTree[segIdx];
    }

    int mid = start + (end-start)/2;

    segTree[segIdx] = buildSegmentTreeUtil(a,start,mid,segTree,2*segIdx + 1) +
                      buildSegmentTreeUtil(a,mid+1,end,segTree,2*segIdx + 2);

    return segTree[segIdx];
}

int query(int* segTree,int s,int e,int x,int y,int segIdx)
{
     if(lazy[segIdx] != 0)
     {
         segTree[segIdx] += (e-s+1)*lazy[segIdx];
         if(s!=e)
         {
             lazy[2*segIdx + 1] += lazy[segIdx];
             lazy[2*segIdx + 2] += lazy[segIdx];
         }
         lazy[segIdx] = 0;
     }
     if(x>e || y<s) return 0;

     if(s>=x && e<=y) return segTree[segIdx];

     int mid = s + (e-s)/2;

     return query(segTree,s,mid,x,y,2*segIdx + 1) +
            query(segTree,mid+1,e,x,y,2*segIdx + 2);

}

int update(int* segTree,int s,int e,int x,int y,int z,int segIdx)
{
    if(lazy[segIdx] != 0)
    {
      segTree[segIdx] += (e-s+1)*lazy[segIdx];
      if(s!=e)
      {
         lazy[2*segIdx + 1] += lazy[segIdx];
         lazy[2*segIdx + 2] += lazy[segIdx];
      }
      lazy[segIdx] = 0;
    }

    if(x>e || y<s) return segTree[segIdx];

    if(s>=x && e<=y)
    {
        segTree[segIdx] += (e-s+1)*z;
        if(s!=e)
        {
            lazy[2*segIdx + 1] += z;
            lazy[2*segIdx + 2] += z;
        }
        return segTree[segIdx];
    }

    int mid = s + (e-s)/2;

    segTree[segIdx] = update(segTree,s,mid,x,y,z,2*segIdx + 1) +
                      update(segTree,mid+1,e,x,y,z,2*segIdx + 2);

    return segTree[segIdx];
}


int* buildSegmentTree(int* a,int n)
{
    int height = (int)ceil(log2(n));
    int nodes  = (1<<(height+1)) - 1;
    int* segTree = (int*)malloc(sizeof(int)*nodes);
    lazy = (int*)malloc(sizeof(int)*nodes);
    memset(lazy,0,sizeof(lazy)*nodes);
    buildSegmentTreeUtil(a,0,n-1,segTree,0);
    return segTree;
}

int main()
{
    int n,q,x,y,z;
    char ch;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int* segTree = buildSegmentTree(a,n);
    while(q--)
    {
        cin>>ch>>x>>y;
        if(ch=='q')
            cout<<query(segTree,0,n-1,x,y,0)<<endl;
        else
        {
            cin>>z;
            update(segTree,0,n-1,x,y,z,0);
        }
    }
    return 0;
}
