main(){
     hotel_service_list l1=NULL;
     client_service_list l3=NULL;
     hotel_client_list l2=NULL;
     client_node *e=NULL;
     service_node  *p=NULL;
     service_node  *p1=NULL;
     service_node  *p2=NULL;
     service_node  *pt1 = malloc(sizeof(service_node ));
     pt1->prest.number=1;
     strcpy(pt1->prest.designation,"Breakfast");
     strcpy(pt1->prest.type,"Restoration");
     pt1->prest.day_start=1;
     pt1->prest.month_start=5;
     pt1->prest.year_start=2023;
     pt1->prest.day_end=31;
     pt1->prest.month_end=8;
     pt1->prest.year_end=2023;
     pt1->prest.nb_place=100;
     pt1->prest.price=150;
  
     service_node  *pt2 = malloc(sizeof(service_node));
     pt2->prest.number=2;
     strcpy(pt2->prest.designation,"WIFI");
     strcpy(pt2->prest.type,"Connection");
     pt2->prest.day=10;
     pt2->prest.moisd=5;
     pt2->prest.year=2023;
     pt2->prest.jourf=10;
     pt2->prest.moisf=10;
     pt2->prest.anneef=2023;
     pt2->prest.nb_place=2000;
     pt2->prest.price=0;
  
     service_node  *pt3 = malloc(sizeof(service_node));
     pt3->prest.number=3;
     strcpy(pt3->prest.designation,"SPA");
     strcpy(pt3->prest.type,"Relaxation");
     pt3->prest.day_start=10;
     pt3->prest.month_start=5;
     pt3->prest.year_start=2023;
     pt3->prest.day_end=10;
     pt3->prest.month_end=9;
     pt3->prest.year_end=2023;
     pt3->prest.nb_place=100;
     pt3->prest.price=500;
  
     service_node  *pt4 = malloc(sizeof(service_node));
     pt4->prest.number=4;
     strcpy(pt4->prest.designation,"Parking");
     strcpy(pt4->prest.type,"Parking");
     pt4->prest.day_start=10;
     pt4->prest.month_start=5;
     pt4->prest.year_start=2023;
     pt4->prest.day_end=10;
     pt4->prest.month_end=10;
     pt4->prest.year_end=2023;
     pt4->prest.nb_place=60;
     pt4->prest.price=20;
     service_node  *pt5 = malloc(sizeof(service_node ));
  
     pt5->prest.number=5;
     strcpy(pt5->prest.designation,"Room Service");
     strcpy(pt5->prest.type,"Room Service");
     pt5->prest.day_start=1;
     pt5->prest.month_start=5;
     pt5->prest.year_start=2023;
     pt5->prest.day_end=31;
     pt5->prest.month_end=8;
     pt5->prest.year_end=2023;
     pt5->prest.nb_place=250;
     pt5->prest.price=0;
  
     pt1->next2=pt2;
     pt2->next2=pt3;
     pt3->next2=pt4;
     pt4->next2=pt5;
     l1=pt1;
  
    printf ("*************WELCOME*************\n");
         do{ printf("\nAre you? (enter 0 to exit) \n");
             printf(" 1: Client.\n");
             printf(" 2: Hotel.\n");
             scanf("%d",&n);
             //Customer case
             if (n==1)
             {
             e=create_client();
             printf("\nYou have successfully registered.\n");
             do {
                 printf("Choose an option:\n");
                 printf("1: Add a service.\n");
                 printf("2: Delete a service.\n");
                 printf("3: Show service list.\n");
                 printf("4: Show history.\n");
                 printf("5: Display the services available between two dates.\n");
                 printf("6: Exit.\n");
                 scanf("%d",&j);getchar();
               
                 switch(j){
                     case 1:{
                         int m,np;
                         int day,month,year;
                       
                         //display_service(l1);
                         printf("Choose a service.\n");
                         scanf("%d",&m);
                       
                         printf("Enter date:\n");
                         printf("Day: ");
                         scanf("%d",&day);
                       
                         printf("\nMonth: ");
                         scanf("%d",&month);
                       
                         printf("\nYear: ");
                         scanf("%d",&year);
                       
                         printf("Enter the number of places you want to reserve:\n");
                         scanf("%d",&np);
                       
                         p2=is_available(l1,m,day,month,year,np);
                         l3=add_service2(l3,p2);
                         getchar();
                         printf("%d",n);
                         break;}
                   
                     case 2: printf("Enter designation:"); scanf("%s",&des1); l3=delete_service2(l3,des1); break;
                   
                     case 3: display_service(l1); break;
                   
                     case 4: display_client_history(l3); break;
                   
                     case 5:{int day1,month1,year1;
                             int day2,month2,year2;
                             
                             printf("Enter start date:\n");
                             printf("Day: ");
                             scanf("%d",&day1);
                             
                             printf("\nMonth: ");
                             scanf("%d",&month1);
                             
                             printf("\nYear: ");
                             scanf("%d",&year1);
                             
                             printf("\nEnter end date\n");
                             printf("Day: ");
                             scanf("%d",&day2);
                             
                             printf("\nMonth: ");
                             scanf("%d",&month2);
                             
                             printf("\nYear: ");
                             scanf("%d",&year2);
                             
                             service_between(l1,day1,month1,year1,day2,month2,year2); break;}
                   
                     default: break;
                 }}while(j!=6);


             }
             //Hotel case
             else if(n==2)
             {
                 do {
                 printf("Choose an option:\n");
                 printf("1: Add a service.\n");
                 printf("2: Delete a service.\n");
                 printf("3: Add a customer.\n");
                 printf("4: Delete a client.\n");
                 printf("5: Show service list.\n");
                 printf("6: Show customer list.\n");
                 printf("7: Exit.\n");
                 scanf("%d",&i);getchar();
                   
                 switch(i){
                     case 1: p = create_service(); l1=add_service1(l1,p); break;
                   
                     case 2: printf("Enter designation:"); scanf("%s",&des2); l1=delete_service1(l1,des2); break;
                   
                     case 3: e=create_client(); l2=add_client(l2,p); break;
                   
                     case 4: printf("Enter customer name:"); scanf("%s",&name); l2=delete_client(l2,name); break;
                       
                     case 5: display_service(l1); break;
                   
                     case 6: display_clients(l2); break;
                   
                     default: break;
                 }
                 }while(i!=7);
            }
         }while(n!=0);
}
