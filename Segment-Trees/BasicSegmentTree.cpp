// This is the basic version of segment trees , where it updates a single element at a time ,and finds the minimum  in the givem range.
// Useful Resources : https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/
// https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
// Youtube Link : https://www.youtube.com/watch?v=CN0N1ddJ9hA&list=PLMCXHnjXnTnuASA1NghV3Vs9J3D_ij5w2
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;


int buildSegmentTreeUtil(int* a,int start,int end,int* segTree,int segIdx)
{
    if(start==end)
    {
        segTree[segIdx] = a[start];
        return segTree[segIdx];
    }

    int mid = start + (end-start)/2;

    segTree[segIdx] = min(buildSegmentTreeUtil(a,start,mid,segTree,2*segIdx + 1),
                          buildSegmentTreeUtil(a,mid+1,end,segTree,2*segIdx + 2));

    return segTree[segIdx];
}

int query(int* segTree,int s,int e,int x,int y,int segIdx)
{
     if(x>e || y<s) return INT_MAX;

     if(s>=x && e<=y) return segTree[segIdx];

     int mid = s + (e-s)/2;

     return min(query(segTree,s,mid,x,y,2*segIdx + 1),
                query(segTree,mid+1,e,x,y,2*segIdx + 2));

}

int update(int* segTree,int s,int e,int x,int y,int segIdx)
{
    if(x<s || x>e) return segTree[segIdx];

    if(s==e)
    {
        if(s==x)
            segTree[segIdx] = y;

        return segTree[segIdx];
    }

    int mid = s + (e-s)/2;

    segTree[segIdx] = min(update(segTree,s,mid,x,y,2*segIdx + 1),
                          update(segTree,mid+1,e,x,y,2*segIdx + 2));

    return segTree[segIdx];
}


int* buildSegmentTree(int* a,int n)
{
    int height = (int)ceil(log2(n));
    int nodes  = (1<<(height+1)) - 1;
    int* segTree = (int*)malloc(sizeof(int)*nodes);
    buildSegmentTreeUtil(a,0,n-1,segTree,0);
    return segTree;
}

int main()
{
    int n,q,x,y;
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
            cout<<query(segTree,0,n-1,x-1,y-1,0)<<endl;
        else
            update(segTree,0,n-1,x-1,y,0);
    }
    return 0;
}
