/*Q1R*/

/*LLLL*/

// LL/P/wk2/q1 insert and remove char in the fixed length

void removes(char *s, int n)
{

	for (int i = 0;i < n; i++) {
            *(s+i)=*(s+i+1);
	}

	printf("Resulting string:%s\n", s);

}

void insert(char *s, int n) {

    char c;
    printf("What is the character you want to insert:");
    scanf(" %c", &c);

    for (int i = n; i > 0; i--) {
        *(s+i)=*(s+i-1);
    }

    s[0] = c;
    s[n] = '\0';

    printf("Resulting string: %s\n", s);

}

// LL/P/wk2/q2 build until -1
// LL/P/wk2/q3 find value and return the index
// LL/P/wk2/q4 free up memory with temp pointer

void main()
{

	ListNode *head, *p, *temp;
	int n;

	head=NULL;
	p=NULL;
	printf("Enter a list of numbers, terminated by the value -1:\n");

	scanf("%d", &n);

	while (n!=-1)
	{
		if (head==NULL)
		{
			head=(ListNode *)malloc(sizeof(ListNode));
			p=head;
		}
		else
		{
			p->next=(ListNode *)malloc(sizeof(ListNode));
			p=p->next;
		}
		p->item=n;
		p->next=NULL;
		scanf("%d", &n);
	}

	//print the items of the current linked list.
	printf("Current list:");
	p=head;
	while (p!=NULL)
	{
		printf("%d ",p->item);
		p=p->next;
	}
	printf("\n");

	// Q3: search for a value in the list.
	printf("Enter value to search for:");
	scanf("%d", &n);
	searchList(head,n);

	// Q4: free up memory.
	p = head;
	while (p!= NULL) {
		temp=p->next;
		free(p);
		p=temp;
	}
	p=temp=head=NULL;

}

int searchList(ListNode *head, int value)
{

	int i = 0;
	ListNode *p = head;

	while (p != NULL)
	{
		if (p->item == value)
		{
			printf("Value %d found at index %d\n", value, i);
			return i;
		}
		p = p->next;
		i++;
	}

	printf("Value %d can not be found!\n", value);
	return -1;

}

// LL/P/wk5/q1 move max to front

int moveMaxToFront(ListNode **ptrHead)
{

    ListNode *pre, *cur;
	ListNode *preMax = NULL;
	int maxItem;

	// check empty list
	if (*ptrHead == NULL) return -1;

	// check only one node in the list
	if ( (*ptrHead)->next == NULL ) return 0;

	// Operate otherwise
	// Set cur to the head
	cur = (*ptrHead);
	maxItem = (*ptrHead)->num;
	// preMax gets set to the address of the ListNode with the max value
	// If preMax is still NULL at the end, first node had the max value
	while (cur != NULL){
		if (cur->num > maxItem){
			maxItem = cur->num;
			preMax = pre;
			}
		pre = cur;
		cur = cur->next;
	}
	// Never saw a value higher than the first node, nothing to move
	if (preMax == NULL) return 0;
	// Move node with max value to first position
	cur = preMax->next;
	preMax->next = preMax->next->next;
	// Update head pointer
	cur->next = *ptrHead;
	*ptrHead = cur;
	return 0;
}

// LL/P/wk5/q2 concatenate

int concatenate(ListNode **ptrHead1, ListNode *head2){

	ListNode *temp = *ptrHead1;

	// Both lists empty, let's return a -1 error value
	if (*ptrHead1 == NULL && head2 == NULL) return -1;

	// Empty first list, just set the head pointer of list 1 to point to first node of list 2
	if (temp == NULL){
		*ptrHead1 = head2;
		return 0;
	}

	// Empty second list, nothing to do
	if (head2 == NULL) return 0;

	// Traverse the first list to get to the last node
	// Notice we check for the value of the next pointer for the current node
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = head2;

	return 0;

}

// LL/P/wk5/q3 combine Alternating

int combineAlternating(ListNode **ptrHead, ListNode *head1, ListNode *head2)
{
	ListNode *temp;
	if (head1 == NULL && head2 == NULL) return -1;
	// If both remaining lists are empty, we're done
	// We know that at least one of the lists has a remaining node inside this while loop
	// Check in pairs each cycle: List #1, then List #2
	while (head1 != NULL || head2 != NULL){// Adding the first node, remember to update the head pointer
		if (*ptrHead == NULL){
			if (head1 != NULL){
				*ptrHead = malloc(sizeof(ListNode));
				(*ptrHead)->num = head1->num;
				head1 = head1->next;
				temp = *ptrHead;
				if (head2 != NULL){
					temp->next = malloc(sizeof(ListNode));
					temp->next->num = head2->num;
					temp = temp->next;
					head2 = head2->next;
				}
			}
			else{
				*ptrHead = malloc(sizeof(ListNode));
				(*ptrHead)->num = head2->num;
				head2 = head2->next;
				temp = *ptrHead;
			}
		}
		else{
			if (head1 != NULL){
				temp->next = malloc(sizeof(ListNode));
				temp->next->num = head1->num;
				temp = temp->next;
				head1 = head1->next;
			}
		if (head2 != NULL){
			temp->next = malloc(sizeof(ListNode));
			temp->next->num = head2->num;
			temp = temp->next;
			head2 = head2->next;
			}
		}
	}
	temp->next =NULL;
	return 0;
}

// LL/P/wk5/q4 insertDbl

typedef struct _dbllistnode{
	int num;
	struct _dbllistnode *pre;
	struct _dbllistnode *next;
} DblListNode;

int insertDbl(DblListNode **ptrHead, int index, int value){
	// Use the insertNode() function as a reference
	// Ensure that the pre pointers are updated as well
	DblListNode *pre, *cur;
	// If empty list or inserting first node, need to update head pointer
	if (*ptrHead == NULL || index == 0){
		cur = *ptrHead;
		*ptrHead=malloc(sizeof(DblListNode));
		(*ptrHead)->num = value;
		(*ptrHead)->next = cur;
		(*ptrHead)->pre = NULL;
		if (cur != NULL)
			cur->pre = *ptrHead;
		return 0;
	}
	// Find the nodes before and at the target position
	// We don't have a version of findNode that accepts DblListNode inputs
	// For now, duplicate the findNode() code in here
	pre = *ptrHead;
	while (index > 1){
		pre = pre->next;
		index--;
	}
	// Create a new node and reconnect the links
	if (pre != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(DblListNode));
		pre->next->pre = pre;
		pre->next->next = cur;
		if (cur != NULL)
			pre->next->next->pre = pre->next;
		pre->next->num = value;
		return 0;
	}
	return 0;
}

// LL/L/q1 find insert remove with **ptrHead

ListNode *findNode(ListNode* cur, int index)
{
   if (cur==NULL || index<0)
      return NULL;
   while(index>0){
      cur=cur->next;
      if (cur==NULL)
         return NULL;
      index--;
   }
   return cur;
}

int insertNode(ListNode **ptrHead, int index, int item){
    ListNode  *pre, *newNode;
    // If empty list or inserting first node, update head pointer
    if (index == 0){
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = *ptrHead;
        *ptrHead = newNode;
        return 1;
    }
    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    else if ((pre = findNode(*ptrHead, index-1)) != NULL){
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = pre->next;
        pre->next = newNode;
        return 1;
    }
    return 0;
}

int removeNode(ListNode **ptrHead, int index){
	ListNode *pre, *cur;
	// Sanity check for empty list
	if (*ptrHead == NULL)
		return -1;
	// If removing first node, need to update head pointer
	if (index == 0){
		cur = *ptrHead;
		 *ptrHead = cur->next;
		free(cur);
		return 0;
	}
	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ( (pre = findNode(*ptrHead, index-1))!= NULL){
		if (pre->next == NULL) return -1;
		cur = pre->next;
		pre->next=cur->next;
		free(cur);
		return 0;
	}
	return -1;
}

// LL/L/q2 op find insert remove with LL

ListNode* findNode2(LinkedList ll, int index)
{
   if(ll.head != NULL){
        ListNode *cur = ll.head;
        if (cur==NULL || index<0 || index >ll.size)
           return NULL;

        while(index>0){
            cur=cur->next;
            if (cur==NULL)
                return NULL;
            index--;
        }
        return cur;
   }
   else
     return NULL;
}

int insertNode2(LinkedList *ll, int index, int item){
    ListNode  *pre, *newNode;
    // If empty list or inserting first node, update head pointer
    if (index == 0){
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = ll->head;

        ll->head = newNode;
        ll->size++;
        return 1;
    }
    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    else if ((pre = findNode2(*ll, index-1)) != NULL){
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = pre->next;
        pre->next = newNode;
        ll->size++;
        return 1;
    }
    return 0;
}

int removeNode2(LinkedList *ll, int index) {

	ListNode *cur, *pre;

	if (ll->head == NULL) return -1;

	if (index==0)
	{
		cur=ll->head;
		ll->head =cur->next;
		free(cur);
		ll->size --;
		return 0;
	}

	if ((pre = findNode2(*ll, index-1))!= NULL)
	{//not the first node
		if (pre->next == NULL) return -1;
		cur = pre->next;
		pre->next=cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;

}

// LL/L/q3 split even odd node

int split(ListNode *head, ListNode **ptrEvenList, ListNode **ptrOddList)
{
	int even = 1, evenSize = 0, oddSize = 0;
	ListNode *cur=head;

	if (cur == NULL)
		return -1;
	while (cur!= NULL){
		if (even==1){
			insertNode(ptrEvenList, evenSize, cur->item);
			evenSize++;
		}
		else{
			insertNode(ptrOddList, oddSize, cur->item);
			oddSize++;
		}
	cur = cur ->next;
	even = -even;
	}
	return 0;
}

// LL/L/q4 duplicate and reverse

int duplicateReverse(ListNode *cur,ListNode **ptrNewHead)
{

    ListNode *temp = cur;

    if(temp == NULL) return -1;

    while (temp != NULL){
        if(insertNode(ptrNewHead,0,temp->item) == -1){
            return -1;
        }
        temp = temp->next;
    }

    return 0;

}

// LL/T/q1 move even items to end

void moveEvenItemsToBack(LinkedList *ll)
{

	ListNode *cur;
	int s, d, i, j = 0;

    if(ll->size < 2){
        return;
	}

	cur = ll->head;
	s = ll->size;

	for(i = 0; i < s; i++){
        if(cur->item %2 ==0){
            d = cur->item;
            cur = cur->next;
            removeNode(ll,j);
            insertNode(ll,ll->size,d);
        }else{
            cur = cur->next;
            j++;
        }
	}

}

// LL/T/q2 move max to front, see Line 112

// LL/T/q3 remove duplicate ll

void removeDuplicatesSortedLL(LinkedList *ll){

    ListNode *cur, *temp;

    if(ll->size == 0) return;

    if(ll->size == 1) return;

    cur = ll->head;

    while(cur->next != NULL){
        if(cur->item == cur->next->item){
            temp = cur->next->next;
            free(cur->next);
            cur->next = temp;
            ll->size--;
        } else cur = cur->next;
    }

    return;

}

// LL/T/Bonus circular ll

void Q3F1(ListNode *Aptr, ListNode *Bptr) {
    Q3F2(Aptr, Bptr);
    Q3F2(Bptr, Aptr);
}

void Q3F2(ListNode *s, ListNode *q) {
    ListNode *temp = s;
    while (temp->next != q) {
        temp = temp->next;
    }
    temp->next = s;
}

// LL/A/q1 insert sorted non-same node, return the position

int insertSortedLL(LinkedList *ll, int item) {

    ListNode *temp;
    ListNode *prev = NULL;
    ListNode *cur = ll->head;
    int index = 0;

    // Create a new node
    ListNode *newNode = malloc(sizeof(ListNode));
    if (newNode == NULL) {
        return -1; // Unable to allocate memory
    }
    newNode->item = item;
    newNode->next = NULL;

    // Traverse the list to find the insertion point
    while (cur != NULL) {
        if (cur->item == item) {
            // The item already exists in the list
            free(newNode);
            return -1;
        } else if (cur->item > item) {
            // We've found the insertion point
            break;
        }
        prev = cur;
        cur = cur->next;
        index++;
    }

    // Insert the new node
    if (prev == NULL) {
        // Insert at the beginning
        newNode->next = ll->head;
        ll->head = newNode;
    } else {
        // Insert in the middle or at the end
        newNode->next = prev->next;
        prev->next = newNode;
    }
    ll->size++;

    return index;

}

// LL/A/q2 merge 2 ll alternatively

void alternateMergeLinkedList(LinkedList *ll1, LinkedList *ll2){

	ListNode *cur1, *cur2, *next1, *next2;

	if (ll1 == NULL || ll2 == NULL) return; // check for empty lists

	cur1 = ll1->head; // current node of the first list
	cur2 = ll2->head; // current node of the second list

	while (cur1 != NULL && cur2 != NULL) {
		next1 = cur1->next; // next node of the first list
		next2 = cur2->next; // next node of the second list
		cur1->next = cur2; // link the current node of the first list to the current node of the second list
		cur2->next = next1; // link the current node of the second list to the next node of the first list
		cur1 = next1; // move to the next node of the first list
		cur2 = next2; // move to the next node of the second list
	}

	ll2->head = cur2; // update the head of the second list to the remaining nodes
	ll2->size = 0; // update the size of the second list to zero

	while (cur2 != NULL) {
		ll2->size++; // increment the size of the second list
		cur2 = cur2->next; // move to the next node of the second list
	}

}

// LL/A/q3 move odd items to back

void moveOddItemsToBack(LinkedList *ll) {

    // Sanity check for empty list
    if (ll == NULL || ll->size == 0) {
        return;
    }

    // Assign of pointers
    ListNode *cur = ll->head;
    ListNode *prev = NULL;
    ListNode *end = ll->head;
    ListNode *new_end = NULL;

    // Find the last node
    while (end->next != NULL) {
        end = end->next;
    }

    // Update the end
    new_end = end;

    // Move odd nodes to end
    while (cur->item % 2 != 0 && cur != end) {
        new_end->next = cur;
        cur = cur->next;
        new_end->next->next = NULL;
        new_end = new_end->next;
    }

    // If there are any even nodes
    if (cur->item % 2 == 0) {
        ll->head = cur;
        // Process remaining nodes
        while (cur != end) {
            if (cur->item % 2 == 0) {
                prev = cur;
                cur = cur->next;
            } else {
                prev->next = cur->next;
                cur->next = NULL;
                new_end->next = cur;
                new_end = cur;
                cur = prev->next;
            }
        }
    } else {
        prev = cur;
    }

    // If the last node is odd, move it to the end
    if (new_end != end && cur->item % 2 != 0) {
        prev->next = cur->next;
        cur->next = NULL;
        new_end->next = cur;
    }

}

// LL/A/q4 split front and back

void frontBackSplitLinkedList(LinkedList *ll, LinkedList *resultFrontList, LinkedList *resultBackList){

    // Sanity check for null ll
    if (ll == NULL || ll->head == NULL)
        return;

    // Calc mid
    int mid = (ll->size % 2 == 0) ? (ll->size / 2) : (ll->size / 2 + 1);
    int i;
    ListNode *current = ll->head;

    // Create front list
    for (i = 0; i < mid; i++){
        insertNode(resultFrontList, i, current->item);
        current = current->next;
    }

    // Create back list
    while (current != NULL){
        insertNode(resultBackList, resultBackList->size, current->item);
        current = current->next;
    }

}

/*SQSQ*/

// SQ/P/q1 creat queue from ll & keep only even value

void createQueueFromLinkedList(LinkedList *ll, Queue *q)
{
	ListNode *cur;

	if (ll == NULL || q == NULL)
		return;

	if (isEmptyQueue(q) == 0)
		removeAllItemsFromQueue(q);

	cur = ll->head;

	while (cur != NULL)
	{
		enqueue(q, cur->item);
		cur = cur->next;
	}
}

void removeOddValues(Queue *q)
{
	int count, i;
	if (q == NULL)
		return;
	count = q->ll.size;

	for (i = 0; i < count; i++)
	{
		int item = dequeue(q);

		if (abs(item) % 2 != 1)
		{
			enqueue(q, item);
		}
	}
}

// SQ/P/q2 SQ/P/q1 creat queue from ll & keep only odd value

void createStackFromLinkedList(LinkedList *ll, Stack *s)
{

    ListNode *cur = ll->head;
    int item;

    if(ll->size == 0) return;

    for(int i = 0; i<ll->size; i++){
        push(s,cur->item);
        cur = cur->next;
    }

    return;

}

void removeEvenValues(Stack *s)
{
    int item;
    Stack temp;
    temp.ll.head = NULL;
    temp.ll.size = 0;

    if(s == NULL) return;

    while(!isEmptyStack(s)){
        item = pop(s);
        if(item%2 != 0){
            push(&temp,item);
        }
    }

    while(!isEmptyStack(&temp)){
        item = pop(&temp);
        push(s,item);
    }

    return;

}

// SQ/P/q3 check whether pair diff == 1

int isStackPairwiseConsecutive(Stack *s)
{

    int a,b;

    if(s->ll.size < 2 || s->ll.size%2 != 0) return 0;

    while(!isEmptyStack(s)){
        a = pop(s);
        b = pop(s);
        if(abs(a-b)!=1) return 0;
    }

    return 1;

}

// SQ/P/q4 reverse stack with sq

void reverse(Queue *q)
{
    Stack s;

    s.ll.head = NULL;
    s.ll.size = 0;
    s.ll.tail = NULL;

    while(!isEmptyQueue(q)){
        push(&s,dequeue(q));
    }

    while(!isEmptyStack(&s)){
       enqueue(q,pop(&s));
    }

}

// SQ/L/q1

void removeUntil(Stack *s, int value){

    while(!isEmptyStack(s)){
        if(peek(s)!=value){
            pop(s);
        }else{
            break;
        }
    }

}

// SQ/L/q2 reverse queue with recursive function

void recursiveReverse(Queue *q){

	int i;

	if (isEmptyQueue(q))
		return;

	 i = dequeue(q);
	 recursiveReverse(q);
	 enqueue(q, i);

}

// SQ/L/q3 check string symmertry

int palindrome(char *word){

    int odd,hlf;
    Stack s1;
    s1.ll.head = NULL;
    s1.ll.size = 0;
    Stack s2;
    s2.ll.head = NULL;
    s2.ll.size = 0;

    printf("In:%s\n",word);

    while(*word){
        if(*word != ' '){
            push(&s1,toupper(*word));
        }
        word++;
    }

    odd = s1.ll.size%2;
    hlf = s1.ll.size/2;

    while(hlf>0){
        push(&s2,pop(&s1));
        hlf--;
    }

    if(odd) pop(&s1);

    while(!isEmptyStack(&s1)){
        if(pop(&s1) != pop(&s2)){
            printf("No\n");
            return -1;
        }
    }

    printf("Yes\n");
    return 0;

}

// SQ/L/q4 check char balance

int balanced(char *e){

    Stack s;
    s.ll.head = NULL;
    s.ll.tail = NULL;
    s.ll.size = 0;

    printf("%s\n",e);

    while(*e){
        if( *e == '(' || *e == '[' || *e == '{' ){
            push(&s,*e);
        }
        else if(*e == ')'){
            if ( isEmptyStack(&s) || pop(&s) != '(' ) return -1;
        }
        else if(*e == ']'){
            if ( isEmptyStack(&s) || pop(&s) != '[' ) return -1;
        }
        else if(*e == '}'){
            if ( isEmptyStack(&s) || pop(&s) != '{' ) return -1;
        }
        e++;
    }

    if(isEmptyStack(&s)) return 0;

    return -1;

}

// SQ/T/q1 reverse stack with queue

void reverseStack(Stack *s)
{

	Queue q;
	q.ll.head = NULL;
	q.ll.size = 0;

	while(!isEmptyStack(s)) enqueue(&q,pop(s));
	while(!isEmptyQueue(&q)) push(s,dequeue(&q));

	return;

}

// SQ/T/q2 reverse first k in queue

void reverseFirstKItems(Queue *q, int k)
{

    // San
    if( k < 1 ) return;
    if( isEmptyQueue(q) ) return;
    if( k > q->ll.size ) return;

    Stack s;
    s.ll.head = NULL;
    s.ll.size = 0;
    int i, l = q->ll.size;

    for(i = 0; i < k; i++){
        push(&s,dequeue(q));
    }

    while(!isEmptyStack(&s)) enqueue(q,pop(&s));

    for( i = 0; i < l - k ; i++ ){
        enqueue(q,dequeue(q));
    }

    return;

}

// SQ/T/q3 sort a stack

void sortStack(Stack *s)
{

    int temp;
    Stack t;
    t.ll.head = NULL;
    t.ll.size = 0;

    while(!isEmptyStack(s)) push(&t,pop(s));

    while(!isEmptyStack(&t)){
        temp = pop(&t);
        while(!isEmptyStack(s)&&peek(s)<temp) push(&t,pop(s));
        push(s,temp);
    }

}

// SQ/A/q1 Q interleave 1233-1323

void interleaveQueue(Queue *q){

    if(q->ll.size%2 != 0){
        // printf("invalid\n");
        return;
    }

    Stack s;
    s.ll.head = NULL;
    s.ll.size = 0;

    int halfSize = q->ll.size / 2;

    // Push first half elements into the stack
    for (int i = 0; i < halfSize; i++) {
        push(&s, dequeue(q));
    }

    // Enqueue back the stack elements
    while (!isEmptyStack(&s)) {
        enqueue(q, pop(&s));
    }

    // Dequeue the first half elements of Queue
    for (int i = 0; i < halfSize; i++) {
        enqueue(q, dequeue(q));
    }

    // Again push the first half elements into the stack
    for (int i = 0; i < halfSize; i++) {
        push(&s, dequeue(q));
    }

    // Interleave the elements of Queue and Stack
    while (!isEmptyStack(&s)) {
        enqueue(q, pop(&s));
        enqueue(q, dequeue(q));
    }

}

// SQ/A Precesence

int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0; // Assuming '(' has the lowest precedence
}

// SQ/A/q2 in2pr Infix -> Prefix

void infixtoPrefix(char *infix, char *prefix) {

    Stack stack;
    stack.ll.size = 0;
    stack.ll.head = NULL;
    int index = 0;

    for (int i = strlen(infix) - 1; i >= 0; i--) {
        char ch = infix[i];
        if (isalnum(ch)) {
            prefix[index++] = ch;
        } else if (ch == ')') {
            push(&stack, ch);
        } else if (ch == '(') {
            while (!isEmptyStack(&stack) && peek(&stack) != ')') {
                prefix[index++] = pop(&stack);
            }
            pop(&stack); // Discard ')'
        } else { // Operator
            while (!isEmptyStack(&stack) && precedence(peek(&stack)) > precedence(ch)) {
                prefix[index++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    // Pop remaining operators from stack to prefix
    while (!isEmptyStack(&stack)) {
        prefix[index++] = pop(&stack);
    }

    // Reverse the obtained prefix expression
    for (int i = 0; i < index / 2; i++) {
        char temp = prefix[i];
        prefix[i] = prefix[index - i - 1];
        prefix[index - i - 1] = temp;
    }

    prefix[index] = '\0';

}

// SQ/A/q3 in2po 1-Infix -> Postfix

void infixtoPostfix(char *infix, char *postfix) {

    Stack stack;
    stack.ll.size = 0;
    stack.ll.head = NULL;
    int index = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[index++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (!isEmptyStack(&stack) && peek(&stack) != '(') {
                postfix[index++] = pop(&stack);
            }
            pop(&stack); // Discard '('
        } else { // Operator
            while (!isEmptyStack(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[index++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    // Pop remaining operators from stack to postfix
    while (!isEmptyStack(&stack)) {
        postfix[index++] = pop(&stack);
    }

    postfix[index] = '\0';

}

// SQ/A/q2 pocalc 4-Calc Postfix

double postfixEvaluation(char* postfix) {

    Stack stack;
    stack.ll.size = 0;
    stack.ll.head = NULL;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            push(&stack, ch - '0'); // Convert char to integer and push onto stack
        } else {
            // Operator encountered
            double operand2 = pop(&stack);
            double operand1 = pop(&stack);
            double result;
            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        return INT_MIN; // Return an error value
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Error: Invalid operator\n");
                    return INT_MIN; // Return an error value
            }
            push(&stack, result);
        }
    }

    return pop(&stack); // The final result will be left on the stack

}

// SQ/A/Bonus prcalc

double prefixEvaluation(char* prefix) {

    Stack stack;
    stack.ll.size = 0;
    stack.ll.head = NULL;

    // Start from the end of the prefix expression and iterate backwards
    for (int i = SIZE - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isdigit(ch)) {
            push(&stack, ch - '0'); // Convert char to integer and push onto stack
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // Operator encountered
            double operand1 = pop(&stack);
            double operand2 = pop(&stack);
            double result;
            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        return INT_MIN; // Return an error value
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Error: Invalid operator\n");
                    return INT_MIN; // Return an error value
            }
            push(&stack, result);
        }
    }

    return pop(&stack); // The final result will be left on the stack

}

// SQ/A/Bonus po2pr (not right)

void postfixToPrefix(char *postfix, char *prefix) {

    Stack stack;
    stack.ll.size = 0;
    stack.ll.head = NULL;
    int index = 0;

    // Find length of postfix expression
    int length = strlen(postfix);

    // Reverse the postfix expression
    char reversed_postfix[SIZE];
    for (int i = 0; i < length; i++) {
        reversed_postfix[i] = postfix[length - 1 - i];
    }
    reversed_postfix[length] = '\0';

    // Iterate through reversed postfix expression
    for (int i = 0; reversed_postfix[i] != '\0'; i++) {
        char ch = reversed_postfix[i];
        if (isalnum(ch)) {
            prefix[index++] = ch;
        } else { // Operator
            if (isEmptyStack(&stack)) {
                push(&stack, ch);
            } else {
                if (ch == '(') {
                    push(&stack, ch);
                } else if (ch == ')') {
                    push(&stack, ch);
                } else {
                    while (!isEmptyStack(&stack) && precedence(peek(&stack)) <= precedence(ch)) {
                        char top = pop(&stack);
                        prefix[index++] = top;
                    }
                    push(&stack, ch);
                }
            }
        }
    }

    // Pop remaining operators from stack to prefix
    while (!isEmptyStack(&stack)) {
        char top = pop(&stack);
        if (top != '(' && top != ')') {
            prefix[index++] = top;
        }
    }

    // Reverse the prefix expression to get the final result
    char final_prefix[SIZE];
    for (int i = 0; i < index; i++) {
        final_prefix[i] = prefix[index - 1 - i];
    }
    final_prefix[index] = '\0';

    strcpy(prefix, final_prefix);
}

/*BTBST*/

// BT/P/q1 find tree height (root = 0)

int maxHeight(BTNode *node){

    int lheight, rheight;

    if(node == NULL){
        return -1;
    }else{
        lheight = maxHeight(node->left);
        rheight = maxHeight(node->right);
        if(lheight > rheight) return lheight+1;
        else{
            return rheight+1;
        }
    }

}

// BT/P/q2 count node with single child

int countOneChildNodes(BTNode *node){

    int count;
    count = 0;

    if(node == NULL) return count;

    if((node->left == NULL && node->right != NULL)
       ||(node->left != NULL && node->right == NULL)){
        count = 1;
    }

    return (count + countOneChildNodes(node->left)
            +countOneChildNodes(node->right));

}

// BT/P/q2 sum odd items

int sumOfOddNodes(BTNode *node){

    int sum;
    if(node == NULL) return 0;
    sum = 0;
    if(abs(node->item) %2 == 1) sum = node->item;
    return (sum + sumOfOddNodes(node->left)
            + sumOfOddNodes(node->right));

}

// BT/L/q1 mirror tree with 3 kinds of traversal

void mirrorTree(BTNode *node){

	BTNode *temp;

	if (node == NULL)
	return;

	// Swap left and right BTNode pointers
	// Pre-order traversal
    /*
	temp = node->left;
	node->left = node->right;
	node->right = temp;
	mirrorTree(node->left);
	mirrorTree(node->right);
    */
	// Post-order traversal
    /*
    mirrorTree(node->left);
    mirrorTree(node->right);
    temp = node->left;
    node->left = node->right;
    node->right = temp;
    */

	// In-order traversal?

	mirrorTree(node->left);
	temp = node->left;
	node->left = node->right;
	node->right = temp;
	mirrorTree(node->left);

}

// BT/L/q2 print value smaller than a given value

void printSmallerValues(BTNode *node, int m){

	if (node==NULL) return;

	if (node->item<m) printf("%d,", node->item);

	printSmallerValues(node->left, m);
	printSmallerValues(node->right, m);

	return;

}

// BT/L/q3 find the smallest value of the tree

int smallestValue(BTNode *node){

	int l,r;

	if (node==NULL) return 100000;

	l=smallestValue(node->left);
	r=smallestValue(node->right);

	if (l<node->item && l<r) return l;
	else if (r<node->item && r<l) return r;
	else return node->item;

}

// BT/L/q4 print node with grandchild

int hasGreatGrandchild(BTNode *node){

    // Calculate the height of each node in the tree
	// Print out (data stored in) node that has height > 1

	int l, r;

	if (node == NULL) return -1;

	l = hasGreatGrandchild(node->left);
	r = hasGreatGrandchild(node->right);

	if (r > l) l = r;
	if (l > 1) printf("%d ", node->item);

	return (l + 1);

}

// BT/T/q1 ts level by level using queue

void levelOrderTraversal(BSTNode* root) {

    Queue q;
    q.head=NULL;
    q.tail=NULL;
    BSTNode *temp;
    temp = root;

    if(temp != NULL) {
        enqueue(&q.head,&q.tail,temp);
        while(!isEmpty(q.head)) {
            temp=dequeue(&q.head,&q.tail);
            printf("%d ",temp->item);
            if(temp->left!=NULL)
                enqueue(&q.head,&q.tail,temp->left);
            if(temp->right!=NULL)
                enqueue(&q.head,&q.tail,temp->right);
        }
    }

}

// BT/T/q2 print pre-order bt iterate

void preOrderIterative(BSTNode *root) {

	Stack s;
	BSTNode *temp;

	s.top = NULL;
	temp = root;

	if (temp == NULL) return;
    push(&s, temp);

	do {

	    temp = pop(&s);
	    printf("%d ",temp->item);

	    if(temp->right != NULL)
            push(&s,temp->right);
        if(temp->left != NULL)
            push(&s,temp->left);

	} while (!isEmpty(&s));

}

// BT/T/q3 find bt max depth

int maxDepth(BTNode *node) {

    if(node == NULL) return -1;
    else {
        int l = maxDepth(node->left);
        int r = maxDepth(node->right);
        if(l > r) return l+1;
        else return r+1;
    }

}

// BT/T/q4 recursion finding node with content

BTNode *searchNode(BTNode *node, int key) {

    BTNode *temp;

    if(node == NULL) return NULL;

    if(node->item == key) return node;
    temp = NULL;
    temp = searchNode(node->left,key);
    if(temp == NULL) temp = searchNode(node->right,key);

    return temp;

}

// BT/A/q1 check whether 2 BTs are structrally identical

int identical(BTNode *tree1, BTNode *tree2) {
    // If both trees are empty, they are identical
    if (tree1 == NULL && tree2 == NULL)
        return 1;
    // If one tree is empty while the other is not, they are not identical
    if (tree1 == NULL || tree2 == NULL)
        return 0;
    // Recursively check left and right subtrees for structural identity
    return (identical(tree1->left, tree2->left) && identical(tree1->right, tree2->right));
}

// BT/A/q2 in order iterative

void inOrderTraversal(BSTNode *root)
{
    if (root == NULL)
        return;

    Stack stack;
    stack.top = NULL;

    BSTNode *current = root;

    while (current != NULL || !isEmpty(&stack))
    {
        // Reach the leftmost node of the current subtree
        while (current != NULL)
        {
            push(&stack, current);
            current = current->left;
        }

        // Current is now NULL, pop the top item from stack
        current = pop(&stack);
        printf("%d ", current->item);

        // Move to the right subtree
        current = current->right;
    }
}

// BT/A/q3 po it with 1 stack

void postOrderIterativeS1(BSTNode *root)
{
    if (root == NULL)
        return;

    Stack stack;
    stack.top = NULL;

    BSTNode *current = root;
    BSTNode *lastVisited = NULL;

    while (current != NULL || !isEmpty(&stack))
    {
        while (current != NULL)
        {
            // Push root's right child and then root to stack
            if (current->right != NULL)
                push(&stack, current->right);

            push(&stack, current);

            // Set root as root's left child
            current = current->left;
        }

        // Pop an item from stack and set it as root
        current = pop(&stack);

        // If the popped item has a right child and the right child is at the top of the stack
        if (current->right != NULL && peek(&stack) == current->right)
        {
            // Remove the right child from stack
            pop(&stack);
            // Push the root back
            push(&stack, current);
            // Set root as root's right child
            current = current->right;
        }
        else
        {
            // Print root's data and set root as NULL
            printf("%d ", current->item);
            lastVisited = current;
            current = NULL; // This is important to avoid re-visiting the same node
        }
    }
}

// BT/A/q4 po it with 2 stacks

void postOrderIterativeS2(BSTNode *root)
{
    if (root == NULL)
        return;

    Stack stack1, stack2;
    stack1.top = NULL;
    stack2.top = NULL;

    push(&stack1, root);

    while (!isEmpty(&stack1))
    {
        // Pop a node from the first stack and push it to the second stack
        BSTNode *current = pop(&stack1);
        push(&stack2, current);

        // Push left and right children of the popped node to the first stack
        if (current->left != NULL)
            push(&stack1, current->left);
        if (current->right != NULL)
            push(&stack1, current->right);
    }

    // Print contents of the second stack
    while (!isEmpty(&stack2))
    {
        BSTNode *current = pop(&stack2);
        printf("%d ", current->item);
    }
}

// BST/L/q1 insert BST node as lecture notes

void insertBSTNode(BTNode **node, int value)
{

	if (*node==NULL) //if the tree is empty
	{
		*node=malloc(sizeof(BTNode));
		(*node)->item =value;
		(*node)->left =NULL;
		(*node)->right = NULL;
		return;
	}
	if ((*node)->item > value) //value is smaller than the node
		insertBSTNode(&((*node)->left), value);
	else if ((*node)->item <value) //value is larger than the node
		insertBSTNode(&((*node)->right), value);
	else // (*node)->item == value, value will not be inserted
	{
		printf("Already exists in the BST\n");
		return;
	}
	return;
}

// BST/L/q2 in-order prt BST

void printBSTInOrder(BTNode *node)
{
	if (node==NULL)
		return;

	printBSTInOrder(node->left );
	printf("%d, ", node->item);
	printBSTInOrder(node->right);

	return;

}

// BST/L/q3 BT->1yes0no

int isBST(BTNode *node, int min, int max) // the item stored in node has to be smaller than max and larger than min
{
	if (node==NULL)
		return 1;

	if (node->item >= max || node->item <= min) //the node's value should belong to (min, max).
		return 0;

	// its left node should be smaller than node->item
	// its right node should be larger than node->item
	return isBST(node->left,min, node->item)&& isBST(node->right,node->item, max) ;

}

// BST/L/q4 rm BST node

BTNode *removeBSTNode(BTNode *node, int value)
{
	BTNode *p;

	if (node==NULL)
	{
		printf("can't find the value!\n");
		return NULL;
	}

	if (node->item >value) //go left tree
		 node->left = removeBSTNode(node->left, value);

	else if (node->item <value) //go right tree
		 node->right = removeBSTNode(node->right, value);

	else// if ((*node)->item ==value) found the node!
		if (node->left!=NULL && node->right !=NULL ) //*node has two children
		{
			p=findMin(node->right);
			node->item =p->item;
			node->right = removeBSTNode(node->right,p->item );
		}
		else //x has no children or one child
		{
			p=node;

			if (node->left !=NULL)
				node=node->left;
			else
				node=node->right;

			free(p);
		}
	return node;
}
