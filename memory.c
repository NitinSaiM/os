#include<stdio.h>

#include<sys/ipc.h>

#include<sys/types.h>

#include<sys/shm.h>

#include<unistd.h>

#include<stdlib.h>

#include<string.h>

int main(){

int shmid,key,n;

char buff[100];

void *shared_memory;

key=5678;

shmid=shmget(key,1024,0666|IPC_CREAT); //process creation

printf("key of the shared memory is %d \n",shmid);

shared_memory=shmat(shmid,NULL,0);  //process attached

printf("the address of the shared memory is %d",shared_memory);   //decimal format

printf("the address of the shared memory is %p",shared_memory);   //hexadecimal format

int *a=shared_memory;

















printf("Enter the number of elements");

scanf("%d",&n);

printf("Enter the array elements");

for (int i=0; i<=n-1;i++)

{

scanf("%d",&a[i]);

}







int pid=fork();

if(pid<0){

printf("Invalid");

}else if(pid ==0){

int b[n],i;

for(i=0;i<n;i++){

b[i]=a[i];

}

int temp;

for (int i=0;i<n-1;i++)

{

    for (int j=i+1;j<=n-1;j++)

    {

        if (b[j]>b[i])

        {

            temp=b[j];

            b[j]=b[i];

            b[i]=temp;

        }

    }

}



for(i=0;i<n;i++){

a[i+n]=b[i];

}



}else{

wait();

printf("before sorting\n");

for (int i=0; i<=n-1;i++)

{

printf("%d \n",a[i]);

}

printf("after sorting \n");

for (int i=n; i<=2*n-1;i++)

{

printf("%d \n",a[i]);

}



}



}
