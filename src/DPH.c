//
// Created by saeed on 1/6/23.
//
#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    // init semaphores
    for (int i = 0; i <= 5; i++)
        sem_init(i, 1);
    // run philosopher processes
    for (int i = 0; i < 5; i++) {
        int pid = fork();
        if (pid == 0) {
            char args[1] = {(char) i + 48};
            char *ph_handler[] = {(char *) "philosopher", args, 0};
            exec("philosopher", ph_handler);
        }
    }
    for (int i = 0; i < 5; i++)
        wait();
    exit();
}