typedef struct temperatura{
    int year;
    int month;
    int day;
    int hours;
    int minutes;
    int temperatura;
} TEMP;
extern void print_struct(TEMP*, int);
extern void add_data(TEMP*,int mass[],int);
extern void stat_mouth(TEMP*,int);
extern void min_temp(TEMP*,int);
extern void max_temp(TEMP* struc,int cout);
extern void min_temp_total(TEMP* struc,int cout);
extern void max_temp_total(TEMP* struc,int cout);
extern void stat_year(TEMP* struc,int cout);
extern void stat_mouth_single(TEMP* struc,int cout,int mes);
extern void min_temp_single(TEMP* struc,int cout,int mes);
extern void max_temp_single(TEMP* struc,int cout,int mes);