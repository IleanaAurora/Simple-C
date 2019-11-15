#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid, i;
    for (i=0;i<20;i++)
    {
        pid=fork();
        if (pid == 0)
            exit(157);
    }
    sleep(100);
    return 0;
}
