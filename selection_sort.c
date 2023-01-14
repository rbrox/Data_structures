void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    
    int i = 0, j = 0;
    int tarr[m + n];
    
    for(int k = 0; k < m + n; ++k)
    {
        if (nums1[i] > nums2[j] || i == m )
        {
            tarr[k] = nums2[j];
            ++j;
        }
        
        else
        {
            tarr[k] = nums1[i];
            ++i;
        }
    }

    for (int i = 0; i < m + n; i++)
    {
        nums1[i] = tarr[i];
    }    
    return nums1;
}

void main()
{
    
}