#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure contenant les différentes données du client

typedef struct client{
        char nom[30];
        char N_PASSEPORT[10];
        char adresse[50];
        char pays[30];
        char phone_number[13];
        char email[100];
}client;

//Nouvelle structure client pour pouvoir créer une liste chainée

typedef struct client1{
    client cl;
    struct client1 *suiv1;
}client1;


//Structure contenant les prestations de l'hotel

typedef struct prestation{
    int numero;
    char designation[20];
    char type[30];
    int jourd;
    int moisd;
    int anneed;
    int jourf;
    int moisf;
    int anneef;
    int nb_place;
    float prix;
}prestation;


//Nouvelle structure prestation pour pouvoir créer une liste chainée

typedef struct prestation1{
    prestation prest;
    struct prestation1 *suiv2;
}prestation1;


//Création d'une liste des clients de l'hotel

typedef client1 *liste_client_hotel ;


//Création d'une liste des prestations de l'hotel

typedef prestation1 *liste_prestation_hotel ;


//Création d'une liste des prestations du client

typedef prestation1 *liste_prestation_client ;


//Structure contenant l'historique des séjours d'un client

typedef struct historique{
    client x;
    prestation c;
}historique;

//Fonction permettant de créer un nouveau client dans la base de donnée

client* creer_client(){
    client a;
    FILE* fc;
    fc=fopen("Client.txt","a");
    client1* e=(client1*)malloc(sizeof(client1));
    printf("\nEntrez le nom complet: ");
    getchar();
    fgets(a.nom,30,stdin);
    printf("\nEntrez le numero de passeport: ");
    fgets(a.N_PASSEPORT,10,stdin);
    printf("\nEntrez le pays : ");
    fgets(a.pays,30,stdin);
    printf("\nEntrez l'adresse : ");
    fgets(a.adresse,50,stdin);
    printf("\nEntrez l'email : ");
    fgets(a.email,100,stdin);
    printf("\nEntrez le numero de telephone : ");
    fgets(a.phone_number,13,stdin);
    fprintf(fc,"%s;%s;%s;%s;%s;%s",a.nom,a.N_PASSEPORT,a.pays,a.adresse,a.email,a.phone_number);
    e->cl=a;
    e->suiv1=NULL;
    fclose(fc);
    return e;
}

//Fonction permettant de créer une prestation

prestation* creer_prestation()
{
    prestation p;
    FILE* fp;
    fp=fopen("Prestation.txt","a");
    prestation1* p1=(prestation1*)malloc(sizeof(prestation1));
    printf("\nEntrez le numero :\n");
    scanf("%d",&p.numero);
    printf("Entrez le type :\n");
    getchar();
    fgets(p.type,30,stdin);
    printf("Entrez la designation :\n");
    fgets(p.designation,20,stdin);
    printf("Entrez la date de debut(jour à part,etc):\n");
    scanf("%d%d%d",&p.jourd,&p.moisd,&p.anneed);
    printf("Entrez la date de fin (jour à part,etc):\n");
    scanf("%d%d%d",&p.jourf,&p.moisf,&p.anneef);
    printf("\nEntrez le prix:\n");
    scanf("%f",&p.prix);
    fprintf(fp,"%d;%s;%s;%d.%d.%d;%d.%d.%d;%f",p.numero,p.type,p.designation,p.jourd,p.moisd,p.anneed,p.jourf,p.moisf,p.anneef,p.prix);
    p1->prest=p;
    p1->suiv2=NULL;
    fclose(fp);
    return p1;
}

//Fonction pour ajouter une prestation à une liste de prestation et qui retourne cette dernière

liste_prestation_hotel ajouter_prestation1(liste_prestation_hotel l,prestation1* p){
    if(l==NULL)
        l=p;
    else{
        prestation1 *courant=l;
        while(courant->suiv2!=NULL)
            courant=courant->suiv2;
        courant->suiv2=p;
    }
    return l;}

//Fonction pour supprimer une prestation d'une liste de prestation et qui retourne cette dernière

liste_prestation_hotel supprimer_prestation1(liste_prestation_hotel l,char nom[20]){
    if(l!=NULL){
        prestation1 *courant=l,*precedent=NULL;
        while(courant!=NULL && strcmp(courant->prest.designation,nom)!=0){
            precedent=courant;
            courant=courant->suiv2;
        }
        if(courant!=NULL){
            if(precedent!=NULL)
                precedent->suiv2=courant->suiv2;
            else
                l=courant->suiv2;
            free(courant);
        }
        else
            printf("\nNom introuvable!\n");
    }
    return l;}

//Fonction pour ajouter une prestation à une liste de prestation et qui retourne cette dernière

liste_prestation_client ajouter_prestation2(liste_prestation_client l,prestation1* p){
    if(l==NULL)
        l=p;
    else{
        prestation1 *courant=l;
        while(courant->suiv2!=NULL)
            courant=courant->suiv2;
        courant->suiv2=p;
    }
    return l;}

//Fonction pour supprimer une prestation d'une liste de prestation et qui retourne cette dernière

liste_prestation_client supprimer_prestation2(liste_prestation_client l,char nom[20]){
    if(l!=NULL){
        prestation1 * courant=l,*precedent=NULL;
        while(courant!=NULL && strcmp(courant->prest.designation,nom)!=0){
            precedent=courant;
            courant=courant->suiv2;
        }
        if(courant!=NULL){
            if(precedent!=NULL)
                precedent->suiv2=courant->suiv2;
            else
                l=courant->suiv2;
            free(courant);
        }
        else
            printf("\nNom introuvable!\n");
    }
    return l;}


//Fonction permettant d'ajouter un client à une liste de client et de la retourner

liste_client_hotel  ajouter_client(liste_client_hotel  l,client1* c){
    if(l==NULL)
        l=c;
    else{
        client1 * courant=l;
        while(courant->suiv1!=NULL)
            courant=courant->suiv1;
        courant->suiv1=c;
    }
    return l;}


//Fonction permettant de supprimer un client d'une liste de client et de la retourner

liste_client_hotel  supprimer_client(liste_client_hotel  l,char name[20]){
    if(l!=NULL){
        client1 *courant=l,*precedent=NULL;
        while(courant!=NULL && strcmp(courant->cl.nom,name)!=0){
            precedent=courant;
            courant=courant->suiv1;
        }
        if(courant!=NULL){
            if(precedent!=NULL)
                precedent->suiv1=courant->suiv1;
            else
                l=courant->suiv1;
            free(courant);
        }
        else
            printf("\nNom introuvable!\n");
    }
    return l;}


//Fonction pour afficher les prestations

void afficher_prestation(liste_prestation_hotel l)
{
    FILE* f;
    f = fopen("Prestation.txt", "r");
    if (l==NULL)
        printf("il n ya pas de prestation disponible ");
    else{
    prestation1 *x=l;
    int i=1;
    printf("la liste des prestation :\n");
    while (x->suiv2!=NULL)
        {   printf("%d.\n",i);
            printf("-Numero : %d\n",x->prest.numero);
            printf("-Designation : %s\n",x->prest.designation);
            printf("-Date de debut : %d.%d.%d\n",x->prest.jourd,x->prest.moisd,x->prest.anneed);
            printf("-Date de fin : %d.%d.%d\n",x->prest.jourf,x->prest.moisf,x->prest.anneef);
            printf("-Nombre de place : %d\n",x->prest.nb_place);
            printf("-Prix : %.2f\t",x->prest.prix);
            x=x->suiv2;
            i++;
            printf("\n**********************************\n");}
            }
    fclose(f);
}

//Fonction pour afficher la liste des clients

void afficher_clients(liste_client_hotel l)
{
    FILE* f;
    f = fopen("Client.txt", "r");
    if (l==NULL)
        printf("Il n ya pas de clients.\n ");
    else{
    client1 *x=l;
    int i=1;
    printf("La liste des clients :\n");
    while (x->suiv1!=NULL)
        {   fprintf("%d.\n",i);
            fprintf("-Nom complet : %s\n",x->cl.nom);
            fprintf("-Numero passerpot: %s\n",x->cl.N_PASSEPORT);
            fprintf("-Pays : %s\n",x->cl.pays);
            fprintf("-Adresse: %s\n",x->cl.adresse);
            fprintf("-Numero telephone : %dsn",x->cl.phone_number);
            fprintf("-Email : %s\t",x->cl.email);
            x=x->suiv1;
            i++;}
            printf("\n");}
    fclose(f);
}

//Fonction pour afficher l'historique du client

void afficher_historique_client(liste_prestation_client l)
{   if    (l == NULL)
    {printf("Aucune prestation pour ce client.\n");}
    historique h;
    int i = 1;
    while(l != NULL)
    {   h.c = l->prest;
        liste_client_hotel lch = NULL;
        client1 *y=lch;
        while(y != NULL && strcmp(y->cl.N_PASSEPORT, h.x.N_PASSEPORT) != 0)
        {y=y->suiv1;}
        if(y != NULL) //si le client a été trouvé, afficher l'historique de la prestation
        {   h.x = y->cl;
            printf("Prestation %d:\n", i);
            printf("Client:\n");
            printf("Nom: %s\n", h.x.nom);
            printf("N° de passeport: %s\n", h.x.N_PASSEPORT);
            printf("Adresse: %s\n", h.x.adresse);
            printf("Pays: %s\n", h.x.pays);
            printf("Téléphone: %s\n", h.x.phone_number);
            printf("Email: %s\n", h.x.email);
            printf("Prestation:\n");
            printf("Numéro: %d\n", h.c.numero);
            printf("Désignation: %s\n", h.c.designation);
            printf("Type: %s\n", h.c.type);
            printf("Début: %d/%d/%d\n", h.c.jourd, h.c.moisd, h.c.anneed);
            printf("Fin: %d/%d/%d\n", h.c.jourf, h.c.moisf, h.c.anneef);
            printf("Nombre de places: %d\n", h.c.nb_place);
            printf("Prix: %.2f\n", h.c.prix);
            printf("\n");
            i++;}
        l = l->suiv2;
    }
}



//Fonction pour verifier la disponibilité d'une prestation

prestation1* est_valable(liste_prestation_hotel l,int pos,int jour,int mois,int annee,int np)
{
    int i=1;
    prestation1 *x=l;
    prestation1 *v=NULL;
    if (l==NULL){
        printf("La liste de prestation est vide.\n");
        return v;
    }
    while(x->suiv2!=NULL && i!=pos)
        {x=x->suiv2;
        i++;}
        if (x->prest.anneed>annee && x->prest.moisd>mois && x->prest.jourd>jour)
            {printf("Le service n'est pas encore disponible.\n");
            return v;}
        else if   (x->prest.anneef<annee && x->prest.moisf<mois && x->prest.jourf<jour)
            {printf("Le service n'est plus disponible.\n");
            return v;}
        else if (x->prest.nb_place-np<0)
            {printf("Le nombre de place est inferieur au nombre que vous demandez.\n");
            return v;}
        else
        {
            x->prest.nb_place=x->prest.nb_place-np;
            return x;
        }

}
void prestation_entre(liste_prestation_hotel l,int jour1,int mois1,int annee1,int jour2,int mois2,int annee2)
{
    int i=1;
    prestation1 *x=l;
    while(x->suiv2!=NULL )
        {
    if ((x->prest.anneed<=annee1 && x->prest.moisd<=mois1 && x->prest.jourd<=jour1) && (x->prest.anneef>=annee2 && x->prest.moisf>=mois2 && x->prest.jourf>=jour2))
    {
            printf("%d.\n",i);
            printf("-Numero : %d\n",x->prest.numero);
            printf("-Designation : %s\n",x->prest.designation);
            printf("-Date de debut : %d.%d.%d\n",x->prest.jourd,x->prest.moisd,x->prest.anneed);
            printf("-Date de fin : %d.%d.%d\n",x->prest.jourf,x->prest.moisf,x->prest.anneef);
            printf("-Nombre de place : %d\n",x->prest.nb_place);
            printf("-Prix : %.2f\t",x->prest.prix);
            i++;
    }
    x=x->suiv2;}
}

main(){
    int n,i,j;
    char des1[20];
    char des2[20];
    char nom[20];
    liste_prestation_hotel l1=NULL;
    liste_prestation_client l3=NULL;
    liste_client_hotel l2=NULL;
    client1 *e=NULL;
    prestation1 *p=NULL;
    prestation1 *p1=NULL;
    prestation1 *p2=NULL;
    prestation1 *pt1 = malloc(sizeof(prestation1));
    pt1->prest.numero=1;
    strcpy(pt1->prest.designation,"Petit dejeuner");
    strcpy(pt1->prest.type,"Restauration");
    pt1->prest.jourd=1;
    pt1->prest.moisd=5;
    pt1->prest.anneed=2023;
    pt1->prest.jourf=31;
    pt1->prest.moisf=8;
    pt1->prest.anneef=2023;
    pt1->prest.nb_place=100;
    pt1->prest.prix=150;
    prestation1 *pt2 = malloc(sizeof(prestation1));
    pt2->prest.numero=2;
    strcpy(pt2->prest.designation,"WIFI");
    strcpy(pt2->prest.type,"Connexion");
    pt2->prest.jourd=10;
    pt2->prest.moisd=5;
    pt2->prest.anneed=2023;
    pt2->prest.jourf=10;
    pt2->prest.moisf=10;
    pt2->prest.anneef=2023;
    pt2->prest.nb_place=2000;
    pt2->prest.prix=0;
    prestation1 *pt3 = malloc(sizeof(prestation1));
    pt3->prest.numero=3;
    strcpy(pt3->prest.designation,"SPA");
    strcpy(pt3->prest.type,"Relaxation");
    pt3->prest.jourd=10;
    pt3->prest.moisd=5;
    pt3->prest.anneed=2023;
    pt3->prest.jourf=10;
    pt3->prest.moisf=9;
    pt3->prest.anneef=2023;
    pt3->prest.nb_place=100;
    pt3->prest.prix=500;
    prestation1 *pt4 = malloc(sizeof(prestation1));
    pt4->prest.numero=4;
    strcpy(pt4->prest.designation,"Parking");
    strcpy(pt4->prest.type,"Parking");
    pt4->prest.jourd=10;
    pt4->prest.moisd=5;
    pt4->prest.anneed=2023;
    pt4->prest.jourf=10;
    pt4->prest.moisf=10;
    pt4->prest.anneef=2023;
    pt4->prest.nb_place=60;
    pt4->prest.prix=20;
    prestation1 *pt5 = malloc(sizeof(prestation1));
    pt5->prest.numero=5;
    strcpy(pt5->prest.designation,"Service de chambre");
    strcpy(pt5->prest.type,"Service de chambre");
    pt5->prest.jourd=1;
    pt5->prest.moisd=5;
    pt5->prest.anneed=2023;
    pt5->prest.jourf=31;
    pt5->prest.moisf=8;
    pt5->prest.anneef=2023;
    pt5->prest.nb_place=250;
    pt5->prest.prix=0;
    pt1->suiv2=pt2;
    pt2->suiv2=pt3;
    pt3->suiv2=pt4;
    pt4->suiv2=pt5;
    l1=pt1;
    printf ("*************WELCOME*************\n");
        do{ printf("\nEtes vous ? (entrer 0 pour quitter) \n");
            printf("  1: Client.\n");
            printf("  2: Hotel. \n");
            scanf("%d",&n);
            //Cas du client
            if (n==1)
            {
            e=creer_client();
            printf("\nVous vous etes bien enregistes.\n");
            do {
                printf("Choisir une option :\n");
                printf("1: Ajouter une prestation.\n");
                printf("2: Supprimer une prestation.\n");
                printf("3: Afficher la liste de prestation.\n");
                printf("4: Afficher l'historique.\n");
                printf("5: Afficher les prestations disponibles entre deux dates.\n");
                printf("6: Quittez.\n");
                scanf("%d",&j);getchar();
                switch(j){
                    case 1:{
                        int m,np;
                        int jour,mois,annee;
                        //afficher_prestation(l1);
                        printf("Choisir une prestation.\n");
                        scanf("%d",&m);
                        printf("Entrer la date:\n");
                        printf("Jour : ");
                        scanf("%d",&jour);
                        printf("\nMois : ");
                        scanf("%d",&mois);
                        printf("\nAnnee : ");
                        scanf("%d",&annee);
                        printf("Entrer le nombre de place que vous voulez reserver:\n");
                        scanf("%d",&np);
                        p2=est_valable(l1,m,jour,mois,annee,np);
                        l3=ajouter_prestation2(l3,p2);
                        getchar();
                        printf("%d",n);
                        break;}
                    case 2: printf("Entrer la designation:"); scanf("%s",&des1); l3=supprimer_prestation2(l3,des1); break;
                    case 3: afficher_prestation(l1); break;
                    case 4: afficher_historique_client(l3); break;
                    case 5:{int jour1,mois1,annee1;
                            int jour2,mois2,annee2;
                            printf("Entrer la date de debut:\n");
                            printf("Jour : ");
                            scanf("%d",&jour1);
                            printf("\nMois : ");
                            scanf("%d",&mois1);
                            printf("\nAnnee : ");
                            scanf("%d",&annee1);
                            printf("\nEntrer la date de fin\n");
                            printf("Jour : ");
                            scanf("%d",&jour2);
                            printf("\nMois : ");
                            scanf("%d",&mois2);
                            printf("\nAnnee : ");
                            scanf("%d",&annee2);
                            prestation_entre(l1,jour1,mois1,annee1,jour2,mois2,annee2);break;}
                    default: break;
                }}while(j!=6);


            }
            //Cas de l'hotel
            else if(n==2)
            {
                do {
                printf("Choisir une option :\n");
                printf("1: Ajouter une prestation.\n");
                printf("2: Supprimer une prestation.\n");
                printf("3: Ajouter un client.\n");
                printf("4: Supprimer un client.\n");
                printf("5: Afficher la liste de prestation.\n");
                printf("6: Afficher la liste de client.\n");
                printf("7: Quittez.\n");
                scanf("%d",&i);getchar();
                switch(i){
                    case 1: p=creer_prestation(); l1=ajouter_prestation1(l1,p); break;
                    case 2: printf("Entrer la designation:"); scanf("%s",&des2); l1=supprimer_prestation1(l1,des2); break;
                    case 3: e=creer_client(); l2=ajouter_client(l2,p); break;
                    case 4: printf("Entrer le nom du client:"); scanf("%s",&nom); l2=supprimer_client(l2,nom); break;
                    case 5: afficher_prestation(l1); break;
                    case 6: afficher_clients(l2); break;
                    default: break;
                }
                }while(i!=7);
           }
        }while(n!=0);
}













