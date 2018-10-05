/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
 
 int max(int a,int b)
 {
     if(a>b) return a;
     return b;
 }
 
int maxSubArray(const int* A, int n1) {
    
    if(n1==0) return 0;
    
    int ans = A[0],i,final_ans=ans;
    
    for(i=1;i<n1;i++)
    {
        if(A[i]+ans > A[i])
        {
            ans = A[i]+ans;
        }
        else
        {
            ans = A[i];
        }
        final_ans=max(final_ans,ans);
    }
    final_ans=max(final_ans,ans);
    return final_ans;
    
}
