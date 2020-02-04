#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 6

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

//lay phan tu dau tien
int peek();
// them
void insert(int data);
//xoa
int removeData();



int peek(){
   return intArray[front];
}

bool isEmpty(){
   return itemCount == 0;
}

bool isFull(){
   return itemCount == MAX;
}

int size(){
   return itemCount;
}  

void insert(int data){

   if(!isFull()){
	
      if(rear == MAX-1){
         rear = -1;            
      }       

      intArray[++rear] = data;
      itemCount++;
   }
}

int removeData(){
   int data = intArray[front++];
	
   if(front == MAX){
      front = 0;
   }
	
   itemCount--;
   return data;  
}

// int main() {
//    /* chen 5 phan tu */
//    insert(3);
//    insert(5);
//    insert(9);
//    insert(1);
//    insert(12);
//    insert(15);	
//    if(isFull()){
//       printf("Hang doi (Queue) da day!\n");   
//    }

//    // xoa mot phan tu 
//    int num = removeData();
	
//    printf("Phan tu bi xoa: %d\n",num);
//    // Chen them mot phan tu
//    insert(16);
//    // neu hang doi la day thi phan tu se khong duoc chen. 
//    insert(17);
//    insert(18);
//    printf("Phan tu tai vi tri front: %d\n",peek());

//    printf("----------------------\n");
//    printf("Gia tri chi muc : 5 4 3 2  1  0\n");
//    printf("----------------------\n");
//    printf("Hang doi (Queue):  ");
	
//    while(!isEmpty()){
//       int n = removeData();           
//       printf("%d ",n);
//    }   
// }