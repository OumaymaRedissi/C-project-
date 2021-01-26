/*---------Structure date--------------*/
struct date
{
    int jour;
    int mois;
    int annee;
};
typedef struct date DATE;

/*---------Structure consultation--------------*/
struct consultation
{
    DATE date;
    int motif;
    int excli;//examen clinique
    int trait;//traitement préscrit

};
typedef struct consultation CONSULTATION;
/*---------Structure patient--------------*/
struct patient
{
    int id;
    int nom;
    DATE  date_n;
    int sexe;//H ou F
    float poids;
    float taille;
    int phone;
    int email;
    int couv;//couverture sociale(cnam,cnss, cnrps assurance mutuelle)
    int profession;
    int maladies;//ancienne maladie
    int traitement;//ancien traitements
    int chir; //antécedent chirgicaux
    int nbC;
    CONSULTATION* cons;

};
typedef struct patient PATIENT;
/*---------Structure cabinet--------------*/
struct cabinet
{
    int nbP;
    PATIENT* pat;
};
typedef struct cabinet CABINET;


DATE saisirDate();
void afficherDate(DATE);


void saisirConsultation(CONSULTATION* c);
void afficherConsultation(CONSULTATION* c);


void saisirPatient(PATIENT* p);
void afficherPatient(PATIENT* p);
int rechercherPatient(PATIENT*,int,int);
void modifierPatient(PATIENT* p);


void menuPrincipal(CABINET c);
void menuListerPatients(CABINET c);
void menuAjouterPatient(CABINET c);
void menuConsulterPatient(CABINET c);
void menuModifierPatient(CABINET c);
void menuSupprimerPatient(CABINET c);




