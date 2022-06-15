#include<stdio.h>

#include<string.h>

#include<sys/types.h>

#include<sys/ipc.h>

#include<sys/shm.h>

#include<unistd.h>

#include<stdlib.h>

int main(){

void *shared_memory;

char buff[100];

int shmid,key;

key=5678;

shmid=shmget(key,1024,0666);

shared_memory=shmat(shmid,NULL,0);



printf("Process attached with shared memory is %p \n ",shared_memory); //address in decimal

printf("data read from shared memory is %s",(char*)shared_memory);

}
