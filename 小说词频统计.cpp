#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word//链表
{
    char w[30];
    int num;
    struct word* next;
}Word;

Word *head=NULL;
int top=0,l=1,nn=0;

Word* SearchWord(char *t);

void CountWord(char* t);

void Sort();

void Printf();

void Release();

int main()
{
    FILE *fp1;
    char ch,temp[30];
    int i,flag;
    printf("统计一篇英文小说中每个词在该小说中的出现频率，\n将每个词的出现频率写入一个文件中。\n");
    if((fp1=fopen("F:\\123.txt","r"))==NULL)
    {
        printf("cant open file\n");
        exit(0);
    }
    while( EOF != (fscanf(fp1,"%s",temp)) )
    {
        int i,n,j,t;
        char temp2[30];
        n=strlen(temp);
        j=0;
        for(i=0;i<n;i++)
        {
            if((temp[i]>='A'&&temp[i]<='Z')||(temp[i]>='a'&&temp[i]<='z'))
            {
                temp2[j++]=temp[i];
            }
        }
        n=j;
        temp2[n]='\0';
        if(temp2[0]=='\0')
        {
            continue;
        }
        for(i=0;i<n;i++)
        {
            if(temp2[i]>=65&&temp2[i]<=90)
            {
                temp2[i]=temp2[i]+32;
            }
        }
        nn++;
           CountWord(temp2);
    }
       Sort();
       Printf();
    printf("共%d个单词\n",nn);
    Release();
    fclose(fp1);
    return 0;
}

Word* SearchWord(char *t)
{
    if(head==NULL)
    {
        head=(Word*)malloc(sizeof(Word));
        strcpy(head->w,t);
        head->num=0;
        head->next=NULL;
        return head;
    }
    Word *p,*pre=NULL;
    p=head;
    while(p)
    {
        if(strcmp(t,p->w)==0)
        {
            break;
        }
        pre=p;
        p=p->next;
    }
    if(p==NULL)
    {
        p=(Word*)malloc(sizeof(Word));
        strcpy(p->w,t);
        p->num=0;
        pre->next=p;
        p->next=NULL;
    }
    return p;
}

void CountWord(char* t)
{
    Word *p=NULL;
    p=SearchWord(t);
    if(p==NULL)
    {
        return;
    }
    else
    {
        p->num++;
    }
}

void Sort()
{
    Word *p1,*p2;
    char t[30];
    p1=head;
    while(p1)
    {
        p2=p1->next;
        while(p2)
        {
            if(strcmp(p1->w,p2->w)>0)
            {
                strcpy(t,p1->w);
                strcpy(p1->w,p2->w);
                strcpy(p2->w,t);
            }
            p2=p2->next;
        }
        p1=p1->next;
    }
}

void Printf()
{
    FILE *fp;
    Word *p;
    int i=0;
    if((fp=fopen("F:\\12333.txt","w"))==NULL)
    {
        printf("cant open file\n");
        exit(0);
    }
    p=head;
    while(p)
    {
        printf("第[%d]个单词为 %s 出现的频率为%d\n",++i,p->w,p->num);
        fprintf(fp,"第[%d]个单词为 %s 出现的频率为%d\n",i,p->w,p->num);
        p=p->next;
    }
    fclose(fp);
}

void Release()
{
    Word *p=head;
    while(p)
    {
        head= p->next;
        delete p;
        p=head;
    }
}

