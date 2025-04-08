#include<stdio.h>
#include<string.h>
#define MAX 256

void buildShiftTable(char pattern[], int shift[]){
    int m = strlen(pattern);

    for(int i=0; i<MAX; i++){
        shift[i] = m;
    }

    for(int i=0; i<m -1; i++){
        shift[(unsigned char)pattern[i]] = m - 1 -i;
    }
}

int horspoolSearch(char text[], char pattern[]){
    int shift[MAX];
    int n = strlen(text);
    int m = strlen(pattern);

    buildShiftTable(pattern, shift);

    int i = m-1;

    while(i<n){
        int k=0;
        while(k<m && pattern[m-1-k] == text[i-k]){
            k++;
        }

        if(k==m){
            return i-m+1;
        }
        i+= shift[(unsigned char)text[i]];
    }
    return -1;
}
int main(){
    char text[100], pattern[100];

    printf("Enter the text");
    scanf("%s", text);

    printf("Enter the pattern");
    scanf("%s", pattern);

    int pos = horspoolSearch(text, pattern);

    if(pos>=0){
        printf("Pattern found at position %d\n", pos);
    }else{
        printf("Pattern not found");
    }
    return 0;
}