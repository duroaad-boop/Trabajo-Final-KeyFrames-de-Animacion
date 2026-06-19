#ifndef ORDENACION_H
#define ORDENACION_H

// ============================================================
//  ordenacion.h

//  Parametros: vector<Keyframe> por referencia o por valor
//  Retorno:    MetricaOrden con comparaciones, intercambios
//              y tiempo de ejecucion
// ============================================================

#include <vector>
#include "../include/cliente.h"
using namespace std;

// ── Bubble Sort con metricas ──────────────────────

MetricaOrden bubbleSortConMetrica(vector<Keyframe>& v);

// ── Merge Sort (intercalacion) con metricas ───────────────

MetricaOrden mergeSortConMetrica(vector<Keyframe>& v);

// ── Funcion auxiliar de Merge Sort ────────────

void merge(vector<Keyframe>& v, int izq, int med, int der,
           int& comparaciones);

// ── Funcion auxiliar recursiva de Merge Sort ─────

void mergeSort(vector<Keyframe>& v, int izq, int der,
               int& comparaciones);

// ── Reporte comparativo ──────────

ReporteComparativo reporteComparativoOrdenacion(
    const vector<Keyframe>& v);
    
// ── Mostrar reporte en pantalla ───────────────

void mostrarReporteOrdenacion(const ReporteComparativo& r);

#endif
