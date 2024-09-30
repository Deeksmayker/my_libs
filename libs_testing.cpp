#define _CRT_SECURE_NO_DEPRECATE

#include <stdint.h>
#include "my_defines.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "my_math.cpp"
#include "string.hpp"
#include "array.hpp"
#include "files.hpp"

void test_str1(){
    String str = String("Chtoto\naboba\nwow!!!\n");
    
    Array<String> splited = split_str(str, "\n", 1);
    
    assert(splited.data[0] == "Chtoto");
    assert(splited.data[1] == "aboba");
    assert(splited.data[2] == "wow!!!");
    
    printf("test_str1 cool!\n");
    
    str.free_str();
    free_str_array(&splited);
}

void test_files1(){
    File test_file = load_file("../test_data/test_arr1.txt", "r");
    
    int test_arr[][10] = {{123, 543, 65, 23, 54}, {534, 12, 32, 54, 5, 6, 7, 8}};
    //int text_arr2[] = {534, 12, 32, 54, 5, 6, 7, 8};
    
    Array<String> splited = Array<String>(16);
    
    for (int i = 0; i < test_file.lines.count; i++){
        splited = split_str(test_file.lines.get(i), "[, ]", 4);
        for (int j = 0; j < splited.count; j++){
            int num = atoi(splited.get(j).data);
            assert(num == test_arr[i][j]);
        }
        
        //printf("%s", test_file.data.get(i).data);
    }
    
    printf("test_files1 cool!\n");
    
    free_str_array(&splited);
    unload_file(&test_file);
}

global_variable b32 testing = true;

int main(){
    if (testing){
        test_str1();
        test_files1();
    }
}
