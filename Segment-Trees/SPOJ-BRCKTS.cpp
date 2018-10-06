//Problem statement : https://www.spoj.com/problems/BRCKTS/
// Selected problems on segment trees : http://letuskode.blogspot.com/2013/01/segtrees.html
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct segNode
{
    int open;
    int closed;
};

typedef struct segNode segNode;

segNode segTree[10000001];

void merge(int segIdx)
{
    int match = min(segTree[2*segIdx + 1].open,segTree[2*segIdx + 2].closed);
    segTree[segIdx].open = segTree[2*segIdx + 1].open + segTree[2*segIdx + 2].open - match;
    segTree[segIdx].closed = segTree[2*segIdx + 1].closed + segTree[2*segIdx + 2].closed - match;
}

void buildSegmentTreeUtil(char* a,int start,int end,int segIdx)
{
    if(start==end)
    {
        if(a[start] == '(')
        {
           segTree[segIdx].open = 1;
           segTree[segIdx].closed = 0;
        }
        else
        {
           segTree[segIdx].open = 0;
           segTree[segIdx].closed = 1;
        }
        return;
    }

    int mid = start + (end-start)/2;

    buildSegmentTreeUtil(a,start,mid,2*segIdx + 1);
    buildSegmentTreeUtil(a,mid+1,end,2*segIdx + 2);

    merge(segIdx);
}

void update(int s,int e,int x,int segIdx)
{
    if(x<s || x>e) return;

    if(s==e)
    {
        if(s==x)
        {
            if(segTree[segIdx].open == 1){
                segTree[segIdx].open = 0;
                segTree[segIdx].closed = 1;
            }
            else
            {
                segTree[segIdx].open = 1;
                segTree[segIdx].closed = 0;
            }
        }
        return;
    }

    int mid = s + (e-s)/2;

    update(s,mid,x,2*segIdx + 1);
    update(mid+1,e,x,2*segIdx + 2);

    merge(segIdx);
}

int main()
{
    int n,q,w,i=1;
    while(scanf("%d",&n) == 1)
    {
    	scanf("%d", &n);
        char str[n+1];
        scanf("%s\n",str);
        scanf("%d",&q);
        printf("Test %d:\n",i++);
        buildSegmentTreeUtil(str,0,n-1,0);
        while(q--)
        {
            scanf("%d",&w);
            if(w!=0)
            update(0,n-1,w-1,0);
            else
            {
                if(segTree[0].open == 0 && segTree[0].closed == 0)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }
    return 0;
}