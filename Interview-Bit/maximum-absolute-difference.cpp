/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
/*int maxArr(int* a, int n1) {
    
    int ans=0,i,j;
    for(i=0;i<n1;i++)
    {
        for(j=i+1;j<n1;j++)
        {
            if(abs(a[i]-a[j])+(j-i) > ans)
            ans = abs(a[i]-a[j])+(j-i);
        }
    }
    
    return ans;
}
*/

int maxArr(int* a, int n) {
    
    if(n<=1) return 0;
    
    int min=a[0],max=a[0],ans=0,i;
    
    for(i=1;i<n;i++)
    {
        min--;
        max++;
        
        if(max-a[i] > ans)a
          ans = max-a[i];
        else if(a[i]-min > ans)
         ans = a[i]-min;
        
        if(a[i]<min)
          min = a[i];
         
        if(a[i]>max)
          max = a[i];
    }
    
    return ans;
}

