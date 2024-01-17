#include "stdio.h"


enum PrintProduct {
    book, jurnal, news, papper
};

float search_area(float w, float h) {
    return w * h;
}

float search_perimetr(float w, float h){
    return w*2 + h*2;
}

struct Rectangle {
    float width;
    float height;
    float start_pos_x;
    float start_pos_y;
    float area;
    float perimetr;
};
struct All_numbs {
    unsigned int als: 3;
};
union mp3 {
    struct All_numbs alls;
    struct {
        unsigned int play: 1;
        unsigned int pause: 1;
        unsigned int record: 1;
    } tmp;
};


int main() {
    char status[2][4] = {"Off", "On"};
    enum PrintProduct product = news;
    printf("news-%d\n", product);
    //create rectangle with width=10 and height = 20
    struct Rectangle rec1 = {10, 20, 0, 0};
    rec1.area = search_area(rec1.width, rec1.height);
    rec1.perimetr = search_perimetr(rec1.width, rec1.height);
    printf("Area of rect = %f\n", rec1.area);
    int num;
    scanf("%x", &num);
    struct All_numbs mp = {num};
    union mp3 mp3;
    mp3.alls = mp;
    printf("play-%s\npause-%s\nrecord-%s\n", status[mp3.tmp.play],status[mp3.tmp.pause],status[mp3.tmp.record]);
    return 0;
}