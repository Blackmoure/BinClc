#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kvad(int x, int y){
    if(y) return x * kvad(x, --y);
    return 1;
}

int main(){
    FILE *fp;
    char c[18000];
    char *x;
    const char s[2] = " ";
    char wipe = "\n";
    int num;
    int A=1, j=0, wrp=0, a=0, u;
    for(int i=0; i<120; i++) printf("+");
    printf("HOLY SCRIPT STARTING\nLOADING FILE (MAX 18K CHARS)");
    fp = fopen("BinR.txt", "r+");
    while(a<18000){
    c[a] = fgetc(fp);
    a++;
    }
    x = strtok(c, s);
    printf("\nTRANSLATED TEXT:\n\n");
    while(x){
        num=NULL;
        wrp++;
        for(int i=0; i<8; i++){
            if(x[7-i]=='1') num+=kvad(2, i);
        }
        if(wrp>=100 && num==' ' || num=='\n') { putchar('\n'); wrp=0; }
        else printf("%c", num);
        x = strtok(NULL, s);
    }
    printf("\n\n");
    fflush(stdin);
    fclose(fp);

    printf("TRANSLATING COMPLETE, CLOSING SCRIPT.\nHAVE A GOOD DAY\n");
    for(int i=0; i<120; i++) printf("+");
    return 0;
}
