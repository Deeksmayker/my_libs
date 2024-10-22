#pragma once

#include "array.hpp"
#include "string.hpp"

struct File{
    //When we will need to keep file open this will be changed
    //FILE *fptr;
    char name[128];
    Dynamic_Array<String> lines;
};

File load_file(const char *name, const char *mode){
    File file;
    //file.name = (char*)malloc(str_len(name) * sizeof(char));
    str_copy(file.name, name);
    file.lines = Dynamic_Array<String>(8);
    
    FILE *fptr = fopen(name, mode);
    
    const unsigned MAX_LENGTH = 5000;
    char buffer[MAX_LENGTH];
    
    if (fptr == NULL){
        printf("NO FILE LOADING TODAY: %s\n", name);
    }

    while (fptr != NULL && fgets(buffer, MAX_LENGTH, fptr)){
        String str = init_string_from_str(buffer);
        
        if (str.data[str.count-1] == '\n'){
            str.count--;
        }
        
        file.lines.add(str);
    }
    
    if (fptr){
        fclose(fptr);
    }
    
    return file;
}

void unload_file(File *file){
    free_string_array(&file->lines);
    //free(file->name);
}



