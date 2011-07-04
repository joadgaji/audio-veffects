#include "PCenter.h"


pCenter::pCenter(int wd){
	setup(wd);
}

//--------------------------------------------------------------
void pCenter::setup(int wd){
	counter = 0;
	wd2 = ofGetWidth();
	int screeni = ofGetWidth() / 2;
	seqx1 = screeni;
	seqx2 = screeni + 400;
	seqx3 = screeni + 800;
	seqx4 = screeni + 1200;
	seqy1 = 7;
	ofSetCircleResolution(50);
	ofBackground(0,0,0);
	bSmooth = false;
	ofSetWindowTitle("graphics example");
	

	ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
}

//--------------------------------------------------------------
void pCenter::update(){
	counter = counter + 0.033f;
	//if(seqx1 < 800)
	//{
		seqx1 = ((seqx1 + seqy1 - (wd2/2-100)) % 1600) + (wd2/2-100);
		seqx2 = ((seqx1 + 400 + seqy1 - (wd2/2-100)) % 1600) + (wd2/2-100);
		seqx3 = ((seqx1 + 800 + seqy1 - (wd2/2-100)) % 1600) + (wd2/2-100);
		seqx4 = ((seqx1 + 1200 + seqy1 - (wd2/2-100)) % 1600) + (wd2/2-100);
	//}else{
	//	seqy1 = seqy1 + 10;
	//}
	//
}

//--------------------------------------------------------------
void pCenter::draw(){

	//--------------------------- circles
	//let's draw a circle:
	ofSetColor(255,250,250);
	float radius = 50 + 10 * sin(counter);
	ofFill();		// draw "filled shapes"
	//ofCircle(800,200,80);

	// now just an outline
	//ofNoFill();
	//ofSetColor(0xCCCCCC);
	//ofCircle(100,400,80);

	// use the bitMap type
	// note, this can be slow on some graphics cards
	// because it is using glDrawPixels which varies in
	// speed from system to system.  try using ofTrueTypeFont
	// if this bitMap type slows you down.
	ofSetColor(0x00000);
	ofDrawBitmapString("circle", 75,500);

	//--------------------------- Dray circle smooth
	int wr = 800 - seqx1;
	//ofCircle(wr,200,80);
	ofSetColor(0x112CF7);
	ofRect(seqx1,0,200,768);
	
	ofSetColor(0x112CF7);
	ofRect(seqx3,0,200,768);
	ofSetColor(0xFFFFFF);
	
	ofSetColor(0x112CF7);
	ofRect(wd2 - seqx1 -200 ,0,200,768);
	ofSetColor(0xFFFFFF);
	
	ofSetColor(0x112CF7);
	ofRect(wd2 - seqx3 -200 ,0,200,768);
	ofSetColor(0xFFFFFF);
	
	

	ofSetColor(0xFFFFFF);
	ofRect(seqx2,0,200,768);
	ofRect(seqx4,0,200,768);
	ofRect(wd2 - seqx2 - 200,0,200,768);
	ofRect(wd2 - seqx4 - 200,0,200,768);
	ofEllipse(ofGetWidth()/2,ofGetHeight()/2,700,400);
	ofSetColor(0x121212);
	ofTriangle(100,100,1000,1000, 1200,1200);
	//ofRect(204,0,205,768);
	//ofRect(612,0,205,768);

	/*if(seqx1 >= 800)
	{
		ofCircle(700,500,40);
		ofSetColor(0xFFFFFF);
		int wr2 = 700 - seqy1;
		ofCircle(wr2,500,40);
		ofRect(wr2,460,seqy1,80);
	}
	*/

	/*--------------------------- rectangles
	ofFill();
	for (int i = 0; i < 200; i++){
		ofSetColor((int)ofRandom(0,255),(int)ofRandom(0,255),(int)ofRandom(0,255));
		ofRect(ofRandom(250,350),ofRandom(350,450),ofRandom(10,20),ofRandom(10,20));
	}
	ofSetColor(0x000000);
	ofDrawBitmapString("rectangles", 275,500);

	//---------------------------  transparency
	ofSetColor(0x00FF33);
	ofRect(400,350,100,100);
	// alpha is usually turned off - for speed puposes.  let's turn it on!
	ofEnableAlphaBlending();
	ofSetColor(255,0,0,127);   // red, 50% transparent
	ofRect(450,430,100,33);
	ofSetColor(255,0,0,(int)(counter * 10.0f) % 255);   // red, variable transparent
	ofRect(450,370,100,33);
	ofDisableAlphaBlending();

	ofSetColor(0x000000);
	ofDrawBitmapString("transparency", 410,500);

	//---------------------------  lines
	// a bunch of red lines, make them smooth if the flag is set

	if (bSmooth){
		ofEnableSmoothing();
	}

	ofSetColor(0xFF0000);
	for (int i = 0; i < 20; i++){
		ofLine(600,300 + (i*5),800, 250 + (i*10));
	}

	if (bSmooth){
		ofDisableSmoothing();
	}

	ofSetColor(0x000000);
	ofDrawBitmapString("lines\npress 's' to toggle smoothness", 600,500);
	*/

}

//--------------------------------------------------------------
int* pCenter::getPositions(int x1, int y1){
	int arreglo[8] = {0,200,400,600,800,900,1000,1200};
	for(int i = 0; i < ARRAYSIZE(arreglo); i++){
		arreglo[i] = ((x1 + 200 + y1 - (wd2/2-200)) % 1600) + (wd2/2-200);
	}
	return arreglo;

}
//--------------------------------------------------------------
void pCenter::keyPressed  (int key){
	if (key == 's'){
		seqy1 = seqy1 + 5;
		
	}
	if(key == 'd' && seqy1 > 5){
		seqy1 = seqy1 - 5;
		
		
	}
	
}

//--------------------------------------------------------------
void pCenter::keyReleased  (int key){

}

//--------------------------------------------------------------
void pCenter::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void pCenter::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void pCenter::mousePressed(int x, int y, int button){
}


//--------------------------------------------------------------
void pCenter::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void pCenter::windowResized(int w, int h){

}
