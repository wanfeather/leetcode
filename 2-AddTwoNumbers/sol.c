struct ListNode* make_node(int value)
{
    struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    node->val = value;
    node->next = NULL;
    
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *p, *output;
    int c, v1, v2, sum;
    
    p = output = make_node(0);
    c = 0;
    
    while(l1 != NULL || l2 != NULL || c != 0)
    {
        v1 = l1 ? l1->val:0;
        v2 = l2 ? l2->val:0;
        sum = c + v1 + v2;
        p->next = make_node(sum % 10);
        p = p->next;
        c = sum / 10;
        l1 = l1 ? l1->next:NULL;
        l2 = l2 ? l2->next:NULL;
    }
    
    return output->next;
}
