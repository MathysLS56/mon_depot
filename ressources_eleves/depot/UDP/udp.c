#include "erreur.h"
#include "udp.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* Créer une socket */
void creer_socket(char* adresseIP, int port, SOCK* sock) {
	
	sock->sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if (sock == -1){
	traiter_erreur(__FUNCTION__);
	sock->addr.sin_family = AF_INET;
    	sock->addr.sin_port = htons(port);
    	if (inet_pton(AF_INET, adresseIP, &sock->addr.sin_addr) <= 0) {
}


void attacher_socket(SOCK* sock) {
	if (bind(sock->sockfd, (struct sockaddr*)&sock->addr, sizeof(sock->addr)) < 0) {
	traiter_erreur(__FUNCTION__);
}

void init_addr(SOCK* sock) {
	memset(&sock->addr, 0, sizeof(sock->addr));
    	sock->addr.sin_family = AF_INET;
}

/* Dimensionner la file d'attente d'une socket */
void dimensionner_file_attente_socket(int taille, SOCK* sock) {
    if (listen(sock->sockfd, taille) < 0) 
	traiter_erreur(__FUNCTION__);
}

/* Recevoir un message */
void recevoir_message(SOCK* dst, char * buffer) {
	
	traiter_erreur(__FUNCTION__);
}

/* Émettre un message */
void envoyer_message(SOCK* dst, char * message) {
	/*A COMPLETER*/
	traiter_erreur(__FUNCTION__);
}
/* Fermer la connexion */
void fermer_connexion(SOCK* sock) {
	/*A COMPLETER*/
	traiter_erreur(__FUNCTION__);
}
