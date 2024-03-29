#include <stdio.h>
#include <ctype.h>

#define SIZE 50 /* Size of Stack */

char s[SIZE];
int top = -1; /* Global declarations */

void push(char elem) {
    s[++top] = elem;
}

char pop() {
    return (s[top--]);
}

int pr(char elem) {
    switch (elem) {
        case '#':
            return 0;
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
        case '%':
            return 3;
        case '^':
            return 4;
    }
}

void main(){
    char infx[50],pofx[50],ch;
    int i=0,k=0;

    printf("Enter infix exp:");
    scanf("%s",infx);
    push('#');

    while((ch=infx[i++])!='\0'){
        if(ch=='('){
            push(ch);
        }
        else if(isalpha(ch)){
            pofx[k++]=ch;
        }
        else if(ch==')'){
            while(s[top]!='('){
                pofx[k++]=pop();
            }
            pop();
        }
        else{
            while(pr(s[top])>=pr(ch)){
                pofx[k++]=pop();
            }
            push(ch);
        }
    }
    while(s[top]!='#'){
        pofx[k++]=pop();
    }
    pofx[k]='\0';
    printf("Postfix exp:%s",pofx);
}