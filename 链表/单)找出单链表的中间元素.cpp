/**
 * 定义两个指针，一个指针
 */
node* FindMiddleList(node* head){
	node *p1, *p2;
	p1 = p2 = head;
	if(head == NULL || head->next == NULL)
		return head;
	while(1){
		if(p2->next && p2->next->next){
			p2 = p2->next->next;
			p1 = p1->next;
		}else{
			break;
		}
	}
	return p1;
}