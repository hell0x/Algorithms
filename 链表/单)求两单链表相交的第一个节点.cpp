/**
 * 求两个单链表相交相交的第一个节点
 * 两个单链表相交，相交的长度一定相等
 * 设两个单链表长度的差值为x, p1和p2指向两个单链表的头
 * 则较长的单链表链表指针向后移动x后，p1和p2再一同移动，
 * 当p1=p2时，相遇点即为第一个公共交点
 */
Node* GetIntersectNode(Node *p1, Node *p2){
	int i=0;
	len1 = GetLength(p1);
	len2 = GetLength(p2);
	if(len1 > len2){
		while(i < (len1-len2))
			p1 = p1->next;
	}else{
		while(i < (len2-len1))
			p2 = p2->next;
	}
	while(p1){
		if(p1 == p2)
			return p1;
		p1 = p1->next;
		p2 = p2->next;
	}
	return NULL;
}

int GetLength(Node *head){
	int i;
	while(head->next){
		i++;
		head = head->next;
	}
	return i;
}