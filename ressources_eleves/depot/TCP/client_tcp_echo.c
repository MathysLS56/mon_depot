#include "tcp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
void traiter_commande(int argc, char** argv, const char* usage) {
    if (argc != 5) {
        printf(stderr, "%s\n", usage);
    }

int main(int argc, char** argv) {
	
	
	traiter_commande(, argv[0], "<adresse IP> port:1023<<message> <nb occurences>\nmauvais nombre d'arguments");
	traiter_commande(, argv[0], "<adresse IP> <port> <message> <nb occurences>\n<adresse IP> est une adresse IP au format décimal pointé");
	traiter_commande(, argv[0], "<adresse IP> <port> <message> <nb occurences>\n<port> est un port non réservé");
	traiter_commande(, argv[0], "<adresse IP> <port> <message> <nb occurences>\n<nb occurences> est un entier positif");

	

	exit(0);
}
