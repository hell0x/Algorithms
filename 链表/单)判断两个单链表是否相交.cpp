/**
 * 判断两个单链表是否相交
 * 如果两个单链表相交，则它们的尾节点一定相等
 */
bool isIntersect(Node *p1, Node *p2){
	if(p1==NULL || p2==NULL)
		return FALSE;
	while(p1->next){
		p1 = p1->next;
	}
	while(p2->next){
		p2 = p2->next;
	}
	if(p1 == p2)
		return TRUE;
	else
		return FALSE;
}