#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct patient{
    int code;
    char name[30];
    char last_n[30];
    int age;
    char eps[50];
    char date_i[10];
    float hour_i;
    char date_f[10];
    float hour_f;
};

void organizer(struct patient org[], int cnt);
void print(struct patient print[], int cnt);

void register_p(int cnt){
    struct patient Patient[cnt];
    for(int i=0; i<cnt; i++){
        printf("Patient number %i \n",i+1);
        printf("code: "); cin>>Patient[i].code;
        cin.ignore();
        printf("name: "); gets(Patient[i].name);
        printf("last name: "); gets(Patient[i].last_n);
        printf("age: "); cin>>Patient[i].age;
        cin.ignore();
        printf("Eps: "); gets(Patient[i].eps);
        printf("Initial date(xx/xx/xxxx): "); gets(Patient[i].date_i);
        printf("Initial hour(xx.xx): "), cin>>Patient[i].hour_i;
        cin.ignore();
        printf("Last date(xx/xx/xxxx): "); gets(Patient[i].date_f);
        printf("Last hour(xx.xx): "); cin>>Patient[i].hour_f;
        system("cls");
    }

    organizer(Patient, cnt);
    print(Patient, cnt);
}

void organizer(struct patient org[], int cnt){
    struct patient aux;
    for(int i=0; i<cnt-1; i++){
        for(int j=i+1; j<cnt; j++){
            if(org[i].code>org[j].code){
                aux=org[i];
                org[i]=org[j];
                org[j]=aux;
            }
        }
    }
}

void print(struct patient print[], int cnt){
    for(int i=0; i<cnt; i++){
        printf("Code: %i \n", print[i].code);
        printf("Name: %s \n", print[i].name);
        printf("Last name: %s \n", print[i].last_n);
        printf("Age: %i \n", print[i].age);
        printf("Eps: %s \n", print[i].eps);
        printf("Initial date: %s \n", print[i].date_i);
        printf("Initial hour: %2f \n", print[i].hour_i);
        printf("Last date: %s \n", print[i].date_f);
        printf("Last hour: %2f \n", print[i].hour_f);
        cout<<"\n";
    }
}

int main(){
    int cnt;
    printf("How many patients?: "); cin>>cnt;

    register_p(cnt);
}