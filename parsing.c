#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "parsing.h" 

int labCheck(char lab[][55],char inlabel[]){
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




int convNum(char temp[]){
	int i,num,j;
	j=1;
	num=0;
	for(i=strlen(temp)-1;i>=0;i--,j*=10)
		num +=j*(temp[i]-48);
		
	return num;
}
int checkComma(char oprin[])
{
	int i,status=1;
	if((!oprin[0]>=48 && oprin[0]<=57))
	{
		printf("Invalid Register No.\n");
		status=0;
		exit;
	}
	for(i=1;i<strlen(oprin);i++)
	{
		if(!(oprin[i]==32))
		{
			printf("Invalid Register No.\n");
			status=0;
			exit;
		}
	}
	return status;
}


void checkCharacter(char inst[]) //remove special character
{
	int i;
	for(i=0;inst[i]!='\0';i++){
		if(!((inst[i]>=97 && inst[i]<=122) || (inst[i]>=65 && inst[i]<=90) ||(inst[i]>=48 && inst[i]<=57) || inst[i]==32 || inst[i]==44 || inst[i]==':'))
		{
			printf("%s Invalid Instruction\n",inst);
			return ;
		}
	}
}
int noOfRegisters(int count,char tempoprin[])
{
			char temp[35];
			int i,status=1,j;
				
				for(i=0;i<strlen(tempoprin);i++)
				{
					while(tempoprin[i]==' ')
					i++;
					if(tempoprin[i]==82 || tempoprin[i]==70)
					count--;
					else
					{
						printf("Invalid registers\n");
						return 0 ;
					}
					j=0;
					i++;
					while(tempoprin[i]!=',' && count!=0)
					{
						temp[j++]=tempoprin[i];
						i++;
					}
					temp[j]='\0';
					while(tempoprin[i]!='\0' && count==0)
					{
						temp[j++]=tempoprin[i];
						i++;
					}
										temp[j]='\0';
					//printf("%s\n",temp);
					checkComma(temp);
					
				}
				if(count!=0)
				{
					printf("Invalid No. of registers\n");
					return 0;
				}
			
	return status;
}
int noOfRegistersI(int count,char tempoprin[])
{

			char temp[35];
			char imm[105];
			int i,status=1,j,data,flag;
				
				for(i=0;i<strlen(tempoprin);i++)
				{
					while(tempoprin[i]==' ')
					i++;
					if(tempoprin[i]==82 || tempoprin[i]==70)
					count--;
					else
					{
						printf("Invalid registers\n");
						return 0 ;
					}
					j=0;
					i++;
					while(tempoprin[i]!=',')
					{
						temp[j++]=tempoprin[i];
						i++;
					}
					temp[j]='\0';
					if(count>0)
					status=checkComma(temp);
					while(tempoprin[i]!='\0' && count==0)
					{
						flag=1;
						if(tempoprin[i]>=48 && tempoprin[i]<=57)
						imm[j++]=tempoprin[i];
						else
							flag=0;
						i++;
					}
					imm[j]='\0';
					if(count==0){
						if(flag)
						data=convNum(imm)%65535;
						else{
							printf("Invalid Data\n");
							return 0;
						}
						
					}
				}
				if(count!=0)
				{
					printf("Invalid No. of registers\n");
					return 0;
				}
			
	return status;
}
int checkOpcode(char inst[],char lab[][55])
{
	FILE *instruct;
	char tempinuser[105],tempop[105],instin[105],tempinst[105],tempoprin[105],temp,count; 
	int i=0,j,status=1,flag=0,x,k,linecounter;
	char *ptr = strchr(inst,':');
			//if the instruction is without lable  or call
			//printf("%s\n",inst);
			if(ptr==NULL)
			{
				
				flag=0;
				for(i=0;inst[i]!=' ' && inst[i]!='\n';i++)
				{
					tempinuser[i]=inst[i];      //tempiuser[] is array for the first part of instruction  i.e. "add"
				}
				tempinuser[i]='\0';
				
			}
			else
			{
				flag=0;
				i=(int)(ptr-inst) + 1;
				while(inst[i]==' ')
					i++;
				x=i; //here value of i  is stored to use it extract the operend;
				k=0;
				for(;inst[i]!=' ';i++)
				{
					tempinuser[k++] = inst[i];      //tempiuser[] is array for the first part of instruction  i.e. "add"
				}
				tempinuser[k]='\0';
				
			}
				instruct = fopen("inst.txt","r");
	
				flag=0;
				
				
			
				char c;
				while(flag==0 && (c=fgetc(instruct))!=EOF)
				{
					
					i=0;
					if(i==0 && c==' ')
					continue;
					if(c!='\0' && c!='\n'){
						instin[i++]=c;
						while((c=fgetc(instruct))!='\n' && c!='\0'){
						instin[i++] =c;
						}
						instin[i]='\0';
						
						//here instin[] contains the  opcode list defined by the isa designer
						for(i=0;instin[i]!=' ' && instin[i]!='\n';i++){
							tempinst[i] = instin[i];
						}
						tempinst[i]='\0';
						
						j=0;

					//	printf("%s %d %d\n",tempinst,strlen(tempinst),strlen(tempinuser));
						//here tempinst is the first part of instruction (i.e. "add") from instruction list defined by the isa designer
						if(strcmp(tempinst,tempinuser)==0)// tempinuser contains add sub etc
						{
														

							
							flag=1;
							int counter;
							counter =0;
							for(i=i+1;instin[i]!='\0';i++){
								tempop[j++]=instin[i];	//tempop contains the corresponding opcode from instruction file operands 01001010 etc
							}
							//printf("%c\n",instin[i-1]);
							tempop[j]='\0';
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
									for(;inst[i]!='\n';i++){
										tempoprin[j++]= inst[i]; //tempoprin contains r1,r2,r3
									}
									tempoprin[j] = '\0';
								//printf("%s\n",tempoprin);
								//printf("%d\n",strlen(tempop));
									temp=(32-strlen(tempop))/16;
									count=((32-strlen(tempop))%16)/4;
									if(temp==1){
										if(tempinuser[0]!='J' && tempinuser[0]!='C')
										status=noOfRegistersI(count,tempoprin);
										else{
											status =labCheck(lab,tempoprin);
											if(status==-1){
												printf("Invalid Label\n");
												return 0;
											}
											
										}
									}
									else
									status=noOfRegisters(count,tempoprin);
									
						}
					}			
				} 
		
	fclose(instruct);

	return status;
}		




int parse(char inst[],char lab[][55]){
	
			int status;
			status =1;
			checkCharacter(inst);
			status=checkOpcode(inst,lab);
			printf("%d\n",status);
			return status;
	
}

/*								

int main()
{
	FILE *input;
	char inst[105],tempinst[105];
	
	char c;
	int i,status=1,counter;
	counter=0;
	input    = fopen("code.txt","r");
	while((c=fgetc(input))!=EOF)
	{
	
		i=0;
		if(i==0 && c==' ')
		continue;
		if(c!='\0' && c!='\n'){
				counter++;
			inst[i++]=c;
			while((c=fgetc(input))!='\n' && c!='\0'){
				inst[i++] =c;
			}
			inst[i]='\0';
		
			for(i=0;inst[i];i++){
				if(inst[i]>=97 && inst[i]<=122)
					inst[i] = toupper(inst[i]);
			}
		
			
			checkCharacter(inst);
			printf("%d . %s\n",counter,inst);
			status=checkOpcode(inst);
			
			
			printf("%d\n",status);
		}
	}
	fclose(input);
	return 0;
}
*/

