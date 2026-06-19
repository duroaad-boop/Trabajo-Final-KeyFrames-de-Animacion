#ifndef CRUD_H
#define CRUD_H

// ============================================================
//  crud.h — Operaciones CRUD sobre el vector de Keyframes
// ============================================================

#include <vector>
#include <string>
#include "../include/cliente.h"
using namespace std;

void agregarKeyframe   (vector<Keyframe>& v);
void eliminarKeyframe  (vector<Keyframe>& v);
void modificarKeyframe (vector<Keyframe>& v);
void listarTodos       (const vector<Keyframe>& v);
void listarPorEscena   (const vector<Keyframe>& v);
void mostrarKeyframe   (const Keyframe& k);
int  generarNuevoId    (const vector<Keyframe>& v);

#endif
