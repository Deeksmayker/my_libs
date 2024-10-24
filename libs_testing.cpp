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
    String str = init_string_from_str("Cht oto\nab{ob}a\nw|ow!!!\n");
    
    //Dynamic_Array<String> splited = split_str(str, "\n", 1);
    Dynamic_Array<Medium_Str> splitted = Dynamic_Array<Medium_Str>(16);
    
    split_str(str.data, "\n {}|", &splitted);
    
    assert(str_cmp(splitted.get(0).data, "Cht"));
    assert(str_cmp(splitted.get(1).data, "oto"));
    assert(str_cmp(splitted.get(2).data, "ab"));
    assert(str_cmp(splitted.get(3).data, "ob"));
    assert(str_cmp(splitted.get(4).data, "a"));
    assert(str_cmp(splitted.get(5).data, "w"));
    assert(str_cmp(splitted.get(6).data, "ow!!!"));
    
    printf("test_str1 cool!\n");
    
    str.free_str();
    //free_string_array(&splitted);
    splitted.free_arr();
}

// void test_files1(){
//     File test_file = load_file("../test_data/test_arr1.txt", "r");
    
//     int test_arr[][10] = {{123, 543, 65, 23, 54}, {534, 12, 32, 54, 5, 6, 7, 8}};
//     //int text_arr2[] = {534, 12, 32, 54, 5, 6, 7, 8};
    
//     Dynamic_Array<String> splited = Dynamic_Array<String>(16);
    
//     for (int i = 0; i < test_file.lines.count; i++){
//         splited = split_str(test_file.lines.get(i), "[, ]", 4);
//         for (int j = 0; j < splited.count; j++){
//             int num = atoi(splited.get(j).data);
//             assert(num == test_arr[i][j]);
//         }
        
//         //printf("%s", test_file.data.get(i).data);
//     }
    
//     printf("test_files1 cool!\n");
    
//     free_string_array(&splited);
//     unload_file(&test_file);
// }

global_variable b32 testing = true;

int main(){
    if (testing){
        test_str1();
        //test_files1();
    }
}
