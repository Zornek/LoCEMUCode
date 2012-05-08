#!/bin/sh
mkdir build || echo "Carpeta creada"
cd build || echo "Entrando en la carpeta"
cmake ../ || echo "Proyecto preparado"
echo "Empezando a crear"
make
sudo make install
