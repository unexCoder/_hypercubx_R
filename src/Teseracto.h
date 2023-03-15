//
//  Teseracto.h
//  init_mesh
//
//  Created by Luigi Tamagnini on 08/09/2021.
//
#pragma once
#include <stdio.h>
#include "ofMain.h"

#ifndef Teseracto_h
#define Teseracto_h

//This is the data for the vertices, which keeps the data as simple as possible:
static GLfloat vdata[16][3] = {
    {-0.5f,  -0.5f,  -0.5f},
    {0.5f,  -0.5f,  -0.5f},
    {0.5f,  -0.5f,  0.5f},
    {-0.5f,  -0.5f,  0.5f},
    {-0.5f,  0.5f,  -0.5f},
    {0.5f,  0.5f,  -0.5f},
    {0.5f,  0.5f,  0.5f},
    {-0.5f,  0.5f,  0.5f},
//
    {-1.0f,  -1.0f,  -1.0f},
    {1.0f,  -1.0f,  -1.0f},
    {1.0f,  -1.0f,  1.0f},
    {-1.0f,  -1.0f,  1.0f},
    {-1.0f,  1.0f,  -1.0f},
    {1.0f,  1.0f,  -1.0f},
    {1.0f,  1.0f,  1.0f},
    {-1.0f,  1.0f,  1.0f}
};
    
//data for the indices, representing the index of the vertices
//that are to be connected
static GLint indices[32][2] = {
    {0,1},{1,2},{2,3},{3,0},
    {4,5},{5,6},{6,7},{7,4},
    {0,4},{1,5},{2,6},{3,7},
    {8,9},{9,10},{10,11},{11,8},
    {12,13},{13,14},{14,15},{15,12},
    {8,12},{9,13},{10,14},{11,15},
    {4,12},{5,13},{6,14},{7,15},
    {0,8},{1,9},{2,10},{3,11}
};

static GLint indices_f[36][3] = {
    {0,1,2},{2,3,0},
    {4,5,6},{6,7,4},
    {0,1,4},{4,5,1},
    {2,6,7},{2,3,7},
    {1,2,5}, {2,5,6},
    {0,3,4},{3,4,7},
    //
    {0,1,8},{1,8,9},
    {1,2,9},{10,2,9},
    {2,3,10},{3,10,11},
    {3,11,0},{11,0,8},
    //
    {4,5,12},{5,12,13},
    {5,6,13},{14,6,13},
    {6,7,14},{7,14,15},
    {7,15,4},{15,4,12},
    //
    {0,4,12},{0,12,8},
    {3,7,15},{3,15,11},
    {1,5,13},{1,13,9},
    {2,6,14},{2,14,10}
};

class Teseracto {
    
public:
    Teseracto();
    ofVboMesh vbomesh;
    ofVboMesh filled;
    ofVbo vbo,vboF;
    void setup();
    void update();
    void draw();
    void draw(int mode, float elem);
    void setGlobalColor(ofFloatColor c);
};
#endif /* Teseracto_h */
