#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void handler(int); 
/* one handler for both signals */
int main(void) { 
if (signal(SIGUSR1, handler) == SIG_ERR) 
    perror("can't catch SIGUSR1"); 
if (signal(SIGUSR2, handler) == SIG_ERR) 
    perror("can't catch SIGUSR2"); 
for ( ; ; ) 
    pause(); 
}
static void handler(int signo) {   
/* argument is signal number */
if (signo == SIGUSR1) 
    printf("received SIGUSR1\n"); 
else if
 (signo == SIGUSR2) 
    printf("received SIGUSR2\n"); 
else
 {  printf("received signal %d\n", signo); 
    abort(); 
    exit(1);   } 
return; 
}
 
