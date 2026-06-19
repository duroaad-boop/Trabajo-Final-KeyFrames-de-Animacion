#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <vector>
#include "../include/cliente.h"
using namespace std;

// ── Busqueda secuencial por objeto ─────────────
void buscarPorObjeto(const vector<Keyframe>& v,
                     const string& objeto);
// ── Busqueda binaria ITERATIVA ────────────────────────
ResultadoBusqueda buscarBinariaIterativa(
    const vector<Keyframe>& v, int frameBuscado);

// ── Busqueda binaria RECURSIVA ───────────────────────
ResultadoBusqueda buscarBinariaRecursiva(
    const vector<Keyframe>& v, int frameBuscado,
    int inicio, int fin, int& llamadas);

// ── Menu de busqueda binaria (iterativa vs recursiva) ─────────

void menuBusquedaBinaria(const vector<Keyframe>& v);

// ── Mostrar resultado de busqueda ─────────────────────────────

void mostrarResultadoBusqueda(const vector<Keyframe>& v,
                               const ResultadoBusqueda& res,
                               const string& metodo);

#endif
