const model_url = 'https://cdn.jsdelivr.net/gh/ml5js/ml5-data-and-models/models/pitch-detection/crepe/';
// loading model from github, thanks to the CodingTrain <3
let mic;
let pitch;
let beginFreq = 0;
let freq = 0;
// gamestate is phase of the game
// start => playing => gameover
let gameState = "start";
let displayText = "Press spacebar to start game, press q to quit";
var pipes = []
const pipeWidth = 50;


function pipe(){
	// length of to top bar
	this.top = random(height/2);
	// length of to bottom bar
	this.bottom = random(height/2);
	this.x = width;
	// width of the bars
	this.w = 10;
	this.speed = 2;

	this.show = function(){
		fill(255);
		rect(this.x, 0, this.w, this.top);
		rect(this.x, height-this.bottom, this.w, this.bottom);
	}

	this.update = function(){
		this.x -= this.speed;
	}
}

function player(){
	this.x = 200;
	this.y = height/2;

	this.show = function(){
		this.y -= freq-beginFreq;
		fill('red');
		circle(this.x,this.y, 20);
		console.log(this.y);
	}
}

function setup(){
	audioContext = new AudioContext();
 	let cnv = createCanvas(windowWidth, windowHeight);
 	textAlign(CENTER);
 	mic = new p5.AudioIn();
 	mic.start(listening);
	pipes.push(new pipe());
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
	text(displayText, width / 2, height - 150);
	if (gameState == "start"){
		begin();
	}
	if (gameState == "playing"){
		merneer = new player();
		if (frameCount % 40 == 0){
			pipes.push(new pipe());
		}

		merneer.show();
		for (var i=0; i<pipes.length; i++){
			pipes[i].show();
			pipes[i].update();
		}
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
	if (gameState == false){
		beginFreq = freq;
		console.log("Begin frequency is ", beginFreq);
	} else if (gameState == true){
		return beginFreq;
	}
}
