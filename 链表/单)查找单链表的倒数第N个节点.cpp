/**
 * 查找单链表的倒数第N个节点
 * 设置两个指针，都指向单链表的头结点，让其中一个指针走n步，
 * 然后两个指针同时走，当前面的节点走到表尾，
 * 那么第二个节点所处的位置就是倒数第N个节点
 */
node* FindKnode(node *head, int N){
	int i = 0;
	node *tempNode = head;
	node *resNode = head;
	while(i < N && tempNode){
		tempNode = tempNode->next;
		i++;
	}
	if(i < N){
		return NULL;
	}
	while(tempNode->next){
		tempNode = tempNode->next;
		resNode = resNode->next;
	}
	return resNode;
}