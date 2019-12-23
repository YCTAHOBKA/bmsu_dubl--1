#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#define TYPE_DATA int

char *getarray(void){
    int n=1;
    char *arr,c;
    arr = calloc(n+1, sizeof(char));

    int i = 0;
    while((c=getchar()) != ';'){
        if( ('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')){ //[a-zA-Z0-9]
            char *temp_arr;
            temp_arr = calloc(n+1, sizeof(char));

            for(int j = 0; j < n; j++){
                temp_arr[j] = arr[j];
            }
            temp_arr[n-1] = c;
            n++;
            i++;
            free(arr);
            arr = temp_arr;
        }
        else if(c == '\n'){
            arr[n]='\0';
            return arr;
        }
    }
    arr[n-1]='\0';
    return arr;
}

void newtop(int n, int arr[n][n], char *name[n]){
    int max=-1, counter[n];
    for(int i=0; i<n; i++){
        counter[i] = 0;
    }
    for (int a=0; a<n; a++){
        for(int b=0; b<n; b++){
            counter[a] += arr[a][b];
            counter[a] += arr[b][a];
        }
        if(max <= counter[a]){
            max = counter[a];
        }
    }

    printf("\nMax: %d", max);
    printf("\nTop of the graph: ");
    for(int i=0; i<n; i++)
        if(counter[i] == max)
            printf("%s ", name[i]);
}


int main(){
    int graph;
    printf("1 - graph\n2 - digraph\n# ");
    scanf("%d", &graph);

    if(!( graph == 1 || graph == 2 ))
        exit(9);

    printf("Amount: ");
    int n;
    scanf("%d",&n);
    if (n <= 0)
        exit(9);

    char *name[n];
    int conn[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            conn[i][j] = 0;
        }
    }

    printf("Enter names:\n");
    getchar();

    for(int i=0; i<n; i++){
        printf("# ");
        name[i] = getarray();

        for (int j=0; j<i; j++){
            if( strcmp(name[i], name[j]) == 0){
                printf("There are similar elements, enter another...\n");
                i--;
            }
        }
    }

    printf("Enter connection\n");
    for(int i=0; i<n; i++){
        printf("%d# ",i);
        _Bool flag=1;
        while(flag){
            char *compare;
            compare = getarray();

            for(int j=0; j<n; j++){
                if( strcmp(compare, name[j]) == 0){
                    conn[i][j]++;
                }
            }

            if(strcmp(compare, "") == 0){
                flag = 0;
            }
            free(compare);
        }
    }

    printf("\n");
    _Bool relat_graph = 1;
    for(int i=0; i<n; i++){
        _Bool temp_relat_graph = 0;
        for(int j=0; j<n; j++){
            if(conn[i][j] == 1)
                temp_relat_graph = 1;

            if(conn[j][i] == 1)
                temp_relat_graph = 1;
        }
        if(temp_relat_graph == 0)
            relat_graph=0;
    }
    if(relat_graph == 0){
        printf("unrelated\n");
    } else {
        printf("related\n");

    }
    printf("Connection table\n");
    for(int i=0; i<n; i++) {
        printf("%s\t", name[i]);
        for (int j=0; j<n; j++) {
            printf("%d ", conn[i][j]);
        }
        printf("\n");
    }

    newtop(n,conn, name);// функция нахождения вершин

    FILE *file=fopen("graph.dot", "w");
    if(file == NULL) {
        printf("Unable to create file\n");
        exit(0);
    }

    char arr[3] = "";
    if(graph == 2){
        fputs("digraph G {", file);
        strcat(arr, "->");
    } else {
        fputs("graph G {", file);
        strcat(arr, "--");
    }

    for(int i=0; i<n; i++){
        fputs(name[i], file);
        fputs("; ", file);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<conn[i][j]; k++){
                fputs(name[i], file);
                fputs(arr, file);
                fputs(name[j], file);
                fputs("; ", file);
            }
        }
    }
    fputs("}", file);

    return 0;
}

