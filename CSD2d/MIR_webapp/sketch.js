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
let displayText = "Make a tone and press play";
var pipes = [];
var score = 0;
const pipeWidth = 20;
const pipeOpening = 400;

function pipe(){
	this.color = color('magenta');
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
		fill(this.color);
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

	this.hits = function(player){
		if (player.newY >= this.bottom||player.newY <= this.top){
			return true;
		} else {
			return false;
		}
	};

	this.set_color = function(color){
		this.color = color;
	};

	this.in_centre = function(){
		if(this.x <= WindowWidth/2+this.w && this.x >= WindowWidth/2-this.w){
			return true;
		}	else {
			return false;
		}
	};
}

function player(){
	this.x = WindowWidth/2;
	this.y = WindowHeight/2;
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
	};
}

function setup(){
	audioContext = new AudioContext();
 	let cnv = createCanvas(WindowWidth, WindowHeight);
 	textAlign(CENTER);
 	mic = new p5.AudioIn();
 	mic.start(listening);
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
		merneer = new player();
		displayText = score;
		textAlign(CENTER, LEFT);
		textSize(32);
		text(displayText, WindowWidth / 2, height - 150);
		var freqVariance = freq - beginFreq;
		merneer.update(freqVariance);
		merneer.show();
		if (frameCount % 50 == 0){
			pipes.push(new pipe());
		}
		for (var i=pipes.length-1; i>= 0; i--){
			pipes[i].show();
			pipes[i].update();
			if (pipes[i].in_centre()==true){
				console.log("in centre");
				if (pipes[i].hits(merneer)==true){
					pipes[i].set_color([255,0,0]);
					score-=1;
				} else {
					pipes[i].set_color([0,255,0]);
					score+=1;
				}
			}
			if (pipes[i].offscreen()){
				pipes.splice(i, 1);
			}
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
	if (gameState == "start"){
		beginFreq = freq;
		console.log("Begin frequency is ", beginFreq);
	} else if (gameState == "playing"){
		return beginFreq;
	}
}
