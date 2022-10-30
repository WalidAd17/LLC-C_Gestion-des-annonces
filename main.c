#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include"ANNONCES_LLC_BIBLIO.h"
#include"ANNONCES_LLC_BIBLIO.c"


int main()
{
  Annonce *tete=NULL;
  Annonce *queue=NULL;
  Annonceur *debut=NULL;
  Annonceur *der=NULL;
  Annonce *arch_tete=NULL;
  Offre6 *w=NULL;
  Demande *x=NULL;
  Annoncet *y=NULL;
  Offre7 *z=NULL;
  int idf,trouve,i;
  int code,choix,fin;
  char nomdutilisateur[50];
  Date date;
  char typedebien[50];
  char localisation[50];
  char categorie[50];
  float prix;
  float surface;



  Color(15,0);
    printf("\n *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   ");
    printf("\n");
    printf("\n");
    printf("                      REPUBLIQUE ALGERIENNE DEMOCRATIQUE ET POPULAIRE \n");
    printf("\n");
    printf("            MINISTRE DE L'ENSEIGNEMENT SUPERIEUR ET DE LA RECHERCHE SCIENTIFIQUE \n");
    printf("\n");
    printf("\n");
    Color(10,0);
    printf("    -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_  \n");
    printf("\n");
    Color(10,0);
    printf("               _");
    printf("                                                            \n");
    printf("              ");
    printf("|_|");
    printf("                                                           \n");
    printf("              ");
    printf("/_/");
    printf("                                                             \n");
    printf("     ");
    printf("___  ___ _");
    printf("                                                              \n");
    printf("    ");
    printf("/ _ \\/ __| |");
    printf("                                                            \n");
    printf("   ");
    printf("|  __/\\__ \\ |");
    printf("           \n");
    printf("    ");
    printf("\\___||___/_|");
    printf("             \n");
    printf("    ");
    printf("\t\t");
    printf("E");
    Sleep(200);
    Color(15,0);
    printf("C");
    Sleep(200);
    printf("O");
    Sleep(200);
    printf("L");
    Sleep(200);
    printf("E");
    Sleep(200);
    printf(" ");
    Sleep(200);
    Color(10,0);
    printf("N");
    Color(15,0);
    Sleep(200);
    printf("A");
    Sleep(200);
    printf("T");
    Sleep(200);
    printf("I");
    Sleep(200);
    printf("O");
    Sleep(200);
    printf("N");
    Sleep(200);
    printf("A");
    Sleep(200);
    printf("L");
    Sleep(200);
    printf("E");
    Sleep(200);
    printf(" ");
    Sleep(200);
    Color(10,0);
    printf("S");
    Color(15,0);
    Sleep(200);
    printf("U");
    Sleep(200);
    printf("P");
    Sleep(200);
    printf("E");
    Sleep(200);
    printf("R");
    Sleep(200);
    printf("I");
    Sleep(200);
    printf("E");
    Sleep(200);
    printf("U");
    Sleep(200);
    printf("R");
    Sleep(200);
    printf("E");
    Sleep(200);
    printf(" ");
    Sleep(200);
    Color(10,0);
    printf("D");
    Sleep(200);
    printf("'");
    Sleep(200);
    printf("I");
    Sleep(200);
    Color(15,0);
    printf("N");
    Sleep(200);
    printf("F");
    Sleep(200);
    printf("O");
    Sleep(200);
    printf("R");
    Sleep(200);
    printf("M");
    Sleep(200);
    printf("A");
    Sleep(200);
    printf("T");
    Sleep(200);
    printf("I");
    Sleep(200);
    printf("Q");
    Sleep(200);
    printf("U");
    Sleep(200);
    printf("E");
    Sleep(200);
    Color(10,0);
    printf("\n");
    printf("\n    -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_  \n") ;
    Color(9,0);
    printf("\n\n\t\t     ALGORITHME ET STRUCTURES DES DONNEES DYNAMIQUES\n");
    Color(15,0);
    printf("\t\t\t\t      * ALSDD * \n");
    printf("\n");
    Color(10,0);
    printf("    -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_  \n") ;
    Color(15,0);
    printf("\n\t\t\t\tTravail Pratique N :1 ");
    Color(10,0);
    printf("\n\n\t\t      =>   ");
    Color(12,0);
    printf("Gestion des annonces immobiliers .");
    printf("\n\n");
    Color(10,0);
    printf("                     ************************************************\n");
    printf("\t\t\t\t   Realise par :");
    printf("\n\n");
    Color(15,0);
    printf("\t\t        ANNAD Walid");
    Color(10,0);
    printf("\n\n\t\t\t\t    Groupe : 3");
    Color(10,0);
    printf("\n\n\t\t\t      Encadre Par :  ");
    Sleep(400);
    Color(15,0);
    printf("Madame ");
    Sleep(200);

    Color(15,0);
    Sleep(200);
    printf("T");
    Sleep(200);
    printf("A");
    Sleep(200);
    printf("M");
    Sleep(200);
    printf("E");
    Sleep(200);
    printf("G");
    Sleep(200);
    printf("L");
    Sleep(200);
    printf("I");
    Sleep(200);
    printf("T");
    Sleep(200);
    Color(10,0);
    printf("\n\n\t\t\t\t\t     Annee Universitaire : ");
    Color(15,0);
    printf(" 2018 / 2019 ");
    Color(10,0);
    printf("\n\n");
    printf("\n    -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_  \n") ;
    printf("\n");
    Color(15,0);
    printf("\n *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   ");
    printf("\n\t\t    ");
    system("pause");



  //Construction de LLC des annonces
   creer_LLC_annonce(&tete,&queue);
  //Construction de LLC des annonceurs
   creer_LLC_annonceur(&debut,&der);

  fin=0;
  while(!fin)
{

          /* affichage menu */

  printf("\n");
  Color(9,0);
  printf(" ---------------------------------------------Menu----------------------------------------------\n");
  printf(" ***********************************************************************************************\n");
  printf("\n");
  Color(15,0);
  printf(    "  01. Afficher la liste des annonces \n"
             "  02. Afficher la liste des des annonceurs\n\n"
             "  03. Enregistrer une nouvelle annonce \n"
             "  04. Enregistrer un nouvel annonceur \n"
             "  05. Supprimer une annonce \n"
             "  06. Afficher la liste des archives\n\n"
             "  07. Rechercher les annonces \n\n"
             "  08. Rechercher les annonces de type offre appartenant à un meme annonceur \n"
             "  09. Lister tous les annonceurs qui sont offreur et demandeur en meme temps \n\n"
             "  10. Eclater les annonces selon leur type (offre/demande) \n\n"
             "  11. Afficher la liste des annonces de type offre (apres l'eclatement) \n"
             "  12. Afficher la liste des annonces de type demande (apres l'eclatement) \n"
             "  13. Trier la liste des annonces de type offre \n"
             "  14. Afficher la liste des annonces de type offre apres le tri \n"
             "  15. Trier la liste des annonces de type demande \n"
             "  16. Afficher la liste des annonces de type demande apres le tri \n"
             "  17. Fusionner la liste des annonces de type offre et la liste des annonces de type demande \n"
             "  18. Afficher la liste des annonces triee"
             "  19. Afficher la liste des offres(ainsi que leurs annonceurs) qui peuvent correspondre a une demande donnée \n"
             "  20.\n"
             "  21. Afficher les annonces ayant une durée de vie ne depassant pas un certain nombre d'heures \n"
             "  22. Afficher les annonces les plus demandees durant une periode donnee \n"
             "  23. Quitter\n");
  printf("\n");
  Color(9,0);
  printf(" ***********************************************************************************************\n");
  Color(10,0);

 printf("\n");
 printf("\n");
 printf("entrer votre choix (de 1 jusqu'a 14):\n");
 scanf("%d", &choix);
 printf("\n");

switch (choix)
 {
     case 1:  //Affichage de LLC des annonces
        affich_LLC_annonce(tete);
        break;
//------------------------------------------------
     case 2:  //Affichage de LLC des annonceurs
        affich_LLC_annonceur(debut);
        break;
//------------------------------------------------
     case 3:  //Ajouter une annonce
        Ajouter_annonce(&queue);
        break;
//------------------------------------------------
     case 4:  //ajouter un annonceur
        Ajouter_annonceur(&der);
        break;
//------------------------------------------------

     case 5:  //supprimer une annonce
        printf("entrer le code d'annonce:\n");
        scanf("%d",&code);
        supprimer_annonce(&tete,&queue,code,&arch_tete,&idf);
        verif_der_annonce(debut,idf,&trouve);
        if(trouve!=0){supprimer_annonceur(&debut ,&der,idf);}
        break;
//------------------------------------------------
     case 6: //Affichier la liste des archives
        affich_archive(arch_tete);
        break;
//------------------------------------------------
     case 7: //Rechercher les annonces
        printf("\n"
             " ---------------------------------------------Menu----------------------------------------------\n"
             " ***********************************************************************************************\n"
             "01.Rechercher une annonce par type de bien immobilier \n"
             "02.Rechercher une annonce par localisation\n"
             "03.Rechercher une annonce par date \n"
             "04.Quitter\n");
        printf("Quel est votre choix?\n\n");
        scanf("%d", &i);
    //*******************************************************************
        switch(i){
        case 1://Rechercher une annonce par type de bien immobilier
          printf("Quel type de bien immobilier recherchez vous (terrain, appartement/maison, bungalow) ? [FAITES ATTENTION A LA MAJUSCULE ET LA MINUSCULE] \n");
          scanf("%s",&typedebien);
          rechercher_annonce_par_tbi(tete , typedebien);
          printf("********************************************************** \n");            break;
    //*******************************************************************
        case 2://Rechercher une annonce par localisation
         printf("Dans quel secteur voulez-vous que votre bien immobilier se situe ? [FAITES ATTENTION A LA MAJUSCULE ET LA MINUSCULE] \n");
         scanf("%s",&localisation);
         rechercher_annonce_par_localisation(tete ,localisation);
         printf("********************************************************** \n");
            break;
    //*******************************************************************
        case 3://Rechercher une annonce par date
         printf("Entrez la date de publication des annonces que vous voulez rechercher . \n");
         printf("********************************************************************* \n");
         printf("Le jour");
         scanf("%d",&date.jour);
         printf("Le mois");
         scanf("%d",&date.mois);
         printf("L'annee");
         scanf("%d",&date.annee);
         rechercher_annonce_par_date(tete , date);
            break;
    //*******************************************************************
        default:
            printf("Vous n'avez pas rentre un nombre correct.\n\n");
            break;}

         break;
//------------------------------------------------
     case 8: //Rechercher les annonces de type offre appartenant à un meme annonceur
         printf("A quel annonceur appartiennent les annonces de type offre que vous recherchez?,Entrez le nom dutilisateur [FAITES ATTENTION A LA MAJUSCULE ET LA MINUSCULE]. \n");
         printf("********************************************************* \n");
         scanf("%s",&nomdutilisateur);
         Rechercher_des_offres_dun_annonceur(tete,debut,nomdutilisateur);
         break;
//------------------------------------------------
     case 9: //Lister tous les annonceurs qui sont offreur et demandeur en même temps
         Lister_Util_Off_Dem(debut , tete);
         break;
//------------------------------------------------
     case 10: //Eclater les annonces selon leur type (offre/demande)
        eclatement_annonce(tete,&w,&x);
        break;
 //-----------------------------------------------
     case 11: //Afficher la liste des annonces de type offre (apres l'eclatement)
        affich_LLC_offre6(w);
        break;
//------------------------------------------------
     case 12: //Afficher la liste des annonces de type demande (apres l'eclatement)
        affich_LLC_demande(x);
        break;
//------------------------------------------------
     case 13: //Trier la liste des annonces de type offre
        tri_offre6_par_date(w);
        break;
//------------------------------------------------
     case 14: //Afficher la liste des annonces de type offre apres le tri
        affich_LLC_offre6(w);
        break;
//------------------------------------------------
     case 15: //Trier la liste des annonces de type demande
        tri_demande_par_date(x) ;
        break;
//------------------------------------------------
     case 16:  //Afficher la liste des annonces de type demande apres le tri
        affich_LLC_demande(x);
        break;
//------------------------------------------------
     case 17: //Fusionner la liste des annonces de type offre et la liste des annonces de type demande
        fusion(&y,w,x);
        break;
//------------------------------------------------
     case 18: //Afficher la liste des annonces triee
        affich_LLC_annoncet(y);
        break;
//-------------------------------------------------
     case 19: //Afficher la liste des offres(ainsi que leurs annonceurs) qui peuvent correspondre a une demande donnée
  printf("Quels sont les critères de votre demande ? \n");
  printf("Entrez le type de bien immobilier [FAITES ATTENTION A LA MAJUSCULE ET LA MINUSCULE] \n");
  scanf("%s",&typedebien);
  printf("Entrez la categorie (location ou vente) ,[FAITES ATTENTION A LA MAJUSCULE ET LA MINUSCULE] \n");
  scanf("%s",&categorie);
  printf("Entrez le prix [EN DA] \n");
  scanf("%f",&prix);
  printf("Entrez la surface [EN m2] \n");
  scanf("%f",&surface);
  offre_correspond_demande(tete,&z,debut,typedebien, categorie,prix, surface);
  break;
//-----------------------------------------------
     case 20:
         fin=1;
         break;
//------------------------------------------------

     default:
        printf("Vous n'avez pas mis un nombre valide.\n\n");
        break;
 }
}

   return 0;
}




