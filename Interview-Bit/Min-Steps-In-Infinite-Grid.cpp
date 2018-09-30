/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer array
 * @input n2 : Integer array's ( B ) length
 * 
 * @Output Integer
 */
 
 int max(int a,int b)
 {
     if(a>b) return a;
     return b;
 }
 
 int distance(int x,int y,int a,int b)
 {
     return max(abs(a-x),abs(b-y));
 }
 
int coverPoints(int* A, int n1, int* B, int n2) {
    
    int i,ans=0;
    for(i=1;i<n1;i++)
    {
        ans+=distance(A[i-1],B[i-1],A[i],B[i]);
    }
    return ans;
}
