
#include <stdio.h>
#include <unistd.h>

int main(){
    printf ("Main before fork()\n");
    int pid1 = fork();
    
    if (pid1 == 0) {
        printf ("launching ps -ef\n");
        char *args[]= { "/bin/ps", "-ef" , NULL};
        execvp("/bin/ps", args);
    }
    int pid2 = fork();
    if (pid2 == 0) {
	printf ("launching free -h\n");
	char *args2[]={ "free","-h",NULL };
	execvp("free",args2);
    }
	else printf ("Child contains ps: %d, Child contains free: %d\n",pid1,pid2);
    
    return 0;
}
