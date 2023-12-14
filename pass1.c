#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
    {
    FILE f1,f2,f3,f4;
    f1=fopen("input.txt","r");
    f2=fopen("symtab.txt","w");
    f3=fopen("intermediate.txt","w");
    char la[20],mne[20],op[20],opt[20],o[20];
    int lc,sa;

    fscanf(f1,"%s%s%X",la,mne,&lc);
    if (strcmp(mne,"START")==0)
        {
        sa=lc;
        fprintf(f3,"%X\t%s\t%s\t%X\n",sa,la,mne,sa);
        fscanf(f1,"%s%s%s",la,mne,op);
        }
    else
        lc=0;
    while (strcmp(mne,"END")!=0)
        {
        fprintf(f3,"%X\t%s\t%s\t%s\n",lc,la,mne,op);
        if (strcmp(la,"-")!=0)
            {
            fprintf(f2,"%s\t%X\n",la,lc);
            }
        f4=fopen("optab.txt","r");
        while (!feof(f4))
            {
            fscanf(f4,"%s%s",opt,o);
            if (strcmp(mne,opt)==0)
                {
                lc+=3;
                break;
                }
            }
        if (strcmp(mne,"WORD")==0)
            lc+=3;
        if (strcmp(mne,"RESW")==0)
            lc+=3*atoi(op);
        if (strcmp(mne,"RESB")==0)
            lc+=atoi(op);
        if (strcmp(mne,"BYTE")==0)
            if (op[0]=='X')
                lc+=1;
            else
                lc+=strlen(op)-3;

        fclose(f4);
        fscanf(f1,"%s%s%s",la,mne,op);
        }
    int pgm;
    if (strcmp(mne,"END")==0)
        {
        fprintf(f3, "%X\t%s\t%s\t%X\n", lc, la, mne, sa);
        pgm = lc - sa; 
        }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    }   