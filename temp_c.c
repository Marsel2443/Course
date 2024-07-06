#include <stdio.h>

typedef struct temperatura{
    int year;
    int month;
    int day;
    int hours;
    int minutes;
    int temperatura;
} TEMP;

void print_struct(TEMP* struc, int cout)
{
    printf("%04d %02d %02d %02d %02d %02d \n",struc[cout].year,
                   struc[cout].month,
                   struc[cout].day,
                   struc[cout].hours,
                   struc[cout].minutes,
                   struc[cout].temperatura);
}

void add_data(TEMP* struc,int mass[],int cout)
{
    struc[cout].year=mass[0];
    struc[cout].month=mass[1];
    struc[cout].day=mass[2];
    struc[cout].hours=mass[3];
    struc[cout].minutes=mass[4];
    struc[cout].temperatura= mass[5];
    
}

void stat_mouth(TEMP* struc,int cout)
{
    int sred_temp=0;
    int day=0;
    for(int i=1;i<=12;i++){
        for(int j=0;j<cout;j++){
            if (struc[j].month==i){
                day++;
                sred_temp+=struc[j].temperatura;
            }
        }
        printf("Sred temp za %d mec = %d\n",i,sred_temp/day);
        sred_temp=0;
        day=0;
    }
}

 void min_temp(TEMP* struc,int cout)
 {
    int min_temp=100;
    for(int i=1;i<=12;i++){
        for(int j=0;j<cout;j++){
            if (struc[j].month==i){
                if(struc[j].temperatura<min_temp)
                    min_temp=struc[j].temperatura;
            }
        }
        printf("Min temp za %d mec = %d\n",i,min_temp);
        min_temp=100;
    }
 }

 void max_temp(TEMP* struc,int cout)
 {
    int max_temp=-100;
    for(int i=1;i<=12;i++){
        for(int j=0;j<cout;j++){
            if (struc[j].month==i){
                if(struc[j].temperatura>max_temp)
                    max_temp=struc[j].temperatura;
            }
        }
        printf("Max temp za %d mec = %d\n",i,max_temp);
        max_temp=-100;
    }
 }

 void min_temp_total(TEMP* struc,int cout)
 {
    int min_temp=100;
    for(int j=0;j<cout;j++){
        if(struc[j].temperatura<min_temp){
            min_temp=struc[j].temperatura;
        }
    }
    printf("Min temp za god  = %d\n",min_temp);
 }

void max_temp_total(TEMP* struc,int cout)
 {
    int max_temp=-100;
    for(int j=0;j<cout;j++){
        if(struc[j].temperatura>max_temp){
            max_temp=struc[j].temperatura;
        }
    }
    printf("Max temp za god  = %d\n",max_temp);
 }

void stat_year(TEMP* struc,int cout)
{
    int sred_temp=0;
    int day=0;
    
    for(int j=0;j<cout;j++){
        sred_temp+=struc[j].temperatura;
        day++;
    }
    printf("Sred temp za god  = %d\n",sred_temp/day);

}  

void stat_mouth_single(TEMP* struc,int cout,int mes)
{
    int sred_temp=0;
    int day=0;
    for(int j=0;j<cout;j++){
        if (struc[j].month==mes){
            day++;
            sred_temp+=struc[j].temperatura;
        }    
    }
    printf("Sred temp za %d mec = %d\n",mes,sred_temp/day);
}

void min_temp_single(TEMP* struc,int cout,int mes)
 {
    int min_temp=100;
    for(int j=0;j<cout;j++){
        if (struc[j].month==mes){
            if(struc[j].temperatura<min_temp)
                min_temp=struc[j].temperatura;
        }
    }
    printf("Min temp za %d mec = %d\n",mes,min_temp);
 }

void max_temp_single(TEMP* struc,int cout,int mes)
 {
    int max_temp=-100;
    for(int j=0;j<cout;j++){
        if (struc[j].month==mes){
            if(struc[j].temperatura>max_temp)
                max_temp=struc[j].temperatura;
        }
    }
    printf("Max temp za %d mec = %d\n",mes,max_temp);
 }
