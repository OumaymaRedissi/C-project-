#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include"bib.h"

DATE saisirDate()
{
    DATE d;
    printf("\n\t\t\t\tJour:");
    scanf("%d",&d.jour);
    printf("\n\t\t\t\tMois:");
    scanf("%d",&d.mois);
    printf("\n\t\t\t\tAnnée:");
    scanf("%d",&d.annee);
    return d;
}
void afficherDate(DATE d)
{
    printf("%d/%d/%d",d.jour,d.mois,d.annee);

}

void saisirConsultation(CONSULTATION* c)
{
    printf("\n\tDate:");
    c->date = saisirDate();
    printf("\n\tMotif:");
    scanf("%d", &c->motif);
    printf("\n\tExamen clinique:");
    scanf("%d", &c->excli);
    printf("\n\tTraitement prescrit:");
    scanf("%d", &c->trait);
}

void afficherConsultation(CONSULTATION* c)
{
    printf("\n\t\tDate:%d",c->motif);
    afficherDate(c->date);
    printf("\n\t\tMotif:%d",c->motif);
    printf("\n\t\tExamen clinique:%d",c->excli);
    printf("\n\t\tTraitement prescrit:%d",c->trait);

}


void saisirPatient(PATIENT* p)
{
    printf("\n\t\t\tID:");
    scanf("%d", &p->id);
    printf("\n\t\t\tNom et Prenom:");
    scanf("%d", &p->nom);
    printf("\n\t\t\tDate de naissance:");
    p->date_n = saisirDate();
    printf("\n\t\t\tSexe H/F:");
    scanf("%d", &p->sexe);
    printf("\n\t\t\tPoids:");
    scanf("%f", &p->poids);
    printf("\n\t\t\tTaille:");
    scanf("%f", &p->taille);
    printf("\n\t\t\tPhone:");
    scanf("%d", &p->phone);
    printf("\n\t\t\tEmail:");
    scanf("%d", &p->email);
    printf("\n\t\t\tCouverture:");
    scanf("%d", &p->couv);
}

void afficherPatient(PATIENT* p)
{
    printf("\n\tID:%d",p->id);
    printf("\n\tNom et Prenom:%d",p->nom);
    printf("\n\tDate de naissance:");
    afficherDate(p->date_n);
    printf("\n\tSexe H/F:%d",p->sexe);
    printf("\n\tPoids:%f",p->poids);
    printf("\n\tTaille:%f",p->taille);
    printf("\n\tPhone:%d",p->phone);
    printf("\n\tEmail:%d",p->email);
    printf("\n\tCouverture:%d",p->couv);
    printf("\n\tNombre de consultations:%d",p->nbC);
}



int rechercherPatient(PATIENT* p , int nbP , int id)
{
    int i=0;
    int ind= -1;

    while(ind==-1 && i<nbP){
        if(((p[i]).id)== id) ind=i;
        i++;
        }
return ind;
}
void modifierPatient(PATIENT* p)
{

    printf("\n\t\t+++++++++Mise a jour fiche patient+++++++++++");
    printf("\n\t\tVeuillez choisir le champ a supprimer:");
    printf("\n\t1.ID:%d",p->id);
    printf("\n\t2.Nom et Prenom:%d",p->nom);
    printf("\n\t3.Date de naissance:");
    afficherDate(p->date_n);
    printf("\n\t4.Sexe H/F:%d",p->sexe);
    printf("\n\t5.Poids:%f",p->poids);
    printf("\n\t6.Taille:%f",p->taille);
    printf("\n\t7.Phone:%d",p->phone);
    printf("\n\t8.Email:%d",p->email);
    printf("\n\t9.Couverture:%d",p->couv);
    printf("\n\tVotre choix:");

    char choix=getche();
    switch (choix)
                {
                case '1':
                    printf("\n\tID:");
                    scanf("%d", &p->id);
                    break;
                case '2':
                    printf("\n\tNom et Prenom:");
                    scanf("%d", &p->nom);
                    break;
                case '3':
                    printf("\n\tDate de naissance:");
                    p->date_n = saisirDate();
                    break;
                case '4':
                    printf("\n\tSexe H/F:");
                    scanf("%d", &p->sexe);
                    break;
                case '5':
                    printf("\n\tPoids:");
                    scanf("%f", &p->poids);
                    break;
                case '6':
                    printf("\n\tTaille:");
                    scanf("%f", &p->taille);
                    break;
                case '7':
                    printf("\n\tPhone:");
                    scanf("%d", &p->phone);
                    break;
                case '8':
                    printf("\n\tEmail:");
                    scanf("%d", &p->email);
                    break;
                case '9':
                    printf("\n\tCouverture:");
                    scanf("%d", &p->couv);
                    break;
                case '0':
                    exit(1);
                }
}

/*-----------------------------------------------------------------------------------*/
 void menuPrincipal(CABINET c)
 {
    printf("\n\t\t*************************************************");
    printf("\n\t\t  *** Bonjour! Cabinet dr.Drake Ramoray   ***");
    printf("\n\t\t*************************************************");
    printf("\n\n\n\n\n\n\n");
    printf("\t\t1.Lister patients");
    printf("\n\t\t2.Creer fiche patient");
    printf("\n\t\t3.Consulter patient");
    printf("\n\t\t4.Mettre a jour fiche patient");
    printf("\n\t\t5.Supprimer patient");
    printf("\n\t\t0.Sortir");
    printf("\n\n\tEnterez votre choix: ");

    char choix=getche();
    switch (choix)
                {
                case '1':
                    menuListerPatients(c);
                    break;
                case '2':
                    menuAjouterPatient(c);
                    break;
                case '3':
                    menuConsulterPatient(c);
                    break;
                case '4':
                    menuModifierPatient(c);
                    break;
                case '5':
                    menuSupprimerPatient(c);
                    break;
                case '0':
                    exit(1);
                }
 }

void menuListerPatients(CABINET c)
{
    printf("\n\t\t*************************************************");
    printf("\n\t\t***            Liste des %d patients          ***",c.nbP);
    printf("\n\t\t*************************************************");
    if(c.nbP==0)
        printf("\n\t\t Pas de patient.");
    else
    for(int i=0;i<c.nbP;i++)
    {
            printf("\n\t\t\t++++++++++++Patient:%d+++++++++++++++",i+1);
            afficherPatient(&c.pat[i]);
            printf("\n\t\t\t+++++++++++++++++++++++++++++++++++++");

    }
    printf("\n\t\t1.Retourner menu principal");
    printf("\n\t\t0.Sortir");
    char choix=getche();
    switch (choix)
                {
                case '1':
                    menuPrincipal(c);
                    break;
                case '0':
                    exit(1);
                }

}

void menuAjouterPatient(CABINET c)
{
    printf("\n\t\t*************************************************");
    printf("\n\t\t***          Creer fiche  patient       ***");
    printf("\n\t\t*************************************************");

	c.nbP++;
	c.pat = (PATIENT*) realloc ( c.pat, c.nbP  *sizeof(PATIENT) );
	if( ! c.pat) exit(-10);
	saisirPatient(&c.pat[c.nbP-1]);

	c.pat[c.nbP-1].nbC=0;
    c.pat[c.nbP-1].cons = (CONSULTATION*) malloc (sizeof(CONSULTATION) );
    if(!c.pat[c.nbP-1].cons) exit(-10);







    printf("\n\t\t1.Retourner menu principal");
    printf("\n\t\t0.Sortir");
    char choix=getche();
    switch (choix)
                {
                case '1':
                    menuPrincipal(c);
                    break;
                case '0':
                    exit(1);
                }
}
void menuConsulterPatient(CABINET c)
{
    int id, ind ;
    printf("\n\t\t*************************************************");
    printf("\n\t\t***         Consulter fiche patient      ***");
    printf("\n\t\t*************************************************");
        do{
            printf("\n\t\t\t\tID du patient");
            scanf("%d",&id);
            ind=rechercherPatient(c.pat,c.nbP,id);
            if(ind==-1)
            printf("\t\t\t\tPatient introuvable");

            }while(ind==-1);

            printf("\n\t\t\t++++++++++++Patient:%d+++++++++++++++",ind);
            afficherPatient(&c.pat[ind]);
            if(c.pat[ind].nbC == 0) printf("\n\t\t Pas de consultation.");
            else
                for(int i=0; i<c.pat[ind].nbC ;i++)
                    {
                        printf("\n\t\t\t++++++++++++Consultation:%d+++++++++++++++",i+1);
                        afficherConsultation(&((c.pat)[ind].cons)[i]);
                        printf("\n\t\t\t+++++++++++++++++++++++++++++++++++++");
                    }



    printf("\n\t\t1.Ajouter consultation");
    printf("\n\t\t2.Retourner menu principal");
    printf("\n\t\t0.Sortir");
    char choix2;
    char choix=getche();
    switch (choix)
                {
                case '1':
                    saisirConsultation(&(c.pat[ind].cons)[c.pat[ind].nbC]);
                    c.pat[ind].nbC++;
                    c.pat[ind].cons = (CONSULTATION*) realloc ( c.pat[ind].cons , c.pat[ind].nbC  *sizeof(CONSULTATION) );
                    if( ! c.pat[ind].cons) exit(-1);



                    printf("\n\t\t\t++++++++++++Patient:%d+++++++++++++++",ind);
                    afficherPatient(&c.pat[ind]);
                    if(c.pat[ind].nbC == 0) printf("\n\t\t Pas de consultation.");
                    else
                        for(int i=0; i<c.pat[ind].nbC ;i++)
                            {
                                printf("\n\t\t\t++++++++++++Consultation:%d+++++++++++++++",i+1);
                                afficherConsultation(&((c.pat)[ind].cons)[i]);
                                printf("\n\t\t\t+++++++++++++++++++++++++++++++++++++");
                            }

                                                printf("\n\t\t1.Retourner menu principal");
                                                printf("\n\t\t0.Sortir");
                                                choix2=getche();
                                                switch (choix2)
                                                {
                                                    case '1':
                                                        menuPrincipal(c);
                                                        break;
                                                    case '0':
                                                        exit(1);
                                                }

                break;
                case '2':
                    menuPrincipal(c);
                    break;
                case '0':
                    exit(1);
                }
}

void menuModifierPatient(CABINET c)
{
    int id, ind ;
    char modif='O';
    printf("\n\t\t*************************************************");
    printf("\n\t\t***         Modifier fiche patient         ***");
    printf("\n\t\t*************************************************");
        do{
            printf("\n\t\tID du patient");
            scanf("%d",&id);
            ind=rechercherPatient(c.pat,c.nbP,id);
            if(ind==-1)
            printf("\n\t\t\t\tPatient introuvable");
        }while(ind==-1);

        do{
            modifierPatient((c.pat)+ind);
            printf("\n\t\t\t\tContinuer la modification? [O/N]");
            modif=getch();
        }while(modif=='O'||modif=='o');


    printf("\n\t\t1.Retourner menu principal");
    printf("\n\t\t0.Sortir");
    char choix=getche();
    switch (choix)
                {
                case '1':
                    menuPrincipal(c);
                    break;
                case '0':
                    exit(1);
                }

}
void menuSupprimerPatient(CABINET c )
{
    int id, ind ;
    printf("\n\t\t*************************************************");
    printf("\n\t\t***         Supprimer fiche patient         ***");
    printf("\n\t\t*************************************************");
        do{
            printf("\n\t\tID du patient a supprimer");
            scanf("%d",&id);
            ind=rechercherPatient(c.pat,c.nbP,id);
            if(ind==-1)
            printf("\n\t\t\t\tPatient introuvable!");

            }while(ind==-1);

            printf("\n\t\t1.Confirmer la suppression de la fiche du patient%d?1",c.pat[ind].nom);
            printf("\n\t\t2.Supprimer un autre patient");
            printf("\n\t\t3.Retourner menu principal");
            printf("\n\t\t0.Sortir");
                char choix=getche();
                switch (choix)
                {
                case '1':
                    free(c.pat[ind].cons);
                    for(int i=ind; i< c.nbP ; i++)
                    {c.pat[i]= c.pat[i+1];}
                    c.nbP--;
                    c.pat = (PATIENT*) realloc ( c.pat, c.nbP  *sizeof(PATIENT) );
                    if( ! c.pat) exit(-13);
                    printf("\n\t\tFiche patient supprimee avec succes");
                    menuPrincipal(c);
                    break;
                case '2':
                    menuSupprimerPatient(c);
                    break;
                case '3':
                    menuPrincipal(c);
                    break;
                case '0':
                    exit(1);
                }
}
