typedef struct Node
{
    int key, val;
    struct Node *next;
}node;

typedef struct Table
{
    int size;
    struct Node **list;
}table;

table *createTable(int size)
{
    table *t = (table *)malloc(sizeof(table));
    int i;
    
    t->size = size;
    t->list = (node **)malloc(sizeof(node *) * size);
    
    for(i = 0; i < size; i++)
        t->list[i] = NULL;
    
    return t;
}

int hashCode(table *t, int key)
{
    if(key < 0)
        return -(key % t->size);
    
    return key % t->size;
}

void insert(table *t, int key, int val)
{
    int pos = hashCode(t, key);
    node *list = t->list[pos];
    node *newNode = (node *)malloc(sizeof(node));
    node *temp = list;
    
    while(temp)
    {
        if(temp->key == key)
        {
            temp->val = val;
            return;
        }
        temp = temp->next;
    }
    newNode->key = key;
    newNode->val = val;
    newNode->next = list;
    t->list[pos] = newNode;
}

int search(table *t, int key)
{
    int pos = hashCode(t, key);
    node *list = t->list[pos];
    node *temp = list;
    
    while(temp)
    {
        if(temp->key == key)
            return temp->val;
        temp = temp->next;
    }
    
    return -1;
}

int twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    table *t = createTable(numsSize);
    int i, com;
    int *result = (int *)malloc(sizeof(int) * 2);
    
    *returnSize = 2;
    
    for(i = 0; i < numsSize; i++)
        insert(t, nums[i], i);
    for(i = 0; i < numsSize; i++)
    {
        com = search(t, target - nums[i]);
        if(com != -1 && com != i)
        {
            result[0] = com;
            result[1] = i;
        }
    }
    free(t);
    
    return result;
}
