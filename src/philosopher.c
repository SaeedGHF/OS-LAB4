//
// Created by saeed on 1/6/23.
//
#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    int i = atoi(argv[1]);
    int j = (i + 1) % 5;
    while (1) {
        // acquiring
        // An even philosopher should pick the right chopstick and then the left chopstick while an odd philosopher should pick the left chopstick and then the right chopstick.
        if (i % 2 == 0) {
            sem_acquire(i);
            sem_acquire(j);
        } else {
            sem_acquire(j);
            sem_acquire(i);
        }
        // logging
        sleep(500);
        sem_acquire(5);
        printf(1, "Philosopher %d locked %d and %d\n", i, i, j);
        sem_release(5);
        // releasing
        sem_release(i);
        sem_release(j);
        // logging
        sleep(500);
        sem_acquire(5);
        printf(1, "Philosopher %d released %d and %d\n", i, i, j);
        sem_release(5);
    }
    exit();
}