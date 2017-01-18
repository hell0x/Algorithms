double cmp(ListNode *p ,ListNode *q)
{return (p->keyVal - q->keyVal);}

ListNode* mergeSortList(ListNode *head)
{
    ListNode *p, *q, *tail, *e;
    int nstep = 1;
    int nmerges = 0;
    int i;
    int psize, qsize;
    if (head == NULL || head->next == NULL)
    {return head;}
    while (1)
    {   p = head;
        tail = NULL;
        nmerges = 0;
        while (p)
        {   nmerges++;  q = p;  psize = 0;
            for (i = 0; i < nstep; i++){
                psize++;
                q = q->next;
                if (q == NULL)break;
}
             qsize = nstep;
            while (psize >0 || (qsize >0 && q))
{
                if (psize == 0 ){e = q; q = q->next; qsize--;}
                elseif (q == NULL || qsize == 0){e = p; p = p->next; psize--;}
                elseif (cmp(p,q) <= 0){e = p; p = p->next; psize--;}
                else{e = q; q = q->next; qsize--;}
                if (tail != NULL){tail->next = e;}
                else{head = e;}
                tail = e;
              }
            p = q;
        }
        tail->next = NULL;
        if (nmerges <= 1){return head;}
        else{nstep <<= 1;}
    }
}