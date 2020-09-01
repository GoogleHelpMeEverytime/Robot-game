/*----------------------------------------------------
Nome:                   Robot
Autore:                 Improta Nicola
Matricola:              0124001479
Finalità del programma: Simulare il movimento di un
						robot in una stanza. Date in
						input le coordinate della 
						posizione iniziale del robot 
						ad ogni passo il robot si muove
						di una sola cella alla volta.
						Nel 30% dei casi il robot si
						muove a caso in una delle quattro 
						direzioni.
						Nel 70% dei casi il robot 
						guardando in ognuna delle 
						quattro direzioni si muove 
						nella direzione con il percorso 
						più lungo.
						Il robot non può mai fare un 
						passo in una direzione e il 
						passo successivo nella direzione
						opposta.
----------------------------------------------------*/

#include "functions.c"

/*----------------------------------------------------
	Nome: 				main
	Descrizione: 		Main programma applicativo
----------------------------------------------------*/

int main(){
	int flag = 0, n, k = 0, j = 0, flag2 = 0;
	srand(time(NULL));	
		
		
		INTRO();          //Visualizzazione dei dati dell'autore del progetto
		system("pause");
		printf("\n\n");
		
		
		printf("INSERIMENTO DELLE COORDINATE INIZIALI DEL ROBOT\n\n");
		
	do{
		//inserimento da tastiera delle coordinate iniziali del robot
		printf("Inserisci numero riga (DA 0 A 15) ");
		scanf("%d", &run.c_x);
		printf("Inserisci numero colonna (DA 0 A 15) ");
		scanf("%d", &run.c_y);
		flag = POSIZIONA_ROBOT(CAMPO);
		//controllo che la posizione scelta non sia una parete o fuori dalla stanza.
		if(flag == 0)
			printf("\nNON PUOI INSERIRE IL ROBOT QUI, C'E' UNA PARETE\n");
		else if(flag == 1)
			printf("\nROBOT INSERITO CORRETTAMENTE\n\n");
		else if(flag == 2)
			printf("\nCOORDINATE ERRATE\n");
			
	}while(flag == 0 || flag == 2);
	
	STAMPA(CAMPO);
	system("pause");
	
	//il ciclo si ripete finché il robot non esce dalla stanza.
	while(flag2 == 0){
		//generazione di un numero casuale
		n = rand()%10;
		STAMPA(CAMPO);
		//30%: se viene generato casualente un numero tra 0 e 2 il robot 
		//si muove in una delle quattro direzioni scelta casualmente.
		if(n >= 0 && n < 3){
			MOVIMENTO_A_CASO(CAMPO, &flag2);
			k++;
		}
		//70%: se viene generato casualmente un numero tra 3 e 9 il robot
		//si muove nella direzione con il percorso più lungo.
		else{
			MOVIMENTO_AUTONOMO(CAMPO, &flag2);
			j++;
		}
	}
	
	STAMPA(CAMPO);

	printf("\nIL ROBOT E' USCITO DALLA STANZA ESEGUENDO: \n");
	printf("%d MOVIMENTO A CASO IN UNA DELLE QUATTRO DIREZIONI\n", k);
	printf("%d MOVIMENTO NELLA DIREZIONE CON NUMERO DI CELLE LIBERE MAGGIORE\n", j);
	return 0;
}
