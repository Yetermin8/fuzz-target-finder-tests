// 15 Relevant Functions
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>

void testLinuxStandardLibrary() {
    // read, pread, readv
    char buffer[100];
    int fd = 0; // Assuming fd is a valid file descriptor
    read(fd, buffer, 100);
    pread(fd, buffer, 100, 0);
    struct iovec iov[1];
    iov[0].iov_base = buffer;
    iov[0].iov_len = 100;
    readv(fd, iov, 1);

    // fread, fgets, getline
    FILE* file = fopen("test.txt", "r");
    if (file) {
        fread(buffer, 1, 100, file);
        fgets(buffer, 100, file);
        char* line = NULL;
        size_t len = 0;
        getline(&line, &len, file);
        free(line);
        fclose(file);
    }

    // recv, recvfrom, recvmsg
    int sockfd = 0; // Assuming sockfd is a valid socket descriptor
    recv(sockfd, buffer, 100, 0);
    struct sockaddr addr;
    socklen_t addrlen = sizeof(addr);
    recvfrom(sockfd, buffer, 100, 0, &addr, &addrlen);
    struct msghdr msg;
    struct iovec iov_msg[1];
    iov_msg[0].iov_base = buffer;
    iov_msg[0].iov_len = 100;
    msg.msg_iov = iov_msg;
    msg.msg_iovlen = 1;
    recvmsg(sockfd, &msg, 0);

    // getenv
    const char* path = getenv("PATH");
    printf("%s\n", path);

    // popen, system
    FILE* pipe = popen("ls", "r");
    if (pipe) {
        fgets(buffer, 100, pipe);
        pclose(pipe);
    }
    system("ls");

    // execl, execle, execlp, execv, execve, execvp
    // Note: These functions will replace the current process, so they are not typically used in normal execution flow
    // execl("/bin/ls", "ls", NULL);
    // execle("/bin/ls", "ls", NULL, NULL);
    // execlp("ls", "ls", NULL);
    // execv("/bin/ls", NULL);
    // execve("/bin/ls", NULL, NULL);
    // execvp("ls", NULL);
}

int main() {
    testLinuxStandardLibrary();
    return 0;
}
