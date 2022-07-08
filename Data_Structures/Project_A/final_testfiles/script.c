#include <stdio.h>
#include <stdlib.h>
int main() {

FILE *fptr;
char c[50];
fptr = fopen("P10_T21.txt","r");

FILE *fwrite;
fwrite = fopen("Pcommand","a");
	if(fwrite==NULL) {
printf("lathos fwrite\n");
exit(-1);
}

if(fptr==NULL) {
printf("error\n");
exit(-1);
}
while (fgets(c, sizeof(c), fptr)){
	if(c[0]=='P') {

        fprintf(fwrite,"%s",c);
}
}
fclose(fwrite);
fclose(fptr);

}
