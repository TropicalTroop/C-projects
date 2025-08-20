/* Encryption Project Draft 2 */

// Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to auto-find dimensions for matrix
void dimensions(int *, int *, int *, int *, char *, char *);

// Function to turn character strings into matrices
void smatrix(int , int , char (*)[], char *);

// One function to print matrices
void pmatrix(int, int, void *, int);

// Function to convert character array to number array
void numconv(int, int, char (*)[], int (*)[]);

// Function to multiply matrices
void matrixmult(int p, int q, int n, int m, int (*)[], int (*)[], int (*)[]);

// Function to find conditional dimensions
void cDimensions(int *, int *, char *);

//Function that takes in string input and turns it into a character and number array
int main(){
	// Introduce user to program, take string input
			char messageinput[1000];
			printf("\nWelcome to Encryptor!\n\nPlease enter a message below:\n");
			fgets(messageinput,999,stdin);
			messageinput[strcspn(messageinput, "\n")] = '\0';

			printf("\nPlease enter the desired Transformation word:\n");
			char EncryptInput[1000];
			fgets(EncryptInput,999,stdin);
			EncryptInput[strcspn(EncryptInput, "\n")] = '\0';
			int m = 0, n=0;

			//Asking user for pre-determined matrix or auto-gen
			int p, q;
			printf("\nCustom matrix (0) or auto-generate matrix (1)?\n");
			int check = 1;
			//	scanf("%d", &check);
			if(check == 0){
				printf("\n\nEnter n: ");
				scanf("%d", &p);
				printf("\n\nEnter m: ");
				scanf("%d", &q);
			}
			else if(check==1){
				dimensions(&p, &q,&n,&m, messageinput, EncryptInput);
			}
			else{
				printf("ERROR");
			}

			printf("\nYou are using a %d x %d matrix.\n", p, q);

			// Initalize character matrix
			char message[p][q];
			memset(message, '\0', sizeof(message));
			smatrix(p, q, message, messageinput);
			int type = 0;
			pmatrix(p, q, message, type);

			//Convert to number matrix
			type = 1;
			int numarray[p][q];
			memset(numarray, 0, sizeof(numarray));
			numconv(p, q, message, numarray);
			printf("\nNumber matrix:\n");
			pmatrix(p, q, numarray, type);

			char TempEncrypt[n][m];
			memset(TempEncrypt, '\0', sizeof(TempEncrypt));
			smatrix(n, m, TempEncrypt, EncryptInput);

			//Convert to number matrix
			type = 1;
			int Transformer[n][m];
			memset(Transformer, 0, sizeof(Transformer));
			numconv(n, m, TempEncrypt, Transformer);
			printf("\n\nHere is your Encryption matrix:\n");
			pmatrix(n, m, Transformer, type);

			printf("\n\n\n\nHere is the resultant encrypted matrix:\n");
			int EncryptedArray[p][m];
			matrixmult(p, q, n, m, numarray, Transformer, EncryptedArray);
			type=1;
			pmatrix(p, m, EncryptedArray, type);

			


}

// Dimension maker
void dimensions(int *p, int *q, int *s, int *t, char *string, char *str2){
	int length = strlen(string)+1;
	int length2 = strlen(str2)+1;
    int n=2; int m =2;

    while (n * m < length2) {
        if (n <= m) {
            n++;
        } else {
            m++;
        }
    }
    *s=n; *t=m;

    int k=2, c=m;
    while (k * c < length) {
            k++;
    }

    *p = k; *q =c;}

// Converts string to char matrix
void smatrix(int n, int m, char message[][m], char *inputstring){
	int index = 0;
	if(message[n-1][0]==0 && n!=m){
					n--;
				}	
	for (int i = 0; i<n && inputstring[index]!='\0'; i++){
		for(int j = 0; j<m && inputstring[index]!='\0'; j++){
				message[i][j] = inputstring[index];
				index++;
		}
	}	}

// Prints character matrix
void pmatrix(int n, int m, void *matrix, int printType){

	if (printType==0){
		char(*message)[m]=(char(*)[m])matrix;
		if(message[n-1][0]==0 && n!=m){
					n--;
				}	
		for (int i = 0; i<n;i++){
			for(int j=0;j<m;j++){
				printf("%c ", message[i][j]);
		}
		printf("\n");
	}
}

	else if(printType==1){
		int(*message)[m]=(int (*)[m])matrix;
		if(message[n-1][0]==0 && n!=m){
					n--;
				}	
		for (int i = 0; i<n;i++){
			for(int j=0;j<m;j++){
				printf("%d ", message[i][j]);
		}
		printf("\n");
	}
}}

void numconv(int n, int m, char message[][m], int numarray[][m]){
	
	for (int i = 0; i<n;i++){
		for (int j = 0; j<m; j++){
			if(message[i][j]>= 'A' && message[i][j]<= 'Z' ){
				numarray[i][j] = message[i][j]-64;
			}
			else if(message[i][j]==' '){
				numarray[i][j] = 0;
			}
		}
	}
}



void matrixmult(int p, int q, int n, int m, int m1[][q], int m2[][m], int m3[][m]){
	for (int i = 0; i<p;i++){
		for (int j = 0; j<m;j++){
			//m3[i][j] = sum;
			// Summation for that
			int sum = 0;

			for (int k=0; k<q; k++){
					sum+=(m1[i][k]*m2[k][j]);
				
			}
			m3[i][j]=sum;
		}
	}
}

void cDimensions(int *p, int *q, char *string){
	int length = strlen(string)+1;
    int n=2, m =2;

    while (n * m < length) {
            n++;
    }
    *p = n; *q =m;
}
