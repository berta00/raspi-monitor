//  Created by Marco Bertagnolli on 03/10/22.

#include "raspi-monitor.h"
#include "stdio.h"
#include "stdlib.h"


char banner[] = "                       _                       _                     __   ______   \n                      (_)                     (_)_                  /  | / __   |  \n  ____ ____  ___ ____  _ ___ ____   ___  ____  _| |_  ___   ____   /_/ || | //| |  \n / ___) _  |/___)  _ \\| (___)    \\ / _ \\|  _ \\| |  _)/ _ \\ / ___)    | || |// | |  \n| |  ( ( | |___ | | | | |   | | | | |_| | | | | | |_| |_| | |        | ||  /__| |  \n|_|   \\_||_(___/| ||_/|_|   |_|_|_|\\___/|_| |_|_|\\___)___/|_|        |_(_)_____/   \n                |_|                                                                \n";


int menu(){
    system("clear");
    printf("%s", banner);
}

void main(){
    int exitCode = menu();
    printf("\\nBye!  exit code: %d", exitCode);
}



