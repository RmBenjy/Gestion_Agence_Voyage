#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure containing different customer data

typedef struct client {
    char name[30];
    char PASSPORT_NUMBER[10];
    char address[50];
    char country[30];
    char phone_number[13];
    char email[100];
} client;

// New client structure to create a linked list

typedef struct client_node {
    client cl;
    struct client_node* next1;
} client_node;

// Structure containing hotel services

typedef struct service {
    int number;
    char designation[20];
    char type[30];
    int day_start;
    int month_start;
    int year_start;
    int day_end;
    int month_end;
    int year_end;
    int nb_place;
    float price;
} service;

// New service structure to create a linked list

typedef struct service_node {
    service prest;
    struct service_node* next2;
} service_node;

// Create a list of hotel guests

typedef client_node* hotel_client_list;

// Create a list of hotel services

typedef service_node* hotel_service_list;

// Create a list of customer services

typedef service_node* client_service_list;

// Structure containing the history of a customer's stays

typedef struct history {
    client x;
    service c;
} history;

// Function to create a new customer in the database

client* create_client() {
    client a;
    FILE* fc;
    fc = fopen("Client.txt", "a");
    client_node* e = (client_node*)malloc(sizeof(client_node));
    printf("\nEnter full name: ");
    getchar();
    fgets(a.name, 30, stdin);

    printf("\nEnter passport number: ");
    fgets(a.PASSPORT_NUMBER, 10, stdin);

    printf("\nEnter country: ");
    fgets(a.country, 30, stdin);

    printf("\nEnter address: ");
    fgets(a.address, 50, stdin);

    printf("\nEnter email: ");
    fgets(a.email, 100, stdin);

    printf("\nEnter phone number: ");
    fgets(a.phone_number, 13, stdin);

    fprintf(fc, "%s;%s;%s;%s;%s;%s", a.name, a.PASSPORT_NUMBER, a.country, a.address, a.email, a.phone_number);
    e->cl = a;
    e->next1 = NULL;
    fclose(fc);
    return e;
}

// Function to create a service

service* create_service() {
    service p;
    FILE* fp;
    fp = fopen("Prestation.txt", "a");
    service_node *p1 = (service_node*)malloc(sizeof(service_node));
    printf("\nEnter number:\n");
    scanf("%d", &p.number);

    printf("Enter type:\n");
    getchar();
    fgets(p.type, 30, stdin);

    printf("Enter the designation:\n");
    fgets(p.designation, 20, stdin);

    printf("Enter the start date(day apart, etc):\n");
    scanf("%d%d%d", &p.day_start, &p.month_start, &p.year_start);

    printf("Enter the end date (day apart, etc):\n");
    scanf("%d%d%d", &p.day_end, &p.month_end, &p.year_end);

    printf("\nEnter price:\n");
    scanf("%f", &p.price);

    fprintf(fp, "%d;%s;%s;%d.%d.%d;%d.%d.%d;%f", p.number, p.type, p.designation, p.day_start, p.month_start, p.year_start, p.day_end, p.month_end, p.year_end, p.price);
    p1->prest = p;
    p1->next2 = NULL;
    fclose(fp);
    return p1;
}

// Function to add a service to a list of services and return the list

hotel_service_list add_service1(hotel_service_list l, service_node* p) {
    if (l == NULL)
        l = p;
    else {
        service_node* current = l;
        while (current->next2 != NULL)
            current = current->next2;
        current->next2 = p;
    }
    return l;
}

// Function to delete a service from a list of services and return the list

hotel_service_list delete_service1(hotel_service_list l, char name[20]) {
    if (l != NULL) {
        service_node* current = l, *previous = NULL;
        while (current != NULL && strcmp(current->prest.designation, name) != 0) {
            previous = current;
            current = current->next2;
        }
        if (current != NULL) {
            if (previous != NULL)
                previous->next2 = current->next2;
            else
                l = current->next2;
            free(current);
        }
        else
            printf("\nName not found!\n");
    }
    return l;
}

// Function to add a service to a list of services and return the list

client_service_list add_service2(client_service_list l, service_node* p) {
    if (l == NULL)
        l = p;
    else {
        service_node* current = l;
        while (current->next2 != NULL)
            current = current->next2;
        current->next2 = p;
    }
    return l;
}

// Function to delete a service from a list of services and return the list

client_service_list delete_service2(client_service_list l, char name[20]) {
    if (l != NULL) {
        service_node* current = l, *previous = NULL;
        while (current != NULL && strcmp(current->prest.designation, name) != 0) {
            previous = current;
            current = current->next2;
        }
        if (current != NULL) {
            if (previous != NULL)
                previous->next2 = current->next2;
            else
                l = current->next2;
            free(current);
        }
        else
            printf("\nName not found!\n");
    }
    return l;
}

// Function to add a client to a list of clients and return the list

hotel_client_list add_client(hotel_client_list l, client_node* c) {
    if (l == NULL)
        l = c;
    else {
        client_node* current = l;
        while (current->next1 != NULL)
            current = current->next1;
        current->next1 = c;
    }
    return l;
}

// Function to delete a client from a list of clients and return the list

hotel_client_list delete_client(hotel_client_list l, char name[20]) {
    if (l != NULL) {
        client_node* current = l, *previous = NULL;
        while (current != NULL && strcmp(current->cl.name, name) != 0) {
            previous = current;
            current = current->next1;
        }
        if (current != NULL) {
            if (previous != NULL)
                previous->next1 = current->next1;
            else
                l = current->next1;
            free(current);
        }
        else
            printf("\nName not found!\n");
    }
    return l;
}

// Function to display services

void display_service(hotel_service_list l) {
    FILE* f;
    f = fopen("Prestation.txt", "r");
    if (l == NULL)
        printf("No services available ");
    else {
        service_node* x = l;
        int i = 1;
        printf("List of services:\n");
        while (x->next2 != NULL) {
            printf("%d.\n", i);
            printf("-Number: %d\n", x->prest.number);
            printf("-Designation: %s\n", x->prest.designation);
            printf("-Start date: %d.%d.%d\n", x->prest.day_start, x->prest.month_start, x->prest.year_start);
            printf("-End date: %d.%d.%d\n", x->prest.day_end, x->prest.month_end, x->prest.year_end);
            printf("-Number of seats: %d\n", x->prest.nb_place);
            printf("-Price: %.2f\t", x->prest.price);
            x = x->next2;
            i++;
            printf("\n**********************************\n");
        }
    }
    fclose(f);
}

// Function to display the list of clients

void display_clients(hotel_client_list l) {
    FILE* f;
    f = fopen("Client.txt", "r");
    if (l == NULL)
        printf("No clients.\n ");
    else {
        client_node* x = l;
        int i = 1;
        printf("List of clients:\n");
        while (x->next1 != NULL) {
            fprintf("%d.\n", i);
            fprintf("-Full Name: %s\n", x->cl.name);
            fprintf("-Passport Number: %s\n", x->cl.PASSPORT_NUMBER);
            fprintf("-Country: %s\n", x->cl.country);
            fprintf("-Address: %s\n", x->cl.address);
            fprintf("-Phone Number: %s\n", x->cl.phone_number);
            fprintf("-Email: %s\t", x->cl.email);
            x = x->next1;
            i++;
        }
        printf("\n");
    }
    fclose(f);
}

// Function to display the client's history

void display_client_history(client_service_list l) {
    if (l == NULL) {
        printf("No services for this client.\n");
    }
    history h;
    int i = 1;
    while (l != NULL) {
        h.c = l->prest;
        hotel_client_list lch = NULL;
        client_node* y = lch;
        while (y != NULL && strcmp(y->cl.PASSPORT_NUMBER, h.x.PASSPORT_NUMBER) != 0) {
            y = y->next1;
        }
        if (y != NULL) {
            h.x = y->cl;
            printf("Service %d:\n", i);
            printf("Client:\n");
            printf("Name: %s\n", h.x.name);
            printf("Passport Number: %s\n", h.x.PASSPORT_NUMBER);
            printf("Address: %s\n", h.x.address);
            printf("Country: %s\n", h.x.country);
            printf("Phone Number: %s\n", h.x.phone_number);
            printf("Email: %s\n", h.x.email);
            printf("Service:\n");
            printf("Number: %d\n", h.c.number);
            printf("Designation: %s\n", h.c.designation);
            printf("Type: %s\n", h.c.type);
            printf("Start: %d/%d/%d\n", h.c.day_start, h.c.month_start, h.c.year_start);
            printf("End: %d/%d/%d\n", h.c.day_end, h.c.month_end, h.c.year_end);
            printf("Number of seats: %d\n", h.c.nb_place);
            printf("Price: %.2f\n", h.c.price);
            printf("\n");
            i++;
        }
        l = l->next2;
    }
}

// Function to check the availability of a service

service_node* is_available(hotel_service_list l, int pos, int day, int month, int year, int np) {
    int i = 1;
    service_node* x = l;
    service_node* v = NULL;
    if (l == NULL) {
        printf("The service list is empty.\n");
        return v;
    }
    while (x->next2 != NULL && i != pos) {
        x = x->next2;
        i++;
    }
    if (x->prest.year_start > year && x->prest.month_start > month && x->prest.day_start > day) {
        printf("The service is not yet available.\n");
        return v;
    }
    else if (x->prest.year_end < year && x->prest.month_end < month && x->prest.day_end < day) {
        printf("The service is no longer available.\n");
        return v;
    }
    else if (x->prest.nb_place - np < 0) {
        printf("The number of seats is less than the number you request.\n");
        return v;
    }
    else {
        x->prest.nb_place = x->prest.nb_place - np;
        return x;
    }
}

void service_between(list_service_hotel l,int day1,int month1,int year1,int day2,int month2,int year2)
{
     int i = 1;
     service_node *x = l;
     while(x->next2! = NULL )
         {
     if ((x->prest.year_start<=year1 && x->prest.month_start<=month1 && x->prest.day_start<=day1) && (x->prest.year_end>=year2 && x->prest. month_end>=month2 && x->prest.day_end>=day2))
     {
             printf("%d.\n",i);
             printf("-Number: %d\n",x->prest.number);
             printf("-Designation: %s\n",x->prest.designation);
             printf("-Start date: %d.%d.%d\n",x->prest.day_start,x->prest.month_start,x->prest.year_start);
             printf("-End date: %d.%d.%d\n",x->prest.day_end,x->prest.month_end,x->prest.year_end);
             printf("-Number of places: %d\n",x->prest.nb_place);
             printf("-Price: %.2f\t",x->prest.price);
             i++;
     }
     x = x->next2;}
}














