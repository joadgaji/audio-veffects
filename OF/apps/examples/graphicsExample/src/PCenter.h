#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

class pCenter : public ofBaseApp{
	
	public:
		pCenter(int wd);
		void setup(int wd);
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		int *getPositions(int x1, int y1);
		
		float 	counter;
		bool	bSmooth;
		int		wd2;
		int		seqx1;
		int		seqy1;
		int		seqx2;
		int		seqx3;
		int		seqx4;
};

#endif

