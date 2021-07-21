const model_url = 'https://cdn.jsdelivr.net/gh/ml5js/ml5-data-and-models/models/pitch-detection/crepe/';
// loading model from github, thanks to the CodingTrain <3
let mic;
let pitch;
let freq = 0;

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
 	text(freq.toFixed(2), width / 2, height - 150);
	fill(255);
 	textAlign(CENTER, CENTER);
 	textSize(32);
	text("Hz", width / 2, height - 100);
}

function modelLoaded() {
  console.log('model loaded');
  pitch.getPitch(gotPitch);
}

function gotPitch(error, frequency) {
  if (error) {
    console.error(error);
  } else {
    //console.log(frequency);
    if (frequency) {
      freq = frequency;
    }
    pitch.getPitch(gotPitch);
  }
}
