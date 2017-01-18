node* is_looplist(node* head){
	node *p1, *p2;
	p1 = p2 = head;
	if(head == NULL || head->next == NULL){
		return head;
	}
	while(p2->next && p2->next->next){
		p1 = p1->next;
		p2 = p2->next->next;
		if(p1==p2){
			return 1;
		}
	}
	return 0;
}