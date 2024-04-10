let canvas;
let context;
let snakeX;
let snakeY;

// ends the game
let gameOver = false;

window.addEventListener("load", () => {
  canvas = document.getElementById("gameCanvas");
  context = canvas.getContext("2d");
  snakeX = canvas.width / 2;
  snakeY = canvas.height / 2;
  generateApple();
  generateYellowApple();
  gameLoop();
});

document.addEventListener("keydown", onKeyDown);

// Point counter
let scoreCount = 0;

// Pause switch
let pSwitch = false;

let old_dx;
let old_dy;

// Snake initial position and size
const snakeSize = 20;

// Snake movement
let dx = 0;
let dy = 0;

// Apple position
let appleX;
let appleY;
const appleSize = 20;

// Yellow Apple position
let appleYellowX;
let appleYellowY;

function drawApple() {
  context.fillStyle = "red";
  context.fillRect(appleX, appleY, appleSize, appleSize);
}

function drawYellowApple() {
  context.fillStyle = "yellow";
  context.fillRect(appleYellowX, appleYellowY, appleSize, appleSize);
}

function generateApple() {
  appleX = Math.floor(Math.random() * (canvas.width / snakeSize)) * snakeSize;
  appleY = Math.floor(Math.random() * (canvas.height / snakeSize)) * snakeSize;
}

function generateYellowApple() {
  appleYellowX = Math.floor(Math.random() * (canvas.width / snakeSize)) * snakeSize;
  appleYellowY = Math.floor(Math.random() * (canvas.height / snakeSize)) * snakeSize;
}

function drawSnake() {
  context.fillStyle = "green";
  context.fillRect(snakeX, snakeY, snakeSize, snakeSize);
}

function update() {
  if (typeof update.count == 'undefined' && gameOver == false) {
    update.count = 0;
  }
  if (update.count++ > 15) {
    update.count = 0;
    snakeX += dx;
    snakeY += dy;

    if (snakeX === appleX && snakeY === appleY) {
      generateApple();
      scoreCount += 2;
    }

    if (snakeX === appleYellowX && snakeY === appleYellowY) {
      generateYellowApple();
      scoreCount++;
    }

    if (snakeX > 400 || snakeX < 0 || snakeY > 400 || snakeY < 0){
      // outside field
      dx = 0;
      dy = 0;
      document.getElementById("gameOver").innerHTML = "Game Over";
      gameOver = true;
    }

    context.clearRect(0, 0, canvas.width, canvas.height);
    drawApple();
    drawYellowApple();
    drawSnake();
    document.getElementById("points").innerHTML = scoreCount;
  }
}


function gameLoop() {
    if (gameOver == false){   // checks for out of bounds and halts the game
      requestAnimationFrame(gameLoop);
      update();
    }

}

function onKeyDown(event) {
    switch (event.keyCode) {
        case 37: // left arrow key
            dx = -snakeSize;
            dy = 0;
            break;
        case 38: // up arrow key
            dx = 0;
            dy = -snakeSize;
            break;
        case 39: // right arrow key
            dx = snakeSize;
            dy = 0;
            break;
        case 40: // down arrow key
            dx = 0;
            dy = snakeSize;
            break;
        case 80:  // p key
            if (pSwitch == false){      // pauses
              if (gameOver == false){
                old_dx = dx;
                old_dy = dy;
                dx = 0;
                dy = 0;
                pSwitch = true;
                document.getElementById("gameOver").innerHTML = "Paused";
                break;
              }
            }
            else if (pSwitch == true){  // unpauses
              if(gameOver == false){
                dx = old_dx;
                dy = old_dy;
                pSwitch = false;
                document.getElementById("gameOver").innerHTML = "";
                break;
              }
            }

    }
}



