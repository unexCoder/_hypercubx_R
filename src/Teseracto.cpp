//
//  teseracto.cpp
//  init_mesh
//
//  Created by Luigi Tamagnini on 08/09/2021.
//

#include "Teseracto.h"
#include "ofMain.h"

Teseracto::Teseracto() {}

void Teseracto::setup() {
    //add vertices to our mesh and add a color at each vertex:
    for (int i = 0; i<16; ++i) {
        vbomesh.addVertex( ofVec3f( vdata[i][0], vdata[i][1], vdata[i][2] ));
        vbomesh.addColor(ofFloatColor(1.0f));
        filled.addVertex( ofVec3f( vdata[i][0], vdata[i][1], vdata[i][2] ));
        filled.addColor(ofFloatColor(1.0f));
    }
    for (int i = 0; i<32; ++i) {
        vbomesh.addIndex(indices[i][0]);
        vbomesh.addIndex(indices[i][1]);
    }
    for (int i = 0; i<36; ++i) {
        filled.addIndex(indices_f[i][0]);
        filled.addIndex(indices_f[i][1]);
        filled.addIndex(indices_f[i][2]);
    }
    vbo = vbomesh.getVbo();
    vboF = filled.getVbo();
}

void Teseracto::update() {}

void Teseracto::draw() {
    vbo.drawElements( GL_LINES, vbo.getNumIndices());
};

void Teseracto::draw(int mode, float elem) {
    int numElements = ofMap(elem, 0.0f, 1.0f, 0, vbo.getNumIndices());
    int numElementsF = ofMap(elem, 0.0f, 1.0f, 0, vboF.getNumIndices());
    switch (mode) {
        case 0:
            vbo.drawElements( GL_LINES, numElements);
            break;
        case 1:
            vboF.drawElements( GL_TRIANGLES, numElementsF);
            break;

        default:
            break;
    }
};

void Teseracto::setGlobalColor(ofFloatColor c) {
    int vertex = vbo.getNumVertices();
    vector<ofFloatColor> colores;
    colores.resize(vertex);
    for (int i = 0; i < vertex; i++) {
        colores[i] = c;
    }
    vbo.setColorData( &colores[0], colores.size(),GL_DYNAMIC_DRAW);
    vboF.setColorData( &colores[0], colores.size(),GL_DYNAMIC_DRAW);
}
