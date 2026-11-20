#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdalign.h>
struct memoryStruct {
    unsigned char * memoryBegin;
    size_t memorySize;
    size_t memoryUsed;
};
void memoryArena(struct memoryStruct *arena,size_t capacity);
void *memoryAllocator(struct memoryStruct *arena,size_t memoryRequest,size_t padiing);
void resetArena(struct memoryStruct *arena);


int main(){
    struct memoryStruct arena ={NULL,0,0};
    memoryArena(&arena,1024);
    void *memoryAllocAdresss = memoryAllocator(&arena,100,1);
    resetArena(&arena);
    void *memoryAllocAdresss2 = memoryAllocator(&arena,sizeof(double),alignof(double));
    printf("starting Adresss : %p\n",(void*)arena.memoryBegin);
    printf("1st Allocator Adresss : %p\n",(void*)memoryAllocAdresss);
    printf("2st Allocator Adresss : %p\n",(void*)memoryAllocAdresss2);
    printf("Memory Size : %d\n",arena.memorySize);
    printf("Memory used : %d\n",arena.memoryUsed);
}

void memoryArena(struct memoryStruct *arena,size_t capacity){
    if(capacity == 0){return;}
    unsigned char*memoryAdress= malloc(capacity);
    arena->memoryBegin = memoryAdress;
    arena->memorySize =capacity;
    arena->memoryUsed =0;
};

void *memoryAllocator(struct memoryStruct *arena,size_t memoryRequest,size_t padding){
    if(padding==0)return NULL;
 size_t availableMemory = arena->memorySize - arena->memoryUsed;
if(availableMemory>=memoryRequest){
unsigned char *requestedMemoryAdresss = arena->memoryBegin+arena->memoryUsed;

 uintptr_t paddingAdress = (uintptr_t)requestedMemoryAdresss;

  size_t extraSpace = 0;

  if(paddingAdress%padding!=0)
  {
    size_t MoveForwAdress = paddingAdress%padding;
    extraSpace = padding-MoveForwAdress;
     arena->memoryUsed+=extraSpace;
     unsigned char *newRequestedMemoryAdresss = arena->memoryBegin+arena->memoryUsed;
     arena->memoryUsed+=memoryRequest;
        
     return newRequestedMemoryAdresss;
  } else {
    unsigned char *newRequestedMemoryAdresss2 = arena->memoryBegin+arena->memoryUsed;
     arena->memoryUsed+=memoryRequest;
     return newRequestedMemoryAdresss2;}
  }

 }



void resetArena(struct memoryStruct *arena){
  arena->memoryUsed = 0;
}

