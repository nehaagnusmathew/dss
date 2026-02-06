
#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void func(int sockfd)
{
    char buff[MAX];
    int n;

    for (;;) {
        bzero(buff, MAX);
        printf("Enter the string : ");

        // Read input from user
        n = 0;
        while ((buff[n++] = getchar()) != '\n');

        // Remove newline
        buff[strcspn(buff, "\n")] = '\0';

        // Send string to server
        write(sockfd, buff, strlen(buff) + 1);

        // Exit condition
        if (strcmp(buff, "exit") == 0) {
            printf("Client Exit...\n");
            break;
        }

        // Read result from server
        bzero(buff, MAX);
        read(sockfd, buff, MAX);

        printf("From Server : %s\n", buff);
    }
}

int main()
{
    int sockfd;
    struct sockaddr_in servaddr;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");

    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // connect the client socket to server socket
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        perror("connection with the server failed");
        exit(0);
    }
    else
        printf("connected to the server..\n");

    // function for palindrome check
    func(sockfd);

    // close the socket
    close(sockfd);
}


