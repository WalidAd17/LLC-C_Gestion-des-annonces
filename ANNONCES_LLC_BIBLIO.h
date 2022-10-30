#ifndef ANNONCES_LLC_BIBLIO_H_INCLUDED
#define ANNONCES_LLC_BIBLIO_H_INCLUDED




//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------

// Les types utilisés:

//----------------------------------------------------------------------------------------
typedef struct Date       // structure des dates
{
    int jour;
    int mois;
    int annee;
}Date;
//----------------------------------------------------------------------------------------
typedef struct Annonceur   // structure de la liste des annonceurs
{
    char nom_utilisateur[50];
    char mot_de_passe[50];
    int num_sequentiel;
    char adresse_mail[50];
    char numero_de_telephonne[50];
    struct Annonceur *next;
}Annonceur;
//----------------------------------------------------------------------------------------
typedef struct Annonce  // structure de la liste des annonces
{
    char type_annonce[50];
    char categorie[50];
    int identifiant;
    Date date_de_publication;
    Date date_de_suppression;
    int prix;
    char localisation[50];
    int surface;
    char type_bien[50];
    char texte_descriptif[100];
    int code_annonce;
    struct Annonce *next;
}Annonce;
//----------------------------------------------------------------------------------------
typedef struct Offre6 //Structure de la liste des annonces de type offre obtenue de l'eclatement de la liste Annonce
 {                       //Question6
    char type_annonce[50];
    char categorie[50];
    int identifiant;
    Date date_de_publication;
    int prix;
    char localisation[50];
    int surface;
    char type_bien[50];
    char texte_descriptif[100];
    struct Offre6 *next;
 }Offre6;
 //---------------------------------------------------------------------------------------
 typedef struct Demande //Structure de la liste des annonces de type demande obtenue de l'eclatement de la liste Annonce
 {                       //Question6
    char type_annonce[50];
    char categorie[50];
    int identifiant;
    Date date_de_publication;
    int prix;
    char localisation[50];
    int surface;
    char type_bien[50];
    char texte_descriptif[100];
    struct Demande *next;
 }Demande;
 //---------------------------------------------------------------------------------------
 typedef struct Annoncet  // structure de la liste des annonces triee par date obtenue de la fusion des 2 structures précédentes(Offre6 et Demande)
{                         //Question6
    char type_annonce[50];
    char categorie[50];
    int identifiant;
    Date date_de_publication;
    int prix;
    char localisation[50];
    int surface;
    char type_bien[50];
    char texte_descriptif[100];
    struct Annoncet *next;
}Annoncet;
//----------------------------------------------------------------------------------------
 typedef struct Offre7 //Structure de la liste des offres qui peuvent correspondre à une demande donnée (Question 7)
 {

    char categorie[50];
    int identifiant;
    Date date_de_publication;
    int prix;
    char localisation[50];
    int surface;
    char type_bien[50];
    char texte_descriptif[100];
    struct Offre7 *next;
 }Offre7;
 //----------------------------------------------------------------------------------------

   // Les entetes des procédures:

//-----------------------------------------------------------------------------------------
void Color(int couleurDuTexte,int couleurDeFond);  // fonction des couleurs (additionnelle)

void allouer_annonce(Annonce **nouveau);

void allouer_annonceur(Annonceur **nouveau);

void allouer_offre6(Offre6 **nouveau);

void allouer_demande(Demande **nouveau);

void allouer_annoncet(Annoncet **nouveau);

void allouer_offre7(Offre7 **nouveau);
//------------------------------------------------------------------------------------------

Annonce *suivant(Annonce *p);

Annonceur *prochain(Annonceur *p);

Offre6 *suivant6(Offre6 *p);

Demande *suivant_d(Demande *p);

Annoncet *suivant_t(Annoncet *p);

Offre7 *suivant7(Offre7 *p);
//------------------------------------------------------------------------------------------

void liberer_annonce(Annonce **ancien);

void liberer_annonceur(Annonceur **ancien);
//------------------------------------------------------------------------------------------
      //question01:

void creer_LLC_annonce(Annonce **Tete, Annonce **Queue);

void creer_LLC_annonceur(Annonceur **adr_tete, Annonceur **adr_queue);

void affich_LLC_annonce(Annonce *tete);

void affich_LLC_annonceur(Annonceur *tete);
//----------------------------------------------------------------------------------------
      //question02:
void Ajouter_annonce(Annonce **adr_queue);

void Ajouter_annonceur(Annonceur **adr_queue);

void verif_der_annonce(Annonceur *debut, int idf,int *trouve);

void archiv(Annonce *p, Annonce **adr_q  );// copy le contenu de p dans q et entrer la date de supression

void supprimer_annonce(Annonce **adr_tete , Annonce **adr_queue, int code, Annonce **adr_arch, int *idf);

void supprimer_annonceur(Annonceur **adr_tete , Annonceur **adr_queue, int idf);

void affich_archive(Annonce *tete_arch);
//----------------------------------------------------------------------------------------
      //question03:
void rechercher_annonce_par_tbi(Annonce *tete , char type[50]);

void rechercher_annonce_par_localisation(Annonce *tete , char localisation[50]);

void rechercher_annonce_par_date(Annonce *tete , Date date);

//----------------------------------------------------------------------------------------
      //question04:

void Rechercher_des_offres_dun_annonceur(Annonce *tete1 , Annonceur *tete2 , char nomdutilisateur[50]);

//----------------------------------------------------------------------------------------
      //question05:

void Lister_Util_Off_Dem(Annonceur *debut , Annonce *tete);

//----------------------------------------------------------------------------------------
      //question06:
void eclatement_annonce(Annonce *tete1,Offre6 **tete2,Demande **tete3);

void affich_LLC_offre6(Offre6 *tete);

void affich_LLC_demande(Demande *tete);

void tri_offre6_par_date(Offre6 *tete);

void permutation_offre6(Offre6 *p, Offre6 *q );

void tri_demande_par_date(Demande *tete);

void permutation_demande(Demande *p, Demande *q );

void fusion(Annoncet **tete , Offre6 *tete1 , Demande *tete2);

void Insertion_offre(Annoncet **tete, Offre6 *p1 , Annoncet **Queue);

void Insertion_demande(Annoncet **tete, Demande *p2 , Annoncet **Queue);

void affich_LLC_annoncet(Annoncet *tete);
//----------------------------------------------------------------------------------------
      //question07:
void affich_LLC_offres_ses_annonceurs(Offre7 *tete1,Annonceur *tete2);

void offre_correspond_demande(Annonce *tete1 , Offre7 **tete2 ,Annonceur *tete3, char type[30] , char categorie[30] , float prix , float surface);

//----------------------------------------------------------------------------------------
      //question08:


//----------------------------------------------------------------------------------------



#endif // ANNONCES_LLC_BIBLIO_H_INCLUDED
