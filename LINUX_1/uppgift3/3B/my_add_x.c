#include <stdio.h>
#include <stdlib.h>

int main(){
	char buf[10];
	int sum = 0;
	int num;
	while(1){
		fgets(buf, sizeof(buf), stdin);
		if(buf[0] == '\n'){
			break;
		}
		num = atoi(buf);
		sum += num; 
	}
	printf("%d", sum);
}

