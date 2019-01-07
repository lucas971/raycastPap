#pragma once
#ifndef HEADER_CONSTANTES_H
#define HEADER_CONSTANTES_H

const double VIEW_ANGLE_HORIZONTAL = 40.0; //FOV horizontal
const double VIEW_ANGLE_VERTICAL = 27.0; //FOV vertical
const int SCREEN_WIDTH = 1280; //Résolution horizontale
const int SCREEN_HEIGHT = 720; //Résolution verticale
const double ANGLE_STEP_HORIZONTAL = VIEW_ANGLE_HORIZONTAL / SCREEN_WIDTH;
const double ANGLE_STEP_VERTICAL = VIEW_ANGLE_VERTICAL / SCREEN_WIDTH;
const int N_SCENE_OBJECTS = 7+1; //Doit correspondre au nombre exact de "Shape" dans la scène.
const double SCENE_DEPTH = 1; //Profondeur de la scène
const double SCENE_HEIGHT = 1; //Hauteur de la scène
const double SCENE_WIDTH = 1; //Largeur de la scène
#endif // !HEADER_CONSTANTES_H
