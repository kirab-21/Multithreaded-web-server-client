#include "proxy_parse.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>


#define MAX_CLIENTS 10

typedef struct cache_element cache_element;

struct cache_element {
    char* data;
    int len;
    char* url;
    time_t lru_time_track;
    cache_element* next;
};

cache_element* find(char* url);
int add_cache_element(char* data, int size, char* url);
void remove_cache_element();

int port_number = 8080;
int proxy_socketId;
pthread_t tid[MAX_CLIENTS];
sem_t semaphore;
pthread_mutex_t lock; 

cache_element* head;
int cache_size;

int main(int argc, char* argv[]) {
    int client_socketId, client_len;
    struct sockaddr server_addr, client_addr;
    sem_init(&semaphore, 0, MAX_CLIENTS);

    pthread_mutex_init(&lock, NULL);

    if(argv == 2) {
        port_number = atoi(argv[1]);
    } else {
        printf("Too few arguements \n");
        exit(1);
    }

    printf("Starting Proxy Server at port: %d \n", port_number);
    
}