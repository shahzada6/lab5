#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/sendfile.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/sendfile.h>
#include <sys/random.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h> 
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

int main()
{
    int fd1, fd2;
    const char *file1 = "LAB04_ONE";
    const char *file2 = "LAB04_TWO";
    const char text[] = "We are writing data inside a file with Write command";
   
    if (creat(file1, 0666) == -1)
    {
        fprintf(stderr, "Error creating %s\n", file1);
        return 1;
    }


    if ((fd1 = open(file1, O_RDWR)) == -1)
    {
        fprintf(stderr, "Error opening %s in read-write mode\n", file1);
        return 2;
    }

 
    write(fd1, text, sizeof(text));
    lseek(fd1, 0, SEEK_SET);

   
    if (creat(file2, 0666) == -1)
    {
        fprintf(stderr, "Error creating %s\n", file2);
        return 1;
    }

  
    if ((fd2 = open(file2, O_WRONLY)) == -1)
    {
        fprintf(stderr, "Error opening %s in write mode\n", file2);
        return 2;
    }

    // Use sndfile to write content in "LAB04_ONE" into "LAB04_TWO"
    if(sendfile(fd2, fd1, NULL, sizeof(text)))
    {
     printf(text);
}
else
{
printf("copying unsuccessful");
}
    // Close the files
    close(fd1);
    close(fd2);
}
