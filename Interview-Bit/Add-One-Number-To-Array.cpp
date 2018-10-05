/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* plusOne(int* A, int n1, int *len1) {
    
    int* b =(int*)malloc(sizeof(int)*(n1+1));
    int carry = 1,i,j;
    for(i=0;i<n1+1;i++)
    b[i]=0;
    for(i=n1-1,j=n1;i>=0;i--,j--)
    {
        b[j]=(A[i]+carry)%10;
        carry=(A[i]+carry)/10;
    }
    
    if(carry!=0)
    b[j--]=1;
    
    for(j=0;b[j]==0 && j<n1+1;j++);
    
    *len1=n1+1-j;
    b=b+j;
    
    return b;
    
}
