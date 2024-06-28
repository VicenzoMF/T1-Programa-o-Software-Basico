#include <stdio.h>
#include "lib_ppm.h"

void aplicar_zoom(struct image_s *imagem, struct image_s *imagem_zoom) {
    int i, j, x, y;
    new_ppm(imagem_zoom, imagem->width * 3, imagem->height * 3);
    for (j = 0; j < imagem->height; j++) {
        for (i = 0; i < imagem->width; i++) {
            struct pixel_s *pixel = &imagem->pix[j * imagem->width + i];
            for (y = 0; y < 3; y++) {
                for (x = 0; x < 3; x++) {
                    struct pixel_s *pixel_zoom = &imagem_zoom->pix[(j * 3 + y) * imagem_zoom->width + (i * 3 + x)];
                    if (x == 0) { // Coluna vermelha
                        if (pixel->r >= 0 && pixel->r <= 74) {
                            pixel_zoom->r = 0;
                        } else if (pixel->r >= 75 && pixel->r <= 134) {
                            pixel_zoom->r = (y == 1) ? 255 : 0;
                        } else if (pixel->r >= 135 && 255 <= 179) {
                            pixel_zoom->r = (y == 1) ? 0 : 255;
                        } else if (pixel->r >= 180 && pixel->r <= 255) {
                            pixel_zoom->r = 255;
                        }
                    } else if (x == 1) { // Coluna verde
                        if (pixel->g >= 0 && pixel->g <= 74) {
                            pixel_zoom->g = 0;
                        } else if (pixel->g >= 75 && pixel->g <= 134) {
                            pixel_zoom->g = (y == 1) ? 255 : 0;
                        } else if (pixel->g >= 135 && pixel->g <= 179) {
                            pixel_zoom->g = (y == 1) ? 0 : 255;
                        } else if (pixel->g >= 180 && pixel->g <= 255) {
                            pixel_zoom->g = 255;
                        }
                    } else if (x == 2) { // Coluna azul
                        if (pixel->b >= 0 && pixel->b <= 74) {
                            pixel_zoom->b = 0;
                        } else if (pixel->b >= 75 && pixel->b <= 134) {
                            pixel_zoom->b = (y == 1) ? 255 : 0;
                        } else if (pixel->b >= 135 && pixel->b <= 179) {
                            pixel_zoom->b = (y == 1) ? 0 : 255;
                        } else if (pixel->b >= 180 && pixel->b <= 255) {
                            pixel_zoom->b = 255;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    struct image_s imagem, imagem_zoom;
    
    // Ler a imagem de entrada
    if (read_ppm("lena.ppm", &imagem) == -1) {
        fprintf(stderr, "Erro ao ler a imagem.\n");
        return 1;
    }
    
    // Aplicar o zoom
    aplicar_zoom(&imagem, &imagem_zoom);
    
    // Escrever a imagem de saída
    if (write_ppm("output.ppm", &imagem_zoom) == -1) {
        fprintf(stderr, "Erro ao escrever a imagem.\n");
        return 1;
    }
    
    // Liberar memória
    free_ppm(&imagem);
    free_ppm(&imagem_zoom);
    
    return 0;
}
