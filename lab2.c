#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>


/*
Función: Lee el archivo que contiene las lineas de control, con la respectiva falla stuck-at-1.
Entrada: Esta funcion no tiene entrada
Salida:La funcion retorna un arreglo de caracteres que contienes los valores "x", en el caso que la linea de control funcione normalmente y, 
"1" en el caso que ocurra una falla stuck-at-1.
*/
char* leerarchivodecontrol(){
	char *valoresLineasControl;
	char *vector;
	vector= (char*)malloc(256*sizeof(char*));
	valoresLineasControl= (char*)malloc(56*sizeof(char*));
	int w=0,c=0,i;
	char aux1;
	char nombre[50];
    printf ("Introduzca nombre del archivo de lineas de control (sin txt): ");
    scanf("%s", &nombre); 
	FILE *archivo;
   strcat(nombre,".txt");  
   archivo=fopen(nombre,"r");
	if(archivo==NULL){
	printf("No se abrio el archivo\n");}
	while(aux1 != EOF){
		aux1 = fgetc(archivo);
		if(aux1=='x'){
		vector[w]=aux1;	
		valoresLineasControl[c]='x';
		c++;
		w++;}
		else if(aux1=='1'){
		vector[w]=aux1;
		valoresLineasControl[c]='1';
		c++;
		w++;}}	
    fclose(archivo);
	return valoresLineasControl;}

/*
Función: Lee el archivo que contiene las las instrucciones a ejecutar.
Entrada: Esta funcion no tiene entrada
Salida:La funcion retorna un arreglo de cadenas de caracteres que contienes los valores de las instrucciones, y los registros donde se
guardarán dichas instrucciones. 
*/

char* leerarchivoinstrucciones()
{   char *vector2;
	vector2= (char*)malloc(256*sizeof(char*));
	int z=0,i;
	int guardado;
	char aux1;
	char nombre[50];
    printf ("Introduzca nombre del archivo de instrucciones (sin txt): ");
    scanf("%s", &nombre); 
	FILE *archivo2;
   strcat(nombre,".txt");  
   archivo2=fopen(nombre,"r");
	if(archivo2==NULL){
		printf("No se abrio el archivo\n");}	
	while(aux1 != EOF){
		aux1 = fgetc(archivo2);
		if(aux1!=','&& aux1!='('&&aux1!=')'){
			vector2[z]=aux1;
			z++;}}	
    fclose(archivo2);
	return vector2;
}

/*
Función: Busca el registro que se le solicita, y retorna el contenido que hay en el.
Entrada: Esta funcion tiene como entrada un arreglo de enteros que contiene el valor de los registros y una cadena que contiene el registro que se busca.
Salida:La funcion retorna el valor que contiene el registro que se busca.
*/
int obtenerregistro(int* registro, char* reg){
	if(strcmp(reg,"$zero")== 0){return registro[0];}
	else if(strcmp(reg,"$at")== 0){return registro[1];}
	else if(strcmp(reg,"$v0")== 0){return registro[2];}
	else if(strcmp(reg,"$v1")== 0){return registro[3];}
	else if(strcmp(reg,"$a0")== 0){return registro[4];}
	else if(strcmp(reg,"$a1")== 0){return registro[5];}
	else if(strcmp(reg,"$a2")== 0){return registro[6];}
	else if(strcmp(reg,"$a3")== 0){return registro[7];}
	else if(strcmp(reg,"$t0")== 0){return registro[8];}
	else if(strcmp(reg,"$t1")== 0){return registro[9];}
	else if(strcmp(reg,"$t2")== 0){return registro[10];}
	else if(strcmp(reg,"$t3")== 0){return registro[11];}
	else if(strcmp(reg,"$t4")== 0){return registro[12];}
	else if(strcmp(reg,"$t5")== 0){return registro[13];}
	else if(strcmp(reg,"$t6")== 0){return registro[14];}
	else if(strcmp(reg,"$t7")== 0){return registro[15];}
	else if(strcmp(reg,"$s0")== 0){return registro[16];}
	else if(strcmp(reg,"$s1")== 0){return registro[17];}
	else if(strcmp(reg,"$s2")== 0){return registro[18];}
	else if(strcmp(reg,"$s3")== 0){return registro[19];}
	else if(strcmp(reg,"$s4")== 0){return registro[20];}
	else if(strcmp(reg,"$s5")== 0){return registro[21];}
	else if(strcmp(reg,"$s6")== 0){return registro[22];}
	else if(strcmp(reg,"$s7")== 0){return registro[23];}
	else if(strcmp(reg,"$t8")== 0){return registro[24];}
	else if(strcmp(reg,"$t9")== 0){return registro[25];}
	else if(strcmp(reg,"$k0")== 0){return registro[26];}
	else if(strcmp(reg,"$k1")== 0){return registro[27];}
	else if(strcmp(reg,"$gp")== 0){return registro[28];}
	else if(strcmp(reg,"$sp")== 0){return registro[29];}
	else if(strcmp(reg,"$fp")== 0){return registro[30];}
	else if(strcmp(reg,"$ra")== 0){return registro[31];}	
}

/*
Función: Cambia el valor del registro que se solicita.
Entrada: Esta funcion tiene como entrada un arreglo de enteros que contiene el valor de los registros, una cadena que contiene el registro que se busca
y el nuevo valor del registro.
Salida:La funcion no retorna nada.
*/
void cambiarregistro(int* registro, char* reg,int newvalor){
	if(strcmp(reg,"$zero")== 0){ registro[0]  = newvalor; }
	else if(strcmp(reg,"$at")== 0){ registro[1]  = newvalor; }
	else if(strcmp(reg,"$v0")== 0){ registro[2]  = newvalor; }
	else if(strcmp(reg,"$v1")== 0){ registro[3]  = newvalor; }
	else if(strcmp(reg,"$a0")== 0){ registro[4]  = newvalor; }
	else if(strcmp(reg,"$a1")== 0){ registro[5]  = newvalor; }
	else if(strcmp(reg,"$a2")== 0){ registro[6]  = newvalor; }
	else if(strcmp(reg,"$a3")== 0){ registro[7]  = newvalor; }
	else if(strcmp(reg,"$t0")== 0){ registro[8]  = newvalor; }
	else if(strcmp(reg,"$t1")== 0){ registro[9]  = newvalor; }
	else if(strcmp(reg,"$t2")== 0){ registro[10] = newvalor; }
	else if(strcmp(reg,"$t3")== 0){ registro[11] = newvalor; }
	else if(strcmp(reg,"$t4")== 0){ registro[12] = newvalor; }
	else if(strcmp(reg,"$t5")== 0){ registro[13] = newvalor; }
	else if(strcmp(reg,"$t6")== 0){ registro[14] = newvalor; }
	else if(strcmp(reg,"$t7")== 0){ registro[15] = newvalor; }
	else if(strcmp(reg,"$s0")== 0){ registro[16] = newvalor; }
	else if(strcmp(reg,"$s1")== 0){ registro[17] = newvalor; }
	else if(strcmp(reg,"$s2")== 0){ registro[18] = newvalor; }
	else if(strcmp(reg,"$s3")== 0){ registro[19] = newvalor; }
	else if(strcmp(reg,"$s4")== 0){ registro[20] = newvalor; }
	else if(strcmp(reg,"$s5")== 0){ registro[21] = newvalor; }
	else if(strcmp(reg,"$s6")== 0){ registro[22] = newvalor; }
	else if(strcmp(reg,"$s7")== 0){ registro[23] = newvalor; }
	else if(strcmp(reg,"$t8")== 0){ registro[24] = newvalor; }
	else if(strcmp(reg,"$t9")== 0){ registro[25] = newvalor; }
	else if(strcmp(reg,"$k0")== 0){ registro[26] = newvalor; }
	else if(strcmp(reg,"$k1")== 0){ registro[27] = newvalor; }
	else if(strcmp(reg,"$gp")== 0){ registro[28] = newvalor; }
	else if(strcmp(reg,"$sp")== 0){ registro[29] = newvalor; }
	else if(strcmp(reg,"$fp")== 0){ registro[30] = newvalor; }
	else if(strcmp(reg,"$ra")== 0){ registro[31] = newvalor; }}

/*
Función: Realiza una instruccion tipo R aritmetica.
Entrada: Esta funcion tiene como entrada un arreglo de enteros que contiene el valor de los registros, la instruccion y los respectivos registros.
Salida:La funcion no retorna nada.
*/
void tipoRaritmetica(int* registros,char* instruccion,char* rd,char* rs,char* rt){
	int res, a1,a2, a3;
	if(strcmp(instruccion,"add")== 0){		
		a1=obtenerregistro(registros, rs);
		a2=obtenerregistro(registros, rt);
		res= a1 +a2;
		cambiarregistro(registros, rd,res);	
	}
	else if(strcmp(instruccion,"sub")== 0){
		a1=obtenerregistro(registros, rs);
		a2=obtenerregistro(registros, rt);
		a3=obtenerregistro(registros, rd);
		res= a1 -a2;
	cambiarregistro(registros, rd,res);}
	else if(strcmp(instruccion,"or")== 0){
		a1=obtenerregistro(registros, rs);
		a2=obtenerregistro(registros, rt);
		res= a1 ^ a2;
	cambiarregistro(registros, rd,res);}
	else if(strcmp(instruccion,"and")== 0){
		a1=obtenerregistro(registros, rs);
		a2=obtenerregistro(registros, rt);
		res= a1 & a2;
	cambiarregistro(registros, rd,res);}
	else if(strcmp(instruccion,"slt")== 0){
		a1=obtenerregistro(registros, rs);
		a2=obtenerregistro(registros, rt);
		if(a1<a2){
			cambiarregistro(registros, rd,1);}
		else{
			cambiarregistro(registros, rd,0);}}}

/*
Función: Realiza una instruccion tipo I, donde ve si los valores de registros son iguales, para poder ver si realizar un salto o no.
Entrada: Esta funcion tiene como entrada un arreglo de enteros que contiene el valor de los registros, la instruccion, una etiqueta y los respectivos registros.
Salida:La funcion retorna un "1" si los volores de registros son iguales, y retorna una "0", si los valores son distintos.
*/
int tipoIBranch(int* registros,char* etiqueta,char* rs,char* rt)
{	int i,a1,a2,directors,direstort;
    a1=obtenerregistro(registros, rs);
	a2=obtenerregistro(registros, rt);
	directors=atoi(rs);
	direstort=atoi(rt);
    
	if(a1 == a2){
		i=1;
		return i;}
	else if(a1==direstort){
		i=1;
		return i;}
    else if(a2==directors){
		i=1;
		return i;}		
		else{
			i=0;
		return i;}}	

/*
Función: Realiza una instruccion tipo I aritmetica.
Entrada: Esta funcion tiene como entrada un arreglo de enteros que contiene el valor de los registros, la instruccion y los respectivos registros.
Salida:La funcion no retorna nada.
*/		
void tipoIaritmetico(int* registros,char* instruccion,char* rs,char* rt,char*inmediate){
	int res, a1,a2;
	
	if(strcmp(instruccion,"addi")== 0){
		a1=atoi(inmediate);
		a2=obtenerregistro(registros, rt);
		res= a1 + a2;
		cambiarregistro(registros, rs,res);
		//return registros;
		
	}
		
	else if(strcmp(instruccion,"subi")== 0){
		a1=atoi(inmediate);
		a2=obtenerregistro(registros, rt);
		res= a2 - a1;
		cambiarregistro(registros, rs,res);
		//return registros;
		
	}
}
	
	

/*
Función: Realiza una instruccion tipo R Loadword y storeword.
Entrada: Esta funcion tiene como entrada un arreglo de memoria uqe guarda la palabra de la instruccion,un arreglo de enteros que contiene el valor de los registros, la instruccion y los respectivos registros.
Salida:La funcion no retorna nada.
*/
void tipoRlwsw(int* memoria,int* registros,char* instruccion, char* registro1, char* argumento5, char* registro2){ 
	int posicionFinal = 0; 
	int i,j, a1,a2; 
	j= atoi(argumento5);
	
			a1=obtenerregistro(registros, registro1);
			a2=obtenerregistro(registros, registro2);
			posicionFinal = a2 + (j/4); 
	if(strcmp(instruccion, "lw") == 0){
		
		a1= memoria[posicionFinal];
        cambiarregistro(registros,registro1,a1);		
	}else if(strcmp(instruccion, "sw") == 0){

		memoria[posicionFinal] =  a1; 
	} 
	return; 
}


/*
Función: A partir de las instrucciones y lineas de control recibidas, hace llamado de funciones segun indiquen las instrucciones, para asi escribir en un archibo los valores respectivos de las lineas de control y registros segun cada instrucción.
Entrada: Esta funcion tiene como entrada un arreglo de caracteres con las el valor de las lineas de control y un arreglo de caracteres con las instrucciones a ejecutrar con sus respectivos registros. 
Salida:La funcion no retorna nada.
*/
void ejecuta(char* lineacontrol,char* instrucciones){   
   char nombre[50];
   printf ("Introduzca nombre del archivo de salida (sin txt): ");
   scanf("%s", &nombre); 
	FILE *archivo;
	strcat(nombre,".txt");  
   archivo=fopen(nombre,"a");
    if(archivo==NULL){
		printf("No se abrio el archivo\n");
	}	
	
    fprintf(archivo,"\nInstruccion           RegDst   Jump   Branch   MemRead   MemtoReg    ALUOp   MemWrite   ALUSrc   RegWrite   $zero  $at  $v0  $v1  $a0  $a1  $a2  $a3  $t0  $t1  $t2  $t3  $t4  $t5  $t6  $t7  $s0  $s1  $s2  $s3  $s4  $s5  $s6  $s7  $t8  $t9  $k0  $k1  $gp  $sp  $fp  $ra  ");
	int posicionstuck;
	int i=0, j=0, k=0, z=0;
	int resultadobeq;
	int valoresRegistros[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int actuallineacontrol[9]={0,0,0,0,0,0,0,0,0};
	char *arreglo[50];
	char* dato;
	char* etiqueta;
	dato = (char*) malloc(20);
	int memory[1056];
	fprintf(archivo,"\n");
	while(lineacontrol[z]!='1'&&z<=9){
		z++;}
		posicionstuck=z;
		char *token = strtok(instrucciones, " ");
        if(token != NULL){
			while(token != NULL){
            dato =token;
			arreglo[i] = dato;
	
            token = strtok(NULL, " \n");
			i++;}
		}
	fprintf(archivo,"\n");
	while( j<i ){	
		if(strcmp(arreglo[j],"add")== 0 || strcmp(arreglo[j],"sub")== 0 || strcmp(arreglo[j],"and")== 0|| strcmp(arreglo[j],"or")== 0||strcmp(arreglo[j],"slt")== 0){			
			if(lineacontrol[7]=='x'){
			fprintf(archivo,"%s %s, %s, %s     ",arreglo[j],arreglo[j+1],arreglo[j+2],arreglo[j+3]);	
			tipoRaritmetica(valoresRegistros,arreglo[j],arreglo[j+1],arreglo[j+2],arreglo[j+3]);
			actuallineacontrol[0]=1;
			actuallineacontrol[1]=0;
			actuallineacontrol[2]=0;
			actuallineacontrol[3]=0;
			actuallineacontrol[4]=0;
			actuallineacontrol[5]=1;
			actuallineacontrol[6]=0;
			actuallineacontrol[7]=0;
			actuallineacontrol[8]=1;
			if(posicionstuck<=9){ actuallineacontrol[posicionstuck]=1; } 
			for (k=0;k<9;k++){		
		fprintf(archivo,"    %d    ",actuallineacontrol[k]);}	
		fprintf(archivo,"      ");
			for (i=0;i<32;i++){		
		fprintf(archivo,"  %d  ",valoresRegistros[i]);}
			j= j+3;}
			else{
				actuallineacontrol[0]=1;
			actuallineacontrol[1]=0;
			actuallineacontrol[2]=0;
			actuallineacontrol[3]=0;
			actuallineacontrol[4]=0;
			actuallineacontrol[5]=1;
			actuallineacontrol[6]=0;
			actuallineacontrol[7]=0;
			actuallineacontrol[8]=1;
			if(posicionstuck<=9){ actuallineacontrol[posicionstuck]=1; } 
			actuallineacontrol[posicionstuck]=1;
			for (k=0;k<9;k++){		
		fprintf(archivo,"    %d    ",actuallineacontrol[k]);}	
		fprintf(archivo,"      ");
					for (i=0;i<32;i++){		
		fprintf(archivo,"  %d  ",valoresRegistros[i]);}
			j= j+3;}
		}
			
		
		
		else if(strcmp(arreglo[j],"addi")== 0 || (arreglo[j],"subi")== 0){	
            fprintf(archivo,"%s %s, %s, %s    ",arreglo[j],arreglo[j+1],arreglo[j+2],arreglo[j+3]);		
			if(lineacontrol[0]=='x'){
			tipoIaritmetico(valoresRegistros,arreglo[j],arreglo[j+1],arreglo[j+2],arreglo[j+3]);
			actuallineacontrol[0]=0;
			actuallineacontrol[1]=0;
			actuallineacontrol[2]=0;
			actuallineacontrol[3]=0;
			actuallineacontrol[4]=0;
			actuallineacontrol[5]=0;
			actuallineacontrol[6]=0;
			actuallineacontrol[7]=1;
			actuallineacontrol[8]=1;
			if(posicionstuck<=9){ actuallineacontrol[posicionstuck]=1; } 
			for (k=0;k<9;k++){		
		    fprintf(archivo,"    %d    ",actuallineacontrol[k]);}
			fprintf(archivo,"      ");
			for (i=0;i<32;i++){		
		    fprintf(archivo,"  %d  ",valoresRegistros[i]);}	
			j= j+3;
			}
			else{
			actuallineacontrol[0]=0;
			actuallineacontrol[1]=0;
			actuallineacontrol[2]=0;
			actuallineacontrol[3]=0;
			actuallineacontrol[4]=0;
			actuallineacontrol[5]=0;
			actuallineacontrol[6]=0;
			actuallineacontrol[7]=1;
			actuallineacontrol[8]=1;
			if(posicionstuck<=9){ actuallineacontrol[posicionstuck]=1; } 
			for (k=0;k<9;k++){		
		    fprintf(archivo,"    %d    ",actuallineacontrol[k]);}
			fprintf(archivo,"      ");
			for (i=0;i<32;i++){		
		    fprintf(archivo,"  %d  ",valoresRegistros[i]);}	
			j= j+3;
			}	
		}
		
		else if(strcmp(arreglo[j],"lw")== 0  ){
			
		    fprintf(archivo,"%s %s, %s(%s)    ",arreglo[j],arreglo[j+1],arreglo[j+2],arreglo[j+3]);
			if(lineacontrol[0]=='x'){
			tipoRlwsw(memory,valoresRegistros,arreglo[j], arreglo[j+1], arreglo[j+2], arreglo[j+3]);
            actuallineacontrol[0]=0;
			actuallineacontrol[1]=0;
			actuallineacontrol[2]=0;
			actuallineacontrol[3]=1;
			actuallineacontrol[4]=1;
			actuallineacontrol[5]=0;
			actuallineacontrol[6]=0;
			actuallineacontrol[7]=1;
			actuallineacontrol[8]=1;
			if(posicionstuck<=9){ actuallineacontrol[posicionstuck]=1; } 
			for (k=0;k<9;k++){		
		    fprintf(archivo,"    %d    ",actuallineacontrol[k]);}
			fprintf(archivo,"      ");
			for (i=0;i<32;i++){		
		    fprintf(archivo,"  %d  ",valoresRegistros[i]);}	
            j= j+3;			
			}
			else{
			actuallineacontrol[0]=0;
			actuallineacontrol[1]=0;
			actuallineacontrol[2]=0;
			actuallineacontrol[3]=1;
			actuallineacontrol[4]=1;
			actuallineacontrol[5]=0;
			actuallineacontrol[6]=0;
			actuallineacontrol[7]=1;
			actuallineacontrol[8]=1;
			if(posicionstuck<=9){ actuallineacontrol[posicionstuck]=1; } 
			for (k=0;k<9;k++){		
		    fprintf(archivo,"    %d    ",actuallineacontrol[k]);}
			fprintf(archivo,"      ");
			for (i=0;i<32;i++){		
		    fprintf(archivo,"  %d  ",valoresRegistros[i]);}	
            j= j+3;		
			}
		
		}
		
		else if(strcmp(arreglo[j],"sw")== 0 ){
			fprintf(archivo,"%s %s, %s(%s)    ",arreglo[j],arreglo[j+1],arreglo[j+2],arreglo[j+3]);
			if(lineacontrol[0]=='x'&&lineacontrol[8]=='x'){
			tipoRlwsw(memory,valoresRegistros,arreglo[j], arreglo[j+1], arreglo[j+2], arreglo[j+3]);
			actuallineacontrol[0]=0;
			actuallineacontrol[1]=0;
			actuallineacontrol[2]=0;
			actuallineacontrol[3]=0;
			actuallineacontrol[4]=0;
			actuallineacontrol[5]=0;
			actuallineacontrol[6]=1;
			actuallineacontrol[7]=1;
			actuallineacontrol[8]=0;
			if(posicionstuck<=9){ actuallineacontrol[posicionstuck]=1; } 
			for (k=0;k<9;k++){		
		    fprintf(archivo,"    %d    ",actuallineacontrol[k]);}
			fprintf(archivo,"      ");
			for (i=0;i<32;i++){		
		    fprintf(archivo,"  %d  ",valoresRegistros[i]);}	
            j= j+3;	
			}
			else{
			actuallineacontrol[0]=0;
			actuallineacontrol[1]=0;
			actuallineacontrol[2]=0;
			actuallineacontrol[3]=0;
			actuallineacontrol[4]=0;
			actuallineacontrol[5]=0;
			actuallineacontrol[6]=1;
			actuallineacontrol[7]=1;
			actuallineacontrol[8]=0;
			if(posicionstuck<=9){ actuallineacontrol[posicionstuck]=1; } 
			for (k=0;k<9;k++){		
		    fprintf(archivo,"    %d    ",actuallineacontrol[k]);}
			fprintf(archivo,"      ");
			for (i=0;i<32;i++){		
		    fprintf(archivo,"  %d  ",valoresRegistros[i]);}	
            j= j+3;		
			}	
		}
		
		
		else if(strcmp(arreglo[j],"beq")== 0){
			fprintf(archivo,"%s %s, %s, %s   ",arreglo[j],arreglo[j+1],arreglo[j+2],arreglo[j+3]);
			if(lineacontrol[0]=='x'&&lineacontrol[7]=='x'&&lineacontrol[8]=='x'){
			resultadobeq= tipoIBranch(valoresRegistros,arreglo[j+3],arreglo[j+1],arreglo[j+2]);	
			if(resultadobeq==1){
			etiqueta = arreglo[j+3];
			actuallineacontrol[0]=0;
			actuallineacontrol[1]=0;
			actuallineacontrol[2]=1;
			actuallineacontrol[3]=0;
			actuallineacontrol[4]=0;
			actuallineacontrol[5]=0;
			actuallineacontrol[6]=0;
			actuallineacontrol[7]=0;
			actuallineacontrol[8]=0;
			if(posicionstuck<=9){ actuallineacontrol[posicionstuck]=1; } 
			for (k=0;k<9;k++){		
		    fprintf(archivo,"    %d    ",actuallineacontrol[k]);}
			fprintf(archivo,"      ");
			for (i=0;i<32;i++){		
		    fprintf(archivo,"  %d  ",valoresRegistros[i]);}
				while(strcmp(arreglo[j],etiqueta)!=0){
					j++;
				}
				j++;
				
			}
			else{
			actuallineacontrol[0]=0;
			actuallineacontrol[1]=0;
			actuallineacontrol[2]=1;
			actuallineacontrol[3]=0;
			actuallineacontrol[4]=0;
			actuallineacontrol[5]=0;
			actuallineacontrol[6]=0;
			actuallineacontrol[7]=0;
			actuallineacontrol[8]=0;
			if(posicionstuck<=9){ actuallineacontrol[posicionstuck]=1; } 
			for (k=0;k<9;k++){		
		    fprintf(archivo,"    %d    ",actuallineacontrol[k]);}
			fprintf(archivo,"      ");
			for (i=0;i<32;i++){		
		    fprintf(archivo,"  %d  ",valoresRegistros[i]);}
			j=j+3;}
			}
			else{
			actuallineacontrol[0]=0;
			actuallineacontrol[1]=0;
			actuallineacontrol[2]=1;
			actuallineacontrol[3]=0;
			actuallineacontrol[4]=0;
			actuallineacontrol[5]=0;
			actuallineacontrol[6]=0;
			actuallineacontrol[7]=0;
			actuallineacontrol[8]=0;
			if(posicionstuck<=9){ actuallineacontrol[posicionstuck]=1; } 
			for (k=0;k<9;k++){		
		    fprintf(archivo,"    %d    ",actuallineacontrol[k]);}
			fprintf(archivo,"      ");
			for (i=0;i<32;i++){		
		    fprintf(archivo,"  %d  ",valoresRegistros[i]);}
			j=j+3;}
		}
		
		
		
		else if(strcmp(arreglo[j],"j")== 0){
			fprintf(archivo,"%s %s",arreglo[j],arreglo[j+1]);
			if(lineacontrol[0]=='x'||lineacontrol[7]=='x'||lineacontrol[8]=='x'){
			etiqueta = arreglo[j+1];
			actuallineacontrol[0]=0;
			actuallineacontrol[1]=1;
			actuallineacontrol[2]=0;
			actuallineacontrol[3]=0;
			actuallineacontrol[4]=0;
			actuallineacontrol[5]=0;
			actuallineacontrol[6]=0;
			actuallineacontrol[7]=0;
			actuallineacontrol[8]=0;
			if(posicionstuck<=9){ actuallineacontrol[posicionstuck]=1; } 
			for (k=0;k<9;k++){		
		    fprintf(archivo,"    %d    ",actuallineacontrol[k]);}
			fprintf(archivo,"      ");
			for (i=0;i<32;i++){		
		    fprintf(archivo,"  %d  ",valoresRegistros[i]);}
				while(strcmp(arreglo[j],etiqueta)!=0){
					j++;
				}
				j++;}
			else{
			actuallineacontrol[0]=0;
			actuallineacontrol[1]=1;
			actuallineacontrol[2]=0;
			actuallineacontrol[3]=0;
			actuallineacontrol[4]=0;
			actuallineacontrol[5]=0;
			actuallineacontrol[6]=0;
			actuallineacontrol[7]=0;
			actuallineacontrol[8]=0;
			if(posicionstuck<=9){ actuallineacontrol[posicionstuck]=1; } 
			for (k=0;k<9;k++){		
		    fprintf(archivo,"    %d    ",actuallineacontrol[k]);}
			fprintf(archivo,"      ");
			for (i=0;i<32;i++){		
		    fprintf(archivo,"  %d  ",valoresRegistros[i]);}
				
			}
		}
		
		
		fprintf(archivo,"\n");
		j++;}
		fclose(archivo);
		return;}

//Función principal.
int main()
{
//Declaracion de variables. 
char* control2;
char* instruccion;


//LLamado de funciones.
control2=leerarchivodecontrol();
instruccion=leerarchivoinstrucciones();
ejecuta(control2,instruccion);

	return 0;
	
}