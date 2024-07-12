FILE *initialisation(char *A, char *mode);
int nbr_ligne(char *name);
int count_words(char *name);
void free_tab(char **tab, int nbr);
void get_args(char **argv, int argc, FILE *file);
void tail_n(FILE *fic, int nbr, int n);
void tail_c(FILE *fic, int nbr, int c);
