//ServiceNow Hiring Challenge 
//Hackerearth link : https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/fill-the-boxes-922504c8/description/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t,n,m,k,cap,weight;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        vector<pair<int,int> > capacities;
        for(int i=0;i<n;i++)
        {
            cin>>cap;
            capacities.push_back(make_pair(cap,cap+k));
            //cout<<capacities[i].first<<" "<<capacities[i].second<<endl;
        }
        vector<int> weights;
        for(int i=0;i<m;i++)
        {
            cin>>weight;
            weights.push_back(weight);
        }
        
        sort(capacities.begin(),capacities.end());
        sort(weights.begin(),weights.end());
        
        int ans = 0;
        
        for(int i=0,j=0;i<m;i++,j++)
        {
            while(j<n && capacities[j].second < weights[i])
            j++;
            
            //cout<<"a:"<<capacities[j].second<<endl;
            if(j==n)
            break;
            
            if(weights[i] >= capacities[j].first && capacities[j].second >= weights[i])
            ans++;
            else
            j--;
        }
        
        cout<<ans<<endl;
    }
}