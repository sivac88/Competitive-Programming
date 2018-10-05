//DESHAW HIRING CHALLENGE
//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/and-sum-54d31846/description/
//Useful Resources : https://www.geeksforgeeks.org/sum-bitwise-possible-subsets-given-set/
//https://stackoverflow.com/questions/16122512/what-happens-if-we-bitwise-shift-an-integer-more-than-its-size
//https://math.stackexchange.com/questions/546414/what-is-the-proof-that-the-total-number-of-subsets-of-a-set-is-2n
#include <iostream>
using namespace std;


#define mod 1000000007
#define ll long long int
#define BITS 64


ll powMod(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    
    ll res = powMod(a,b/2);
    res=(res%mod)*(res%mod);
    
    if(b%2)
    res*=a;
    
    return res%mod;
    
}

int main()
{
    int t,n,count;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long int a[n];
        for(int i=0;i<n;i++)
          cin>>a[i];
          
        long long int ans = 0,subsets,contribution;
          
        for(int i=0;i<BITS;i++)
        {
            count = 0;
            for(int j=0;j<n;j++)
                if(a[j]&(1ll<<i))
                 count++;
                 
           //cout<<"count:"<<count<<endl;
           if(count!=0)
           {
                subsets = (powMod(2,count) - 1)%mod;
                contribution = powMod(2,i)%mod;
                ans = (ans%mod + (subsets*contribution)%mod)%mod;
           }
        }
        
        cout<<ans<<endl;
    }
    return 0;
}