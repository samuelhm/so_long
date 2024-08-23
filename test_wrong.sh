#!/bin/bash

# Verificar si el directorio ./maps existe
if [ ! -d "./maps/maps_error" ]; then
  echo "El directorio ./maps/maps_error no existe."
  exit 1
fi

# Iterar sobre todos los archivos en el directorio ./maps
for file in ./maps/maps_error/*; do
  # Verificar si es un archivo regular (evitar directorios u otros tipos de archivos)
  if [ -f "$file" ]; then
    echo "Ejecutando: vals ./so_long $file"
    $vals ./so_long "$file"
  else
    echo "$file no es un archivo regular."
  fi
done
