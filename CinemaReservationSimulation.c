#include <stdio.h>
#include <stdlib.h>
void menu();//menu episode
void login();//Signup and Signin is 
void costsShow();//Revenue record is showed here
void costsRecord();//Revenue record is recorded here
void info();//Matinee info is has here 

void reservationMake();/*Customer makes reservation in here*/

enum cost{student=20,full=30}cost;
enum color{Red,Blue,Green};
int r1=0,r2=0,r3=0,r4=0,r5=0;
int b1=0,b2=0,b3=0,b4=0,b5=0;
int g1=0,g2=0,g3=0,g4=0,g5=0;


struct salon{
	char matine[5][50];

    
}customer[3];

struct {
	char userName[50];
	char password[50];
}Users[100];

int *checkNullR;//for red
int *checkNullB;//for blue
int *checkNullG;//for green
int loginSayac=0;
int totalCost=0;
FILE *fp3;
int j=0,i=0,k=0;//red=j, blue=i, green=k



int main(void) {


login();


return 0;
}



void login(){
	system("cls");
	int result;
	int signSayac;
	FILE *fp2;
	Menu:
	printf("\n\t****ACCOUNT****\n\t1)Login\n\t2)Signup\n\t3)Exit\n");
	scanf("%d",&result);
	system("cls");
	if(result==1){
		for(loginSayac;loginSayac<100;loginSayac++){
	
			printf("USERNAME:");
			scanf("%s",Users[loginSayac].userName);
			printf("PASSWORD (dont use number):");
			scanf("%s",Users[loginSayac].password);
			
			fp2=fopen("sifre.txt","a+");
			fprintf(fp2,"%s \t%s\n",Users[loginSayac].userName,Users[loginSayac].password);
			
			fclose(fp2);
			printf("LOGIN SUCCESSFUL\n");
			loginSayac++;
			
		goto Menu;
			
		}
   	}
   	else if(result==2){
   		char loginPersonName[20];
   		char loginPersonPassword[20];
   		printf("USERNAME:");
   		scanf("%s",loginPersonName);
   		
		printf("\nPASSWORD:");
   		scanf("%s",loginPersonPassword);
	    fp2=fopen("sifre.txt","r");

		while(!feof(fp2)){
            
            for(signSayac=0;signSayac<100;signSayac++){
			fscanf(fp2,"%s %s  ",Users[signSayac].userName,Users[signSayac].password);
			if(strcmp(Users[signSayac].userName,loginPersonName)==0 && strcmp(Users[signSayac].password,loginPersonPassword)==0)
			{
				printf("\n\tSUCCESSFUL ENTRY\n");
				menu();
			}
            }
	
			
			printf("\n\tUSER NOT FOUND\n");
			goto Menu;
			
		}
   	
		fclose(fp2);

	}
	else if(result==3){	
   		printf("\n EXIT");
   		exit(1);
	   }
	
}

void menu(){
	system("cls");
	int value;
	printf("\n\t1)RESERVATION\n\t2)REVENUE\n\t3)INFORMATION\n\t4)LOGIN\n\t4)EXIT\n\n");
	scanf("%d",&value);
	if(value==1){
		reservationMake();
	}
	else if(value==2){
		costsShow();
	}
	else if(value==3){
		info();
	}
	else if(value==4){
		login();
	}
	else if(value==5){
		exit(1);
	}
}

void reservationMake(){
    system("cls");
    
	int result,rmatinee,bmatinee,gmatinee;
    
    printf("\n\t*****HALL******\n\t1)Red\n\t2)Blue\n\t3)Green\n");
    scanf("%d",&result);
    system("cls");
        if(result==1){
            
            printf("\n\t*****MATINEE******\n\t1)Matrix 4\n\t2)TOP GUN-2\n\t3)The Eternals \n\t4.Godzilla vs.Kong\n\t5)Suicide Squad 2\n");
            scanf("%d",&rmatinee);
            for(j;j<50;j++){
                checkNullR=customer[Red].matine[rmatinee][j];
                
                if(checkNullR==NULL){
                    
					if(rmatinee==1){
						r1++;
						checkNullR=r1;
						printf("Seat number:%d",checkNullR);	
					}
					else if(rmatinee==2){
						r2++;
						checkNullR=r2;
						printf("Seat number:%d",checkNullR);
					}
					else if(rmatinee==3){
						r3++;
						checkNullR=r3;
						printf("Seat number:%d",checkNullR);
					}
					else if(rmatinee==4){
						r4++;
						checkNullR=r4;
						printf("Seat number:%d",checkNullR);

					}
					else if(rmatinee==5){
						r5++;
						checkNullR=r5;
						printf("Seat number:%d",checkNullR);						
					}
					
					j++;
					break;               
                }
	        }
           	costsRecord();
   	 	}
    	else if(result==2){
    		printf("\n\t*****MATINEE******\n\t1)Guardian\n\t2)Terminator 5 \n\t3)Fall in love\n\t4)No Man of GOD \n\t5)Fast and Farious 9\n");
            scanf("%d",&bmatinee);
            for(i;i<50;i++){
                checkNullB=customer[Blue].matine[bmatinee][i];
                
                if(checkNullB==NULL){
                    
					if(bmatinee==1){
						b1++;
						checkNullR=b1;
						printf("Seat number:%d",checkNullR);							
					}
					else if(bmatinee==2){
						b2++;
						checkNullR=b2;
						printf("Seat number:%d",checkNullR);						
					}
					else if(bmatinee==3){
						b3++;
						checkNullR=b3;
						printf("Seat number:%d",checkNullR);						
					}
					else if(bmatinee==4){
						b4++;
						checkNullR=b4;
						printf("Seat number:%d",checkNullR);					
					}
					else if(bmatinee==5){
						b5++;
						checkNullR=b5;
						printf("Seat number:%d",checkNullR);						
					}
					i++;
					break;
                


         	}
         	
    	 }
    	 costsRecord();
    }
     	else if(result==3){
     		printf("\n\t*****MATINEE******\n\t1)Avatar 2\n\t2)Uncharted\n\t3)Black Widow\n\t4)Jungle Cruise\n\t5)Bond 25 (No Time No Die)\n");
            scanf("%d",&gmatinee);
            for(k;k<50;k++){
                checkNullG=customer[Green].matine[gmatinee][k];
                
                if(checkNullG==NULL){
                	
					if(gmatinee==1){
						g1++;
						checkNullG=g1;
						printf("Seat number:%d",checkNullG);
							
					}
					else if(gmatinee==2){
						g2++;
						checkNullG=g2;
						printf("Seat number:%d",checkNullG);
					}
					else if(gmatinee==3){
						g3++;
						checkNullG=g3;
						printf("Seat number:%d",checkNullG);						
					}
					else if(gmatinee==4){
						g4++;
						checkNullG=g4;
						printf("Seat number:%d",checkNullG);						
					}
					else if(gmatinee==5){
						g5++;
						checkNullG=g5;
						printf("Seat number:%d",checkNullG);						
					}
					k++;
					break;
            
			}	
          }costsRecord();
      }
        else{
			printf("incorrect entry");
			
			reservationMake();
		}
}


void costsRecord(){
	int cash;

	printf("\n\tWhich ticket Do you take?\n\t1)Full\n\t2)Student\n\t3)MENU\n");
	scanf("%d",&cash);
	
	
	if(cash==1){
		totalCost+=full;
		
	}
	else if(cash==2){
		totalCost+=student;
	}
	else if(cash==3){
		menu();
	}
	
	menu();
}

void costsShow(){
	int value;
	fp3=fopen("payment.txt","w+");
	fprintf(fp3,"%d\n",totalCost);
	
	fscanf(fp3,"%d",totalCost);
	fclose(fp3);

	printf("totalCost:%d\n",totalCost);
	printf("\nclick '2' For menu ");
	scanf("%d",&value);
	if(value==2){
		menu();
	}
}
void info(){
	
	int value;
	int result;
	FILE *fp4;
	fp4=fopen("log.txt","w+");
	fprintf(fp4,"RED:%d\n1)Matrix 4:%d\n2)TOP GUN-2:%d \n3)The Eternals:%d\n4)Godzilla vs.Kong:%d\n5)Suicide Squad 2:%d\n\n\n",j,r1,r2,r3,r4,r5);
	fprintf(fp4,"BLUE:%d\n1)Guardian:%d\n2)Terminator 5:%d\n3)Fall in love :%d\n4)No Man of GOD:%d\n5)Fast and Farious 9:%d\n\n",i,b1,b2,b3,b4,b5);
	fprintf(fp4,"GREEN:%d\t\n1)Avatar 2:%d\n2)Uncharted:%d\n3)Black Widow:%d\n4)Jungle Cruise:%d\n5)Bond 25 (No Time No Die):%d\n\n",k,g1,g2,g3,g4,g5);
	
		
	fclose(fp4);
	back:
	system("cls");
	printf("\n\t*****HALL******\n\t1)Red\n\t2)Blue\n\t3)Green\n\t4)Menu\n");
	scanf("%d",&result);
	if(result==1){
		printf("\tRED:%d\n\t1)Matrix 4: %d\n\t2)TOP GUN-2: %d \n\t3)The Eternals: %d\n\t4)Godzilla vs.Kong: %d\n\t5)Suicide Squad 2: %d\n",j,r1,r2,r3,r4,r5);
	}
	else if(result==2){
		printf("t\tBLUE: %d\n\t1)Guardian: %d\n\t2)Terminator 5: %d\n\t3)Fall in love: %d\n\t4)No Man of GOD: %d\n\t5)Fast and Farious 9: %d\n",i,b1,b2,b3,b4,b5);
	}
	else if(result==3){
		printf("\tGREEN: %d\n\t1)Avatar 2: %d\n\t2)Uncharted: %d\n\t3)Black Widow: %d\n\t4)Jungle Cruise: %d\n\t5)Bond 25 (No Time No Die): %d\n",k,g1,g2,g3,g4,g5);
	}
	else if(result==4){
		menu();
	}
	printf("\nclick '2' For back ");
	scanf("%d",&value);
	if(value==2){
		goto back;
	}

}

