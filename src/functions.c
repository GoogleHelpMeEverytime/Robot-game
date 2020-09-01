#include "header.h"
/*----------------------------------------------------------
	Nome: 			INTRO
	Descrizione: 	Visualizza i dati dell'autore del progetto.
----------------------------------------------------------*/
void INTRO()
{
 	printf("Corso di Laurea in Informatica\n");
    printf("Anno Accademico 2017-2018\n");
    printf("Corso di Programmazione I e Laboratorio Programmazione I\n");
    printf("--------------------------------------------------------\n");
    printf("Progetto di Esame di Laboratorio\n");
    printf("Robot\n");
    printf("--------------------------------------------------------\n");
    printf("Autore:    IMPROTA NICOLA\n");
    printf("Matricola: 0124001479\n");
    printf("--------------------------------------------------------\n\n");
}

/*----------------------------------------------------------
	Nome: 			POSIZIONA_ROBOT
	Descrizione:	Funzione che permette di inserire il 
					robot nella stanza
	Parametri: 		char a [][16]: Matrice rappresentante la stanza
					da cui il robot deve uscire
----------------------------------------------------------*/

int POSIZIONA_ROBOT(char a [][16]){

	if((run.c_x >= 0 && run.c_x <= MAX_ROWCOL - 1) && (run.c_y >= 0 && run.c_y <= MAX_ROWCOL - 1)){

		if(a[run.c_x][run.c_y] == ' '){
			a[run.c_x][run.c_y] = 'X';
			return 1;
		}

		else{
			return 0;
		}
	}
	else
		return 2;

}
/*----------------------------------------------------------
	Nome: 			MOVIMENTO_A_CASO
	Descrizione: 	Funzione che permette il movimento casuale
					del robot in una delle quattro celle vicine.
	Parametri: 		char a [][16]: Matrice rappresentante la stanza
					da cui il robot deve uscire;
					int *p: Puntatore contenente l'indirizzo della 
					variabile int flag2 dichiarata nel main.  
					
----------------------------------------------------------*/

void MOVIMENTO_A_CASO(char a[][16], int *p){
	int m, flag = 0, flag3 = 0;
	
	a[run.c_x][run.c_y]= ' ';
	
	
	
	while(flag3 == 0){
		m = rand()%4+1; //genera un numero casuale rappresentante la direzione
					  //in cui il robot deve andare
		flag = 0;
		while(flag == 0){
			//controllo sulla direzione precedente
			if((m == 1 && run.direzione == 3) || (m == 3 && run.direzione == 1) || (m == 2 && run.direzione == 4) || (m == 4 && run.direzione == 2))
				m = rand()%4+1;
			else
				flag = 1;		
				}	
		
		switch(m){
			
			case 1: //il robot va in alto
				if(a[run.c_x - 1][run.c_y] != '#'){
					flag3 = 1;
					run.c_x--;
					run.direzione = 1;
				}
				break;
			case 2: //il robot va a destra
				if(a[run.c_x][run.c_y + 1] != '#'){
					flag3 = 1;
					run.c_y++;
					run.direzione = 2;	
				}
				break;
			case 3: //il robot va in basso
				if(a[run.c_x + 1][run.c_y] != '#'){
					flag3 = 1;
					run.c_x++;
					run.direzione = 3;	
				}
				break;
			case 4: //il robot va a sinistra
				if(a[run.c_x][run.c_y - 1] != '#'){
					flag3 = 1;
					run.c_y--;
					run.direzione = 4;	
				}
				break;
			}	
	}	
		//inserimento del robot nella nuova posizione
		if((run.c_x >= 0 && run.c_x <= MAX_ROWCOL - 1) && (run.c_y >= 0 && run.c_y <= MAX_ROWCOL - 1)){
			if(a[run.c_x][run.c_y] == '@'){
				a[run.c_x][run.c_y] = 'X';
				*p = 1;
			}
			else{
				a[run.c_x][run.c_y] = 'X';
			}		
		}
}
			
/*----------------------------------------------------------
	Nome: 			MOVIMENTO_AUTONOMO
	Descrizione: 	Funzione che permette il movimento 
					autonomo del robot. Ad ogni passo vengono 
					contate quante celle sono disponibili in ogni
					direzione. Il robot si muove nella direzione
					con il percorso più lungo.
	Parametri: 		char a [][16]: Matrice rappresentante la stanza
					da cui il robot deve uscire;
					int *p: Puntatore contenente l'indirizzo della 
					variabile int flag2 dichiarata nel main.
----------------------------------------------------------*/

void MOVIMENTO_AUTONOMO(char a[][16], int *p){
	
	int max[4] = {0};
	int i, j, k, flag = 0, flag2 = 0;
	
	    //conta celle - alto
	i = run.c_x;
	while(a[i-1][run.c_y] != '#' && i >= 0){
		i--;
		max[0]++;
	}
	
        //conta celle - destra
	j = run.c_y;
	while(a[run.c_x][j+1] != '#' && j < MAX_ROWCOL){
		j++;
		max[1]++;
	}
	
        //conta celle - basso      
	i = run.c_x;
	while(a[i+1][run.c_y] != '#' && i < MAX_ROWCOL){
		i++;
		max[2]++;
	}
	
        //conta celle - sinistra
	j = run.c_y;
	while(a[run.c_x][j-1] != '#' && j >= 0){
		j--;
		max[3]++;
	}
	
	//sceglie il percorso più lungo
	k = MASSIMO(max);
	
	a[run.c_x][run.c_y] = ' ';
	
	switch(k){
		case 1: //vai in alto
				if(a[run.c_x-1][run.c_y] != '#'){
					flag2 = 1;
					run.c_x--;
					run.direzione = 1;
				}
				break;
			case 2: //vai a destra
				if(a[run.c_x ][run.c_y+1] != '#'){
					flag2 = 1 ;
					run.c_y++;
					run.direzione = 2;	
				}
				break;
			case 3: //vai in basso
				if(a[run.c_x+1 ][run.c_y] != '#'){
					flag2 = 1;
					run.c_x++;
					run.direzione = 3;	
				}
				break;
			case 4: //vai a sinistra
				if(a[run.c_x][run.c_y-1] != '#'){
					flag2 = 1;
					run.c_y--;
					run.direzione = 4;	
				}
				break;
	}
	
	//inserimento del robot nella nuova posizione
	if((run.c_x >= 0 && run.c_x <= MAX_ROWCOL - 1) && (run.c_y >= 0 && run.c_y <= MAX_ROWCOL - 1)){
		if(a[run.c_x][run.c_y] == '@'){
			a[run.c_x][run.c_y] = 'X';
			*p = 1;
		}
		else{
			a[run.c_x][run.c_y] = 'X';
		}
	}
	
}

/*----------------------------------------------------------
	Nome: 			MASSIMO
	Descrizione: 	Funzione che restituisce l'indice del 
					massimo elemento di un array.
	Parametri: 		int a[]: Vettore contenente il numero di celle
					disponibili in ogni direzione 
					(MOVIMENTO_AUTONOMO).
----------------------------------------------------------*/

int MASSIMO(int a[]){
	int i, max1, max2, ind_max1, ind_max2;
	srand(time(NULL));
	if(a[0] >= a[1]){
	max1 = a[0];
	max2 = a[1];
	ind_max1 = 1;
	ind_max2 = 2;
}
else{
	max1 = a[1];
	max2 = a[0];
	ind_max1 = 2;
	ind_max2 =1;
}

for(i = 2; i < 4; i++){
	
	if(a[i] > max1){
		max2 = max1;
		ind_max2 = ind_max1;
		max1 = a[i];
		ind_max1 = i+1;
	}
	else if(a[i] >= max2){
		max2 = a[i];
		ind_max2 = i+1;
	}
}
	
	if(max1 != max2){
		if((ind_max1 == 1 && run.direzione == 3) || (ind_max1 == 3 && run.direzione == 1) || (ind_max1 == 2 && run.direzione == 4) || (ind_max1 == 4 && run.direzione == 2))
			return ind_max2;
		else
			return ind_max1;
	}
	
	else if(rand() % 2 == 0){
		if((ind_max1 == 1 && run.direzione == 3) || (ind_max1 == 3 && run.direzione == 1) || (ind_max1 == 2 && run.direzione == 4) || (ind_max1 == 4 && run.direzione == 2))
			return ind_max2;
		else
			return ind_max1;
	}
	else{
		if((ind_max2 == 1 && run.direzione == 3) || (ind_max2 == 3 && run.direzione == 1) || (ind_max2 == 2 && run.direzione == 4) || (ind_max2 == 4 && run.direzione == 2))
			return ind_max1;
		else
			return ind_max2;
	}
}

/*----------------------------------------------------------
	Nome: 			STAMPA
	Descrizione: 	Funzione che stampa ad ogni passo la stanza
					e la posizione del robot.
	Parametri: 		char a [][16]: Matrice rappresentante la stanza
					da cui il robot deve uscire;
----------------------------------------------------------*/

void STAMPA(char a [] [16]){
	int i, j;

	for(i = 0; i < MAX_ROWCOL; i++){
		for(j = 0; j < MAX_ROWCOL; j++){
			printf("%c ", a[i][j]);
		}
	printf("\n");
	}
}

