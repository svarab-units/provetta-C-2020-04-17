/*
scrivere un programma in C seguendo queste specifiche:

*INSERITE TUTTI gli header files necessari (#include ...)*



è dato un array di int inizializzato con i seguenti valori:

// definitela come variabile globale

int work_array[] = {

   7788, -7066, -6641, -2324, 7799, 3530, -8426, 267, -569, -4432, -217, 1761, 4885, 274, -6318, 3527, 4346, 1710, 2562, 7932, -8472, 7351, 354, -7463, 1657, -4285, 3926, -7771, -4498, -3430, -5992, 2488, 658, -6352, -7909, 188, 3005, -8457, 4242, 1259, 3662, 32, 7910, 1252, 3067, -5430, 6794, 3550, -3073, 2204, -821, 6769, 390, -2097, 1685, -2996, -6410, 3972, -4800, 4674, -2337, 1897, -1160, -7987, -8890, -2197, 938, -6302, -5909, 3723, 8615, 7096, 3080, -5511, 6339

};



// è dato questo tipo dati:

typedef struct {

   int splitter_value; // valore "separatore"

   int * less_than_array; // array dei valori <= splitter_value

   unsigned int less_than_array_len; // lunghezza di less_than_array

   int * larger_than_array; // array dei valori > splitter_value

   unsigned int larger_than_array_len; // lunghezza di larger_than_array

} split_result;



implementare la seguente funzione:



split_result splitter(int * param_array, unsigned int array_len, int splitter_value);



splitter divide in due parti param_array, dove array_len è il numero di celle:

*alloca* due nuovi array (chiamiamoli array1 ed array2) dove

in array1 vengono copiati i valori di param_array che sono minori o uguali di splitter_value

mentre in array2 vengono copiati i valori di param_array che sono maggiori di splitter_value

utilizza il tipo dati split_result per restituire i due nuovi array, con le loro dimensioni, e splitter_value



i due array creati hanno dimensione "esatta", cioè non ci devono essere celle non utilizzate.



potete fare un primo passaggio e contare quanti valori sono <= splitter_value

poi fate un secondo passaggio e popolate i due array



esempio d'uso di splitter():

int array [] = { 0,1,2,3,4,5,6,7,8,9 };

split_result r;

r = split_result(array, 10, 5);

// il primo array conterrà i valori 0,1,2,3,4,5

// l'altro array conterrà i valori 6,7,8,9



nel main():

- scrivere la dimensione di work_array

- "splittare" work_array per splitter_value = 0

- scrivete il numero di celle dei due array restituiti



poi, il processo padre crea due processi figli:



il primo processo figlio lavorerà sull'array less_than_array (quello con valori <= 0) per cercare e scrivere:

valore minimo, massimo di less_than_array 



quando il primo processo figlio ha terminato, allora il processo padre avvia il secondo processo figlio:



il secondo processo figlio lavorerà sull'array larger_than_array (quello con valori > 0) per cercare e scrivere:

valore minimo, massimo di larger_than_array 



quando il secondo processo figlio ha terminato, allora il processo padre scrive il messaggio "bye!" e può terminare.







il risultato su stdout del programma sarà del tipo:



dimensione di work_array: <scrivete il numero di celle...>

less_then_len=<nn> larger_then_len=<mm>

esecuzione primo processo:

min = -...., max = .....

esecuzione secondo processo:

min = ...., max = ....

bye!
*/
