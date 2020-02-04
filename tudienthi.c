#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"
#include <ctype.h>

void danhsachmenu(){
  printf("\n--------------------MENU------------------\n");
  printf("1.nap tu dien\n");
  printf("2.noi dung tu dien\n");
  printf("3.them/sua tu\n");
  printf("4.dich cau anh - viet\n");
  printf("5.Quit.\n");
}


void ReadText(FILE *fin,ElementType element,TreeType *T){
  char c;
  int j=0;
  printf("\nnoi dung file sau khi luu:\n\n");
  printf("%-20s %-50s\n\n","TU","NGHIA");
  while(!feof(fin)){
  //   fscanf(fin,"%s",element[j].tu);
  //   fgetc(fin);
  //   fgets(element[j].nghia,20,fin);
  //   element[j].nghia[strlen(element[j].nghia)-1]='\0';
  //   j++;
  // }
  // for(int i=0;i<j;i++)
  
    fscanf(fin,"%s %s",element.tu,element.nghia);
    printf("%-20s %-50s\n",element.tu,element.nghia);
    InsertNode(element,T);
  }
}

void totext(FILE *fin,TreeType T){
  if((fin=fopen("tudien.txt","a"))==NULL){
          printf("khong the mo file!\n");
          
    }
        
  if(T==NULL){
    MakeNullTree(&T);
    printf("hien tai cay chua co phan tu nao\nnhap them tu cho cay:\n");
  }
  
      // totext(fout,T->left);
      // fprintf(fout,"%-20s %-50s\n",T->element.tu,T->element.nghia);
      // totext(fout,T->right);
      
      ElementType element;
      printf("nhap tu: ");scanf("%s",element.tu);
      TreeType check=Search(element.tu,T);
      if(check==NULL){
        printf("nhap nghia: ");scanf("%s",element.nghia);
        InsertNode(element,&T);
        fprintf(fin,"\n%s %s",element.tu,element.nghia);
        printf("da them tu thanh cong !\n");
      }
      else
      {
        printf("tu da ton tai\nnhap y/n de thay doi nghia cua tu\n");
        char text[10];
        scanf("%s",text);
        if(strcmp(text,"y")==0){
          printf("nhap nghia: ");scanf("%s",element.nghia);
          DeleteNode(element.tu,&T);
          InsertNode(element,&T);
          fprintf(fin,"\n%s %s",element.tu,element.nghia);
          printf("da sua tu thanh cong !\n");
        }
        if(strcmp(text,"n")==0)
        {
          
        }
      }

    fclose(fin);
}
//void dich(char cau1,

int main(){
   FILE *fin;
  int i,j,n,menu;
  ElementType element,tach[50];
  TreeType T;
  MakeNullTree(&T);
  do{
    danhsachmenu();
    printf("Chon menu: ");scanf("%d",&menu);
    switch(menu){
    case 1:
      {
          printf("\t++++++++++ NAP TU DIEN ++++++++++\n");
          if((fin=fopen("tudien.txt","r"))==NULL){
            printf("khong the mo file!\n");
            return 1;
          }
          ReadText(fin,element,&T);
          fclose(fin);
          break;
      }
    case 2:
      {
          printf("\t++++++++++ SAP XEP TU DIEN++++++++++\n");
          inorderprint(T);
          break;
      }
   case 3:
      {
         printf("\t++++++++++++ THEM / SUA TU ++++++++\n");
        
        totext(fin,T);
        
        break;
      }
    case 4:
      {
          printf("\t++++++++++++ DICH ANH - VIET ++++++++\n");
          char cau[100],cau1[100],s1[50][10],*p;
          int dem=0;
          printf("Nhap vao 1 cau tieng anh: ");
          __fpurge(stdin);
          // gets(cau1,30);
          // scanf("%s",cau1);
          fgets(cau1,sizeof(cau1),stdin);
          for(int i=0;i<strlen(cau1);i++){
            if(isupper(cau1[i])) cau1[i]=tolower(cau1[i]);
            }
          p=strtok(cau1," ");
          while(p != NULL){
                strcpy(s1[dem],p);
                dem++;
                printf("%s\n",p);
                p=strtok(NULL," ");
              }

          printf("phan dich:\n\n");
          TreeType pr;
          for(int i=0;i<dem;i++){
            pr=Search(s1[i],T);
            if(pr != NULL)
              printf("%s\n",pr->element.nghia);
            else
            printf("<tu thieu>\n");
          }
          printf("\n");
          printf("bo sung va chinh sua tu:\n");
          // for(int i=0;i<dem;i++){
          //   pr=NULL;
          //   pr=Search(s1[i],T);
          //   if(pr==NULL){
          //     printf("Tu chua co trong tu dien\nNhap bo sung: ");ElementType a[1];
          //     // gets(a[0].nghia);
          //     scanf("%s",a[0].nghia);
          //     strcpy(a[0].tu,s1[i]);
          //       InsertNode(a[0],&T);
          //   }
          // }
          //       TreeType q;q=NULL;
          // for(int i=0;i<dem;i++){
          //   q=Search(s1[i],T);
          //   printf("%s ",q->element.nghia);
          // }
          // printf("\n");
          totext(fin,T);
          break;
      }

    case 5:
      {
          freetree(T);
          break;
      }
    }
    }while(menu>0&&menu<5);
  return 0;
}
