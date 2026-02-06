
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

// Palindrome checking function
int isPalindrome(char *str)
{
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        if (str[i] != str[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

// Function designed for palindrome checking
void func(int connfd)
{
    char buff[MAX];

    for (;;) {
        bzero(buff, MAX);

        // Read string from client
        int n = read(connfd, buff, MAX);
        if (n <= 0)
            break;

        // Remove newline
        buff[strcspn(buff, "\n")] = '\0';

        printf("From client: %s\n", buff);

        // Exit condition
        if (strcmp(buff, "exit") == 0) {
            printf("Server Exit...\n");
            break;
        }

        // Palindrome check
        if (isPalindrome(buff))
            strcpy(buff, "Palindrome");
        else
            strcpy(buff, "Not Palindrome");

        // Send result to client
        write(connfd, buff, strlen(buff) + 1);
    }

    close(connfd);
}

// Driver function
int main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");

    len = sizeof(cli);
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("server accept failed...\n");
        exit(0);
    }
    else
        printf("server accept the client...\n");

    func(connfd);

    close(sockfd);
}


	


