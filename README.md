# T1-Programa-o-Software-Basico

Este projeto realiza um zoom em uma imagem no formato PPM, ampliando cada pixel original em uma área de 3x3 pixels na nova imagem. O valor das cores dos novos pixels é ajustado com base na intensidade das cores do pixel original.

## Descrição do Código

O código pega uma imagem de entrada, aplica um efeito de zoom e salva a imagem resultante. Abaixo está uma descrição detalhada do funcionamento do código:

1. **Leitura da Imagem**: O programa lê a imagem de entrada (`lena.ppm`) utilizando a função `read_ppm`.
2. **Aplicação do Zoom**: A função `aplicar_zoom` amplia a imagem, criando uma nova imagem onde cada pixel da original é replicado em uma área de 3x3 pixels. As cores dos novos pixels são ajustadas com base nos valores de vermelho, verde e azul do pixel original:
   - **Coluna Vermelha**:
     - Intensidade entre 0 e 74: valor ajustado para 0.
     - Intensidade entre 75 e 134: valor central ajustado para 255, outros para 0.
     - Intensidade entre 135 e 179: valores laterais ajustados para 255, central para 0.
     - Intensidade entre 180 e 255: valor ajustado para 255.
   - **Coluna Verde**:
     - Mesmo esquema de ajuste da coluna vermelha, mas para a cor verde.
   - **Coluna Azul**:
     - Mesmo esquema de ajuste da coluna vermelha, mas para a cor azul.
3. **Escrita da Imagem**: A imagem ampliada é salva no arquivo `output.ppm` utilizando a função `write_ppm`.
4. **Liberação de Memória**: A memória alocada para as imagens é liberada antes de encerrar o programa.

## Arquivos

- `main.c`: Contém o código principal do projeto.
- `lib_ppm.h` e `lib_ppm.c`: Contêm as funções de leitura e escrita de arquivos PPM.

## Compilação e Execução

Para compilar e executar o programa, siga as instruções abaixo:

```sh
gcc main.c lib_ppm.c -o zoom
./zoom
```

## Requisitos

- GCC (ou outro compilador C compatível)
- Biblioteca padrão C

## Exemplo de Uso

1. Coloque uma imagem PPM chamada `lena.ppm` no mesmo diretório do código.
2. Compile e execute o programa.
3. O arquivo `output.ppm` será gerado com a imagem ampliada.

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).

---

Este projeto exemplifica o processamento básico de imagens e manipulação de pixels em C. É ideal para quem deseja aprender mais sobre programação gráfica e manipulação de arquivos PPM.
