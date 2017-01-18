/**
 * 方法一
 * 使用三个指针遍历单链表，逐个进行反转
 */
node* TraverReverseList(node* head){
    node *p, *q, *r;
    if(head == NULL || head->next == NULL){
        return head;
    }
    p = head;
    q = head->next;
    while(q){
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head->next = NULL;
    head = p1;
    return head;
}

/**
 * 对于第2个节点到第N个节点，依次插入到第一个节点（head节点）之后，
 * 最后将第一个节点挪到表尾
 */
node* InsertReverseList(node* head){
    node *p, *q;
    p = head->next;
    while(p){
        q = p->next;
        p->next = q->next;
        q->next = head->next;
        head->next = q;
    }
    p->next = head;
    head = p->next->next;
    p->next->next = NULL;
    return head;
}