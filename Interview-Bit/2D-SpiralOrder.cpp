/**
 * @input A : Read only ( DON'T MODIFY ) 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* spiralOrder(const int** A, int n11, int n12, int *len1) {
    
    int i,ansi=0;
    int* ans = (int*)malloc((n11*n12)*sizeof(int));
    *len1 = n11*n12;
        
    int left =0,right=n12-1,top=0,bottom=n11-1,dir=0;
    
    while(left<=right && top<=bottom)
    {
        if(dir==0)
        {
            for(i=left;i<=right;i++)
            ans[ansi++]=A[top][i];
            
            top++;
        }
        else if(dir==1)
        {
            for(i=top;i<=bottom;i++)
            ans[ansi++]=A[i][right];
            
            right--;
        }
        else if(dir==2)
        {
            for(i=right;i>=left;i--)
            ans[ansi++]=A[bottom][i];
            
            bottom--;
        }
        else
        {
            for(i=bottom;i>=top;i--)
            ans[ansi++]=A[i][left];
            
            left++;
        }
        
        dir = (dir+1)%4;
    }
    
        
    return ans;
    
}
