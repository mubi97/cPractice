#include <stdio.h>

float calDistance(float d, float dCovered, int trainFlag) {
    int sTrain = 0;
    
    if(trainFlag == 0) {
        sTrain = 70;
        trainFlag = 1;
    } else {
        sTrain = 50;
        trainFlag = 0;
    }
    
    int s = 80 + sTrain;
    float dCovered1 = (d/s) * 80;
    int dc = (int)d;
    if(dc <= dCovered1) {
        return d + dCovered;
    }
    
    if (dc == 0) {
        return dCovered;
    }
    
    d -= dCovered1;
    printf("%f\t", d);
    return dCovered + calDistance(d, dCovered1, trainFlag);
}

int main() {
    printf("%f\n",calDistance(100.0f, 0.0f, 0.0f));
    return 0;
}

