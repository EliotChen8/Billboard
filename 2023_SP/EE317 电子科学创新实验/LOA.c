/* HTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHTHT */

// Lab: search and insert node

ListNode* HashSearch(HashTable Q4Hash, int key) {

    int hashVal;
    ListNode *toBeSearched;

    // here we assume that hsize != NULL
    if(Q4Hash.hSize != 0) hashVal = Hash(key,Q4Hash.hSize);
    else return NULL;

    toBeSearched = Q4Hash.Table[hashVal].head;
    while(toBeSearched != NULL){
        if(toBeSearched->key == key) return toBeSearched;
        toBeSearched = toBeSearched->next;
    }

    return NULL; // not found

}

int HashInsert(HashTable* Q4HashPtr, int key) {

    int hashVal;
    ListNode *newNode;

    if(Q4HashPtr->hSize != 0) hashVal = Hash(key,Q4HashPtr->hSize); // calc hashVal
    else return 0; // no slot

    if(HashSearch(*Q4HashPtr,key) != NULL ) return 0; // dup node

    // mem alloc
    newNode = (ListNode *)malloc(sizeof(ListNode));
    // write new node
    newNode->key = key;
    newNode->next = Q4HashPtr->Table[hashVal].head;
    // insert new node to the front
    Q4HashPtr->Table[hashVal].head = newNode;
    // update size
    Q4HashPtr->nSize++;
    Q4HashPtr->Table[hashVal].size++;

    return 1; // success

}

// Hw4-1: Coalesced Hashing search and insert

int HashInsert(int key, HashSlot hashTable[]){

    // check dup key at first
    if(HashFind(key,hashTable) != -1) return -1;

    // calc original hashVal
    int hashVal = hash(key);

    // valid at the first try
    if(hashTable[hashVal].indicator == EMPTY){
        hashTable[hashVal].key = key;
        hashTable[hashVal].indicator = USED;
    }

    // find thread end
    int nextVal;
    while(nextVal != -1){
        if(hashTable[nextVal].key == key) return -1;
        hashVal = nextVal;
        nextVal = hashTable[nextVal].next;
    }
    
    // find slot from here to end
    for(int i = hashVal+1; i < TABLESIZE; i++){
        if(hashTable[i].indicator == EMPTY){
            hashTable[hashVal].next = i;
            hashTable[i].key = key;
            hashTable[i].indicator = USED;
        }
    }
    
    // find slot from head to here
    for(int i = 0; i < hashVal; i++){
        if(hashTable[i].indicator == EMPTY){
            hashTable[hashVal].next = i;
            hashTable[i].key = key;
            hashTable[i].indicator = USED;
        }
    }
    
    return TABLESIZE;

}

// Hw4-2 HT and DbLL search insert and del

int HashInsert(HashTable* Q1Ptr, int key) {

    // Calc hash value
    int index = Hash(key, Q1Ptr->hSize);

    // Check dup
    if (HashSearch(*Q1Ptr, key) != NULL) return 0;

    // Init new node
    ListNode* newNd = (ListNode*)malloc(sizeof(ListNode));
    newNd->key = key;
    newNd->next = NULL;
    newNd->pre = NULL;

    // Insret node @ hashval ll head
    newNd->next = Q1Ptr->Table[index].head;
    if (Q1Ptr->Table[index].head != NULL) Q1Ptr->Table[index].head->pre = newNd;
    Q1Ptr->Table[index].head = newNd;
    Q1Ptr->Table[index].size++;
    Q1Ptr->nSize++;

    return 1;

}

int HashDelete(HashTable* Q1Ptr, int key) {

    // calc hashvl
    int index = Hash(key, Q1Ptr->hSize);

    // trv, find nd with key
    ListNode* cur = Q1Ptr->Table[index].head;
    while (cur != NULL && cur->key != key) cur = cur->next;

    // not found
    if (cur == NULL) return 0;

    // rm node
    if (cur->pre != NULL) cur->pre->next = cur->next;
    else Q1Ptr->Table[index].head = cur->next;
    if (cur->next != NULL) cur->next->pre = cur->pre;
    free(cur);

    // updt ll
    Q1Ptr->Table[index].size--;
    Q1Ptr->nSize--;

    return 1;

}

ListNode* HashSearch(HashTable Q1, int key) {

    int index;
    ListNode *temp;

    if(Q1.hSize != 0) index = Hash(key,Q1.hSize);
    else return NULL;

    temp = Q1.Table[index].head;

    while(temp !=NULL){
        if(temp->key == key) return temp;
        temp = temp->next;
    }

    return NULL;

}

// Hw4-3 Open Addr in Db hashing
// May not be included

int HashInsert(int key, HashSlot hashTable[]) {

    int loopCnt = 0;
    int keyCmp = 0;
    int hashValue = hash1(key);
    int delFlag = 0;
    int delHashValue = 0;

    while (hashTable[hashValue].indicator != EMPTY) {

        if (delFlag == 1 && loopCnt == TABLESIZE){
            hashTable[delHashValue].key = key;
            hashTable[delHashValue].indicator = USED; 
            return 36;
        } else if (loopCnt >= TABLESIZE){
            return keyCmp; // hashtb full
        } 
        
        if(hashTable[hashValue].indicator == USED){
            keyCmp++;
            if (hashTable[hashValue].key == key) return -1; // dup key 
        } else {
            // NO keyCmp++ at DEL slot
            if(delFlag == 0) delHashValue = hashValue;
            delFlag = 1;
        }

        loopCnt++;
        hashValue = hash1((key+loopCnt*hash2(key)));

    }

    if(delFlag == 0){
        hashTable[hashValue].key = key;
        hashTable[hashValue].indicator = USED; 
    } else {
        hashTable[delHashValue].key = key;
        hashTable[delHashValue].indicator = USED; 
    }

    return keyCmp;
    
}

int HashDelete(int key, HashSlot hashTable[]) {

    int loopCnt = 0;
    int keyCmp = 0;
    int hashValue = hash1(key);

    while (hashTable[hashValue].indicator != EMPTY) {

        if (loopCnt >= TABLESIZE) break;

        if(hashTable[hashValue].indicator == USED){
            keyCmp++;
            if (hashTable[hashValue].key == key) {
                // cahnge the slot to DEL
                hashTable[hashValue].indicator = DELETED;
                return keyCmp;
            }
        }

        loopCnt++;
        hashValue = hash1((key+loopCnt*hash2(key)));

    }

    return -1; // not found

}

/* GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG */

// Lab 6-1,2 AdjList <-> AdjMat

void adjM2adjL(Graph *g) {

    if(g->type == ADJ_MATRIX) return;
    if(g->V<=0) return;

    int i,j;
    ListNode **adjList;
    ListNode *cur;

    adjList = (ListNode**)malloc(g->V*(sizeof(ListNode*)));

    for(i=0; i<g->V; i++)
        adjList[i] = NULL;

    for(i=0; i<g->V; i++){
        for(j=0; j<g->V; j++){
            if(adjList[i] == NULL){
                adjList[i] = (ListNode *)malloc(sizeof(ListNode));
                adjList[i]->vertex = j+1;
                adjList[i]->next = NULL;
                cur = adjList[i];
            } else {
                cur->next->vertex = j+1;
                cur->next->next = NULL;
                cur = cur->next;
            }
        }
    }

    for(i=0; i<g->V; i++)
        free(g->adj.matrix[i]);
    free(g->adj.matrix);

    g->type = ADJ_LIST;
    g->adj.list = adjList;

}

void adjL2adjM(Graph *g){

    if(g->type == ADJ_MATRIX) return;
    if(g->V<=0) return;

    int i,j;
    int **adjMat = (int**)malloc(g->V*sizeof(int *));
    for(i=0; i<g->V; i++)
        adjMat[i] = (int*)malloc(g->V*sizeof(int));
    ListNode *cur;

    for(i=0; i<g->V; i++)
        for(j=0; j<g->V; i++)
            adjMat[i][j] = 0;

    for(i=0; i<g->V; i++){
        cur = g->adj.list[i];
        while(cur != NULL){
            adjMat[i][cur->vertex-1] = 1;
            cur = cur->next;
        }
    }

    for(i=0; i<g->V; i++)
        free(g->adj.list[i]);
    free(g->adj.list);

    g->type = ADJ_MATRIX;
    g->adj.matrix = adjMat;

}

// Lab6-3 calc Deg

void calDegreeV(Graph g, int *degreeV) {

    int i,j;
    ListNode *cur = NULL;

    if(g.type == ADJ_LIST){
        for(i=0; i<g.V; i++){
            degreeV[i] = 0;
            cur = g.adj.list[i];
            while(cur != NULL){
                degreeV[i]++;
                cur = cur->next;
            }
        }
    } else {
        for(i=0; i<g.V; i++){
            degreeV[i] = 0;
            for(j=0; j<g.V; i++){
                degreeV[i] += g.adj.matrix[i][j];
            }
        }
    }

}

// Lab6-4 BFS

void BFS(Graph g, int v){

    int w,u;

    // Create a Q
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;

    // enQ v into q
    enqueue(&q,v);

    // mark v as visited
    g.visited[v-1] = 1;
    printf("%d",v-1);

    // while q is not empty
    while(isEmptyQueue(q) == 0){

        // deQ a vertex and note as w
        w = dequeue(&q);

        // for each unvisited && adj vertex
        for(u=1; u<=g.V; u++){
            if(g.visited[u-1]==0 && g.matrix[w-1][u-1]==1){

                // mark as visited
                g.visited[u-1] = 1;
                printf("%d",u-1);
                
                // enQ u
                enqueue(&q,u);
            }
            
        // end for
        }
        
    // end while
    }

// end BFS
}

// Lab7-1 DFS

void DFS_I (Graph g, int v){

    int w,u;

    int *visitedV = (int*)malloc(g.V*sizeof(int));
    for(int i=0; i<g.V; i++){
        visitedV[i] = 0;
    }
    
    // create a stack S
    Stack s;
    s.head = NULL;
    s.size = 0;
    
    // push v to s
    push(&s,v);
    
    // mark v as visited
    visitedV[v-1] = 1;
    
    // while s is not empty do
    while(isEmptyStack(s) == 0){
            
        int unvisited = 0;
        
        // peek the stack and denote vertex as w
        w = peek(s);
        
        // else
        for(u=1; u<=g.V; u++){
            if(visitedV[u]==0 && g.matrix[v-1][u-1]==1){
                
                unvisited = 1;
                
                // push unvisited u to s
                push(&s,u);
                
                // mark u as visited
                visitedV[u-1] = 1;
                
                break;
            }
        }
        
        // if no visited v adj to w
        if(unvisited == 0){
                
            // pop a vertex from s
            pop(&s);
        
        // end if
        }
    
    // end while
    }

// end DFS
}

// Lab7-2 DFS-R

void DFS_R (Graph_DFS g, int v) {

    int u;
    g.visited[v-1] = 1;

    for(u=1; u<=g.V; u++){
        if(g.matrix[v-1][u-1]==1 && g.visited[u-1]==0){
            DFS_R(g,u);
        }
    }

    printf("%d ",v);

}

// Hw5-1 shortest Distance using BFS

int SD(Graph g, int v, int w) {

    int ww,uu;

    // init q
    Queue q;
    q.size = 0;
    q.head = NULL;
    q.tail = NULL;

    for(int i=0; i<g.V; i++)
        g.visited[i] = 0;

    int d[g.V];
    for(int i=0; i<g.V; i++)
        d[i] = -1;
    d[v-1] = 0;

    // enq v into q
    enqueue(&q,v);
    g.visited[v-1] = 1;

    while(isEmptyQueue(q)==0){

        ww = dequeue(&q);

        if(ww == w){
            removeAllItemsFromQueue(&q);
            return d[w];
        }

        for(uu=1; uu<=g.V; uu++){
            if(g.visited[uu-1]==0 && g.matrix[ww-1][uu-1]==1){
                g.visited[uu-1] == 1;
                d[uu-1] = d[ww-1]+1;
                enqueue(&q,uu);
            }
        }

    }

    return -1;

}

// Hw5-2 unD Connect ???

int Connected(Graph g) {

    Stack s;
    s.head = NULL;
    s.size = 0;

    for (int i = 0; i < g.V; i++) {

        for (int j = 0; j < g.V; j++)
            g.visited[j] = 0;

        push(&s, i);

        g.visited[i] = 1;

        int count = 1;

        while (!isEmptyStack(s)) {

            int u = peek(s);
            int v;

            for (v = 0; v < g.V; v++) {
                if (g.matrix[u][v]==1 && g.visited[v]==0) {
                    g.visited[v] = 1;
                    push(&s, v);
                    count++;
                    break;
                }
            }

            if (v == g.V) pop(&s);

        }

        if (count != g.V) {
            removeAllItemsFromStack(&s);
            return 0; // not connected
        }

        removeAllItemsFromStack(&s);
        
    }

    // Otw
    return 1;

}

// Hw5-3 D Connect

int Connected(Graph g) {

    int u,v,w;
    v = 1;

    Stack s;
    s.head = NULL;
    s.size = 0;

    push(&s,v);
    g.visited[v-1] = 1;

    while(isEmptyStack(s)==0){

        w = peek(s);
        int found = 0;

        for(u=1; u<=g.V; u++){
            if(g.matrix[w-1][u-1]==1 && g.visited[u-1]==0){
                push(&s,u);
                g.visited[u-1] = 1;
                found = 1;
                break;
            }
        }

        if(found==0) pop(&s);

    }

    for(int i=0; i<g.V; i++){
        if(g.visited[i]==0){
            removeAllItemsFromStack(&s);
            return 0;
        }
    }

    removeAllItemsFromStack(&s);
    return 1;

}

/* BTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDPBTDP */

// BT Lab7-3 NQueen

int nQueens(int** board, int BSize, int col) {

    if(col>=BSize){
        printSolution(board,BSize);
        return 1;
    }

    int found = 0;

    for(int i=0; i<BSize; i++){
        if(isSafe(board,BSize,i,col)){
            board[i][col] = 1;
            if(nQueens(board,BSize,col+1) || found) found = 1;
            board[i][col] = 0;
        }
    }

    return found;

}

// BT Hw6-3 Coloring

int graphColoring(int** graph, int m, int* color, int v) {

    if(v>=V) {
        count++;
        return 1;
    }

    int found = 0;

    for(int c=1; c<=m; c++){
        if(isSafe(v, graph, color, c)){
            color[v] = c;
            if(graphColoring(graph, m, color, v+1) || found) found = 1;
            color[v] = 0;
        }
    }

    return found;
    
}

// DP Lab8-1 Cutting rode

int *r;

int cr_recursive(int *p, int n) {

    if(n==0) return 0; // nothing to cut

    int i, tmp;
    int ans = -1; // init ans storage

    for(i=1; i<=n; i++){
        tmp = p[i] + cr_recursive(p,n-i); // check the ans for each i
        if(tmp>ans) ans = tmp; // store better ans
    }

    return ans;

}

int cr_top_down_dp(int *p, int n) {

    if(n==0) return 0; // nothing to cut

    if(r[n]>0) return r[n];

    int i, tmp;
    int ans = -1;

    for(i=1; i<=n; i++){
        tmp = p[i] + cr_top_down_dp(p,n-i);
        if(tmp>ans) ans = tmp;
    }

    return ans;

}

int cr_bottom_up_dp(int *p, int n) {

    if(n==0) return 0; // nothing to cut

    int i, j, tmp;
    r[0] = 0;

    for (i=1; i<=n; i++){
        for (j=1; j<=i; j++){
            tmp = p[j] + r[j-i];
            if(tmp>r[j]) r[j] = tmp;
        }
    }

    return r[n];

}

// Lab8-3 ways to sum

int waysToScore(int n, int* score){

    int *ans = (int*)malloc((n+1)*sizeof(int));
    for(int i=0; i<n+1; i++)
        ans[i]=0;
    ans[0]=1;

    for(int i=1; i<=n; i++){
        if(i-score[0]>=0) ans[i] += ans[i-score[0]];
        if(i-score[1]>=0) ans[i] += ans[i-score[1]];
        if(i-score[2]>=0) ans[i] += ans[i-score[2]];
    }

    return ans[n];

}

// Hw6-2 Calc Arr

int top_down_dp(int n) {

    // basics
    if(n<=0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;

    // return result
    if(memo[n]>0) return memo[n];

    // calc
    memo[n] = top_down_dp(n-1)+2*top_down_dp(n-2)-3*top_down_dp(n-3);

    return memo[n];

}

// Hw6-3 Knapsack DONT KNOW WHY

int bottom_up_dp(int n, int *s, int *v, int C) {

    int **arr = (int**)malloc((n+1)*sizeof(int*));
    for(int i=0; i<n+1; i++)
        arr[i] = (int*)malloc((C+1)*sizeof(int));

    for(int i=1; i<=n; i++){
        for(int j=0; j<=C; j++){
            if(s[i]<=j){
                if((arr[i-1][j-s[i]]+v[i]) > arr[i-1][j]){
                    arr[i][j] = arr[i-1][j-s[i]] + v[i];
                } else {
                    arr[i][j] = arr[i-1][j];
                }
            } else {
                arr[i][j] = arr[i-1][j];
            }
        }
    }

    return arr[n][C];
    
}