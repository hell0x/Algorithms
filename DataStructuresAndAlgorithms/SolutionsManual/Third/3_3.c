//单链表交换两个元素
void ExchangeLinkedList(List L, Position PosBefoP){
	Position P, PosAfteP;

	P = PosBefoP->Next;
	PosAfteP = P->Next;

	P->Next = PosAfteP->Next;
	PosAfteP->Next = P;
	PosBefoP->Next = PosAfteP;
}

//双链表交换两个元素
volid ExchangeDoubleLinkedList(List L, Position PosBefoP){
	Position P, PosAfteP;

	P = PosBefoP->Next;
	PosAfteP = P->Next;

	P->Next = PosAfteP->Next;
	P->Front = PosAfteP;
	PosAfteP->Next = P;
	PosAfteP->Front = PosBefoP;
	PosBefoP->Next = PosAfteP;
	PosAfteP->Next->Front = P;
}