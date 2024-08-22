#include "classe.h"

int main() {
    char formulaire[256];
    char fin_html[64];
    char resultat[64] = "";
    char *tab = getenv("QUERY_STRING");
    char sortie[1024];  // Buffer pour toute la sortie HTML

    // Générer le formulaire
    generer_formulaire(formulaire, sizeof(formulaire));

    // Générer la fin du HTML
    generer_fin_html(fin_html, sizeof(fin_html));

    // Initialiser le buffer de sortie
    strcpy(sortie, "Content-Type: text/html\n\n");

    // Ajouter le formulaire au buffer de sortie
    strcat(sortie, formulaire);

    // Ajouter le résultat de l'analyse IP si disponible
    if (tab != NULL) {
        analyser_ip(tab, resultat, sizeof(resultat));
        strcat(sortie, resultat);
    }

    
    strcat(sortie, fin_html);

    // Afficher le contenu complet en une fois
    printf("%s", sortie);

    return 0;
}
