#ifndef ARCHIVOS_H
#define ARCHIVOS_H

// ============================================================
//  archivos.h  — Capa de persistencia CSV
//  Unica capa que sabe que existe un archivo en disco.
// ============================================================

#include <vector>
#include <string>
#include "../include/cliente.h"
using namespace std;

// Lee el CSV y llena el vector con objetos Keyframe
void cargarKeyframes(vector<Keyframe>& v,
                     const string& nombreArchivo);

// Escribe todos los Keyframes al CSV
void guardarKeyframes(const vector<Keyframe>& v,
                      const string& nombreArchivo);

// Muestra el contenido del CSV en pantalla
void mostrarArchivoCSV(const string& nombreArchivo);
// carga automaticamente 10 registros de prueba
void seedDatos(vector<Keyframe>& v,
               const string& nombreArchivo);

#endif
