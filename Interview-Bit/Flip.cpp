/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* flip(char* A, int *len1) {
    
    int* ans=(int*)malloc(sizeof(int)*2),i;
    int max=0,count_l=-1,max_l=-1,max_r=-1,count=0;
    for(i=0;A[i]!='\0';i++)
    {
        if(A[i]=='0'){
            if(count==0 && count_l==-1)
                count_l = i;
            count++;
        }
        else
        {
            if(count>0)
              count--;
            else
            count_l = -1;
        }
             
        if(count>max)
        {
            max = count;
            max_l = count_l;
            max_r = i;
        }
    }
   // printf("%d\n",max_r);
    if(max_r != -1){
    *len1 = 2;
    ans[0] = max_l+1;
    ans[1] = max_r+1;
    return ans;
    }
    
    *len1 = 0;
    return ans;
}
