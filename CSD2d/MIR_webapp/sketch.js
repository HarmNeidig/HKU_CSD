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

const pipeWidth = 20;
const pipeOpening = 400;

function pipe(){
	// length of to top bar
	this.top = random(height/2);
	// length of to bottom bar
	this.bottom = this.top + pipeOpening;
	this.x = WindowWidth;
	// width of the bars
	this.w = pipeWidth;
	this.speed = 5;
	this.highlight = false;
	this.show = function(){
		fill(255);
		if (this.highlight) {
      fill(255, 0, 0);
    }
		rect(this.x, 0, this.w, this.top);
		rect(this.x, this.bottom, this.w, WindowHeight);
	};

	this.offscreen = function(){
		if (this.x < -this.w){
			return true;
		} else {
			return false;
		}
	};

	this.update = function(){
		this.x -= this.speed;
	};

	// to fix:
	// split function into  Hits top and Hits Bot
	this.hits_bot = function(player){
		if (this.x == (WindowWidth/2)){
			if (player.y > this.bottom){
				this.highlight = true;
				return true;
			} else {
				return false;
			}
		}
		this.highlight = false;
		return false;
	};
	this.hits_top = function(player){
		if (this.x == (WindowWidth/2)){
			if (player.y < this.top){
				this.highlight = true;
				return true;
			} else {
				this.highlight = false;
				return false;
			}
		}
	};
}

function player(){
	this.x = WindowWidth/2;
	this.y = WindowHeight/2;
	this.speed = 2;
	this.show = function(){
		fill('red');
		circle(this.x,this.newY, 10);

	};
	this.update = function(freqVariance){
		this.newY = this.y-freqVariance;
		if (this.newY > height) {
      this.newY = height;
    }
    if (this.newY < 0) {
      this.newY = 0;
    }
	}
}

function setup(){
	audioContext = new AudioContext();
 	let cnv = createCanvas(WindowWidth, WindowHeight);
 	textAlign(CENTER);
 	mic = new p5.AudioIn();
 	mic.start(listening);
	pipes.push(new pipe());
	merneer = new player();
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
		begin();
	}
	if (gameState == "playing"){
		// init player
		var freqVariance = freq - beginFreq;
		merneer.update(freqVariance);
		merneer.show();

		// show pipes
		for (var i=pipes.length-1; i>= 0; i--){
			pipes[i].show();
			pipes[i].update();

			// checks if player hits pipes
			if (pipes[i].hits_bot(merneer)==true){
				console.log("boem bottom");
			}
			if (pipes[i].hits_top(merneer)==true){
				console.log("boem top");
			}

			// deletes pipe if is offscreen
			if (pipes[i].offscreen()){
				pipes.splice(i, 1);
			}
		}
		// makes new pipe after 100 frames
		if (frameCount % 100 == 0){
			pipes.push(new pipe());
		}
	}
	if (gameState == "gameover"){
			background(255);
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
