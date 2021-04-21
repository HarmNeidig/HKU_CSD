(
x = {
	arg lpf = 600, freq= 440;
	var exitator = LPF.ar((WhiteNoise.ar(Impulse.kr(0.5))), lpf);

	DynKlank.ar(`[[1.0,2.35,5.424,6.46],
		[1.0,2.35,5.424,6.46],
		[1.0,2.35,5.424,6.46]], exitator, freq , 0, 660/freq)*0.01!2
}.play
)

x.set(\lpf, 1000, \freq, 200)

