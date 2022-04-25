#include <conio.h>
#include <dos.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

#include <unistd.h>

char clinic[100][100] = {"Dentist", "Pedriatic", "Psychiatrist", "Dermatologist"};
char dentist[100][100] ={"Amoxicilin","Ibuprofen","Naproxen"};
char pedriatic[100][100] ={"Sanmol","Bisolvon Kids","Hufagripp"};
char psychiatrist[100][100] ={"Xanax", "Sentriline", "Sleeping pill"};
char dermatologist[100][100] ={"Visancort", "Bioplacenta", "Bevalex"};
char price[100][100]={"100000","50000","88000","75000","30000","60000"};
int pq=0,pq_s=0;

struct patient {
  char name[100];
  char birth[100];
  char age[100];
  char addres[100];
  char status[100];
  struct patient *next;
};
struct details {
  char doctor[100];
  char treatment[1000];
  char clinic[100];
  char cost_d[100];
  struct details *next;
  struct patient *list;
};
struct pharmacy{
	char nama[1000];
	char medication[1000];
	char diagnosis[1000];
	char cost_m[1000];
	char cost_d[1000];
	char cost_a[1000];
	char status[1000];
}pharmacy_q[1000];

struct details *all = NULL;
struct patient *patient = NULL;
struct details *display(struct details *);
struct details *Regis(struct details *);
struct details *delete_beg(struct details *);
struct details *Queue(struct details *);
struct details *copy();
void display_p();
void delete_p();

int no_antrian = 0;

int main() {
  int option;
  all = copy();

  do {
   	printf("(\\___/)================================================\n");
	printf("(• . •)              MDFR Hospital                      \n");
	printf("/>   <\\================================================\n");
    printf("1. List Doctor\n");
    printf("2. Take Queue\n");
    printf("3. Queue\n");
    printf("4. Send Patient To Pharmacy\n");
    printf("5. Display Pharmacy Queue\n");
    printf("6. Call For Take Drugs And Payment\n");

    printf(">>");
    scanf("%d", &option);
    getchar();
    switch (option) {
    case 1:
      all = display(all);
      break;
    case 2:
      all = Regis(all);
      system("cls");
      break;
    case 3:
      all = Queue(all);
      system("cls");
      break;
    case 4:
    system("cls");
      all = delete_beg(all);
      system("cls");
      break;
    case 5:
		system("cls");
      	display_p();
      	system("cls");
      	break;
    case 6:
    	delete_p();
    	system("cls");
    	break;
    }
    
  } while (option != 7);

  return 0;
}
struct details *copy() {

	struct details *curr;
	curr = (struct details *)malloc(sizeof(struct details));

	struct details *fathur = curr;
	strcpy(curr->doctor, "Adam");
	strcpy(curr->treatment, "Monday-Saturday\n\t      From 10AM-9PM");
	strcpy(curr->clinic, clinic[0]);
	strcpy(curr->cost_d,"50000");
	curr->list=NULL;

	curr->next = (struct details *)malloc(sizeof(struct details));
	curr = curr->next;
	strcpy(curr->doctor, "Shafa");
	strcpy(curr->treatment, "Monday-Saturday\n\t      From 9AM-9PM");
	strcpy(curr->clinic, clinic[0]);
	strcpy(curr->cost_d,"50000");
	curr->list=NULL;

	curr->next = (struct details *)malloc(sizeof(struct details));
	curr = curr->next;
	strcpy(curr->doctor, "Alyza");
	strcpy(curr->treatment, "Monday-Saturday\n\t      From 9AM-9PM");
	strcpy(curr->clinic, clinic[1]);
	strcpy(curr->cost_d,"30000");
	curr->list=NULL;

	curr->next = (struct details *)malloc(sizeof(struct details));
	curr = curr->next;
	strcpy(curr->doctor, "Faishal");
	strcpy(curr->treatment, "Monday-Saturday\n\t      From 9AM-9PM");
	strcpy(curr->clinic, clinic[1]);
	strcpy(curr->cost_d,"30000");
	curr->list=NULL;

	curr->next = (struct details *)malloc(sizeof(struct details));
	curr = curr->next;
	strcpy(curr->doctor, "Tara");
	strcpy(curr->treatment, "Monday-Saturday\n\t      From 9AM-9PM");
	strcpy(curr->clinic, clinic[2]);
	strcpy(curr->cost_d,"40000");
	curr->list=NULL;

	curr->next = (struct details *)malloc(sizeof(struct details));
	curr = curr->next;
	strcpy(curr->doctor, "Mario");
	strcpy(curr->treatment, "Monday-Saturday\n\t      From 9AM-9PM");
	strcpy(curr->clinic, clinic[2]);
   	strcpy(curr->cost_d,"40000");
	curr->list=NULL;

	curr->next = (struct details *)malloc(sizeof(struct details));
	curr = curr->next;
	strcpy(curr->doctor, "Dierta");
	strcpy(curr->treatment, "Monday-Saturday\n\t      From 9AM-9PM");
	strcpy(curr->clinic, clinic[3]);
	strcpy(curr->cost_d,"60000");
	curr->list=NULL;

	curr->next = (struct details *)malloc(sizeof(struct details));
	curr = curr->next;
	strcpy(curr->doctor, "Arya");
	strcpy(curr->treatment, "Monday-Saturday\n\t      From 9AM-9PM");
	strcpy(curr->clinic, clinic[3]);
	strcpy(curr->cost_d,"60000");
	curr->list=NULL;

	curr->next = NULL;

  return fathur;
}
struct details *display(struct details *all) {
  int i, y;
  struct details *curr;

  system("cls");
 	printf("(\\___/)================================================\n");
	printf("(• . •)                    Display                      \n");
	printf("/>   <\\================================================\n");

  curr = all;

  for (i = 0; i < 4; i++) {
    printf("%s\n", clinic[i]);
    printf("---------------------------\n");
	for (y = 0; y < 2; y++) {
      printf("> Doctor    : %s\n", curr->doctor);
      printf("> Available : %s\n\n", curr->treatment);
     
 
      curr = curr->next;
    }
  }

  printf("Press Enter To Continue");
  getchar();
  system("cls");
  return all;
}
struct details *Queue(struct details *all) {
	system("cls");
	int i, y, x = 1;	
	struct details *curr;
	struct patient *curr_p;
	printf("(\\___/)================================================\n");
	printf("(• . •)                     Queue                       \n");
	printf("/>   <\\================================================\n");

	curr = all;

	
	for (i = 0; i < 4; i++) {
	printf("%d) %s\n", x, clinic[i]);
	x++;
	}
	printf("\n");

  int option, count = 0;
  printf("Choose Clinic What You Want\n");
  printf(">>");
  scanf("%d", &option);
  getchar();
  system("cls");
  while (1) {
  
	if (strcmp(curr->clinic, clinic[option - 1]) == 0) {
	  break;
	} else {
	  
	  curr = curr->next;
	  count++;
	}
	}
	
	curr_p = curr->list;
	i=0;
	
	printf("Doctor %s Queue\n",curr->doctor);
	printf("---------------\n");
	if(curr_p!=NULL){
	
	while(curr_p !=NULL){
		i++;
		printf("Patient Name : %s\n",curr_p->name);
		printf("Queue  	: %d\n\n", i);
	curr_p = curr_p->next;
	}
	}
	else{
	printf("No Patient For Doctor %s:(\n\n",curr->doctor);
	}
	  curr=curr->next;
	  curr_p = curr->list;
	i=0;
	printf("\n\n");
	printf("Doctor %s Queue\n",curr->doctor);
	printf("---------------\n");
	if(curr_p!=NULL){
	while(curr_p !=NULL){
		i++;
		printf("Patient Name : %s\n",curr_p->name);
		printf("Queue 	: %d\n\n", i);
	curr_p = curr_p->next;
	}
	}
	else{
	printf("No Patient For Doctor %s:(\n\n",curr->doctor);
	printf("Press Enter To Continue\n");
	}
	getchar();
	return all;
}
struct details *Regis(struct details *all) {
  system("cls");
  int i, y, x = 1;
  struct details *curr;
  curr = (struct details *)malloc(sizeof(struct details));
  struct details *fathur = curr;
  struct patient *curr_p;

  if (curr->list == NULL) {
    curr_p = (struct patient *)malloc(sizeof(struct patient));
  }

 	printf("(\\___/)==========================================(\\___/)\n");
	printf("(• . •)                 Register                 (• . •)  \n");
	printf("/>   <\\==========================================/>   <\\\n");

  curr = all;


  for (i = 0; i < 4; i++) {
    printf("%d) %s\n", x, clinic[i]);
    x++;
  }
  printf("\n");

  int option, count = 0;
  printf("Choose Clinic What You Want\n");
  printf(">>");
  scanf("%d", &option);
  getchar();
  system("cls");
  while (1) {
  
    if (strcmp(curr->clinic, clinic[option - 1]) == 0) {
      break;
    } else {
      
      curr = curr->next;
      count++;
    }
  }


  for (i = 0; i < 2; i++) {
    printf("%d> Doctor    : %s\n", i+1, curr->doctor);
    printf(" > Available : %s\n\n", curr->treatment);
    curr = curr->next;
  }
  printf("Choose Doctor That You Want\n");
  printf(">>");
  scanf("%d", &option);
  getchar();
  curr = all;
  for (i = 0; i < count + option - 1; i++) {
    curr = curr->next;
  }
  curr_p = curr->list;




  	char name[1000];

  
	if(curr_p == NULL) {
	
  	curr_p = (struct patient *)malloc(sizeof(struct patient));
    curr->list = curr_p;
	} else {
		while (curr_p->next != NULL) {
      curr_p = curr_p->next;
		}
    curr_p->next = (struct patient *)malloc(sizeof(struct patient));
    curr_p = curr_p->next;
	}

	system("cls");
  printf("Enter Your Name: ");
  scanf("%[^\n]", &name);
  getchar();
  strcpy(curr_p->name, name);
  printf("Enter Your Birth : ");
  scanf("%[^\n]", &name);
  getchar();
  strcpy(curr_p->birth, name);
  printf("Enter Your Age : ");
  scanf("%[^\n]", &name);
  getchar();
  strcpy(curr_p->age, name);
  printf("Enter Your Adress : ");
  scanf("%[^\n]", &name);
  getchar();
  strcpy(curr_p->addres, name);
  printf("Enter Your Status(Bpjs/Inhealth/Mandiri) : ");
  scanf("%[^\n]", &name);
  getchar();
  int len=strlen(name);
  for(i=0;i<len;i++){
  	if(i==0&&name[i]>=92){
  		name[i] -=32;
	  }
	  else if(i!=0&&name[i]<92){
	  	name[i]+=32;
	  }
  }
  strcpy(curr_p->status, name);
  printf("Press Enter To Continue");
  getchar();
  system("cls");
  curr_p->next = NULL;
  

  return all;
}
struct details *delete_beg(struct details *all){
	
	struct details *curr;
	struct details *fathur = curr;
	struct patient *curr_p;
	int i, y, x = 1;
	curr=all;
	for (i = 0; i < 4; i++) {
    printf("%d) %s\n", x, clinic[i]);
    x++;
  }
  printf("\n");

  int option, count = 0;
  printf("Choose Clinic What You Want\n");
  printf(">>");
  scanf("%d", &option);
  getchar();
  system("cls");
  while (1) {
  
    if (strcmp(curr->clinic, clinic[option - 1]) == 0) {
      break;
    } else {
      
      curr = curr->next;
      count++;
    }
  }


  for (i = 0; i < 2; i++) {
    printf("%d> Doctor    : %s\n", i + 1, curr->doctor);
    curr = curr->next;
  }
  printf("Choose Doctor That You Want\n");
  printf(">>");
  scanf("%d", &option);
  getchar();
  curr = all;
  for (i = 0; i < count + option - 1; i++) {
    curr = curr->next;
  }
	curr_p=curr->list;
	if(curr_p==NULL){
		printf("No Patient:(\n\n");
		printf("Press Enter To Continue\n");
		getchar();
		return all;
	}
	strcpy(pharmacy_q[pq].nama,curr_p->name);
	printf("----------------------------\n");
	printf("Details For %s Before Go To Pharmacy\n",curr_p->name);
	printf("Diagonosis:");
	scanf("%[^\n]",pharmacy_q[pq].diagnosis);
	getchar();
	int val=rand()%3;
	int vol=rand()%6;
	printf("Medication:");
	if(strcmp(curr->clinic,clinic[0])==0){
		strcpy(pharmacy_q[pq].medication,dentist[val]);
		strcpy(pharmacy_q[pq].cost_m,price[vol]);
	}
	else if(strcmp(curr->clinic,clinic[1])==0){
		strcpy(pharmacy_q[pq].medication,pedriatic[val]);
		strcpy(pharmacy_q[pq].cost_m,price[vol]);
	}
	else if(strcmp(curr->clinic,clinic[2])==0){
		strcpy(pharmacy_q[pq].medication,psychiatrist[val]);
		strcpy(pharmacy_q[pq].cost_m,price[vol]);
	}		
	else if(strcmp(curr->clinic,clinic[3])==0){
		strcpy(pharmacy_q[pq].medication,dermatologist[val]);
		strcpy(pharmacy_q[pq].cost_m,price[vol]);
	}	
	
	strcpy(pharmacy_q[pq].status,curr_p->status);
	strcpy(pharmacy_q[pq].cost_d,curr->cost_d);
	strcpy(pharmacy_q[pq].cost_a,"10000");
  pq++;
   FILE *fclub;
	fclub = fopen("history.txt", "a");
	int k;
	for(k=0; k<1; k++){
	fprintf(fclub, "#%s#%s#%s#%s#%s#", curr_p->name,curr_p->age,curr_p->birth,curr_p->addres,curr_p->status);
	}
	fclose(fclub);
	
     if(curr->list!= NULL){
         
         curr->list=curr_p->next;
          return all;free(curr);
     }
     return all;
 }
void display_p(){
 	int v=0,i;
	system("cls");
	printf("(\\___/)================================================\n");
	printf("(• . •)              Pharmacy Queue                     \n");
	printf("/>   <\\================================================\n");
	for(i=pq_s;i<pq;i++){
 	printf("Patient Name :%s\n",pharmacy_q[i].nama);
	printf("Diagnosis  :%s\n",pharmacy_q[i].diagnosis);
	printf("Medication :%s\n",pharmacy_q[i].medication);
	printf("Queue   :%d\n",v+1);	
 	printf("---------------------------------------\n");
 	v++;
	 }
 	printf("\n");
 	printf("Press Enter To Continue\n");
 	getchar();
 }
void delete_p(){
 	printf("(\\___/)================================================\n");
	printf("(• . •)              Payment Queue                      \n");
	printf("/>   <\\================================================\n");
 	long long total=atoi(pharmacy_q[pq_s].cost_m)+atoi(pharmacy_q[pq_s].cost_d)+atoi(pharmacy_q[pq_s].cost_a);
 	system("cls");

 	if(strcmp(pharmacy_q[pq_s].nama,"")!=0){
	 	if(strcmp(pharmacy_q[pq_s].status,"Bpjs")!=0&&strcmp(pharmacy_q[pq_s].status,"Inhealth")!=0){
 	printf("Total Payment For %s\n",pharmacy_q[pq_s].nama);
 	printf("-----------------------\n");
 
 	printf("Drug :%s\n",pharmacy_q[pq_s].cost_m);
 	printf("Doctor's Services :%s\n",pharmacy_q[pq_s].cost_d);
 	printf("Administration :%s\n",pharmacy_q[pq_s].cost_a);
 	printf("Total Payment : %lld\n\n",total);
 	
 	printf("Please Complete Your Payment In Cashier\n");
 	getchar();
 	}
 	else{
 		printf("the costs are covered by insurance\n\n");
 		printf("Press Enter To Continue");
 		getchar();
	 }
	 FILE *fclub;
	fclub = fopen("history.txt", "a");
	int k;
	for(k=0; k<1; k++){
	fprintf(fclub, "%s#%s#%s#%s#%s#\n", pharmacy_q[pq_s].medication,pharmacy_q[pq_s].diagnosis,pharmacy_q[pq_s].cost_m,pharmacy_q[pq_s].cost_d,pharmacy_q[pq_s].cost_a);
	}
	fclose(fclub);
	pq_s++;
 }
 else{
 	printf("No Queue\n");
 	getchar();
 }
 }
