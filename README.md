# Robot-game
Un gioco dove un robottino deve uscire autonomamente da una stanza. La posizione iniziale del robot è decisa dal utente.

### Descrizione
Si voleva sviluppare un algoritmo per la simulazione del movimento di un robot in una stanza.
La stanza è pavimentata a tasselli quadrati(caselle) ed è dotata di pareti esterne e interne. Il robot è in grado di "vedere", cioè
di stabilire guardando in una delle quattro direzioni quante caselle sono libere fino ad arrivare alla parete.
### Movimento del robot
Il robot può muoversi solo in due modi: 
1. Si guarda intorno e controlla quante caselle libere sono presenti e sceglie di andare nella direzione con più caselle libere.
2. Effettua un movimento casuale in una delle quattro direzioni
### Vincoli
1. Il robot non può muoversi nella direzione opposta rispetto al passo precedente(i-esimo passo: SU i-esimo+1 passo: non può andare in BASSO)
2. Nel 30% dei casi il robot si muove seguendo la modalità di movimento casuale
3. Nel 70% dei casi il robot si muove seguendo la modalità di movimento che prevede di guardare nelle quattro direzioni e scegliere quella con più celle libere.
### Idea
Questo progetto è stato assegnato agli studenti del Corso di Laurea in Informatica dell' Università degli Studi di Napoli "Parthenope" per il corso di Programmazione 1.
# Installazione
### Clone repository
```console
$ git clone https://github.com/GoogleHelpMeEverytime/Robot-game.git

```
