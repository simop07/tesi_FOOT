# APPUNTI

## COMPILAZIONE PDF:

- Inserire ref alla correlazione delle equazioni sul numero di massa A nel capitolo 2-capitolo 3 in un'eventuale discussione della matrice di correlazione.
- Nel cap 3 scrivi la formula inversa delle bethe bloch, scrivi il materiale usato (EJ-200) e le sue specifiche.
- Inserire ref. sul pdf da cui hai ricavato il valore delle costanti
- Scegliere in modo opportuno quali frammenti selezionare per i grafici, aggiungere per esempio che si sono scelti (tra tutti i frammenti) non solo i frammenti più abbondanti ma anche gli isotopi più abbondanti di quei frammenti.
- Aggiungere sulle tabelle del terzo capitolo il numero atomico dei frammenti selezionati.
- Controlla dalla citazione 155 esclusa in poi per la bibliografia.
- Decidi se mettere pagine bianche prima dell'inizio dei capitoli.
- Decidere se mettere una dedica

## CODICE:

- sia p che CALO sono in GEV, il TW è in MEV e l'MSD non si deve contare in questo tipo di analisi. si devono considerare per il TW ASSIEME i TWdE1/TWdE2.

## DOMANDE:

- Gli istogrammi che vengono peggio sono l'A_3 del Litio, l'A1 e l'A_3 del Berillio e l'A_1 e l'A_3 del Boro (magari da rivedere il cut).
- I fit dopo l'elio peggiorano e nessuno dei multifit funziona. Magari, dal Litio incluso in poi, è più opportuno fare i fit solo degli isotopi più abbondanti (anche perché le occorrenze degli isotopi meno abbondanti sono davvero poche).
- I fit migliorano o peggiorano se si passa da 500 bin a 250 bin? -> dire che ho ridotto il numero dei bin perché i grafici sembravano piuttosto "frastagliati"
- Fare i fit anche sugli istogrammi blu, magari con un divide della canvas.
- Le barre di errore sul multigraph le lascio perdere? Bisognerebbe fare una propagazione degli errori sull'errore percentuale, attraverso gli errori dei parametri dati dal fit.
- Rimuovere con SetOptFit i dati del fit (visto che lì appaiono i risultati di un unico fit, mentre andrebbero messi i risultati di più fit).
- Cambiando alcuni bin nella simulazione alcuni fit a multi gaussiana sono diventati migliori.
- Il secondo termine dell'ALM presenta un più o un meno?