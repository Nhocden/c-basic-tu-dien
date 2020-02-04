typedef struct thuatngutinhoc{
  char tu[25];
  char nghia[25];
}ElementType;

typedef struct Node{
  ElementType element;
  struct Node *left,*right;
}Node;

typedef struct Node* TreeType;

void MakeNullTree(TreeType *T){
  (*T)=NULL;
}

int EmptyTree(TreeType T){
  return T==NULL;
}

TreeType LeftChild(TreeType T){
  if(T!=NULL) return T->left;
  else return NULL;
}

TreeType RightChild(TreeType T){
  if(T!=NULL) return T->right;
  else return NULL;
}

int IsLeaf(TreeType T){
  if(T!=NULL)
    return(LeftChild(T)==NULL)&&(RightChild(T)==NULL);
  else return -1;
}

int nb_nodes(TreeType T){
  if(EmptyTree(T))
    return 0;
  else return 1+nb_nodes(LeftChild(T))+nb_nodes(RightChild(T));
}

int height(TreeType T){
  if(T==NULL) return 0;
  int lh=height( LeftChild(T));
  int rh=height( RightChild(T));
  return 1+(lh>rh?lh:rh);
}

int numla(TreeType T){
  if(T==NULL) return 0;
  if((T->left==NULL)&&(T->right==NULL))
    return 1;
  else
    return numla(T->left)+numla(T->right);
}

Node* create_node(ElementType newdata){
  Node *N;
  N=(Node*)malloc(sizeof(Node));
  if(N!=NULL)
    {
      N->left=NULL;
      N->right=NULL;
      N->element=newdata;
    }
  return N;
}

TreeType FindMin(TreeType T){
  if(T->left==NULL)
    return T;
  else return FindMin(T->left);
}

TreeType FindMax(TreeType T){
  if(T->right==NULL)
    return T;
  else return FindMax(T->right);
}

void InsertNode(ElementType x,TreeType *T){
  if(*T==NULL){
    *T=(Node*)malloc(sizeof(Node));
    (*T)->element=x;
    (*T)->left=NULL;
    (*T)->right=NULL;
  }
  else if(strcmp((*T)->element.tu,x.tu)>0)
    InsertNode(x,&(*T)->left);
   else if(strcmp((*T)->element.tu,x.tu)<0)
    InsertNode(x,&(*T)->right);
   else printf("Tu da ton tai trong cay.\n");
}

void inorderprint(TreeType T){
  if(T!=NULL)
    {
      inorderprint(T->left);
      printf("%-25s %c %-40s\n",T->element.tu,':',T->element.nghia);
      inorderprint(T->right);
    }
}

TreeType Search(char *tu,TreeType T){
  if(T==NULL) return NULL;
  else if(strcmp(T->element.tu,tu)==0) return T;
  else if(strcmp(T->element.tu,tu)<0) return Search(tu,T->right);
  else return Search(tu,T->left);
}

void PhanTuTheMang(Node *p,TreeType *T){
  if((*T)->left!=NULL){
    PhanTuTheMang(p,&(*T)->left);
  }
  else{
    (p)->element=(*T)->element;
    p=*T;
    (*T)=(*T)->right;
  }
}

void DeleteNode(char *tu,TreeType *T){
  if((*T)!=NULL){
    if(strcmp((*T)->element.tu,tu)>0) DeleteNode(tu,&(*T)->left);
    else if(strcmp((*T)->element.tu,tu)<0) DeleteNode(tu,&(*T)->right);
    else{
      Node* p=*T;
      if((*T)->left==NULL) (*T)=(*T)->right;
      else if((*T)->right==NULL) (*T)=(*T)->left;
      else PhanTuTheMang(p,&(*T)->right);//trai nhat cua cay con phai
      free(p);
    }
  }
}

void freetree(TreeType T){
  if (T!=NULL)
    {
      freetree(T->left);
      freetree(T->right);
      free((void *) T);
    }
}

typedef struct node
{
  ElementType element;
  struct node* next;
  struct node *prev;
}node;
typedef struct queue
{
    node *front,*rear;
  //int count;
}queue;

void init(queue *q){
  q->front=q->rear=NULL;
}

node* makenode(ElementType x)
{
  node *p=(node*)malloc(sizeof(node));
  p->next=NULL;
  p->element=x;
  return p;
}

int isempty(queue q)
{
    if(q.front==NULL) return 1;
  return 0;
}

void enqueue(queue *q,ElementType x)
{
  node *p=makenode(x);
  if(isempty(*q))
    q->front=q->rear=p;
  else{
    q->rear->next=p;
    q->rear=p;
  }
}

int dequeue(queue *q)
{
  if(isempty(*q)){
    printf("Queue is empty!\n");
    return 0;
  }
  else{
    ElementType x=q->front->element;
    if(q->front->next==NULL) init(q);
    else{
      node *temp;
      temp=q->front;
      q->front=q->front->next;
      free(temp);
    }
    return 1;
  }
}

void DuyetCayTheoChieuRong(TreeType T){
  if(T!=NULL){
    queue q;
    init(&q);
    enqueue(&q,T->element);
    while(isempty(q)!=1){
      //
      TreeType p=T;
      printf("%-25s %c %-40s\n",p->element.tu,':',p->element.nghia);
      dequeue(&q);
      if(p->left!=NULL){
	enqueue(&q,p->left->element);
	p=p->left;
      }
      if(p->right!=NULL){
	enqueue(&q,p->right->element);
	p=p->right;
      }
    }
  }
}
