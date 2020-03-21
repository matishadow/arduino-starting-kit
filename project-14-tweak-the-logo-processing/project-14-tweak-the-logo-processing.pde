import processing.serial.*;
Serial myPort;

PImage logo;
int backgroundColor = 0;

void setup() {
	size(1, 1);
	surface.setResizable(true);
	colorMode(HSB, 255);

	logo = loadImage("https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fi.ytimg.com%2Fvi%2FwDgjdXtrnzM%2Fmaxresdefault.jpg");
	surface.setSize(logo.width, logo.height);

	println("Available serial ports:");
	println(Serial.list());

	myPort = new Serial(this, Serial.list()[0], 9600);

}

void draw() {
	if (myPort.available() > 0){
		backgroundColor = myPort.read();
		println(backgroundColor);
	}

	background(backgroundColor, 255, 255);
	image(logo, 0, 0);
}