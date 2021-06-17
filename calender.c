#include "calender.h"

//스케줄 관리 프로그램의 작동 로직은 calender.c에서 구현한다.

/*★해야할일★
1. while문 탈출
2. 구조체 배열 내용 없는 곳에 입력받기
→ 임시 구조체 만들어 확인 check함수 만들어서 비교
*/

#include <stdlib.h> //malloc, free
typedef struct schedule{
   int year;
   int month;
   int day;
   char content[30];
   struct schedule *next;
}schedule;

schedule *head=NULL;
//int index=0;
void sub_menu();
void schedule_input();
void main_menu();
void add_node();
void print_node();
int total_days(schedule*, schedule*);

void calender(){
    sub_menu();
}

int main(){
   calender();
}

void sub_menu(){
   int menu_num;
   while(1){
      printf("1. 스케줄 입력\n2. 스케줄 삭제\n3. 스케줄 보기\n4. Main menu\n메뉴 : ");
      scanf("%d",&menu_num);
      getchar();
      if(menu_num==0){
          break;
      }
      switch(menu_num){
         case 1:
            schedule_input();
            break;
         case 2:
            break;
         case 3:
            break;
         case 4:
            main_menu();
            break;
      }
   }
}
void schedule_input(){
   printf("입력 : ");
   printf("\n입력하기전\n");//
   add_node();
   print_node();
   //printf("출력 : %d년 %d월 %d일 %s\n",newnode.year,newnode.month,newnode.day,newnode.content);
   printf("일정을 추가하였습니다.\n아무 키나 입력하세요...\n");
}

void add_node(){
   schedule *newnode = malloc(sizeof(schedule));
   schedule *cur=head;
   int compare;
   scanf("%d %d %d %s",&newnode->year, &newnode->month,&newnode->day,newnode->content);
   getchar();
   if(head==NULL){
      printf("head->next가 null을 가리킴\n");
      head = newnode;
      newnode->next=NULL;
      //index++;
   }
   compare=total_days(cur,newnode);
   else if(compare==1){
      newnode->next=cur;
      head=newnode;
   }
   else{
      while(1){
         compare=total_days(cur->next,newnode);
         switch(compare){
            case 1:
               newnode->next=cur;
               head=newnode;
               break;
            case 2:
               newnode->next=cur->next;
               cur->next=newnode;
               break;
            case 3:
               printf("일정을 추가하려면 y 를, 덮어쓰려면 n 를 입력하세요 :");
               char add;
               scanf("%c",add);
               if(add=='y'){
                  dddd;
               }
               else if(add=='n'){

               }
               else{
                  printf("다시 입력하세요.\n");
               }
               break;
            case 4:
               printf("답 없음\n");
               break;

         }
      }
   }
   /*
   else if(((cur->year) >= (newnode->year))&&((cur->month) >= (newnode->month))&&((cur->day) >= (newnode->day))){
      printf("cur next 전에 newnode 정렬\n");
      newnode->next=cur;
      head=newnode;
   }
   else{
       while(1){
          printf("%d %d %d %s\n", cur->year, cur->month, cur->day, cur->content);
          if((cur->next)==NULL){
             cur->next=newnode;
             newnode->next=NULL;
             printf("\ncur->next가 NULL일때 노드 추가\n");
             break;
         }
         else if(((cur->next->year)>=(newnode->year))&&((cur->next->month)>=(newnode->month))&&((cur->next->day)>=(newnode->day))){
            newnode->next=cur->next;
            cur->next=newnode;
            printf("\nif문 노드 추가\n");
            break;
         }
         cur=cur->next;
         printf("\n다음 노드로 넘어감\n");
      }
   }*/
}


int total_days(schedule *cur, schedule *newnode/*int year, int month, int day*/){
        int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //평년 28일, 윤년 29일
        long cur_total,newnode_total = 0L;

        cur_total = (cur->year - 1) * 365L + (cur->year - 1) / 4 - (cur->year - 1) / 100 + (cur->year - 1) / 400;
        newnode_total = (newnode->year - 1) * 365L + (newnode->year - 1) / 4 - (newnode->year - 1) / 100 + (newnode->year - 1) / 400;
        
        if (!(cur->year % 4) && cur->year % 100 || !(cur->year % 400)) //윤년 구하기
               months[1]++;
        for (int i = 0; i < cur->month - 1; i++)
               cur_total += months[i];
        cur_total += cur->day;
        months[1]--;
        
        if (!(newnode->year % 4) && newnode->year % 100 || !(newnode->year % 400)) //윤년 구하기
               months[1]++;
        for (int i = 0; i < newnode->month - 1; i++)
               newnode_total += months[i];
        newnode_total += newnode->day;

        if(cur_total>newnode_total){
           return 1;
        }
        else if(cur_total<newnode_total){
           return 2;
        }
        else if(cur_total==newnode_total){
           return 3;
        }
        else{
           printf("오류입니다.\n");
           return 4;
        }

        //printf("cur_total : %ld, newnode_total :%ld",cur_total,newnode_total);
}

void print_node(){
   schedule *cur=head;
   while(cur!=NULL){
      printf("출력 : %d년 %d월 %d일 %s\n",cur->year,cur->month,cur->day,cur->content);
      cur=cur->next;
   }
}

void main_menu(){
   //break;
}