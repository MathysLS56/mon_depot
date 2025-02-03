#include "tcp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void traiter_commande(int argc, char** argv, const char* usage) {
    if (argc != 5) {
        fprintf(stderr, "%s\n", usage);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char** argv) {
    traiter_commande(argc, argv, "Usage: <adresse IP> <port> <message> <nb occurences>\n"
                                 "<adresse IP> est une adresse IP au format décimal pointé\n"
                                 "<port> est un port non réservé\n"
                                 "<message> est le message à envoyer\n"
                                 "<nb occurences> est un entier positif");

    const char* ip_address = argv[1];
    int port = atoi(argv[2]);
    const char* message = argv[3];
    int nb_occurences = atoi(argv[4]);

    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < nb_occurences; i++) {
        send(sockfd, message, strlen(message), 0);
    }

    close(sockfd);
    return 0;
}
