#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "terminal_control.h"
#include "horse.h"

pthread_barrier_t barrier;
pthread_mutex_t print_lock;
pthread_mutex_t win_lock;
int win_counter = 0;
int last_printed = -1;

void* race(void* arg) {
    int id = *(int*)arg;

    pthread_barrier_wait(&barrier); //wait until all threads joined

    char* colors[2] = {
        TC_YEL,
        TC_WHT
    };
    int color_id = 0;

    int dec_count = 0; 

    //print trace from 1 to 100  
    for (int i = 1; i <= 100; i++) {
        char buffer[5] = {'.', '\0'};
        int col = i + dec_count;

        //prepare buffer
        if (i % 10 == 0) {
            dec_count++;
            sprintf(buffer, "%d", i);
            col--;
        }

        //attomic print trace and horse
        pthread_mutex_lock(&print_lock);

        if (last_printed != id) {
            color_id = !color_id;
            last_printed = id;
        }

        tc_mv_cursor(id * 3 + 2, col);
        printf("%s%s%s", colors[color_id], buffer, TC_RST);
        print_horse(id * 3 + 1, i + 2 + dec_count, i/5, id);

        pthread_mutex_unlock(&print_lock);
    }

    //print winning text as an atomic section
    pthread_mutex_lock(&win_lock);

    tc_mv_cursor(id * 3 + 2, 100 + dec_count + 12 ); 
    win_counter++;
    printf("%d place", win_counter);

    pthread_mutex_unlock(&win_lock);

    return NULL;
}


int main() {
    int n_threads;

    //ask for number of threats to race
    printf("Input the number of threads to race: ");
    scanf("%d", &n_threads); 

    //allocate memorie for threads
    pthread_t *threads = (pthread_t *)malloc(sizeof(pthread_t) * n_threads);
    int* ids = malloc(n_threads * sizeof(int));

    if (threads == NULL || ids == NULL) { //ensure memory safety
        puts("Unable to allocate memory for variable \'threads\'");
        return 1;
    }

    //inicialize thread barrier
    pthread_barrier_init(&barrier, NULL, n_threads);
    pthread_mutex_init(&print_lock, NULL);
    pthread_mutex_init(&win_lock, NULL);

    //create threads
    for (int i = 0; i < n_threads; i++){
        ids[i] = i;
        pthread_create(&threads[i], NULL, race, &ids[i]);
    }

    tc_clear(); //clear terminal before thread race

    //strat all threads
    for (int i = 0; i < n_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    //destroy pthread entities
    pthread_barrier_destroy(&barrier);
    pthread_mutex_destroy(&print_lock);
    pthread_mutex_destroy(&win_lock);

    //free alocated memory
    free(threads);
    free(ids);

    tc_mv_cursor(n_threads * 3 + 1, 0);

    return 0;
}