const model_url = 'https://cdn.jsdelivr.net/gh/ml5js/ml5-data-and-models/models/pitch-detection/crepe/';
// loading model from github, thanks to the CodingTrain <3
let mic;
let pitch;
let beginFreq = 0;
var freqVariance = 0;
let freq = 0;
const WindowWidth  = window.innerWidth || document.documentElement.clientWidth || document.body.clientWidth;
const WindowHeight = window.innerHeight|| document.documentElement.clientHeight|| document.body.clientHeight;

// gamestate is phase of the game
// start => playing => gameover
let gameState = "start";
let displayText = "Press spacebar to start game, press q to quit";
var pipes = [];
var bg_lines = [];

const pipeWidth = 165;

function lines(){
	// line(x1, y1, x2, y2)
	this.width=random(WindowWidth);
	this.height=random(WindowHeight);
	this.show = function(){
		fill(255);
		line(this.width, 0, 0, this.height);
		line(0, this.height, this.width, 0);
	}
	this.update = function(){

	}
}
function pipe(){
	// length of to top bar
	this.top = random(height/2);
	// length of to bottom bar
	this.bottom = random(height/2);
	this.x = WindowWidth;
	// width of the bars
	this.w = 10;
	this.speed = 5;

	this.show = function(){
		fill(255);
		rect(this.x, 0, this.w, this.top);
		rect(this.x, height-this.bottom, this.w, this.bottom);
	}

	this.offscreen = function(){
		if (this.x < -this.w){
			return true;
		} else {
			false;
		}
	}

	this.update = function(){
		this.x -= this.speed;
	}

	this.hits = function(player){
		if((player.y < this.top || player.y < height - this.bottom) &&
			(player.x > this.x && player.x < this.x + this.w)){
				return true;
		}
		return false;
	}
}

function player(freqVariance){
	this.x = WindowWidth/2;
	this.y = WindowHeight/2;
	this.lineX = WindowWidth/2;
	this.speed = 2;
	this.show = function(freqVariance){
		fill('red');
		this.newY = this.y-freqVariance;
		circle(this.x,this.newY, 20);
	}
}

function setup(){
	audioContext = new AudioContext();
 	let cnv = createCanvas(WindowWidth, WindowHeight);
 	textAlign(CENTER);
 	mic = new p5.AudioIn();
 	mic.start(listening);
	pipes.push(new pipe());
	bg = new lines();
}

function listening() {
  console.log('listening');
  pitch = ml5.pitchDetection(
    model_url,
    audioContext,
    mic.stream,
    modelLoaded
  );
}

function draw(){
 	background(0);
	fill(255);
	textAlign(CENTER, CENTER);
	textSize(32);
	text(displayText, WindowWidth / 2, height - 150);
	if (gameState == "start"){
		for(var i = 0; i>255;i++){
			bg.drawlines();
		}
		begin();
	}
	if (gameState == "playing"){
		var freqVariance = freq - beginFreq;
		for (var i=pipes.length-1; i>= 0; i--){
			pipes[i].show();
			pipes[i].update();

			if (pipes[i].hits(player)==true){
				console.log("boem");
				gameState = "start";
			}

			if (pipes[i].offscreen()){
				pipes.splice(i,1);
			}
		}

		merneer = new player();
		if (frameCount % 100 == 0){
			pipes.push(new pipe());
		}
		merneer.show(freqVariance);
	}
}

function modelLoaded() {
  console.log('model loaded');
  pitch.getPitch(gotPitch);
}

function gotPitch(error, frequency) {
  if (error) {
    console.error(error);
  } else {
    if (frequency) {
      freq = frequency;
    }
    pitch.getPitch(gotPitch);
  }
}

function begin() {
  if (keyCode === 81) {
		gameState = "gameover";
  } else if (keyCode === 32){
		setBeginFreq(freq);
    gameState = "playing";
		displayText = "";
	}
}

function setBeginFreq(freq){
	if (gameState == "start"){
		beginFreq = freq;
		console.log("Begin frequency is ", beginFreq);
	} else if (gameState == "playing"){
		return beginFreq;
	}
}
