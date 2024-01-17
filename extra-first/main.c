#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqoai.h>

#pragma pack(push, 1)
typedef struct {
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
} header;
#pragma pack(pop)
#pragma pack(push, 1)

typedef struct {
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} info;

#pragma pack(pop)
header bitmapFileHeader;
info bitmapInfoHeader;

int width = 0, height = 0, stage = 0;

typedef struct {
    unsigned char red, green, blue;
} pixel;


FILE *check_and_open_file(char *path){
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        fclose(file);
        exit(1);
    }
    return file;
}

pixel **readFile(char *path) {
    FILE *file = check_and_open_file(path);
    fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    pixel **pixels = malloc(sizeof(pixel *) * (height));
    if (bitmapFileHeader.bfType != 0x4D42) {
        fclose(file);
        exit(1);
    }
    unsigned char trash[3];
    fread(&bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    fseek(file, bitmapFileHeader.bfOffBits, SEEK_SET);
    int ptrash = width%4;
    height = bitmapInfoHeader.biHeight;
    width = bitmapInfoHeader.biWidth;
    for (int i = 0; i < height; i++) {
        pixels[i] = malloc(sizeof(pixel) * (width));
        for (int j = 0; j < width; j++) {
            fread(&pixels[i][j], sizeof(pixel), 1, file);
        }
        fwrite(0, ptrash, 1, file);
    }
    fclose(file);
    return pixels;
}

void createFileForStage(pixel **pixels, char *path) {
    char *way_to_save = malloc(sizeof(char) * 100);
    sprintf(way_to_save, "%s\\%s%d%s", path, "tier-", stage, ".bmp");
    printf("Create: %s", way_to_save);
    FILE *file = fopen(way_to_save, "wb");
    fwrite(&bitmapFileHeader, sizeof(header), 1, file);
    fwrite(&bitmapInfoHeader, sizeof(info), 1, file);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fwrite(&pixels[i][j], sizeof(pixel), 1, file);
        }
        fwrite(0, 1, width%4*3, file);
    }
    fclose(file);
}


int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Wrong input");
        return 1;
    }
    char *path;
    char *path_to_save;
    int max_tier = -10;
    int dump_save = 1;
    int count_to_save = 0;
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--input")) {
            path = argv[i + 1];
        } else if (!strcmp(argv[i], "--output")) {
            path_to_save = argv[i + 1];
        } else if (!strcmp(argv[i], "--max_iter"))
            max_tier = atoi(argv[i + 1]);
        else if (!strcmp(argv[i], "--dump_freq"))
            count_to_save = atoi(argv[i + 1]);
    }
    //path = "123.bmp";
    //path_to_save = "C:\\Users\\Danil\\Desktop\\test";
    pixel **pixels = readFile(path);
    char enter = '\n';
    while (scanf("%c", &enter)) {
        if (enter != '\n' || max_tier == stage) {
            break;
        }
        stage++;
        count_to_save++;
        if (count_to_save == dump_save) {
            createFileForStage(pixels, path_to_save);
            count_to_save = 0;
        }
    }
}