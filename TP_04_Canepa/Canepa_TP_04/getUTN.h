int menu (char* item);
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);
int getLongInt(long int* input,char message[],char eMessage[], long int lowLimit, long int hiLimit);
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);
int getString(char input[],char message[],char eMessage[], int lowLimit, int hiLimit);
int getDate(long int* input,char message[]);
int getAvg(float* input1,float* input2,float* solution);

int validaS_N(void);
int validaDecision(char message[]);
