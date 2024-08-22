#include "classe.h"

// Fonction pour générer le formulaire HTML
void generer_formulaire(char *buffer, size_t taille) {
    snprintf(buffer, taille,
        "<html>\n"
        "<head><title>CLASS</title></head>\n"
        "<body>\n"
        "<form action=\"classe.cgi\" method=\"GET\">\n"
        "IP: <input type=\"text\" name=\"ip\" placeholder=\"0.0.0.0\"><br>\n"
        "<input type=\"submit\" value=\"submit\"><br>\n"
        "</form>\n");
}

// Fonction pour générer la fin du HTML
void generer_fin_html(char *buffer, size_t taille) {
    snprintf(buffer, taille,
        "</body>\n"
        "</html>\n");
}

// Fonction pour analyser l'adresse IP et générer sa classe
void analyser_ip(char *tab, char *resultat, size_t taille) {
    int a, b, c, d;
    char ip[16]; // Assez grand pour une adresse IP

    // Extraire l'adresse IP depuis la chaîne de requête
    if (sscanf(tab, "ip=%15[0-9.]s", ip) == 1) {
        // Analyser l'adresse IP
        if (sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d) == 4) {
            // Vérifier la validité de l'adresse IP
            if (a >= 0 && a <= 255 && b >= 0 && b <= 255 &&
                c >= 0 && c <= 255 && d >= 0 && d <= 255) {
                // Déterminer la classe de l'IP
                if (a >= 0 && a <= 127) {
                    snprintf(resultat, taille, "Class A<br>\n");
                } else if (a >= 128 && a <= 191) {
                    snprintf(resultat, taille, "Class B<br>\n");
                } else if (a >= 192 && a <= 223) {
                    snprintf(resultat, taille, "Class C<br>\n");
                } else if (a >= 224 && a <= 239) {
                    snprintf(resultat, taille, "Class D<br>\n");
                } else if (a >= 240 && a <= 255) {
                    snprintf(resultat, taille, "Class E<br>\n");
                } else {
                    snprintf(resultat, taille, "Invalid IP address<br>\n");
                }
            } else {
                snprintf(resultat, taille, "Invalid IP address format<br>\n");
            }
        } else {
            snprintf(resultat, taille, "Invalid IP address format<br>\n");
        }
    } else {
        snprintf(resultat, taille, "No IP address provided<br>\n");
    }
}

