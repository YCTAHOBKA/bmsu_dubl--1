#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int a=0, b=0, buff_num=0, dv=0;
    char arr[10][10], c;
     for(int i=0;i<10;i++){
            for(int f=0;f<10;f++){
                arr[i][f]=0;
            }
        }
    printf("Ââåäèòå äåñÿòè÷íûå ÷èñëà:\n");
    while((c=getchar()) != EOF){
          if(c!='\n'){
            arr[a][b]=c;
            b++;
          } else{
                arr[a][b]=0;
                a++;
                b=0;
          }
    }
    printf("Äåñÿòè÷íûå ÷èñëà\n");
        for(int i=0;i<a;i++){
                        printf("%s",arr[i]);
            printf("\n");
        }
        printf("Äâîè÷íûå ÷èñëà\n");
        int f=0;
        for(int i=0;i<a; i++){
            while(arr[i][f]!=0){
                if(arr[i][f] != ' '){
                    buff_num *= 10;
                    buff_num += arr[i][f]-'0';
                    } else {
                        int cl=0,temp=0; char ost[10]={0};
                         while(buff_num!=0){
                            ost[cl] = buff_num%2 + '0';
                            cl++;
                            buff_num = buff_num/2;
                        }
                            for(int i=0; i<cl/2; i++){
                                temp = ost[i];
                                ost[i] = ost[cl-i-1];
                                ost[cl-i-1] = temp;
                                }
                                printf("%s ", ost);
                        }
                f++;
            }
                int cl=0,temp=0; char ost[10]={0};
                    while(buff_num!=0){
                            ost[cl] = buff_num%2 + '0';
                            cl++;
                            buff_num = buff_num/2;
                        }
                    for(int i=0; i<cl/2; i++){
                                temp = ost[i];
                                ost[i] = ost[cl-i-1];
                                ost[cl-i-1] = temp;
                                }
                                printf("%s ", ost);
                f=0;
                printf("\n");
        }
        printf("\nEND");
    return 0;
}
