#include "ofMain.h"
#include "ofApp.h"


//========================================================================
int main( ){

#ifdef OF_TARGET_OPENGLES                    // <-------- setup the GL context
    ofGLESWindowSettings settings;
    settings.glesVersion=2;
#else
    ofGLWindowSettings settings;
    settings.setGLVersion(4,1);
    settings.setSize(1920, 1080);
#endif
    ofCreateWindow(settings);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
