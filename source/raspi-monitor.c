//  Created by Marco Bertagnolli on 03/10/22.

#include "raspi-monitor.h"

char banner[] = "                       _                       _                     __   ______   \n                      (_)                     (_)_                  /  | / __   |  \n  ____ ____  ___ ____  _ ___ ____   ___  ____  _| |_  ___   ____   /_/ || | //| |  \n / ___) _  |/___)  _ \\| (___)    \\ / _ \\|  _ \\| |  _)/ _ \\ / ___)    | || |// | |  \n| |  ( ( | |___ | | | | |   | | | | |_| | | | | | |_| |_| | |        | ||  /__| |  \n|_|   \\_||_(___/| ||_/|_|   |_|_|_|\\___/|_| |_|_|\\___)___/|_|        |_(_)_____/   \n                |_|                                                                \n";


// FILE PARSER

void settingFileParser(char completePath[]){
    FILE *jsonConfigFile;
    jsonConfigFile = fopen(completePath, "r");
    
    if(jsonConfigFile == NULL){
        menu("error: cant find config file!")
    }
}

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

// SYSTEM DATA

int getIp(){
    return 154;
}
 
void statusBackupFile(char zipPath[]){
    FILE *statusBackupFile;
    
    // unzipfile
    system("sudo gzip -d -k %s", zipPath);
    // get file name
    char fileName[] = "";
    int iterator = 0;
    for(int characterIndex = 0; characterIndex < zipPath; characterIndex++){
        if(zipPath[characterIndex] == '/'){
            fileName[iterator] = zipPath[characterIndex];
            iterator++;
        } else {
            char fileName[] = "";
            iterator = 0;
        }
    }
    
    statusBackupFile = fopen(fileName, "r");
    
    if(statusBackupFile == NULL){
        menu("error: cant find status file from backup");
    }
}

// MENU FUNCTIONS

void config(){
    system("clear");
    printf("%s", banner);
    printf("\n\n(config)> ");
    
    char menuConfigOption[100] = "";
    scanf("%s", &menuConfigOption);
    
    if(strcmp(menuConfigOption, "man")){
        // manual
        printf("\nRaspi-Monitor config manual  \n\nCommands:            Description:\n");
        printf("---------------------------------------------------------------------------\n");
        printf("- \"ip\"               set ip assegnation option  \n");
        printf("- \"openVpn\"          set all the openvpn options  \n");
        printf("- \"ssh\"              set all the ssh (server) option  \n");
        printf("- \"ftp\"              set all the ftp options  \n");
        printf("- \"clear\"            just clear the shell  \n");
        printf("- \"back\"             returns to menu");
        
    } else if (strcmp(menuConfigOption, "ip")){
        // ip options
        printf("\n1.DHCP         2.");
        printf("\n\n(config-ip)> ");
        
        int menuConfigIpOption = 0;
        scanf("%d", &menuConfigIpOption);
        
        if(){
            
        }
    }
    
    openVpnFileParser("/var/log/openvpn/status.log");
    
    return;
}

void serverStatus(){
    system("clear");
    printf("%s", banner);
    printf("\n(serverStatus)> ");
    
    int menuServSOption;
    scanf("%d", &menuServSOption);
    
    return;
}

void serverInfo(){
    int clearTerminal = 1;
    int serverInfoExit = 0;
    
    while(serverInfoExit == 0){
        
        if(clearTerminal == 1){
            system("clear");
            printf("%s", banner);
            
            clearTerminal = 0;
        }
        
        printf("\n\n(serverInfo)> ");
        
        char menuServerIOption[100] = "";
        scanf("%s", &menuServerIOption);
        
        if(strcmp(menuServerIOption, "man") == 0){
            // manual
            printf("\nRaspi-Monitor info manual  \n\nCommands:            Description:\n");
            printf("---------------------------------------------------------------------------\n");
            printf("- \"ip\"               returns all the raspberry ip information  \n");
            printf("- \"webserverStatus\"  returns all the raspi-monitor webserver status  \n");
            printf("- \"raspberryInfo\"    returns all the raspberry hardware/software information  \n");
            printf("- \"clear\"            just clear the shell  \n");
            printf("- \"back\"             returns to menu");
            
        } else if(strcmp(menuServerIOption, "ip") == 0){
            // ip information
            //char currentIp[] = getIp();
            
            printf("local ip: %s  \nnetmask: %s  \ninterface: %s", "192.168.1.154", "255.255.255.0", "wlan0");
            
        } else if(strcmp(menuServerIOption, "webserverStatus") == 0){
            // webserver status
            
        } else if(strcmp(menuServerIOption, "raspberryInfo")   == 0){
            // raspberry info
            
        } else if(strcmp(menuServerIOption, "clear")           == 0){
            // clear terminal
            clearTerminal = 1;
            
        } else if(strcmp(menuServerIOption, "back")            == 0){
            // exit
            serverInfoExit = 1;
            
        } else {
            printf("\"%s\": Unknown command", menuServerIOption);
        }
    }
    
    menu(" ");
    
    return;
    
}

void updateCheck(){
    
    // git update
    system("git pull");
    menu("Updated!");
    
    return;
}

int menu(char message[]){
    int menuExit = 0;
    
    while(menuExit == 0){
        system("clear");
        printf("%s", banner);
        printf("\n1.Configuration      2.Server start/stop  \n3.Server info        4.Ceck update  \n");
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
                menuExit = 1;
                break;
            default:
                menu("Inexistring option");
        }
    }
    return 0;

}

void main(){
    int exitCode = menu("Welcome!");
    printf("\nBye! => exit code: %d\n", exitCode);
}
