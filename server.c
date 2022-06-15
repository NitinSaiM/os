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

int n,*shmptr,*s,shmid,i;

printf("Enter n");

scanf("%d",&n);

shmid=shmget(k,100*sizeof(n),0666);

shmptr=shmat(shmid,NULL,0);

s=shmptr;

*s=n;

*(shmptr+1)=0;



while(*(shmptr+1)==0)

sleep(1);



s=s+2;

for(i=1;i<=n;i++)

{

printf("%d ",*s);

s++;

}

shmdt(shmptr);

}
