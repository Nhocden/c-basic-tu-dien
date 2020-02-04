#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int length();
//hien thi list bat dau tu first toi last
void displayForward();
//hien thi list bat dau tu last toi first
void displayBackward();
//chen link tai vi tri dau tien
void insertFirst(int key, int data);
//chen link tai vi tri cuoi cung
void insertLast(int key, int data);
//chen sau gia tri k
bool insertAfter(int key, int newKey, int data);
//xoa phan tu dau tien
struct node* deleteFirst();
//xoa link tai vi tri cuoi cung
struct node* deleteLast();
//xoa mot link voi key da cho
struct node* deleteKey(int key);


struct node {
   int data;
   int key;
	
   struct node *next;
   struct node *prev;
};

//link nay luon luon tro toi first Link 
struct node *head = NULL;

//link nay luon luon tro toi last Link 
struct node *last = NULL;

struct node *current = NULL;

//kiem tra xem list co trong khong
bool isEmpty(){
   return head == NULL;
}

// so luong node
int length(){
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next){
      length++;
   }
	
   return length;
}

//hien thi list bat dau tu first toi last
void displayForward(){

   //bat dau tu phan dau list
   struct node *ptr = head;
	
   //duyet toi cuoi list
   printf("\n[ ");
	
   while(ptr != NULL){        
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

//hien thi list bat dau tu last toi first
void displayBackward(){

   //bat dau tu cuoi list
   struct node *ptr = last;
	
   //duyet toi phan dau list
   printf("\n[ ");
	
   while(ptr != NULL){    
	
      //in du lieu
      printf("(%d,%d) ",ptr->key,ptr->data);
		
      //di chuyen toi phan tu tiep theo
      ptr = ptr ->prev;
      printf(" ");
   }
	
   printf(" ]");
}


//chen link tai vi tri dau tien
void insertFirst(int key, int data){

   //tao mot link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;
	
   if(isEmpty()){
      //lam cho no thanh last link
      last = link;
   }else {
      //cap nhat first prev link
      head->prev = link;
   }

   //tro no toi first link cu
   link->next = head;
	
   //tro first toi first link moi
   head = link;
}

//chen link tai vi tri cuoi cung
void insertLast(int key, int data){

   //tao mot link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;
	
   if(isEmpty()){
      //lam cho no thanh last link
      last = link;
   }else {
      //lam cho no thanh last link moi
      last->next = link;     
      //danh dau last node la prev cua link moi
      link->prev = last;
   }

   //tro last toi last node moi
   last = link;
}

//xoa phan tu dau tien
struct node* deleteFirst(){

   //luu tham chieu toi first link
   struct node *tempLink = head;
	
   //neu chi co link
   if(head->next == NULL){
      last = NULL;
   }else {
      head->next->prev = NULL;
   }
	
   head = head->next;
   //tra ve link da bi xoa
   return tempLink;
}

//xoa link tai vi tri cuoi cung

struct node* deleteLast(){
   //luu tham chieu toi last link
   struct node *tempLink = last;
	
   //neu chi co link
   if(head->next == NULL){
      head = NULL;
   }else {
      last->prev->next = NULL;
   }
	
   last = last->prev;
	
   //tra ve link bi xoa
   return tempLink;
}

//xoa mot link voi key da cho

struct node* deleteKey(int key){

   //bat dau tu link dau tien
   struct node* current = head;
   struct node* previous = NULL;
	
   //neu list la trong
   if(head == NULL){
      return NULL;
   }

   //duyet qua list
   while(current->key != key){
      //neu no la last node
		
      if(current->next == NULL){
         return NULL;
      }else {
         //luu tham chieu toi link hien tai
         previous = current;
			
         //di chuyen next link
         current = current->next;             
      }
   }

   //cap nhat link
   if(current == head) {
      //thay doi first de tro toi next link
      head = head->next;
   }else {
      //bo qua link hien tai
      current->prev->next = current->next;
   }    

   if(current == last){
      //thay doi last de tro toi prev link
      last = current->prev;
   }else {
      current->next->prev = current->prev;
   }
	
   return current;
}

bool insertAfter(int key, int newKey, int data){
   //bat dau tu first link
   struct node *current = head; 
	
   //neu list la trong
   if(head == NULL){
      return false;
   }

   //duyet qua list
   while(current->key != key){
	
      //neu day la last node
      if(current->next == NULL){
         return false;
      }else {           
         //di chuyen next link
         current = current->next;             
      }
}
	
    //tao mot link
    struct node *newLink = (struct node*) malloc(sizeof(struct node));
   newLink->key = newKey;
   newLink->data = data;

   if(current == last) {
      newLink->next = NULL; 
      last = newLink; 
   }else {
      newLink->next = current->next;         
      current->next->prev = newLink;
   }
	
   newLink->prev = current; 
   current->next = newLink; 
   return true; 
}

// int main() {

//    insertFirst(1,10);
//    insertFirst(2,20);
//    insertFirst(3,30);
//    insertFirst(4,1);
//    insertFirst(5,40);
//    insertFirst(6,56); 

//    printf("\nIn danh sach (First ---> Last): ");  
//    displayForward();
	
//    printf("\n");
//    printf("\nIn danh sach (Last ---> first): "); 
//    displayBackward();

//    printf("\nDanh sach, sau khi xoa ban ghi dau tien: ");
//    deleteFirst();        
//    displayForward();

//    printf("\nDanh sach, sau khi xoa ban ghi cuoi cung: ");  
//    deleteLast();
//    displayForward();

//    printf("\nDanh sach, chen them phan tu sau key(4): ");  
//    insertAfter(4,7, 13);
//    displayForward();

//    printf("\nDanh sach, sau khi xoa key(4) : ");  
//    deleteKey(4);
//    displayForward();
// }