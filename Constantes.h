#pragma once
#ifndef HEADER_CONSTANTES_H
#define HEADER_CONSTANTES_H

const double VIEW_ANGLE_HORIZONTAL = 40.0; //FOV horizontal
const double VIEW_ANGLE_VERTICAL = 27.0; //FOV vertical
const int SCREEN_WIDTH = 30; //R�solution horizontale
const int SCREEN_HEIGHT = 30; //R�solution verticale
const double ANGLE_STEP_HORIZONTAL = VIEW_ANGLE_HORIZONTAL / SCREEN_WIDTH;
const double ANGLE_STEP_VERTICAL = VIEW_ANGLE_VERTICAL / SCREEN_WIDTH;
const int N_SCENE_OBJECTS = 5; //Doit correspondre au nombre exact de "Shape" dans la sc�ne.
const double SCENE_DEPTH = 20; //Profondeur de la sc�ne
const double SCENE_HEIGHT = 20; //Hauteur de la sc�ne
const double SCENE_WIDTH = 20; //Largeur de la sc�ne
#endif // !HEADER_CONSTANTES_H
