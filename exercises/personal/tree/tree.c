#include <stdio.h>

int main(int argc, char argv[]){
    
    //ask for height.
    int height;
    printf("Write height of the tree:\n");
    scanf("%i", &height);
    printf("\n");

    //for loop that will print height times of spaces and gradually decrease by 1 every time loop is run.
    for (int i = 1; i <= height; i++){//height oldugu surece bunu tekrarla
        int stars = (i * 2) - 1;//i 1 ile basliyor, 1*2 =2, 2-1 =1. soshite, i 2 olunca, ayni formula ile 2*2 = 4, 4-1 = 3. ve bu sekilde ilerliyor. Kisacasi, yildizlari, i nin her loopta artmasindan faydalaniyorum, i yi 2ye carpip -1 yapiyorumki tekil sayilardan olsunki agacin bir center'i olsun. 
        int space = height - i + 1;//Kullanicinin verdigi degerden dynamic olan "i" ile her loop eksilmeyi cogaltarak son loop ta bosluk kalmiyor, ve +1 ile stars taki -1 ile balance yapiyorum.

        for (int i = 0; i < space; i++){//bosluktan az oldugu surece print
            printf(" ");
        }

        for (int i = 0; i<stars; i++){//Starstan az oldugu surece print
            printf("^");
        }
         printf("\n");
    }

    //Root of tree
    for (int i = 0; i < (height / 2); i++){//boyun yarisi kadar koku olsun.

    for (int i = 0; i < height; i++){//boyu kadari bosluk olsun(ortasina horizontally) yetismek icin.
        printf(" ");//ortasina yetisene kadarbosluk
    }
    printf("|\n");//agacin ortasina yetisince, bu karakter koku
    }
        printf("\n");//agac bitince bir line bos birakilsin
    return 0;
}
