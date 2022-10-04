//  Created by Marco Bertagnolli on 03/10/22.

#include "raspi-monitor.h"

char banner[] = "                       _                       _                     __   ______   \n                      (_)                     (_)_                  /  | / __   |  \n  ____ ____  ___ ____  _ ___ ____   ___  ____  _| |_  ___   ____   /_/ || | //| |  \n / ___) _  |/___)  _ \\| (___)    \\ / _ \\|  _ \\| |  _)/ _ \\ / ___)    | || |// | |  \n| |  ( ( | |___ | | | | |   | | | | |_| | | | | | |_| |_| | |        | ||  /__| |  \n|_|   \\_||_(___/| ||_/|_|   |_|_|_|\\___/|_| |_|_|\\___)___/|_|        |_(_)_____/   \n                |_|                                                                \n";


// FILE PARSER

void openVpnFileParser(char completePath[]){
    FILE *vpnLogFile;
    vpnLogFile = fopen(completePath, "r");
    
    char fileText[255];
    
    if(vpnLogFile == NULL){
        menu("error: cant find vpn log file");
    }
    
    // iterate throught file
    
    
    printf("%s", fileText);
    
    fclose(vpnLogFile);

    return;
}


// MENU FUNCTIONS

void config(){
    system("clear");
    printf("%s", banner);
    printf("\n\nconfig> ");
    
    int menuConfOption;
    scanf("%d", &menuConfOption);
    
    openVpnFileParser("/var/log/openvpn/status.log");
    
    return;
}

void serverStatus(){
    system("clear");
    printf("%s", banner);
    printf("\n\nserverStatus> ");
    
    int menuServSOption;
    scanf("%d", &menuServSOption);
    
    return;
}

void serverInfo(){
    system("clear");
    printf("%s", banner);
    printf("\n\nserverInfo> ");
    
    int menuServIOption;
    scanf("%d", &menuServIOption);
    
    return;
    
}

void updateCheck(){
    menu("Alredy updated!");
    
    return;
}

int menu(char message[]){
    system("clear");
    printf("%s", banner);
    printf("\n1.Configuration      2.Server start/stop  \n3.Server info        4.Ceck update  \n\n");
    printf("%s", message);
    printf("\n> ");
    
    int menuOption;
    scanf("%d", &menuOption);
    
    switch(menuOption){
        case 1:
            config();
            break;
        case 2:
            serverStatus();
            break;
        case 3:
            serverInfo();
            break;
        case 4:
            updateCheck();
            break;
        case 0:
            exit(1);
            break;
        default:
            menu("Inexistring option");
    }
}

void main(){
    int exitCode = menu("Welcome!");
    printf("\nBye! => exit code: %d\n", exitCode);
}
