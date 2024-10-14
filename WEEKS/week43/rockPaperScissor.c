#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

struct choices {
    int rock,paper, scissors;
};

int main(int argc, char *argv[])
{
    int userChoice;
    struct choices handSign;
    //the timer/randomizer for the winning.
int i = 0;	    
	    while(i < 10){
	        i++;
	        sleep(1);
	        printf(%i, i);
	        fflush(stdout);
	        if(i == 9){
	            i = 0;
	        }
	    }
	    
	    printf(Pick your stand:n 0 = Rockn 1 = Papern 2 = Scissorsn);
	    scanf( %c, &userChoice);
	    
	    
	    
} 
