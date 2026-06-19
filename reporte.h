#ifndef REPORTE_H
#define REPORTE_H

// ============================================================
//  reporte.h — Generador de reporte en formato PDF
//  Requisito 5b (10 pts)
//
//  Estrategia: genera un archivo HTML con todos los datos
//  estructurados y estilos de impresion (@media print).
//  El usuario lo abre en el navegador y usa Ctrl+P para
//  exportar como PDF — sin dependencias externas.
//
//  Adicionalmente genera un archivo .ps (PostScript) puro
//  que cualquier visor de PDF puede convertir directamente.
// ============================================================

#include <vector>
#include <string>
#include "../include/cliente.h"
#include "../include/ordenacion.h"
using namespace std;

// ── Reporte HTML (abre en navegador → imprimir → PDF) ────────
// Proposito : Genera un archivo HTML con tabla de keyframes,
//             reporte comparativo de ordenacion y estadisticas.
//             Incluye estilos @media print para impresion.
// Parametros: v             - vector de Keyframes
//             rep           - ReporteComparativo (puede ser
//                             vacio si no se ordeno aun)
//             nombreArchivo - ruta del HTML a generar
//                             ej: "data/reporte.html"
void generarReporteHTML(const vector<Keyframe>& v,
                         const ReporteComparativo& rep,
                         const string& nombreArchivo);

// ── Reporte PDF minimalista via PostScript ────────────────────
// Proposito : Genera un archivo .ps con el listado de
//             keyframes en formato tabular. Se puede
//             convertir a PDF con ps2pdf o GhostScript.
// Parametros: v             - vector de Keyframes
//             nombreArchivo - ruta del .ps  ej: "data/reporte.ps"
void generarReportePS(const vector<Keyframe>& v,
                       const string& nombreArchivo);

// ── Menu de generacion de reporte ─────────────────────────────
// Proposito : Pregunta al usuario que formato prefiere,
//             genera el archivo y muestra las instrucciones
//             para abrirlo / convertirlo a PDF.
// Parametros: v   - vector de Keyframes
//             rep - ReporteComparativo con metricas
void menuGenerarReporte(const vector<Keyframe>& v,
                         const ReporteComparativo& rep);

#endif
