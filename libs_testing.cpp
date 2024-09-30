#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

#include "my_defines.hpp"
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

int main(){
    //printf("abdfsaoba");
    
    test_str1();
}
