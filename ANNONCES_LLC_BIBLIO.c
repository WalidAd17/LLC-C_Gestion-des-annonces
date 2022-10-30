#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include"ANNONCES_LLC_BIBLIO.h"


//l'implementation des fonctions utilisées

// fonction d'affichage de couleurs

void Color(int couleurDuTexte,int couleurDeFond)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

//*******************************************************************************************************************************
void allouer_annonce(Annonce **nouveau)
{
    *nouveau=(Annonce*)malloc(sizeof(Annonce));
}

void allouer_annonceur(Annonceur **nouveau)
{
    *nouveau=(Annonceur*)malloc(sizeof(Annonceur));
}

void allouer_offre6(Offre6 **nouveau)
{
    *nouveau=(Offre6*)malloc(sizeof(Offre6));
}

void allouer_demande(Demande **nouveau)
{
    *nouveau=(Demande*)malloc(sizeof(Demande));
}

void allouer_annoncet(Annoncet **nouveau)
{
    *nouveau=(Annoncet*)malloc(sizeof(Annoncet));
}

void allouer_offre7(Offre7 **nouveau)
{
    *nouveau=(Offre7*)malloc(sizeof(Offre7));
}
//*****************************************************************************************************************************

Annonce *suivant(Annonce *p)
{
    return p->next;
}

Annonceur *prochain(Annonceur *p)
{
    return p->next;
}

Offre6 *suivant6(Offre6 *p)
{
    return p->next;
}

Demande *suivant_d(Demande *p)
{
    return p->next;
}

Annoncet *suivant_t(Annoncet *p)
{
    return p->next;
}

Offre7 *suivant7(Offre7 *p)
{
    return p->next;
}
//*****************************************************************************************************************************

void liberer_annonce(Annonce **ancien)
{
     free(*ancien);
    *ancien=NULL;
}

void liberer_annonceur(Annonceur **ancien)
{
     free(*ancien);
    *ancien=NULL;
}
//*****************************************************************************************************************************
void creer_LLC_annonce(Annonce **Tete, Annonce **Queue) /*Role: Creer la LLC des annonces à partir du fichier texte "annonce"
                                                                        Rendre la tete et la queue de la liste*/

{
    Annonce *p;
    Annonce *t;
    Annonce *q;

    FILE* fichier = NULL;
    fichier = fopen("annonce.txt","r");
    t=*Tete;

    while(!feof(fichier))    // on lit à partir du fichier "annonce.txt" les données de chaque annonce
    {
            allouer_annonce(&p);
            fscanf(fichier,"%s %s %d %d %d %d %d %s %d %s %s %d",p->type_annonce,p->categorie,&p->identifiant,&p->date_de_publication.jour,&p->date_de_publication.mois,&p->date_de_publication.annee,&p->prix,p->localisation,&p->surface,p->type_bien,p->texte_descriptif,&p->code_annonce);

            if (t==NULL) //ici on crée le premier maillon de la liste (tete)
            {    t=p;
                *Tete=t;
                 q=p; //La tete et la queue pointent le meme maillon (la premier et le seul)
            }
            else //ici on ajoute un maillon de plus
            {
                q->next=p;
                q=p; //Le dernier maillon devient la nouveau maillon
            }


    }
    fclose(fichier);
    q->next=NULL;
    *Queue=q;
}
//*****************************************************************************************************************************
void creer_LLC_annonceur(Annonceur **Tete, Annonceur **Queue) /*Role: Creer la LLC des annonceurs à partir du fichier texte "annonceur"
                                                                        Rendre la tete et la queue de la liste*/
{   Annonceur *p;
    Annonceur *t;
    Annonceur *q;

    FILE* fichier = NULL;
    fichier = fopen("annonceur.txt","r");
    t=*Tete;

     while(!feof(fichier))
     {

            allouer_annonceur(&p);
            fscanf(fichier,"%s %s %d %s %s",p->nom_utilisateur,p->mot_de_passe,&p->num_sequentiel,p->adresse_mail,p->numero_de_telephonne);

            if (t==NULL)
            {
                t=p;
                *Tete=t;
                 q=p;
            }
            else
            {
                q->next=p;
                q=p;
            }
    }
    fclose(fichier);
    q->next=NULL;
    *Queue=q;
}
//*****************************************************************************************************************************
void affich_LLC_annonce(Annonce *tete) //Role : Afficher la LLC des annonces
{
    Annonce *p;
    p=tete;
    printf(" # La liste des annonces : \n");
    printf(" ------------------------\n");
    printf("\n");
    printf(" type d'annonce  |   categorie  |identifiant|  jdp/mdp/adp   |     prix     |  localisation  |    surface    |   type du bien | Code d'annonce\n");

    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    while(p != NULL) //On parcourt la liste jusqu'à la queue
    {
    printf("     %s          %s      %d          %d/%d/%d        %d da      %s        %d m2        %s       %d\n",p->type_annonce,p->categorie,p->identifiant,p->date_de_publication.jour,p->date_de_publication.mois,p->date_de_publication.annee,p->prix,p->localisation,p->surface,p->type_bien,p->code_annonce);
    printf(" texte descriptif: %s\n",p->texte_descriptif);
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    p=suivant(p);
    }
}


//*****************************************************************************************************************************
void affich_LLC_annonceur(Annonceur *tete) //Role : Afficher la LLC des annonceurs
{
    Annonceur *p;
    p=tete;
    printf(" # La liste des annonceurs : \n");
    printf(" ------------------------\n");
    printf("\n");
    printf("Nom dutilisateur   |   mot de passe    |   num sequentiel  |   adresse mail    |   numero de telephonne \n");
    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("\n");
    while(p != NULL)
    {
    printf("    %s          %s          %d          %s          %s          \n",p->nom_utilisateur,p->mot_de_passe,p->num_sequentiel,p->adresse_mail,p->numero_de_telephonne);
    printf("---------------------------------------------------------------------------------\n");
    p=prochain(p);
    }
}
//*****************************************************************************************************************************
//question02:
//*****************************************************************************************************************************
void Ajouter_annonce(Annonce **adr_queue)
{ Annonce *q ,*p;
     q=*adr_queue;
     p=*adr_queue;
   allouer_annonce(&p);
   q->next=p;
   p->next=NULL;
   printf("entrer le type d'annonce\n");
   scanf("%s",p->type_annonce)  ;
   printf("entrer la categorie\n");
   scanf("%s",p->categorie)  ;
   printf("entrer l'identifiant d'annonceur\n");
   scanf("%d",&p->identifiant)  ;
   printf("entrer la date de publication (jour moins annee) :\n");
   scanf("%d %d %d",&p->date_de_publication.jour,&p->date_de_publication.mois,&p->date_de_publication.annee)  ;
   printf("entrer le prix d'annonce\n");
   scanf("%d",&p->prix)  ;
   printf("entrer la localisation\n");
   scanf("%s",p->localisation)  ;
   printf("entrer la surface\n");
   scanf("%d",&p->surface)  ;
   printf("entrer le type bien\n");
   scanf("%s",p->type_bien)  ;
   printf("entrer le texte descriptif\n");
   scanf("%s",p->texte_descriptif)  ;
   printf("entrer le code de cette annonce\n");
   scanf("%s",p->code_annonce)  ;
   *adr_queue=p;
}
//*****************************************************************************************************************************
void Ajouter_annonceur(Annonceur **adr_queue)
{ Annonceur *q ,*p;
     q=*adr_queue;
     p=*adr_queue;
   allouer_annonceur(&p);
   q->next=p;
   p->next=NULL;
   printf("entrer le nom d'utilisateur\n");
   scanf("%s",p->nom_utilisateur)  ;
   printf("entrer le mot de passe\n");
   scanf("%s",p->mot_de_passe)  ;
   printf("entrer le numero sequentiel\n");
   scanf("%d",&p->num_sequentiel)  ;
   printf("entrer l'adresse email :\n");
   scanf("%s",p->adresse_mail)  ;
   printf("entrer le numero de telephonne\n");
   scanf("%s",p->numero_de_telephonne)  ;
   *adr_queue=p;
}
//*****************************************************************************************************************************
void verif_der_annonce(Annonceur *debut, int idf,int *trouve)
{ Annonceur *p;

 p=debut;
 *trouve=0;
  while(((p != NULL)&&(*trouve==0)))
  {
      if((p->num_sequentiel)==idf){*trouve=1;}
      p=prochain(p);
  }
}
//*****************************************************************************************************************************
void archiv(Annonce *p, Annonce **adr_q  )// copy la partie de p dans q et entrer la date de supression
{ Annonce *q ;q=*adr_q;
    strcpy(q->type_annonce,p->type_annonce);
    strcpy(q->categorie,p->categorie);
    q->identifiant=p->identifiant;
    q->date_de_publication.jour=p->date_de_publication.jour;
    q->date_de_publication.mois=p->date_de_publication.mois;
    q->date_de_publication.annee=p->date_de_publication.annee;
    q->prix=p->prix;
    strcpy(q->localisation,p->localisation);
    q->surface=p->surface;
    strcpy(q->type_bien,p->type_bien);
    strcpy(q->texte_descriptif,p->texte_descriptif);
    q->code_annonce=p->code_annonce;
    printf("entrer la date de supression jour mois annee :\n");
    scanf("%d %d %d",&q->date_de_suppression.jour,&q->date_de_suppression.mois,&q->date_de_suppression.annee);
}
//*****************************************************************************************************************************
void supprimer_annonce(Annonce **adr_tete , Annonce **adr_queue, int code, Annonce **adr_arch, int *idf)
{ Annonce *p,*prec,*a,*q, *der;
  p=*adr_tete;
  a=*adr_arch;
  while((p != NULL)&&(((p->code_annonce) != code)))
  {
      prec=p;
      p=suivant(p);
  }
  if(p!=NULL)
  {   *idf=p->identifiant;
      //Archiver P
       if(a==NULL){allouer_annonce(&a); archiv(p,&a) ; *adr_arch=a;der=*adr_arch;}
       else {allouer_annonce(&q); q->next=NULL ;archiv(p,&q); der->next=q ; der=q ; der->next=NULL ;}
      //Supprimer P
      if(p==*adr_tete){*adr_tete=suivant(*adr_tete);}
      else
      {
           if(p==*adr_queue){*adr_queue=prec;}
           prec->next=suivant(p);}

   liberer_annonce(&p);
  }
}
//*****************************************************************************************************************************
void supprimer_annonceur(Annonceur **adr_tete , Annonceur **adr_queue, int idf)
{ Annonceur *p,*prec;
  p=*adr_tete;

  while((p != NULL)&&((p->num_sequentiel != idf)))
  {
      prec=p;
      p=prochain(p);
  }
  if(p!=NULL)
  {
      //Supprimer P
      if(p==*adr_tete){*adr_tete=prochain(*adr_tete);}
      else
      {
           if(p==*adr_queue){*adr_queue=prec;}
           prec->next=prochain(p);
      }

   liberer_annonceur(&p);
  }
}
//*****************************************************************************************************************************
void affich_archive(Annonce *tete_arch)
{Annonce *p;
    p=tete_arch;
    printf(" # L'archive : \n");
    printf(" --------------\n");
    printf("\n");
    printf(" type d'annonce   |   categorie  | identifiant |  jdp/mdp/adp   |      prix     |  localisation  |    surface    |  type du bien   |  Code  | date de suppression\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
     while(p != NULL)
    {
    printf("     %s          %s        %d          %d/%d/%d       %d da      %s        %d m2        %s      %d     %d/%d/%d \n",p->type_annonce,p->categorie,p->identifiant,p->date_de_publication.jour,p->date_de_publication.mois,p->date_de_publication.annee,p->prix,p->localisation,p->surface,p->type_bien,p->code_annonce,p->date_de_suppression.jour,p->date_de_suppression.mois,p->date_de_suppression.annee);
    printf(" texte descriptif: %s\n",p->texte_descriptif);
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    p=suivant(p);
    }
}
//*****************************************************************************************************************************
//question03:
//*****************************************************************************************************************************
void rechercher_annonce_par_tbi(Annonce *tete , char type[50])//Role : Recherceher une annonce par type de bien immobllier et l'afficher
{
    Annonce *p;
    p=tete;
    int cpt=0;

    while (p != NULL)
    {
      if (strcmp(p->type_bien,type)==0) //On vérifie le champs type_bien , si on le trouve identique au type donné on affiche l'annonce et on incrémente le compteur cpt
      {
          printf("     %s           %s            %d            %d/%d/%d       %d da          %s          %d m2           %s             %s\n",p->type_annonce,p->categorie,p->identifiant,p->date_de_publication.jour,p->date_de_publication.mois,p->date_de_publication.annee,p->prix,p->localisation,p->surface,p->type_bien,p->texte_descriptif);
          cpt=cpt+1;
      }
      p=suivant(p);
    }
    if (cpt==0)
      {
          printf("Desole, les annonces de biens immobiliers de type ""%s"" ne sont pas disponibles. \n ", type);
      }
      else
      {
          printf("Les annonces de biens immobiliers de type ""%s"" sont celles au dessus. \n" , type );
      }
}
//***************************************************************************************************************************
void rechercher_annonce_par_localisation(Annonce *tete , char localisation[50]) //Role : Recherceher une annonce par localisation et l'afficher
{   Annonce *p;
    p=tete;
    int cpt=0;
    while (p != NULL)
    {
      if (strcmp(p->localisation,localisation)==0) //On vérifie le champs localisation , si on le trouve identique à la localisation donnée on affiche l'annonce et on incrémente le compteur cpt
      {
          printf("     %s           %s            %d            %d/%d/%d       %d da          %s          %d m2           %s             %s\n",p->type_annonce,p->categorie,p->identifiant,p->date_de_publication.jour,p->date_de_publication.mois,p->date_de_publication.annee,p->prix,p->localisation,p->surface,p->type_bien,p->texte_descriptif);
          cpt=cpt+1;
      }
      p=suivant(p);
    }
    if (cpt==0)
      {
          printf("Desole, les annonces de biens immobiliers situes a ""%s"" ne sont pas disponibles.  \n", localisation);
      }
      else
      {
          printf("Les annonces de biens immobiliers situes a ""%s"" sont celles au dessus. \n" , localisation );
      }

}
//*****************************************************************************************************************************
void rechercher_annonce_par_date(Annonce *tete , Date date) //Role : Recherceher une annonce par date et l'afficher
{   Annonce *p;
    p=tete;
    int cpt=0;
    while (p != NULL)
    {
      if (p->date_de_publication.jour== date.jour && p->date_de_publication.mois==date.mois && p->date_de_publication.annee==date.annee)
        //On vérifie le champs date_de_publication , si on le trouve identique à la date donnée on affiche l'annonce et on incrémente le compteur cpt
      {
          printf("     %s           %s            %d            %d/%d/%d       %d da          %s          %d m2           %s             %s\n",p->type_annonce,p->categorie,p->identifiant,p->date_de_publication.jour,p->date_de_publication.mois,p->date_de_publication.annee,p->prix,p->localisation,p->surface,p->type_bien,p->texte_descriptif);
          cpt=cpt+1;
      }
      p=suivant(p);
    }
    if (cpt==0)
      {
          printf("Desole, les annonces de biens immobiliers publiees le ""%d / %d / %d"" ne sont pas disponibles.  \n", date);
      }
      else
      {
          printf("Les annonces de biens immobiliers publiees le  ""%d / %d / %d"" sont celles au dessus. \n" , date );
      }

}
//*****************************************************************************************************************************
//question04:
//*****************************************************************************************************************************
void Rechercher_des_offres_dun_annonceur(Annonce *tete1 , Annonceur *tete2 , char nomdutilisateur[50]) //Role: Afficher les anonces de type offre appartenant à un meme annonceur
{
    Annonce *p;
    p=tete1;
    Annonceur *q;
    q=tete2;
    Annonceur *a=NULL;
    char ch[30]="offre";
    int cpt=0;

    while (q !=NULL) //On parcourt la liste des annonceurs pour obtenir le num_sequentiel de lannonceur (qui fait la relation entre un annonceur et ses annonces) à fin qu'on puisse trouver ses annonces
    {
        if (strcmp(q->nom_utilisateur,nomdutilisateur)==0)
        {
            a=q;
        }

        q=prochain(q);
    }
    if (a==NULL) //on vérifie si le nom d'utilisateur donné existe ou pas
    {
        printf("Lannonceur ""%s"" n'existe pas. \n",nomdutilisateur );
    }
    else //S'il existe on affiche ses annonces (de type offre)
    {
       while (p != NULL) //on parcourt la liste des annonces et on affiche celles qui sont de type offre et qui leur identifiant est identique au num séquentiel de lannonceur
      {
        if (p->identifiant==a->num_sequentiel && strcmp(p->type_annonce,ch)==0)
        {
          printf("     %s           %s            %d            %d/%d/%d       %d da          %s          %d m2           %s             %s\n",p->type_annonce,p->categorie,p->identifiant,p->date_de_publication.jour,p->date_de_publication.mois,p->date_de_publication.annee,p->prix,p->localisation,p->surface,p->type_bien,p->texte_descriptif);
         cpt=cpt+1;
        }

        p=suivant(p);
      }

        if (cpt==0)
       {
        printf("Aucune annoce de type offre appartient a lannonceur ""%s"" . \n",nomdutilisateur);
       }
        else
       {
         printf("Les annonces de type offre appartenant a lannonceur ""%s"" sont celles au dessus. \n ",nomdutilisateur);
       }

    }
}
//*****************************************************************************************************************************
//question05:
//*****************************************************************************************************************************

void Lister_Util_Off_Dem(Annonceur *debut , Annonce *tete)
{ Annonceur *p ; Annonce *q; int trouveOff,trouveDem;
    printf(" # La liste des annonceurs : \n");
    printf(" ------------------------\n");
    printf("\n");
    printf("Nom dutilisateur|  mot de passe | num sequentiel| adresse mail | numero de telephonne \n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("\n");
  p=debut;
 while (p != NULL)
 {
     trouveOff=0;trouveDem=0;
     q=tete;
     while ((q!= NULL) && ((trouveOff==0) || (trouveDem==0)))
     {

          if(q->identifiant == p->num_sequentiel)
          {
              if(strcmp(q->type_annonce,"offre")==0){trouveOff=1;}
              else{trouveDem=1;}
          }
          q=suivant(q);
     }
             //L'affichage d'annonceur:

     if((trouveOff==1) && (trouveDem==1))
          {
           printf("    %s              %s         %d       %s         %s       \n",p->nom_utilisateur,p->mot_de_passe,&p->num_sequentiel,p->adresse_mail,p->numero_de_telephonne);
           printf("---------------------------------------------------------------------------------------\n");
          }
     p=prochain(p);
  }
}
//*****************************************************************************************************************************
//question06:
//*****************************************************************************************************************************
void eclatement_annonce(Annonce *tete1,Offre6 **tete2,Demande **tete3) //Role : Éclater le liste des annonces selon leur type (offre/demande) en crééant 2 listes , une contient les ffres et lautre les demandes
{
  Annonce *p;
  Offre6 *q;
  Demande *r;
  Demande *a;
  Offre6 *b;
  Offre6 *der2;
  Demande *der;
  char ch[30]="demande";
  p=tete1;
  q=*tete2;
  r=*tete3;

  while ( p != NULL) //On parcourt la liste des annonces
  {
      if (strcmp(p->type_annonce,ch)==0) //si lannonce est de type demande on insére le maillon pointé par p à la fin de la liste Demande
      {
        if (r==NULL)
            {
                allouer_demande(&r);
                strcpy(r->categorie,p->categorie);
                r->identifiant=p->identifiant;
                r->date_de_publication=p->date_de_publication;
                r->prix=p->prix;
                strcpy(r->localisation,p->localisation);
                r->surface=p->surface;
                strcpy(r->type_bien,p->type_bien);
                strcpy(r->texte_descriptif,p->texte_descriptif);
                *tete3=r;
                der=*tete3;
            }
            else
            { allouer_demande(&a);
              a->next=NULL;
              strcpy(a->categorie,p->categorie);
              a->identifiant=p->identifiant;
              a->date_de_publication=p->date_de_publication;
              a->prix=p->prix;
              strcpy(a->localisation,p->localisation);
              a->surface=p->surface;
              strcpy(a->type_bien,p->type_bien);
              strcpy(a->texte_descriptif,p->texte_descriptif);
              der->next=a;
              der=a;
              der->next=NULL;
            }
      }
      else //Si lannonce est de type offre on insére le maillon pointé par p à la fin de la liste Offre6
      {
          if (q==NULL)
            {
                allouer_offre6(&q);
                strcpy(q->categorie,p->categorie);
                q->identifiant=p->identifiant;
                q->date_de_publication=p->date_de_publication;
                q->prix=p->prix;
                strcpy(q->localisation,p->localisation);
                q->surface=p->surface;
                strcpy(q->type_bien,p->type_bien);
                strcpy(q->texte_descriptif,p->texte_descriptif);
                *tete2=q;
                der2=*tete2;
            }
            else
            { allouer_offre6(&b);
              b->next=NULL;
              strcpy(b->categorie,p->categorie);
              b->identifiant=p->identifiant;
              b->date_de_publication=p->date_de_publication;
              b->prix=p->prix;
              strcpy(b->localisation,p->localisation);
              b->surface=p->surface;
              strcpy(b->type_bien,p->type_bien);
              strcpy(b->texte_descriptif,p->texte_descriptif);
              der2->next=b;
              der2=b;
              der2->next=NULL;
      }

  }
  p=suivant(p);
}
}
//*****************************************************************************************************************************
void affich_LLC_offre6(Offre6 *tete) // Role: afficher la liste des annonces de type offre obtenue de léclatement
{
    Offre6 *p;
    p=tete;
    printf(" # La liste des annonces de type offre : \n");
    printf(" ---------------------------------------\n");
    printf("\n");
    printf("   categorie  | identifiant |  jdp/mdp/adp   |        prix        |  localisation  |    surface    |   type du bien   |         texte descriptif \n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n");
    while(p!=NULL)
    {
    printf("      %s            %d            %d/%d/%d       %d da          %s          %d m2           %s             %s\n",p->categorie,p->identifiant,p->date_de_publication.jour,p->date_de_publication.mois,p->date_de_publication.annee,p->prix,p->localisation,p->surface,p->type_bien,p->texte_descriptif);
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    p=suivant6(p);
    }

}
//*****************************************************************************************************************************
void affich_LLC_demande(Demande *tete) // Role: afficher la liste des annonces de type demande obtenue de léclatement
{
    Demande *p;
    p=tete;
    printf(" # La liste des annonces de typr demande: \n");
    printf(" ----------------------------------------\n");
    printf("\n");
    printf("   categorie  | identifiant |  jdp/mdp/adp   |        prix        |  localisation  |    surface    |   type du bien   |         texte descriptif \n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n");
    while(p!=NULL)
    {
    printf("    %s            %d            %d/%d/%d       %d da          %s          %d m2           %s             %s\n",p->categorie,p->identifiant,p->date_de_publication.jour,p->date_de_publication.mois,p->date_de_publication.annee,p->prix,p->localisation,p->surface,p->type_bien,p->texte_descriptif);
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    p=suivant_d(p);
    }

}
//*****************************************************************************************************************************
void tri_offre6_par_date(Offre6 *tete) // Role: Trier la liste des offres par date selon la méthode de tri par bulles
{
  int trie=0;
  int tmp_val;
  char tmp_ch[700];
  Date tmp_date;
  Offre6 *q;
  Offre6 *p;
while ( trie==0) // On sarrete lorsqu'on aura plus de permutations
{
  trie=1;
  p=tete;

  while (p->next != NULL) //On parcourt la liste jusqu'à arriver à lavant dernier maillon en comparant la ddp des maillons successives si on trouve (ddp de p > ddp de p->next) on permute
  {
    if (p->date_de_publication.annee > p->next->date_de_publication.annee) //on commence par vérifier lannee de publication
    {
        permutation_offre6(p,p->next);
        trie=0;
    }
    else
    {
         if (p->date_de_publication.annee == p->next->date_de_publication.annee) //si lannee de publication est identique pour les 2 maillons ,on passe au mois de publication
       {
           if (p->date_de_publication.mois > p->next->date_de_publication.mois)
            { permutation_offre6(p,p->next);
              trie=0;
            }
            else
            {
                if (p->date_de_publication.mois == p->next->date_de_publication.mois)
                {
                     if (p->date_de_publication.jour > p->next->date_de_publication.jour)  //si le mois de publication est identique pour les 2 maillons ,on passe au jour de publication
                     {
                         permutation_offre6(p,p->next);
                         trie=0;
                     }
                }

            }

      }

    }
    p=suivant6(p);
  }

}
}
//*****************************************************************************************************************************
void permutation_offre6(Offre6 *p, Offre6 *q ) // Role : Réaliser la permutation de 2 maillons de type Offre6
{
int tmp_val; //une temporaire valeur
char tmp_ch[700]; //une temporaire chaine de caracteres
Date tmp_date;


           strcpy(tmp_ch,q->categorie);
           strcpy(q->categorie,p->categorie);
           strcpy(p->categorie,tmp_ch);
           tmp_val=q->identifiant;
           q->identifiant=p->identifiant;
           p->identifiant=tmp_val;
           tmp_date=q->date_de_publication;
           q->date_de_publication=p->date_de_publication;
           p->date_de_publication=tmp_date;
           tmp_val=q->prix;
          q->prix=p->prix;
           p->prix=tmp_val;
           strcpy(tmp_ch,q->localisation);
           strcpy(q->localisation,p->localisation);
           strcpy(p->localisation,tmp_ch);
           tmp_val=q->surface;
           q->surface=p->surface;
           p->surface=tmp_val;
           strcpy(tmp_ch,q->type_bien);
           strcpy(q->type_bien,p->type_bien);
           strcpy(p->type_bien,tmp_ch);
           strcpy(tmp_ch,q->texte_descriptif);
           strcpy(q->texte_descriptif,p->texte_descriptif);
           strcpy(p->texte_descriptif,tmp_ch);
}
//****************************************************************************************************************************
void tri_demande_par_date(Demande *tete) // Role: Trier la liste des demandes par date selon la méthode de tri par bulles
{
  int trie=0;
  int tmp_val;
  char tmp_ch[700];
  Date tmp_date;
  Demande *q;
  Demande *p;
while ( trie==0)
{
  trie=1;
  p=tete;
  while (p->next != NULL)
  {
    if (p->date_de_publication.annee > p->next->date_de_publication.annee)
    {
        permutation_demande(p,p->next);
        trie=0;
    }
    else
    {
         if (p->date_de_publication.annee == p->next->date_de_publication.annee)
       {
           if (p->date_de_publication.mois > p->next->date_de_publication.mois)
            { permutation_demande(p,p->next);
              trie=0;
            }
            else
            {
                if (p->date_de_publication.mois == p->next->date_de_publication.mois)
                {
                     if (p->date_de_publication.jour > p->next->date_de_publication.jour)
                     {
                         permutation_demande(p,p->next);
                         trie=0;
                     }
                }

            }

      }

    }
    p=suivant_d(p);
  }

}
}
//*****************************************************************************************************************************
void permutation_demande(Demande *p, Demande *q )  // Role : Réaliser la permutation de 2 maillons de type Demande
{
int tmp_val;
char tmp_ch[700];
Date tmp_date;


           strcpy(tmp_ch,q->categorie);
           strcpy(q->categorie,p->categorie);
           strcpy(p->categorie,tmp_ch);
           tmp_val=q->identifiant;
           q->identifiant=p->identifiant;
           p->identifiant=tmp_val;
           tmp_date=q->date_de_publication;
           q->date_de_publication=p->date_de_publication;
           p->date_de_publication=tmp_date;
           tmp_val=q->prix;
          q->prix=p->prix;
           p->prix=tmp_val;
           strcpy(tmp_ch,q->localisation);
           strcpy(q->localisation,p->localisation);
           strcpy(p->localisation,tmp_ch);
           tmp_val=q->surface;
           q->surface=p->surface;
           p->surface=tmp_val;
           strcpy(tmp_ch,q->type_bien);
           strcpy(q->type_bien,p->type_bien);
           strcpy(p->type_bien,tmp_ch);
           strcpy(tmp_ch,q->texte_descriptif);
           strcpy(q->texte_descriptif,p->texte_descriptif);
           strcpy(p->texte_descriptif,tmp_ch);
}
//****************************************************************************************************************************
void fusion(Annoncet **tete , Offre6 *tete1 , Demande *tete2) //Role: Fusion des 2 listes triées Offre6 et Demande en créant una 3eme liste Annoncet
{
    Offre6 *p1;
    Demande *p2;
    Annoncet *t;
    Annoncet *q=NULL;
    p1=tete1;
    p2=tete2;
    t=*tete;
while ( (p1!=NULL) && ( p2!=NULL) ) //on parcourt les 2 listes au mm tempts jusqu'à arriver en queue dune des 2 listes
{
     if (p2->date_de_publication.annee > p1->date_de_publication.annee)
    {

        Insertion_offre(&t,p1,&q);
        p1=suivant6(p1);
    }
    else
    {
         if (p2->date_de_publication.annee < p1->date_de_publication.annee)
       {
           Insertion_demande(&t,p2,&q);
           p2=suivant_d(p2);
       }
       else
       {
           if (p2->date_de_publication.mois > p1->date_de_publication.mois)
            {
                 Insertion_offre(&t,p1,&q);
                 p1=suivant6(p1);
            }
            else
            {
                if (p2->date_de_publication.mois < p1->date_de_publication.mois)
                {
                   Insertion_demande(&t,p2,&q);
                   p2=suivant_d(p2);
                }
                else
                {
                     if (p2->date_de_publication.jour > p1->date_de_publication.jour)
                     {
                         Insertion_offre(&t,p1,&q);
                         p1=suivant6(p1);
                     }
                     else
                     {
                         if (p2->date_de_publication.jour < p1->date_de_publication.jour)
                         {
                             Insertion_demande(&t,p2,&q);
                             p2=suivant_d(p2);
                         }
                         else //si les ddp sont identiques dans les 2 maillons pointés par p1 et q1 on insére les 2 maillons en fin de la liste Annoncet
                         {
                             Insertion_offre(&t,p1,&q);
                             p1=suivant6(p1);

                             Insertion_demande(&t,p2,&q);
                             p2=suivant_d(p2);
                         }
                     }
                }

            }

     }

    }
}

while ( p1!=NULL )
{
   Insertion_offre(&t,p1,&q);
   p1=suivant6(p1);
}
while ( p2!=NULL )
{
    Insertion_demande(&t,p2,&q);
    p2=suivant_d(p2);
}

q->next=NULL;


}
//****************************************************************************************************************************
void Insertion_offre(Annoncet **tete, Offre6 *p1 , Annoncet **Queue) //Role: inserer un maillon pointé par p1 en fin de la liste Annoncet et rendre la queue de cette derniere
{
    Annoncet *p;
    Annoncet *t;
    Annoncet *q;
    q=*Queue;
    t=*tete;

    allouer_annoncet(&p);

    strcpy(p->type_annonce,p1->type_annonce);
    strcpy(p->categorie,p1->categorie);
    p->identifiant=p1->identifiant;
    p->date_de_publication=p1->date_de_publication;
    p->prix=p1->prix;
    strcpy(p->localisation,p1->localisation);
    p->surface=p1->surface;
    strcpy(p->type_bien,p1->type_bien);
    strcpy(p->texte_descriptif,p1->texte_descriptif);

    if ( t==NULL)
    {
        t=p;
        *tete=t;
        q=p;
        *Queue=q;
    }
    else
    {
       q->next=p;
       q=p;
       *Queue=q;
    }

}
//***********************************************************************************************************************
void Insertion_demande(Annoncet **tete, Demande *p2 , Annoncet **Queue) // //Role: inserer un maillon pointé par p2 en fin de la liste Annoncet et rendre la queue de cette derniere
{
    Annoncet *p;
    Annoncet *t;
    Annoncet *q;
    q=*Queue;
    t=*tete;

    allouer_annoncet(&p);

    strcpy(p->type_annonce,p2->type_annonce);
    strcpy(p->categorie,p2->categorie);
    p->identifiant=p2->identifiant;
    p->date_de_publication=p2->date_de_publication;
    p->prix=p2->prix;
    strcpy(p->localisation,p2->localisation);
    p->surface=p2->surface;
    strcpy(p->type_bien,p2->type_bien);
    strcpy(p->texte_descriptif,p2->texte_descriptif);

    if ( t==NULL)
    {
        t=p;
        *tete=t;
        q=p;
        *Queue=q;
    }
    else
    {
       q->next=p;
       q=p;
       *Queue=q;
    }

}
//****************************************************************************************************************************
void affich_LLC_annoncet(Annoncet *tete) //Role:Affciher la liste des annonces triée Annoncet
{
    Annoncet *p;
    p=tete;
    printf(" # La liste des annonces triee : \n");
    printf(" ------------------------\n");
    printf("\n");
    printf(" type d'annonce   |   categorie  | identifiant |  jdp/mdp/adp   |        prix        |  localisation  |    surface    |   type du bien   |         texte descriptif \n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n");
    while(p!=NULL)
    {
    printf("     %s          %s            %d            %d/%d/%d       %d da          %s          %d m2           %s             %s\n",p->type_annonce,p->categorie,p->identifiant,p->date_de_publication.jour,p->date_de_publication.mois,p->date_de_publication.annee,p->prix,p->localisation,p->surface,p->type_bien,p->texte_descriptif);
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    p=suivant_t(p);
    }

}

//*****************************************************************************************************************************
//question07:
//*****************************************************************************************************************************
void affich_LLC_offres_ses_annonceurs(Offre7 *tete1,Annonceur *tete2) //Role:Afficher la liste des offres qui peuvent correspondre a une demande donee ainsi que les informations de leurs annonceurs
{
    Offre7 *p;
    Annonceur *q;
    p=tete1;
    q=tete2;
    printf(" # Voici la liste des offres correspandantes a votre demande ainsi que leurs annonceurs : \n");
    printf(" -----------------------------------------------------------------\n");
    printf("\n");
    printf(" categorie  | identifiant |  jdp/mdp/adp   |        prix        |  localisation  |    surface    |   type du bien   |         texte descriptif \n");
    printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n");
    while(p!=NULL)
    {
      while (q->num_sequentiel != p->identifiant)
            {
                q=prochain(q);
            }
      printf("   %s            %d            %d/%d/%d       %d da          %s          %d m2           %s             %s\n",p->categorie,p->identifiant,p->date_de_publication.jour,p->date_de_publication.mois,p->date_de_publication.annee,p->prix,p->localisation,p->surface,p->type_bien,p->texte_descriptif);
      printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
      printf("Nom dutilisateur   |   mot de passe    |   num sequentiel  |   adresse mail    |   numero de telephonne \n");
      printf("-----------------------------------------------------------------------------------------------------------");
      printf("    %s          %s          %d          %s          %s          \n",q->nom_utilisateur,q->mot_de_passe,q->num_sequentiel,q->adresse_mail,q->numero_de_telephonne);
      printf("---------------------------------------------------------------------------------");
      p=suivant7(p);
    }

}
//*****************************************************************************************************************************
void offre_correspond_demande(Annonce *tete1 ,Offre7 **tete2 ,Annonceur *tete3, char type_bien[30] , char categorie[30] , float prix , float surface)
//Role: Creer la liste des offres qui peuvent correspondre a une demande donnée selon certains criteres et l'afficher ainsi que les informations des annonceurs
{
    Annonce *p;
    Offre7 *r;
    Offre7 *der;
    Offre7 *a;
    p=tete1;
    r=*tete2;
    char ch[30]="offre";
    float b= (prix/10)+ prix;
    float c= prix - (prix/10);
    float d= (surface/10) + surface;
    float e= surface - (surface/10);
    int cpt=0;

    while (p != NULL)
    {
        if ( strcmp(p->type_bien,type_bien)==0 && strcmp(p->categorie,categorie)==0 && strcmp(p->type_annonce,ch)==0 && c<p->prix && p->prix<b && e<p->surface && p->surface<d )
        {
            if (r==NULL)
            {
                allouer_offre7(&r);
                strcpy(r->categorie,p->categorie);
                r->identifiant=p->identifiant;
                r->date_de_publication=p->date_de_publication;
                r->prix=p->prix;
                strcpy(r->localisation,p->localisation);
                r->surface=p->surface;
                strcpy(r->type_bien,p->type_bien);
                strcpy(r->texte_descriptif,p->texte_descriptif);
                *tete2=r;
                der=*tete2;
            }
            else
            { allouer_offre7(&a);
              a->next=NULL;
              strcpy(a->categorie,p->categorie);
              a->identifiant=p->identifiant;
              a->date_de_publication=p->date_de_publication;
              a->prix=p->prix;
              strcpy(a->localisation,p->localisation);
              a->surface=p->surface;
              strcpy(a->type_bien,p->type_bien);
              strcpy(a->texte_descriptif,p->texte_descriptif);
              der->next=a;
              der=a;
              der->next=NULL;
            }
        cpt=cpt+1;

       }
     p=suivant(p);

    }
    if (cpt==0)
    {
        printf("Desole,les offres que vous recherchez ne sont pas disponibles. \n");
    }
else
    {
       affich_LLC_offres_ses_annonceurs(r,tete3);
    }

}
//*****************************************************************************************************************************
//question08:
//*****************************************************************************************************************************





//*****************************************************************************************************************************

