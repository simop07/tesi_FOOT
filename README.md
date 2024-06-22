# APPUNTI

## COMPILAZIONE PDF:

- Inserire ref alla correlazione delle equazioni sul numero di massa A nel capitolo 2-capitolo 3 in un'eventuale discussione della matrice di correlazione.
- Nel cap 3 scrivi la formula inversa delle bethe bloch, scrivi il materiale usato (EJ-200) e le sue specifiche.
- Inserire ref. sul pdf da cui hai ricavato il valore delle costanti

## CODICE:

- Per la formula bethe-bloch scritta meglio vedi: https://pdg.lbl.gov/2021/reviews/rpp2020-rev-passage-particles-matter.pdf
- Per gli h_A1/2/3: scegi un range degli istogrammi migliore e più bin per gli istogrammi
- PEr le z1/2/3 -> seleziona le caratteristiche di EJ-200 e non del target. Confronta il valore di z con la charge del TW.
- Prova a fare grafico E in funzione del TOF.
- Inizia a fare grafici per ogni frammento, quindi imponendo la condizione di A==1, e così via.
- fai assolutamente un TFILE nuovo per l'analisi
- sia p che CALO sono in GEV, il TW è in MEV e l'MSD non si deve contare in questo tipo di analisi. si devono considerare per il TW ASSIEME i TWdE1/TWdE2.

## DOMANDE:

- Fare un'analisi dell'efficienza del metodo di ricostruzione? quindi prendere gli istogrammi di generazione e fare un Divide con gli istogrammi di ricostruzione?
- Io ho ricostruito i frammenti del CDR, ho visto che in una tesi vengono ricostruiti altri isotopi, li aggiungo?
- Solo a titolo di curiosità, per quale motivo a ROOT non piacciono le ottimizzazioni sui for loop? Esempio della necessità di inserire un grafico inutile per fare in modo che le canvas tornassero.