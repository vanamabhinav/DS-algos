#include<stdio.h>

int main() {
    // N days 
    
    // Every day represents rainfall level

    // If it is 0, then it means no rainfall and the waterlevel decreases by some value

    // If it is not 0, then we need to add the value to the waterlevel

    // If the waterlevel increases over a certain threshold, then raise an alarm

    int rainFallPrediction[9] = {4, 6, 0, 2, 1, 8, 0, 3, 3};
    int DECREASES_BY = 4;
    int waterLevel = 0;
    int WATER_LEVEL_THRESHOLD = 10;
 
    for(int day = 0; day < 9; day++) {
        waterLevel += rainFallPrediction[day];
        if(waterLevel > WATER_LEVEL_THRESHOLD) {
            printf("THERE WILL BE A RED ALERT");
            return 0;
        }

        if(rainFallPrediction[day] == 0) {
            waterLevel -= DECREASES_BY;
        }
    }
    return 0;
}