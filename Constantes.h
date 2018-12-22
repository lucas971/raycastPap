#pragma once
#ifndef HEADER_CONSTANTES_H
#define HEADER_CONSTANTES_H

const double VIEW_ANGLE_HORIZONTAL = 40.0; //FOV horizontal
const double VIEW_ANGLE_VERTICAL = 27.0; //FOV vertical
const int SCREEN_WIDTH = 30; //Résolution horizontale
const int SCREEN_HEIGHT = 30; //Résolution verticale
const double ANGLE_STEP_HORIZONTAL = VIEW_ANGLE_HORIZONTAL / SCREEN_WIDTH;
const double ANGLE_STEP_VERTICAL = VIEW_ANGLE_VERTICAL / SCREEN_WIDTH;
const int N_SCENE_OBJECTS = 5; //Doit correspondre au nombre exact de "Shape" dans la scène.
const double SCENE_DEPTH = 20; //Profondeur de la scène
const double SCENE_HEIGHT = 20; //Hauteur de la scène
const double SCENE_WIDTH = 20; //Largeur de la scène
#endif // !HEADER_CONSTANTES_H
