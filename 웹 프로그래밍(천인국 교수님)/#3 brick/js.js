var canvas = document.getElementById("myCanvas");
var ctx = canvas.getContext("2d");
var ballRadius = 8;
var x = canvas.width/2;
var y = canvas.height-30;
var dx = 4;
var dy = -4;
var paddleHeight = 10;
var paddleWidth = 175;
var paddleX = (canvas.width-paddleWidth)/2;
var rightPressed = false;
var leftPressed = false;
var brickRowCount = 9;
var brickColumnCount = 5;
var brickWidth = 75;
var brickHeight = 20;
var brickPadding = 10;
var brickOffsetTop = 30;
var brickOffsetLeft = 30;
var counter = 0;

var score = 0;

var lives = 5;

var newx = canvas.width/2;;
var newy = canvas.height-30;
var drawcou = 0;
var newdx = 4;
var newdy = -4;
var newpaddleX = (canvas.width-paddleWidth)/2;


var bricks = []; // Bricks를 생성해주는 부분입니다.
for(var c=0; c<brickColumnCount; c++) { // 위의 변수파트에서 선언해준 brickColumnCount와
    bricks[c] = [];
    for(var r=0; r<brickRowCount; r++) { // brickRowCount만큼의 2차원 배열을 생성하여 Brick을 생성합니다.(실체는 없음)
        bricks[c][r] = { x: 0, y: 0, status: 1, color: 3};
        if(r == 0 || r == 8) {
            bricks[c][r].status = 0;
        }
    }
}

document.addEventListener("keydown", keyDownHandler, false);
document.addEventListener("keyup", keyUpHandler, false);
document.addEventListener("mousemove", mouseMoveHandler, false);

function mouseMoveHandler(e) {
    var relativeX = e.clientX - canvas.offsetLeft;
    if(relativeX > 0 && relativeX < canvas.width) {
        paddleX = relativeX - paddleWidth/2;
    }
}

function keyDownHandler(e) {
    if(e.keyCode == 39) {
        rightPressed = true;
    }
    else if(e.keyCode == 37) {
        leftPressed = true;
    }
}
function keyUpHandler(e) {
    if(e.keyCode == 39) {
        rightPressed = false;
    }
    else if(e.keyCode == 37) {
        leftPressed = false;
    }
}

function collisionDetection() {
    for(var c=0; c<brickColumnCount; c++) {
        for(var r=0; r<brickRowCount; r++) {
            var b = bricks[c][r];
            if(b.status == 1) {
                if(x > b.x && x < b.x+brickWidth && y > b.y && y < b.y+brickHeight) {
                    dy = -dy;

                    if(c == 0&&r == 2) {
                        newdrawBall();
                        drawcou = 1;
                    }

                    if(r == 3 && c == 3) {
                        lives += 10;                 
                    }

                    if(dy > 0) {
                        dy += 1; // 속도 빠르게 해주는 부분
                        dx += 1 ;// 속도 빠르게 해주는 부분
                        if (dy > 10 || dx > 10) {
                            dy = 10;
                            dx = 10;
                        }
                    }
                    else if(dy < 0) {
                        dy -= 1; // 속도 빠르게 해주는 부분
                        dx -= 1;// 속도 빠르게 해주는 부분
                        if (dy < -10 || dx < -10) {
                            dy = -10;
                            dx = -10;
                        }
                    }

                    b.color--;
                    if(b.color == 0){
                        b.status = 0;
                        counter++;
                    }
                    if (c == 4 && (r !=1) && (r !=3) && (r !=5) && (r !=7)) {
                        score--;
                    }
                    score++;
                    if(counter == (brickRowCount-2) * brickColumnCount - 3)  {
                        alert("Victory !");
                        document.location.reload();
                    }
                }
            }
        }
    }
}


function newcollisionDetection() {
    for(var c=0; c<brickColumnCount; c++) {
        for(var r=0; r<brickRowCount; r++) {
            var b = bricks[c][r];
            if(b.status == 1) {
                if(newx > b.x && newx < b.x+brickWidth && newy > b.y && newy < b.y+brickHeight) {
                    newdy = -newdy;

                    if(c == 0 && r == 2) {
                        newdrawBall();
                        ++drawcou;
                    }

                    if(newdy > 0) {
                        newdy += 1; // 속도 빠르게 해주는 부분
                        newdx += 1 ;// 속도 빠르게 해주는 부분
                        if (newdy > 10 || newdx > 10) {
                            newdy = 10;
                            newdx = 10;
                        }
                    }
                    else if(newdy < 0) {
                        newdy -= 1; // 속도 빠르게 해주는 부분
                        newdx -= 1;// 속도 빠르게 해주는 부분
                        if (newdy < -10 || newdx < -10) {
                            newdy = -10;
                            newdx = -10;
                        }
                    }

                    b.color--;
                    if(b.color == 0){
                        b.status = 0;
                        counter++;
                    }
                    if (c == 4 && (r !=1) && (r !=3) && (r !=5) && (r !=7)) {
                        score--;
                    }
                    score++;
                    if(counter == (brickRowCount-2) * brickColumnCount)  {
                        alert("Victory !");
                        document.location.reload();
                    }
                }
            }
        }
    }
}

function drawScore() {
    ctx.font = "16px Arial";
    ctx.fillStyle = "Black";
    ctx.fillText("SCORE : "+score, 8, 20);
}

function drawLives() {
    ctx.font = "16px Arial";
    ctx.fillStyle = "Black";
    ctx.fillText("LIFE : "+lives, canvas.width-65, 20);
}

function drawBall() {
    ctx.beginPath();
    ctx.arc(x, y, ballRadius, 0, Math.PI*2);
    ctx.fillStyle = "Black";
    ctx.fill();
    ctx.closePath();
}

function newdrawBall(){
    ctx.beginPath();
    ctx.arc(newx, newy, ballRadius, 0, Math.PI*2);
    ctx.fillStyle = "Pink";
    ctx.fill();
    ctx.closePath()
}

function drawPaddle() {
    ctx.beginPath();
    ctx.rect(paddleX, canvas.height-paddleHeight, paddleWidth, paddleHeight);
    ctx.fillStyle = "Black";
    ctx.fill();
    ctx.closePath();
}

function drawBricks() {

    for(var c=0; c<brickColumnCount; c++) {
        for(var r=0; r<brickRowCount; r++) {
            if(bricks[c][r].status == 1) {
                var brickX = (r*(brickWidth+brickPadding))+brickOffsetLeft;
                var brickY = (c*(brickHeight+brickPadding))+brickOffsetTop;
                bricks[c][r].x = brickX;
                bricks[c][r].y = brickY;
                ctx.beginPath();
                ctx.rect(brickX, brickY, brickWidth, brickHeight);
                if(r == 3 && c == 3) {
                    ctx.fillStyle = "Black";
                    bricks[c][r].color = 1;
                    ctx.fillStyle = "Pink";                   
                }
                else if (c == 0 && r == 2) { // 3번째 열을 파란색으로
                    ctx.fillStyle="#0067a3";
                    bricks[c][r].color = 1;
                }
                else {
                    ctx.fillStyle = "#808080";
                    if(bricks[c][r].color == 2) {
                        ctx.fillStyle = "#d3d3d3";
                    }
                    else if(bricks[c][r].color == 1) {
                        ctx.fillStyle = "white";
                    }
                }
                if (c == 4 && (r !=1) && (r !=3) && (r !=5) && (r !=7)) {
                    ctx.fillStyle="Black";
                    bricks[c][r].color = -1;
                }
                ctx.fill();
                ctx.closePath();
            }
        }
    }
}


function draw() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    drawBricks();
    drawBall();
    drawPaddle();
    drawScore();
    drawLives();
    collisionDetection();

    if(x + dx > canvas.width-ballRadius || x + dx < ballRadius) {
        dx = -dx;
    }

    if(y + dy < ballRadius) {
        dy = -dy;
    }
    else if(y + dy > canvas.height-ballRadius) {
        if(x >= paddleX && x < paddleX + paddleWidth) {
            dy = -dy;
        }
        else {
            lives--;
            if(!lives) {
                alert("Failed");
                document.location.reload();            
            }
            else {
                x = canvas.width/2;
                y = canvas.height-30;
                dx = 4;
                dy = -4;
                paddleX = (canvas.width-paddleWidth)/2;
            }
        }
    }

    if(rightPressed && paddleX < canvas.width-paddleWidth) {
        paddleX += 7;
    }
    else if(leftPressed && paddleX > 0) {
        paddleX -= 7;
    }

    x += dx;
    y += dy;
    requestAnimationFrame(draw);
    if (drawcou != 0) {
        requestAnimationFrame(newdraw);
    }
}


function newdraw() {
    newdrawBall();
    newcollisionDetection();

    if(newx + newdx > canvas.width-ballRadius || newx + newdx < ballRadius) {
        newdx = -newdx;
    }
    if(newy + newdy < ballRadius) {
        newdy = -newdy;
    }
    else if(newy + newdy > canvas.height-ballRadius) {
        if(newx > paddleX && x < paddleX + paddleWidth) {
            newdy = -newdy;
        }
        else {
            lives--;
            drawcou--;
            newx = canvas.width/2;
            newy = canvas.height-30;
            newdx = 4;
            newdy = -4;
            paddleX = (canvas.width-paddleWidth)/2;
        }
    }

    if(rightPressed && newpaddleX < canvas.width-paddleWidth) {
        newpaddleX += 7;
    }
    else if(leftPressed && paddleX > 0) {
        newpaddleX -= 7;
    }

    newx += newdx;
    newy += newdy;
}

draw();
if (drawcou >= 0) {
    newdraw();
}