# Snake

[![en](https://img.shields.io/badge/lang-en-red.svg)](README.md)
[![de-at](https://img.shields.io/badge/lang-de--at-green.svg)](README.de-at.md)

Complete the following tasks by adjusting the existing source files.

<!-- 1. Using CSS, add a background image to the game canvas. -->
<!-- 1. Increase the size of the game field to be 800 pixels wide while
   keeping the current height. -->
1. Implement a counter for the points. Whenever the snake eats an apple, the
   counter is incremented. The counter has to be shown in the
   `<span id="points">`.
   
   
1. Pause the game when `p` is pressed. Restart it, when
   `p` is pressed again.
   
   
1. Currently, the snake can leave the game field and never dies. Change this so
   that the game stops when the snake would leave the field.
   
   
1. Display "Game over" below the score when the game ends.


1. Instead of displaying a single red apple, display a red and a yellow apple
   at the same time that also adds a point to the user's score when eaten.
   
   
1. Instead of regenerating both apples when one is eaten, only regenerate
   the one that was eaten and leave the other one where it was.
   
1. Eating the red apple should yield two points while eating the yellow one
   is rewarded with only one additional point.

## Grading
If you implemented all tasks above: 1. For each task that does not work, the
grade is reduced by one. That means:
* 7 working tasks: 1
* 6 working tasks: 2
* 5 working tasks: 3
* 4 working tasks: 4
* otherwise: 5
