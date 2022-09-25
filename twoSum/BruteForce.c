int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *output = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int i, j, compare;
    
    for(i = 0; i < numsSize; i++)
    {
        compare = target - nums[i];
        for(j = i+1; j < numsSize; j++)
        {
            if(compare == nums[j])
            {
                output[0] = i;
                output[1] = j;
                
                return output;
            }
        }
    }
    
    return NULL;
}
