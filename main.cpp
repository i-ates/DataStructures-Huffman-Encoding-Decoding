#include "HuffmanCoding.h"
#include <bits/stdc++.h>

int main(int argc, char **argv) {
    HuffmanCoding system;
    if(strcmp(argv[1],"-i") == 0){
        if (strcmp(argv[3],"-encode")==0){
            system.executeEncoding(argv[2]);
        } else if (strcmp(argv[3],"-decode")==0){
            system.executeDecoding(argv[2]);
        }
    }else if (strcmp(argv[1],"-s") == 0){
        system.executeReturn(argv[2]);
    }else if (strcmp(argv[1],"-l") == 0){
        system.executeListing();
    }
    return 0;
}
