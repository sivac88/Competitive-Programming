/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* repeatedNumber(const int* A, int n1, int *len1) {
    
    *len1 = 2;
    int* b = (int*)malloc(sizeof(int)*2),i;
    long long int n=0,m=0;
    for(i=0;i<n1;i++)
    {
        n+=(i+1)-A[i];
        m+=(long long)(i+1)*(i+1) - (long long)A[i]*A[i];
    }
    
    b[1] = (int)(m/n + n)/2;
    b[0] = b[1] - (int)n;
    
    return b;
    
}
