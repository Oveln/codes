#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 20

char operators[] = "+-*^";

char generate_random_operator() {
    return operators[rand() % 4];
}

int generate_random_number() {
    return rand() % 900+100;
}

void generate_expression(int length,bool canp) {
    if (length <= 3) {
        printf("%d", generate_random_number());
        return;
    }

    char c = generate_random_operator();
    while (canp && c=='^') c = generate_random_operator();
    bool flg = 0;
    bool isp = c == '^'; 
    
    if (c == '+' || c == '-') length-=2,flg = 1;
    
    int left_length = length<3 ? 1 : rand() % (length-2) + 2;
    int right_length = length - 1 - left_length;
    
    if (isp) right_length = 3 ,left_length = length -1 - right_length; 

    if (flg) printf("(");
    generate_expression(left_length,isp);
    printf("%c", c);
    if (isp) printf("%d", (rand()%1000)*(rand()%1000)*(rand()%1000)); else generate_expression(right_length,isp);
//    if (isp) printf("%d", (rand()%10)); else generate_expression(right_length,isp);
    if (flg) printf(")");
}

int main() {
    srand(time(0));
    printf("100 56677\n");
    for (int i=1;i<=100;i++) {
    	generate_expression(MAX_LENGTH,0);
    	printf("\n");
	}
    return 0;
}

