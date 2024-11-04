#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct student{
    int code;
    char name[30];
    char subject[50];
    int sex;
    int age;
    float final_g;
};

struct grades{
    float first;
    float second;
    float third;
};

void math(struct grades Grades[], struct student aux[], int cnt);
void print(struct student Student[], int cnt, int apr, int repro);

void register_s(int cnt){
    struct student Student[cnt];
    struct grades Grades[cnt];
    for(int i=0; i<cnt; i++){
        printf("Code: "); cin>>Student[i].code;
        cin.ignore();
        printf("Name: "); gets(Student[i].name);
        printf("Subject: "); gets(Student[i].subject);
        printf("Sex(1. male, 2. female): "); cin>>Student[i].sex;
        printf("Age: "); cin>>Student[i].age;
        system("cls");

        printf("%s grades \n",Student[i].name);
        printf("First grade: "); cin>>Grades[i].first;
        printf("Second grade: "); cin>>Grades[i].second;
        printf("Third grade: "); cin>>Grades[i].third;
        system("cls");
    }

    math(Grades,Student,cnt);
}

void math(struct grades Grades[], struct student aux[], int cnt){
    int apr=0;
    int repro=0;
    for(int i=0; i<cnt; i++){
        float final=(Grades[i].first*0.3)+(Grades[i].second*0.3)+(Grades[i].third*0.4);
        aux[i].final_g=final;
        if(final>=3){
            apr++;
        }
        else{
            repro++;
        }
    }

    print(aux,cnt,apr,repro);
}

void print(struct student Student[], int cnt, int apr, int repro){
    printf("Grades \n");
    for(int i=0; i<cnt; i++){
        printf("%s --- %2f \n",Student[i].name, Student[i].final_g);
    }
    printf("%i aproved --- %i reproved", apr, repro);
}

int main(){
    int cnt;
    cout<<"How many students?: "; cin>>cnt;
    register_s(cnt);
}