#!/usr/bin/env python3
# Versión ultra simple: lee results.csv (asumido en el directorio padre de este script)
# y genera un gráfico tiempo vs n para cada algoritmo, guardando results_plot.png

import csv, os
import matplotlib.pyplot as plt

csv_file = os.path.join(os.path.dirname(__file__), '..', 'results.csv')
out_path = os.path.join(os.path.dirname(__file__), '..', 'results_plot.png')

metodos = {}
with open(csv_file, newline='') as f:
    reader = csv.reader(f)
    next(reader, None)  # cabecera
    for row in reader:
        if len(row) < 4:
            continue
        metodo = row[0]
        try:
            n = int(row[1])
            prom = float(row[2])
        except ValueError:
            continue
        metodos.setdefault(metodo, []).append((n, prom))

for m in metodos:
    metodos[m].sort(key=lambda x: x[0])

preferencia = ['Quick', 'Merge', 'Radix']
algoritmos = [a for a in preferencia if a in metodos] + [a for a in metodos.keys() if a not in preferencia]
ns_ordenados = sorted({n for datos in metodos.values() for n, _ in datos})

# Construir un dict para acceso rápido: valores[alg][n] = promedio
valores = {alg: {n: prom for n, prom in metodos[alg]} for alg in algoritmos}

# Parámetros de barras
m = len(algoritmos)
bar_width = 0.8 / m
xs_base = list(range(len(ns_ordenados)))  # 0,1,2 para tus 3 tamaños

for idx_alg, alg in enumerate(algoritmos):
    desplazamiento = -0.4 + bar_width/2 + idx_alg * bar_width
    xs = [x + desplazamiento for x in xs_base]
    ys = [valores[alg].get(n, 0.0) for n in ns_ordenados]
    plt.bar(xs, ys, width=bar_width, label=alg)

# Etiquetas eje X centradas en cada grupo
plt.xticks(xs_base, [f"{n:,}".replace(',', '.') for n in ns_ordenados])
plt.xlabel('n')
plt.ylabel('Tiempo (ms)')
plt.title('Tiempo vs n (barras)')
plt.grid(axis='y', alpha=0.3, linestyle='--')
plt.legend()
plt.tight_layout()
plt.savefig(out_path, dpi=130)
print('Plots done')

