/**
 * 判断一个单链表是否有环,如果有，找到环的入口点
 */
node* is_looplist(node* head){
	node *p1, *p2;
	p1 = p2 = head;
	if(head == NULL || head->next == NULL){
		return head;
	}
	//判断环是否存在
	while(p2->next && p2->next->next){
		p1 = p1->next;
		p2 = p2->next->next;
		if(p1==p2){
			break;
		}
	}
	if(p1!=p2) return NULL;

	p1 = head;
	while(p1 != p2){
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}