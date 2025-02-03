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
<<<<<<< HEAD
	int sock ;
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	/*A COMPLETER*/
	traiter_erreur(__FUNCTION__);
	/*A COMPLETER*/
=======
	sock->sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock->sockfd == -1) {
        traiter_erreur(__FUNCTION__);
        return;
    }
	sock->adresse.sin_family = AF_INET;
    sock->adresse.sin_port = htons(port);
    sock->adresse.sin_addr.s_addr = inet_addr(adresseIP);
    sock->longueur_adresse = sizeof(sock->adresse);
>>>>>>> 6f32960 (cr??ation serveur et client tcp)
}

/* Attacher une socket */
void attacher_socket(SOCK* sock) {
<<<<<<< HEAD
	/*A COMPLETER*/
	traiter_erreur(__FUNCTION__);
=======
	int verif;
	verif=bind(sock->sockfd, (struct sockaddr*)&sock->adresse, sock->longueur_adresse);
	if (verif==-1){	
		traiter_erreur(__FUNCTION__);
	}
>>>>>>> 6f32960 (cr??ation serveur et client tcp)
}

/*Initialiser la structure adresse client */
void init_addr(SOCK* sock) {
<<<<<<< HEAD
	/*A COMPLETER*/
=======
    sock->adresse.sin_family = AF_INET;
    sock->adresse.sin_addr.s_addr = INADDR_ANY; 
    sock->longueur_adresse = sizeof(sock->adresse);
>>>>>>> 6f32960 (cr??ation serveur et client tcp)
}

/* Dimensionner la file d'attente d'une socket */
void dimensionner_file_attente_socket(int taille, SOCK* sock) {
	/*A COMPLETER*/
<<<<<<< HEAD
	traiter_erreur(__FUNCTION__);
=======
	int verif;
	verif=listen(sock->sockfd, taille);
	if (verif==-1){	
		traiter_erreur(__FUNCTION__);
	}
>>>>>>> 6f32960 (cr??ation serveur et client tcp)
}

/* Recevoir un message */
void recevoir_message(SOCK* dst, char * buffer) {
<<<<<<< HEAD
	/*A COMPLETER*/	
	traiter_erreur(__FUNCTION__);
=======
	int verif;
	verif=recvfrom(dst->sockfd, buffer, 1024, 0, (struct sockaddr*)&dst->adresse, &dst->longueur_adresse);
	if (verif==-1){
		traiter_erreur(__FUNCTION__);
	}
	
>>>>>>> 6f32960 (cr??ation serveur et client tcp)
}

/* Émettre un message */
void envoyer_message(SOCK* dst, char * message) {
<<<<<<< HEAD
	/*A COMPLETER*/
	traiter_erreur(__FUNCTION__);
}
/* Fermer la connexion */
void fermer_connexion(SOCK* sock) {
	/*A COMPLETER*/
=======
	int verif;
	verif=sendto(dst->sockfd, message, strlen(message), 0, (struct sockaddr*)&(dst->adresse), dst->longueur_adresse);
	if (verif==-1){
		traiter_erreur(__FUNCTION__);
	}
}
/* Fermer la connexion */
void fermer_connexion(SOCK* sock) {
	close(sock->sockfd);
>>>>>>> 6f32960 (cr??ation serveur et client tcp)
	traiter_erreur(__FUNCTION__);
}
