#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("Insta");

	ofBackground(239);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(ofGetFrameNum() * 0.1);
	ofRotateY(ofGetFrameNum() * 0.25);

	float radius = 400;
	ofIcoSpherePrimitive ico_sphere = ofIcoSpherePrimitive(radius, 3);
	vector<ofMeshFace> triangles = ico_sphere.getMesh().getUniqueFaces();

	for (int i = 0; i < triangles.size(); i++) {

		ofPoint average = (triangles[i].getVertex(0) + triangles[i].getVertex(1) + triangles[i].getVertex(2)) / 3;

		float noise_value = ofNoise(average.x * 0.003, average.y * 0.003, average.z * 0.003, ofGetFrameNum() * 0.007);
		if (noise_value > 0.5) {

			vector<ofPoint> vertices;
			for (int j = 0; j < 3; j++) {

				ofPoint point(triangles[i].getVertex(j).x, triangles[i].getVertex(j).y, triangles[i].getVertex(j).z);
				vertices.push_back(point);
			}

			ofFill();
			ofSetColor(39);
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape();

			ofNoFill();
			ofSetColor(239);
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape();
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}