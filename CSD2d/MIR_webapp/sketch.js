const model_url = 'https://cdn.jsdelivr.net/gh/ml5js/ml5-data-and-models/models/pitch-detection/crepe/';
// loading model from github, thanks to the CodingTrain <3
let mic;
let pitch;
let beginFreq = 0;
let freq = 0;
let gameStarted = false;
let displayText = "Press spacebar to start game, press q to quit";

function setup(){
	audioContext = new AudioContext();
 	let cnv = createCanvas(windowWidth, windowHeight);
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
	text(displayText, width / 2, height - 150);
	begin();
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
		gameStarted = false;
  } else if (keyCode === 32){
		setBeginFreq(freq);
    gameStarted = true;
		displayText = "";
	}
}

function setBeginFreq(freq){
	if (gameStarted == false){
		beginFreq = freq;
		console.log("Begin frequency is ", beginFreq);
	} else if (gameStarted == true){	
		return beginFreq;
	}
}
