#include <stdio.h>
struct location
{
    float latitude;
    float longitude;
    char city[64];
    char street[128];
    char country[64];
};

struct person
{
    int age;
    char name[64];
    float rotation;
    unsigned int bit : 4;
    struct location location;
};

int main(void)
{
    struct person student_1 = {.age = 17, .name[0] = 'K', .rotation = 3.14, .bit = 15}; 
    struct location student_1_loc = {.latitude = 28.123145, .longitude = 9.8204922};
    student_1.location = student_1_loc;
    
    printf("%d\n", student_1.age);
    printf("%s\n", student_1.name);
    printf("%f\n", student_1.rotation);
    printf("%d\n", student_1.bit);
    printf("%f\n", student_1.location.latitude);
    printf("%f\n", student_1.location.longitude);
    return 0;
}
