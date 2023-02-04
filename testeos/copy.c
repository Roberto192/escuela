#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAST_CHAR_PTR (char *)

void *copy_mem(void *_des, void *_data, int size);

int main(){
  int text[] = {85, 84, 85, 85, 0};
  char buff[100];
  
  puts(CAST_CHAR_PTR text);
  copy_mem(buff, text, 5);
  puts(buff);
  
  return 0;
}

void *copy_mem(void *_des, void *_data, int size){
  char *des = CAST_CHAR_PTR _des;
  char *data = CAST_CHAR_PTR _data;
  char d;
  int i, j, n;
  
  for(i = 0; i < size * sizeof(int); i++){
    printf("%d ",data[i]);
    des[i] = data[i];
  }
  
  return des;
}