#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
	char matricula[50];
	char nome[50];
	char curso[50];
}aluno;

void incluir(aluno *a);
void alterar(aluno *a);
void consultar(aluno *a);
void excluir(aluno *a);
void listar(aluno *a);
void finalizar(aluno *a, FILE *f);

int b=0,i=0,z=0,x[100]={99},aux,v=0;

int main(){
	int z=0,num;
	aluno *aln=NULL;
	FILE *fl;
	
    fl=fopen("Lista_alunos.txt", "r"); 
  
	if((fl=fopen("Lista_alunos.txt", "r"))== NULL){
		exit(0);
	   }
	else{
		aln=(aluno *)malloc(1*sizeof(aluno));
        
	    while(fscanf(fl,"%s %s %s",&aln[b].nome,&aln[b].matricula,&aln[b].curso) != EOF){
	    	printf("%s %s %s\n",aln[b].nome,aln[b].matricula,aln[b].curso);
	    	aln=(aluno *)realloc(aln,(b+2)*sizeof(aluno));
	    	b++;
	    	i++;
		}
	     
	}
      
   
    for(;;){
    	
    	printf("-------------CADASTRO DE ALUNOS-----------\n");
            printf("1-Para incluir aluno\n");
            printf("2-Para alterar dados\n");
            printf("3-Para consultar aluno\n");
            printf("4-Para excluir aluno\n");
            printf("5-Para listar\n");
            printf("0-  Sair\n");
            scanf("%d",&num);
          
        
		switch (num){
			case 1:
				if(z) goto a;
				if(b>=1)
				    aln=(aluno *)realloc(aln,(b+1)*sizeof(aluno));
				a:    
				incluir(aln);
				break;
			case 2:
				alterar(aln);
				break;
			case 3:
				consultar(aln);
				break;
			case 4:
				excluir(aln);
				break;
			case 5:
			    listar(aln);
				break;
			case 0:
			    finalizar(aln, fl);
			    break;
			
	            	}      
    	
	}
	
}
        
	void incluir(aluno *a){
		
			if(z){
				aux=b;
				v--;
				b=x[v];
			
			}
   		      
			printf("digite seu nome:");
			fgets(a[b].nome,50,stdin);
			a[b].nome[strcspn(a[b].nome, "\n")] = 0;
			fflush(stdin);
			printf("digite sua matricula:");
			fgets(a[b].matricula,20,stdin);
			a[b].matricula[strcspn(a[b].matricula, "\n")] = 0;
			fflush(stdin);
			printf("digite seu curso:");
			fgets(a[b].curso,50,stdin);
			a[b].curso[strcspn(a[b].curso, "\n")] = 0;
			fflush(stdin);
			b++;
			if(z){
			b=aux;
			if(v==0) z=0;
			} 
		
			
	}
   	  
	
		void alterar(aluno *a){
		 
		 int num,i;
		 char ma[20];
		 char text[20];
        
		printf("\nO que deseja alterar?\n");
		printf("1-nome\n"); 
        printf("2-curso\n");
        scanf("%i",&num);
        fflush(stdin);
        if(num==1){
        printf("Digite a matricula do aluno que deseja alterar:");
		fgets(ma,20,stdin);
		ma[strcspn(ma, "\n")] = 0;
		fflush(stdin);
		
        for(i=0;i<b;i++){
		        if (!strcmp(ma,a[i].matricula)){
		        	printf("Seu nome eh:%s\n",a[i].nome);
		        	printf("Digite o novo nome:");
		        	fgets(a[i].nome,20,stdin);
		        	a[i].nome[strcspn(a[i].nome, "\n")] = 0;
		        	fflush(stdin);
				} 
				}}
       else if(num==2) {
       	printf("Digite a matricula do aluno que deseja alterar:");
				fgets(ma,20,stdin);
				ma[strcspn(ma, "\n")] = 0;
				fflush(stdin);
				for(i=0;i<b;i++){
		        if (strcmp(ma,a[i].matricula)==0){
		        	printf("Digite o novo curso:");
		        	fgets(a[i].curso,20,stdin);
		        	a[i].curso[strcspn(a[i].curso, "\n")] = 0;
		        	fflush(stdin);
				} }
	   }
     }
     
     void consultar(aluno *a){
		
		fflush(stdin);
		char ma[20];
		printf("Digite a matricula do aluno que deseja consultar:");
		fgets(ma,20,stdin);
		ma[strcspn(ma, "\n")] = 0;
		fflush(stdin);
		for(i=0;i<b;i++){
		if (strcmp(ma,a[i].matricula)==0){
			printf("NOME:%s\n",a[i].nome);
   	    	printf("CURSO:%s\n",a[i].curso);
		}
		
	}
	}
	
	void finalizar(aluno *a, FILE *f){
		
	   fclose(f);
	   
		f=fopen("Lista_alunos.txt", "r++");
		
		for(i=0;i<=b-1;i++){
			fprintf(f,"%s %s %s\n", a[i].nome,a[i].matricula,a[i].curso);
		}
		 
		fclose(f);
		exit(0);
		
	}
	
	
	void listar(aluno *a){
   	
   	for(i=0;i<b;i++){
   		    
   		    if(!strcmp("",a[i].matricula))
                continue;
			   
   	    	printf("NOME:%s\n",a[i].nome);
   	    	printf("CURSO:%s\n",a[i].curso);
   	    	printf("MATRICULA:%s\n",a[i].matricula);
   	    	printf("----------------------------\n");
	   }
   	
   
   	
   } 
	
	
	
	
	

