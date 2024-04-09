#include"BinaryTree.h"



int num = 0,num1 = 0;
void visit(ElemType e){
    printf("%d ",e);
}

BinaryTree init(BinaryTree tree){
    int i;
    while(1){
        while(1){
            i = Scan();
            if(i == -999 && num == 0)
                printf("不行哦，必须输入一个数字来建立根结点\n");
            else
                break;
        }
        num++;
        if(i == -999){
            num = 0;
            return tree;
        }
        else{
            tree = insert(tree,i);
            if(num == 1)
                tree->parent = NULL;
        }
    }
}

Node* insert(BinaryTree tree, ElemType e){
    num1 = 0;
    if(tree == NULL){
        tree = (Node *)malloc(sizeof(Node));
        tree->value = e;
        tree->left = tree->right = NULL;
        tree->parent = NULL;
    }
    else if(e > tree->value){
        tree->right = insert(tree->right,e);
        tree->right->parent = tree;
    }
    else if(e < tree->value){
        tree->left = insert(tree->left,e);
        tree->left->parent = tree;
    }
    else{
        printf("该节点已经存在\n");
        num1 = 1;
    }
    return tree;
}

BinaryTree deleteNode(BinaryTree tree, ElemType e){
    Node *t = tree;
    while(t->parent != NULL)
        t = t->parent;
    num++;
    if(tree == NULL)
        return NULL;
    if(e > tree->value)
        deleteNode(tree->right,e);
    else if(e < tree->value)
        deleteNode(tree->left,e);
    else{
        if(tree->left == NULL){
            if(num == 1){
                if(tree->right == NULL){
                    free(tree);
                    return NULL;
                }
                tree = tree->right;
                free(tree->parent);
                tree->parent = NULL;
            }
            else if(e > tree->parent->value){
                tree->parent->right = tree->right;
                free(tree);
            }
            else{
                tree->parent->left = tree->right;
                free(tree);
            }
        }
        else if(tree->right == NULL){
            if(num == 1){
                if(tree->left == NULL){
                    free(tree);
                    return NULL;
                }
                tree = tree->left;
                free(tree->parent);
                tree->parent = NULL;
            }
            else if(e > tree->parent->value){
                tree->parent->right = tree->left;
                free(tree);
            }
            else{
                tree->parent->left = tree->left;
                free(tree);
            }
        }
        else{
            Node *find = tree->left;
            while(find->right != NULL)
                find = find->right;
            tree->value = find->value;
            if(find->parent == tree)
                tree->left = find->left;
            else
                find->parent->right = find->left;
        }
    }
    return t;
}

Node *search(BinaryTree tree, ElemType e){
    if(tree == NULL || e == tree->value)
        return tree;
    else if(e > tree->value)
        return search(tree->right,e);
    else if(e < tree->value)
        return search(tree->left,e);
}
//递归前序
Status preorder(BinaryTree tree){
    if(tree == NULL)
        return FALSE;
    visit(tree->value);
    preorder(tree->left);
    preorder(tree->right);
}
//递归中序
Status inorder(BinaryTree tree){
    if(tree == NULL)
        return FALSE;
    inorder(tree->left);
    visit(tree->value);
    inorder(tree->right);
}
//递归后序
Status postorder(BinaryTree tree){
    if(tree == NULL)
        return FALSE;
    postorder(tree->left);
    postorder(tree->right);
    visit(tree->value);
}


//非递归前序
void preorderNoReturn(BinaryTree tree){
    LinkedStack *s = (LinkedStack *)malloc(sizeof(LinkedStack));
    InitStack(s);
    Node *p = tree;
    Node *q;
    int x;
    while(p || !isEmptyStack(s)){
        if(p){
            visit(p->value);
            push(s,p->value);
            p = p->left;
        }
        else{
            pop(s,&x);
            q = search(tree,x);
            p = q->right;
        }
    }
}

//非递归中序
void inorderNoReturn(BinaryTree tree){
    LinkedStack *s = (LinkedStack *)malloc(sizeof(LinkedStack));
    InitStack(s);
    Node *p = tree;
    Node *q;
    int x;
    while(p || !isEmptyStack(s)){
        if(p){
            push(s,p->value);
            p = p->left;
        }
        else{
            pop(s,&x);
            q = search(tree,x);
            visit(q->value);
            p = q->right;
        }
    }
}

//非递归后序
void postorderNoReturn(BinaryTree tree){
    LinkedStack *s = (LinkedStack *)malloc(sizeof(LinkedStack));
    InitStack(s);
    Node *p = tree;
    Node *q = NULL;
    Node *t;
    int x,y;
    while(p || !isEmptyStack(s)){
        if(p){
            push(s,p->value);
            p = p->left;
        }
        else{
            getTop(s,&x);
            p = search(tree,x);
            if(p->right && p->right != q){
                p = p->right;
                push(s,p->value);
                p = p->left;
            }
            else{
                pop(s,&x);
                p = search(tree,x);
                printf("%d ",x);
                q = p;
                p = NULL;
            }
        }
    }
}
void level(BinaryTree tree,int leve){
    if(tree == NULL)
        return;
    else if(leve == 1)
        visit(tree->value);
    else{
        level(tree->left,leve - 1);
        level(tree->right,leve - 1);
    }
}
Status levelorder(BinaryTree tree){
    int height = getHeight(tree);
    for(int i = 0;i <= height;i++){
        level(tree,i);
    }
}
int getHeight(BinaryTree tree){
    int left, right;
    if(tree == NULL)
        return 0;
    else{
        left = getHeight(tree->left);
        right = getHeight(tree->right);
        return left > right ? (left + 1) : (right + 1);
    }
}

int Scan(){
    char t[10];
    int i;
    while(1){
        printf("输入数据(整数)(输入#为不输入):");
        gets(t);
        if(t[0] == '#')
            return -999;
        for(i = 0;t[i];i++)
            if(t[i] > '9' || t[i] < '0'){
                i = -1;
                break;
            }
        if(i == -1 || strlen(t) == 0)
            printf("输入错误请重新输入\n");
        else
            return atoi(t);
    }
}










Status InitStack(LinkedStack *L){
    L->top = (sNode *)malloc(sizeof(sNode));
    if(!L->top)
        return FALSE;
    L->top = NULL;
    L->count = 0;
    return TRUE;
}
//栈是否为空
Status isEmptyStack(LinkedStack *L){
    if(!L->count)
        return TRUE;
    return FALSE;
}

//获取栈长度
int StackLength(LinkedStack *L){
    return L->count;
}
//获取栈顶元素
Status getTop(LinkedStack *L,ElemType *e){
    if(isEmptyStack(L))
        return FALSE;
    *e = L->top->data;
    return TRUE;
}
//进栈
Status push(LinkedStack *L,ElemType e){
    sNode *p = (sNode *)malloc(sizeof(sNode));
    p->data = e;
    p->next = L->top;
    L->top = p;
    L->count++;
    return TRUE;
}
//出栈
Status pop(LinkedStack *L,ElemType *e){
    if(isEmptyStack(L))
        return FALSE;
    sNode *p = L->top;
    *e = p->data;
    L->top = p->next;
    free(p);
    L->count--;
    return TRUE;
}









//创建队列
Status InitQueue(Queue *Q){
    qNode * s = (qNode *)malloc(sizeof(qNode));
    Q->front = Q->rear = s;
    Q->front->next = NULL;
    Q->length = 0;
    return TRUE;
}

//判断队列是否为空
Status isEmptyQueue(Queue *Q){
    if(Q->length == 0)
        return TRUE;
    return FALSE;
}



//获取队列长度
int QueueLength(Queue *Q){
    return Q->length;
}

//进队列
Status enQueue(Queue *Q,ElemType *e){
    qNode *node = (qNode *)malloc(sizeof(qNode));
    node->data;
    node->next = NULL;
    if(Q->length == 0){
        Q->rear = Q->front = node;
    }
    else{
        Q->rear->next = node;
        Q->rear = node;
    }
    Q->length++;
}

//出队列
Status deQueue(Queue *Q,ElemType *e){
    if(isEmptyQueue(Q))
        return FALSE;
    qNode *t = Q->front;
    if(Q->front == Q->rear)
        Q->front = Q->rear = NULL;
    else
        Q->front = Q->front->next;
    *e = t->data;
    free(t);
    Q->length--;
    return TRUE;
}
