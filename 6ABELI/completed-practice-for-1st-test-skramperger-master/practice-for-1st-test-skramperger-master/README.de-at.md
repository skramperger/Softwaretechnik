# Tetris

[![en](https://img.shields.io/badge/lang-en-red.svg)](README.md)
[![de-at](https://img.shields.io/badge/lang-de--at-green.svg)](README.de-at.md)

Führe die folgenden Aufgaben aus, indem die vorhandenen Quelldateien angepasst
werden.

1. Füge mithilfe von CSS ein Hintergrundbild zur Spielfläche hinzu.
1. Implementiere einen
   ["hard drop"](https://tetris.fandom.com/wiki/Hard_Drop)
   durch drücken der „Leertaste“.
1. Füge der Seite den folgenden statischen Text hinzu:
   ```html
   Cleared rows: 0
   Points: 0
   ```
   Jede der oben genannten Zahlen muss in ein `span` mit einer eindeutigen
   `id`, damit diese später einfach über den JavaScript Code des Spiels
   geändert werden können.
1. Füge in JavaScript einen Zähler für fertige Reihen hinzu. Das
   korrespondierende HTML-Element muss auch den korrekten Zählerstand anzeigen.
1. Füge in JavaScript einen Zähler für die Gesamtpunktzahl hinzu. Die Punkte
   müssen laut Nintendos
   [ursprünglichem Punktesystem](https://tetris.fandom.com/wiki/Scoring#Original_Nintendo_Scoring_System)
   berechnet werden.
   Beachte, dass wir keine Level implementiert haben. Dadurch wird die
   Berechnung viel einfacher.
1. Die Tetrominos sollen auch gegen den Uhrzeigersinn rotieren können
   (Linksdrehung). Zum Auslösen soll die rechte Umschalttaste
   verwendet werden.

## Benotung
Wenn alle oben genannten Aufgaben funktionieren: 1. Für jede Aufgabe, die
nicht funktioniert, wird die Note wird um eins herabgesetzt. Das bedeutet:
* 6 funktionierende Aufgaben: 1
* 5 funktionierende Aufgaben: 2
* 4 funktionierende Aufgaben: 3
* 3 funktionierende Aufgaben: 4
* ansonsten: 5
