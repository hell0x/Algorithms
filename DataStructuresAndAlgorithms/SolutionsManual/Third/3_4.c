List IntersectList(List L1, List L2){
	List L;
	Position P1, P2;
	P1 = L1->Next;
	P2 = L2->Next;
	L = malloc(sizeof(struct Node));
	if(L == NULL)
		printf("Out of memory\n"),exit(0);
	L->Next = NULL;
	while(P1 == NULL || P2 == NULL){
		if(P1->Element > P2->Element)
			P2 = P2->Next;
		else if(P1->Element < P2->Element)
			P1 = P1->Next;
		else{
			L->Next = P1;
			L = L->Next;
			P1 = P1->Next;
			P2 = P2->Next;
		}
	}
	return L;
}