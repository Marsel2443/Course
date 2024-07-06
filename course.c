#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "temp_h.h"


TEMP statistic[518400]={0};

int main(int argc,char* argv[])
{
    char* filename="";
    int res=0;
    char* month="";
    int m;
    while((res=getopt(argc,argv,"hf:m:"))!=-1)
    {
        switch (res)
        {
            case 'h': printf("argumet -m = month\nargument -f = filename");
            break;
            case 'm':
                month=optarg;
            break;
            case 'f':
                filename=optarg;
            break;
        }      
    }
    if(month){
        m = atoi(month);
    }
    TEMP* ptr=statistic;
    int mass[6]={0};
    char buffer[3];
    int cout=0;
    unsigned length = 0;
    FILE* fp =fopen(filename,"r");
    if(fp == NULL){
        perror(filename);
        return 1;
    }
    char ch;
    int i=0;
    while (!feof(fp)){
        while(length<5){
            fscanf(fp,"%d;",&mass[length]);
            length++;
            }
        while((ch=fgetc(fp)) != EOF){
            if (ch == '\n'){
                break;
            }
            if (ch==' '){
                continue;
            }
            buffer[i++]=ch;
        }
        if(buffer[0] !='-'){
            if (i==2){
            mass[5]=(buffer[0]-48)*10+buffer[1]-48;
            }
            else{
                mass[5]=buffer[0]-48;
            }
        }
        if (buffer[0] == '-'){
             if (i==3){
            mass[5]=-((buffer[1]-48)*10+buffer[2]-48);
            }
            else{
                mass[5]=-(buffer[1]-48);
            }
        } 
        if(mass[5]>99 || mass[5]<-99){
            printf("Error temp. year %d,month%d,day%d,hours%d,minutes%d\n",mass[0],mass[1],mass[2],mass[3],mass[4]);
            cout++;
            length=0;
            i=0;
            continue;
        }
        add_data(ptr, mass, cout);
 //       print_struct(statistic,cout);
        cout++;
        length=0;
        i=0;
    }        
    fclose(fp);
    if(m==0){
        stat_mouth(ptr,cout);
        min_temp(ptr,cout);
        max_temp(ptr,cout);
        min_temp_total(ptr,cout);
        max_temp_total(ptr,cout);
        stat_year(ptr,cout);
    }
    else{
        stat_mouth_single(ptr,cout,m);
        min_temp_single(ptr,cout,m);
        max_temp_single(ptr,cout,m);
    }

    return 0;
}
