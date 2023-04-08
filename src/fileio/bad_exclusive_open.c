#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ename.c.inc"
#include "errno.h"
#include "error_functions.h"

int main(int argc, char* argv[])
{
    int  fd;
    char buf[32];

    fd = open(argv[1], O_WRONLY); /* Open 1: check if file exists */
    if (fd != -1) {               /* Open succeeded */
        printf("[PID %ld] File \"%s\" already exists\n", (long)getpid(),
               argv[1]);
        close(fd);
    } else {
        if (errno != ENOENT) { /* Failed for unexpected reason */
            errExit("open");
        } else {
#if 1
            printf("[PID %ld] File \"%s\" doesn't exist yet\n",
                   (long)getpid(), argv[1]);
            if (argc > 2) { /* Delay between check and create */
                sleep(5);   /* Suspend execution for 5 seconds */
                printf("[PID %ld] Done sleeping\n", (long)getpid());
            }
#endif
            fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
            if (fd == -1)
                errExit("open");

            printf("[PID %ld] Created file \"%s\" exclusively\n",
                   (long)getpid(), argv[1]);
            /* MAY NOT BE TRUE! */

            sprintf(buf, "%d%c", getpid(), '\0');
            write(fd, buf, strlen(buf));

            close(fd);
        }
    }

    return 0;
}