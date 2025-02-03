#include "udp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>

void traiter_commande(int argc, char** argv, const char* usage) {
    if (argc != 5) {
        fprintf(stderr, "%s\n", usage);
        exit(EXIT_FAILURE);
    }

    // Validate IP address
    struct sockaddr_in sa;
    if (inet_pton(AF_INET, argv[1], &(sa.sin_addr)) != 1) {
        fprintf(stderr, "%s\n", usage);
        exit(EXIT_FAILURE);
    }

    // Validate port
    int port = atoi(argv[2]);
    if (port <= 1024 || port > 65535) {
        fprintf(stderr, "%s\n", usage);
        exit(EXIT_FAILURE);
    }

    // Validate number of occurrences
    int nb_occurrences = atoi(argv[4]);
    if (nb_occurrences <= 0) {
        fprintf(stderr, "%s\n", usage);
        exit(EXIT_FAILURE);
    }

    // If all validations pass, proceed with the message
    printf("IP Address: %s\n", argv[1]);
    printf("Port: %d\n", port);
    printf("Message: %s\n", argv[3]);
    printf("Number of occurrences: %d\n", nb_occurrences);
}

int main(int argc, char** argv) {
    traiter_commande(argc, argv, "Usage: <adresse IP> <port> <message> <nb occurences>\n"
                                "<adresse IP> est une adresse IP au format décimal pointé\n"
                                "<port> est un port non réservé\n"
                                "<nb occurences> est un entier positif");

    exit(0);
}

