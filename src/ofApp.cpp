#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){



	ofDirectory dir;
	dir.listDir("imagesRaw");
	for (int i = 0; i < dir.size(); i++){
		ofImage img;
		images.push_back(img);
		images.back().load(dir.getPath(i));
		//cout << dir.getPath(i) << endl;
		cout << "loaded " << i << " of " << dir.size() << endl;


		// Constrain Aspect Ratio
		ofRectangle targetDim(0, 0,  800, 640);
		ofRectangle imageDim(0, 0, images.back().getWidth(), images.back().getHeight());

		// Resize Images

		targetDim.scaleTo(imageDim);
		//cout << targetDim << endl;
		images.back().crop(targetDim.x, targetDim.y, targetDim.width, targetDim.height);
		images.back().resize(800, 640);
	}
	
    average.allocate(800,640, OF_IMAGE_COLOR);
    
    for (int i = 0; i < 800; i++){
        for (int j = 0; j < 640; j++){
            
            // average:
            // (1) add all values up
            float sumRed = 0;
            float sumBlue = 0;
            float sumGreen = 0;
            for (int k = 0; k < images.size(); k++){
                ofColor color = images[k].getColor(i,j);
                sumRed += color.r;
                sumGreen += color.g;
                sumBlue += color.b;
            }
            // (2) divide
            sumRed /= (float)images.size();
            sumBlue /= (float)images.size();
            sumGreen /= (float)images.size();
            average.setColor(i,j, ofColor(sumRed, sumGreen, sumBlue));
            
            
        }
    }
    
    average.update();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
average.draw(0, 0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
