#include "udp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

void traiter_commande(int condition, const char* progname, const char* msg) {
    if (!condition) {
        fprintf(stderr, "Usage: %s %s\n", progname, msg);
        exit(1);
    }
}

int main(int argc, char** argv) {
    traiter_commande(argc == 2, argv[0], "<port>\nmauvais nombre d'arguments");

    int port = atoi(argv[1]);
    traiter_commande(port >= 1024 && port <= 65535, argv[0], "<port>\n<port> est un port non réservé");

//----------------prototype socket
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Echec creation socket\n");
        exit(1);
    }

   
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    
    if (bind(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("Echec creation socket");
        close(sock);
        exit(1);
    }

    printf("Serveur écoute sur le port %d\n", port);

    while (1) {
        
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        char buf[1024];
        ssize_t recv_len = recvfrom(sock, buf, sizeof(buf) - 1, 0, (struct sockaddr*) &client_addr, &addr_len);
        if (recv_len == -1) {
            perror("message non reçu");
            close(sock);
            exit(1);
        }

        buf[recv_len] = '\0';
        printf("Message reçu de %s:%d: %s\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buf);

        // reponse
        const char* response = "Message reçu";
        if (sendto(sock, response, strlen(response), 0, (struct sockaddr*) &client_addr, addr_len) == -1) {
            perror("réponse non envoyé");
            close(sock);
            exit(1);
        }
    }

    // Fermeture du socket
    close(sock);

    return 0;
}
