#include<stdio.h>

#include<sys/ipc.h>

#include<sys/types.h>

#include<sys/shm.h>

#include<unistd.h>

#include<stdlib.h>

#include<string.h>

int main(){

int shmid,key;

char buff[100];

key=5678;

void *shared_memory;



shmid=shmget(key,1024,0666|IPC_CREAT); //process creation

printf("key of the shared memory is %d \n",shmid);

shared_memory=shmat(shmid,NULL,0);  //process attached

printf("the address of the shared memory is %p \n",shared_memory);



read(0,buff,100);

strcpy(shared_memory,buff);







}
