#include<stdio.h>

#include<string.h>

#include<unistd.h>

#include<stdlib.h>

#include<sys/ipc.h>

#include<sys/shm.h>

#include<sys/types.h>



void main()

{

key_t k=123;

int n,*shmptr,*s,shmid;



shmid=shmget(k,100*sizeof(n),IPC_CREAT|0666);

shmptr=shmat(shmid,NULL,0);

s=shmptr;

*(shmptr+1)=-1;

while(*(shmptr+1)!=0)

sleep(1);

n=*s;

s=s+2;

int i,a=0,b=1,c=0;

*s=a;

s++;

*s=b;

s++;

for(i=3;i<=n;i++)

{

c=a+b;

*s=c;

s++;

a=b;

b=c;

}

*(shmptr+1)=1;

shmdt(shmptr);

shmctl(shmid,IPC_RMID,NULL);



}
