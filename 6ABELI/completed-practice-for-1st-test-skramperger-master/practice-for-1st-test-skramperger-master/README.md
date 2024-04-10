# Tetris

[![en](https://img.shields.io/badge/lang-en-red.svg)](README.md)
[![de-at](https://img.shields.io/badge/lang-de--at-green.svg)](README.de-at.md)

Complete the following tasks by adjusting the existing source files.

1. Using CSS, add a background image to the game canvas.
1. Implement
   [dropping the tetrominoe](https://tetris.fandom.com/wiki/Hard_Drop)
   when the `spacebar` is pressed.
1. Add the following static text to the page:
   ```html
   Cleared rows: 0
   Points: 0
   ```
   Each of the numbers above have to be wrapped in a `span` with a designated
   `id` to be easily changed from the game's JavaScript later on.
1. Add a counter for cleared rows. The visible `Cleared rows` counter
   has to show this value.
1. Add a counter for the total points. The points have to be implemented
   according to Nintendo's
   [original scoring system](https://tetris.fandom.com/wiki/Scoring#Original_Nintendo_Scoring_System).
   Note that we don't have levels implemented which will make the scoring much
   easier. The visible `Points` counter has to show this value.
1. Allow the tetrominoes to be rotated counter clockwise (left rotation)
   in addition to the current rotation. Use the right shift button to trigger
   this rotation.
<!---
1. Show a preview of the
   [upcoming tetrominoe](https://tetris.fandom.com/wiki/Next)
-->

## Grading
If you implemented all tasks above: 1. For each task that does not work, the
grade is reduced by one. That means:
* 6 working tasks: 1
* 5 working tasks: 2
* 4 working tasks: 3
* 3 working tasks: 4
* otherwise: 5
