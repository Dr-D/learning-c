#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define ARRAY_SIZE 40

void *run(void*);
void update_array(int);

int test_array[ARRAY_SIZE];
pthread_mutex_t mutex;

int main(int argc, char *argv[]) {
  const int THREAD_COUNT = 4;

  pthread_t threads[THREAD_COUNT];
  int thread_nums[THREAD_COUNT];

  int i;
  for(i = 0; i < THREAD_COUNT; i++) {
    thread_nums[i] = i;
    int created = pthread_create((threads + i), NULL, run, (thread_nums + i));

    //on success pthread_create returns 0.
    if(created != 0) {
      printf("Failed to create thread.\n");
      exit(EXIT_FAILURE);
    }
  }
  
  for(i = 0; i < THREAD_COUNT; i++) {
    pthread_join(*(threads + i), NULL);
  }

  for(i = 0; i < ARRAY_SIZE; i++) {
    printf("test_array[%d]: '%d'\n", i, test_array[i]);
  }
  
  exit(EXIT_SUCCESS);
}

void *run(void* param) {
  
  int *num = param;
  printf("In thread: '%d'\n", *num);
  update_array(*num);

  return NULL;
}

void update_array(int thread_num) {
  //pthread_mutex_lock(&mutex);
  
  printf("In thread: '%d'\n", thread_num);
  int i;
  for(i = 0; i < ARRAY_SIZE; i++) {    
    int array_val = test_array[i];
    int random = rand() %100;
    usleep(random);
    test_array[i] = ++array_val;
  }

  //pthread_mutex_unlock(&mutex);
}
