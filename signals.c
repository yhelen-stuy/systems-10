#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

static void sighandler(int signo) {
    if (signo == SIGINT) {
        int fd = open("errors.log", O_CREAT | O_WRONLY | O_APPEND, 0644);
        char error[] = "Exited due to SIGINT\n";
        write(fd, error, sizeof(error)-1);
        close(fd);
        exit(SIGINT);
    }

    if (signo == SIGUSR1) {
        printf("Hi, parent PID: %d\n", getppid());
    }
}

int main() {
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);

    while (1) {
        printf("PID: %d\n", getpid());
        sleep(1);
    }
}
