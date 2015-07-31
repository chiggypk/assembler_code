#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "parsing.h"

int convNum(char temp[]){
	int i,num,j;
	j=1;
	num=0;
	for(i=strlen(temp)-1;i>=0;i--,j*=10)
		num +=j*(temp[i]-48);
		
	return num;
}


void getbin(int num,char temp[]){
	int c,k,j;
	j=0;
	for (c = 3; c >= 0; c--)
  {
   	k = num >> c;
 
    if (k & 1)
      temp[j++]='1';
    else
      temp[j++]='0';
  }
  temp[j]='\0';
}


void oprconvert3add(char oprout[], char oprin[]){
	int i,j,k,num,x,num1,num2,num3,flag1,flag2,flag3;
	char temp1[105],temp2[105],temp3[105];
	j=0;
	k=0;
	x=1;
	flag1=flag2=flag3=0;
	for(i=0;i<strlen(oprin);i++){
		if((oprin[i]=='R' ||oprin[i]=='F') && x==1){
			j=0;
			if(oprin[i]=='F')
			flag1=1;
			i++;
			while(oprin[i]!=' ' && oprin[i]!=','){
				temp1[j++]=oprin[i];
				i++;
			}
			temp1[j]='\0';
			x++;
		}
		if((oprin[i]=='R' || oprin[i]=='F') && x==2){
			j=0;
			if(oprin[i]=='F')
			flag2=1;
			i++;
			while(oprin[i]!=' ' && oprin[i]!=','){
				temp2[j++]=oprin[i];
				i++;
			}
			temp2[j]='\0';
			x++;
		}
		if((oprin[i]=='R' || oprin[i]=='F') && x==3){
			j=0;
			if(oprin[i]=='F')
			flag3=1;
			i++;
			while(oprin[i]){
				temp3[j++]=oprin[i];
				

				i++;
			}
			temp3[j]='\0';

			x++;
		}	
	}
	

	num1=convNum(temp1);
	num2=convNum(temp2);
	num3=convNum(temp3);
	if(flag1)
	num1 +=10;
	if(flag2)
	num2 +=10;
	if(flag3)
	num3 +=10;
	getbin(num1,temp1);
	getbin(num2,temp2);
	getbin(num3,temp3);


	for(k=0;temp1[k];){
		oprout[k++]= temp1[k];
	}
	for(i=0;temp2[i];i++){
		oprout[k++]= temp2[i];
	}
	for(i=0;temp3[i];i++){
		oprout[k++]= temp3[i];
	}
	oprout[k] = '\0';
}

void oprconvert2add(char oprout[], char oprin[]){
	int i,j,k,num,x,num1,num2,flag1,flag2;
	char temp1[105],temp2[105];
	j=0;
	k=0;
	x=1;
	flag1=flag2=0;
	for(i=0;i<strlen(oprin);i++){
		if((oprin[i]=='R' || oprin[i]=='F') && x==1){
			j=0;
			if(oprin[i]=='F')
			flag1=1;
			i++;
			while(oprin[i]!=' ' && oprin[i]!=','){
				temp1[j++]=oprin[i];
				i++;
			}
			temp1[j]='\0';
			x++;
		}
	
		if((oprin[i]=='R' || oprin[i]=='F')&& x==2){
			j=0;
			i++;
			if(oprin[i]=='F')
			flag2=1;
			while(oprin[i]!=' ' && oprin[i]!=',' && oprin[i]){
				temp2[j++]=oprin[i];
				i++;
			}
			temp2[j]='\0';

			x++;
		}	
	}
	num1=convNum(temp1);
	num2=convNum(temp2);
	if(flag1)
	num1 +=10;
	if(flag2)
	num2 +=10;
	
	getbin(num1,temp1);
	getbin(num2,temp2);
	for(k=0;temp1[k];){
		oprout[k++]= temp1[k];
	}
	for(i=0;temp2[i];i++){
		oprout[k++]= temp2[i];
	}
	
	oprout[k] = '\0';
}


void oprconvert1add(char oprout[], char oprin[]){
	int i,j,k,num1;
	char temp1[105];
	j=0;
	k=0;
	for(i=0;i<strlen(oprin);i++){
		
		if(oprin[i]=='R'){
			j=0;
			i++;
			while(oprin[i]!=' ' && oprin[i]!=',' && oprin[i]){
				temp1[j++]=oprin[i];
				i++;
			}
			temp1[j]='\0';
		}	
	}
	num1=convNum(temp1);
	getbin(num1,temp1);
	for(k=0;temp1[k];){
		oprout[k++]= temp1[k];
	}
	
	oprout[k] = '\0';
}

	
void getAddress(int num,char temp[]){
		int c,k,j;
	j=0;
	for (c = 15; c >= 0; c--)
  {
   	k = num >> c;
    if (k & 1)
      temp[j++]='1';
    else
      temp[j++]='0';
  }

  temp[j]='\0';
}



int labSearch(char lab[][55],char inlabel[]){
	int i,flag;
	flag=0;
	for(i=0;lab[i][0]!='\0';i++){
		//printf("%s %s %d\n",lab[i],inlabel,i);
			if(strcmp(lab[i],inlabel)==0){
				
				flag=1;
				break;
			}
	}
	if(flag)
		return i;
	else
	return -1;
}




void jumpCall(char oprout[], char oprin[],char lab[][55],int labadd[],char tempoprin[]){
	int i,adr;
	char temp[17];
	
	if(tempoprin[0]=='J' || tempoprin[0]=='C'){
			adr=labSearch(lab,oprin);
	}
	else{
		adr=convNum(oprin);
	}
	
	getAddress(adr,temp);
	strcpy(oprout,temp);

}



void oprconvimmid8(char oprout[], char oprin[]){
		int i,j,k,num,x,num1,num2,num3;
	char temp1[105],temp2[105],temp3[105];
	j=0;
	k=0;
	x=1;

	for(i=0;i<strlen(oprin);i++){
		if(oprin[i]=='R' && x==1){
			j=0;
			i++;
			while(oprin[i]!=' ' && oprin[i]!=','){
				temp1[j++]=oprin[i];
				i++;
			}
			temp1[j]='\0';
			x++;
		}
		if(oprin[i]=='R' && x==2){
			j=0;
			i++;
			while(oprin[i]!=' ' && oprin[i]!=','){
				temp2[j++]=oprin[i];
				i++;
			}
			temp2[j]='\0';
			x++;
		}
		if(oprin[i]>=48 && oprin[i]<=57 && x==3){
			j=0;
			while(oprin[i]){
				temp3[j++]=oprin[i];
				

				i++;
			}
			temp3[j]='\0';

			x++;
		}	
	}
	

	num1=convNum(temp1);
	num2=convNum(temp2);
	num3=convNum(temp3);

	getbin(num1,temp1);
	getbin(num2,temp2);
	getAddress(num3,temp3);


	for(k=0;temp1[k];){
		oprout[k++]= temp1[k];
	}
	for(i=0;temp2[i];i++){
		oprout[k++]= temp2[i];
	}
	for(i=0;temp3[i];i++){
		oprout[k++]= temp3[i];
	}
	oprout[k] = '\0';
}

void oprconvimmid12(char oprout[], char oprin[]){
		int i,j,k,num,x,num1,num2;
	char temp1[105],temp2[105];
	j=0;
	k=0;
	x=1;
	for(i=0;i<strlen(oprin);i++){
		if(oprin[i]=='R' && x==1){
			j=0;
			i++;
			while(oprin[i]!=' ' && oprin[i]!=','){
				temp1[j++]=oprin[i];
				i++;
			}
			temp1[j]='\0';
			x++;
		}
	
		if(oprin[i]>=48 && oprin[i]<=57 && x==2){
			j=0;
			while(oprin[i]!=' ' && oprin[i]!=',' && oprin[i]){
				temp2[j++]=oprin[i];
				i++;
			}
			temp2[j]='\0';

			x++;
		}	
	}
	num1=convNum(temp1);
	num2=convNum(temp2);
	getbin(num1,temp1);
	getAddress(num2,temp2);
	for(k=0;temp1[k];){
		oprout[k++]= temp1[k];
	}
	for(i=0;temp2[i];i++){
		oprout[k++]= temp2[i];
	}
	
	oprout[k] = '\0';	
}

int main(){
	
	FILE *input, *instruct,*output,*check,*check2;
	
	int i,j,labcounter,address,flag,outcounter,k,x;
	char inst[105],tempinst[55],tempinuser[55];
	char c;
	char lab[105][55];
	int  labadd[105];
	char instin[105];
	char opcode[105][35],tempop[35]; 
	char tempopr[105],tempoprin[105];
	address =labcounter= 0;
	input    = fopen("code.txt","r");
	instruct = fopen("inst.txt","r");
	output  = fopen("out.txt","w");
	int counter;
	counter=0;
	i=0;
		int linecounter;
		linecounter=0;
		check2=fopen("rt1.txt","w");
	while((c=fgetc(input))!=EOF){
		i=0;
		
		if(i==0 && c==' ' )
		continue;
		
		if(c!='\0' && c!='\n'){
			inst[i++]=c;
			while((c=fgetc(input))!='\n'  && c !='\0'){
				inst[i++]=c;
			}
			inst[i]='\0';
			fprintf(check2,"%d.  %s\n",linecounter++,inst);
			for(i=0;inst[i]!='\0';i++){
					if(inst[i]>=97 && inst[i]<=122)
						inst[i]=toupper(inst[i]);
			}
			
			 char *ptr = strchr(inst,':');
			
			if((ptr - inst)<0 ){
				if(address==65536 ){
					printf(" Memory exceeded  !!!!!\n");
					return 0;
				}
				
				address += 4; 
			}
			else{
				if(address==65536 ){
					printf(" Memory exceeded  !!!!!\n");
					return 0;
				}
					
				address +=4;
				labadd[labcounter]=address;
				char templab[55];
				for(i=0;inst[i]!=' ' && inst[i]!=':' ;i++){
					templab[i] = inst[i]; 
				}
				templab[i]='\0';
			//	printf("%d\n",labSearch(lab,templab));
				if(labSearch(lab,templab)!=-1){
					printf("Label \" %s \" already present at line  %d  \n",templab,labadd[labSearch(lab,templab)]/4);
					return 0;		
				}
				else{
					strcpy(lab[labcounter],templab);
					labcounter++; 
				}
				
			}	
		}
	}
	fclose(input);
	int status;
	status =1;
	//status=	parse(inst,lab);
		input    = fopen("code.txt","r");
		outcounter=0;
		
		//here inst contains the instruction of user 2nd go 
	
		check = fopen("rt.txt","w");
		
		
		while((c=fgetc(input))!=EOF){
			i=0;
			if(i==0 && c==' ' )
			continue;
			if(c!='\0' && c!='\n' ){
				
				linecounter++;
					inst[i++]=c;
					while((c=fgetc(input))!='\n'  && c !='\0'){
						inst[i++]=c;
					}
					inst[i]='\0';
						
				
			//conversion of instruction into uppercase
			
				for(i=0;inst[i]!='\0';i++){
					if(inst[i]>=97 && inst[i]<=122)
						inst[i]=toupper(inst[i]);
				}
				char *ptr = strchr(inst,':');
				//if the instruction is without lable  or call
				
				if(ptr-inst <0){
					flag=0;
				
					for(i=0;inst[i]!=' ' && inst[i]!='\0';i++){
						tempinuser[i] = inst[i];      //tempiuser[] is array for the first part of instruction  i.e. "add"
					
					}
					tempinuser[i]='\0';
				}
				else{
						flag=0;
						i=(int)(ptr-inst) + 1;
						while(inst[i]==' ')
						i++;
						x=i; //here value of i  is stored to use it extract the operend;
						k=0;
						for(;inst[i]!=' ';i++){
							tempinuser[k++] = inst[i];      //tempiuser[] is array for the first part of instruction  i.e. "add"
						}
						tempinuser[k]='\0';
				
				}
					
				instruct = fopen("inst.txt","r");
				int counter;
				counter=0;
				flag=0;
				char cc;
				
				
				while(flag==0 && (cc=fgetc(instruct))!=EOF){
					i=0;
					
					if(cc!='\0' && cc!='\n'){
						instin[i++]=cc;
						while((cc=fgetc(instruct))!='\n'  && cc !='\0'){
							instin[i++]=cc;
						}
						instin[i]='\0';
						
						//here instin[] contains the  opcode list defined by the isa designer
						for(i=0;instin[i]!=' ' &&instin[i]!='\0';i++){
							tempinst[i] = instin[i];
						}
						tempinst[i]='\0';
						j=0;
					
						//	printf("%s %d %d\n",tempinst,strlen(tempinst),strlen(tempinuser));
						//here tempinst is the first part of instruction (i.e. "add") from instruction list defined by the isa designer
						if(strcmp(tempinst,tempinuser)==0){
						
							flag=1;
							int counter;
							counter =0;
							for(i=i+1;instin[i]!='\0';i++){
								tempop[j++]=instin[i];	//tempop contains the corresponding opcode from instruction file
							}
							
							//printf("%c\n",instin[i-1]);
							tempop[j]='\0';
						
							if(strlen(tempop)!=32){
									printf("%s\n",inst);
								//if the instruction is not immidiate type
								//if(tempinuser[strlen(tempinuser)-1]!='I'){
										if(ptr!=NULL)
											i=strlen(tempinuser)+ x  ;
										else
											i=strlen(tempinuser);
										while(inst[i]==' ')
											i++;
										j=0;
										for(;inst[i]!='\0';i++){
											tempoprin[j++]= inst[i];
										}
										tempoprin[j] = '\0';
									
									//printf("%d\n",strlen(tempop));
									
									if(strlen(tempop)==20){
										oprconvert3add(tempopr,tempoprin);
									
									}
									else if(strlen(tempop)==24){
										oprconvert2add(tempopr,tempoprin);
									}
									else if(strlen(tempop)==16){
									
										jumpCall(tempopr,tempoprin,lab,labadd,tempinst);
								
									}
									else if(strlen(tempop)==28){
										oprconvert1add(tempopr,tempoprin);
									}
									else if(strlen(tempop)==8){
										oprconvimmid8(tempopr,tempoprin);
									}
									else if(strlen(tempop)==12){
										
										oprconvimmid12(tempopr,tempoprin);
										

									}
									k=0;
							
							

							
								
								if(strlen(tempop)!=32){
									strcpy(opcode[outcounter],tempop);
								
									strcat(opcode[outcounter],tempopr);
									//printf("%s\n",opcode[outcounter]);
									fprintf(check,"%d.  %s\n%s\n",outcounter,inst,opcode[outcounter]);
									outcounter++;
								}
								
							
							}
							else{
									//printf("%s\n",tempinst);
									strcpy(opcode[outcounter],tempop);
									//printf("%s\n",opcode[outcounter]);
									fprintf(check,"%d.  %s\n%s\n",outcounter,inst,opcode[outcounter]);
									outcounter++;
							}
						//}
						
						}
									
					} 
						
				}
						
									fclose(instruct);

				
			}
		
		}
		for(i=0;i<outcounter;i++){
			fputs(opcode[i],output);
			fprintf(output,"\n");
		}
		fclose(input);
		fclose(instruct);
		fclose(output);
		fclose (check);
		fclose (check2);
		return 0;
	
}
