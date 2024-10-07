#pragma once

size_t str_len(const char *line){
    size_t result = 0;   
    while (line[result] && result < 100){
        result++;
    }
    
    return result;
}

void mem_copy_back(void *dest, void *source, size_t bytes){
    char *new_dest   = (char*)dest;
    char *new_source = (char*)source;
    for (int i = bytes - 1; i >= 0; --i){
        new_dest[i] = new_source[i];
        //printf("%s\n", new_dest[i]);
    }
}

void mem_copy(void *dest, void *source, size_t bytes){
    char *new_dest   = (char*)dest;
    char *new_source = (char*)source;
    for (int i = 0; i < bytes; i++){
        new_dest[i] = new_source[i];
        //printf("%s\n", new_dest[i]);
    }
}

void str_copy(char *dest, const char *source){
    int len = str_len(source);
    mem_copy((void*)dest, (void*)source, len * sizeof(char));
    dest[len] = '\0';

    // size_t bytes = str_len(source);
    // for (size_t i = bytes; i > 0; --i){
    //     dest[i - 1] = source[i - 1];
    //     //printf("%s\n", new_dest[i]);
    // }
}

b32 str_start_with(char *str, char *start_with){
    int len = str_len(str);
    int start_with_len = str_len(start_with);
    
    if (start_with_len > len){
        return false;
    }
    
    for (int i = 0; i < start_with_len; i++){
        if (str[i] != start_with[i]){
            return false;
        }
    }
    
    return true;
}

// b32 str_cmp(char *first, char *second){
//     int len1 = str_len(first);
//     int len2 = str_len(second);
    
//     if (len1 != len2) return false;
    
//     for (int i = 0; i < len1; i++){
//         if (first[i] != second[i]) return false;
//     }
    
//     return true;
// }

b32 str_cmp(char *first, const char *second){
    int len1 = str_len(first);
    int len2 = str_len(second);
    
    if (len1 != len2 || len1 == 0) return false;
    
    for (int i = 0; i < len1; i++){
        if (first[i] != second[i]) return false;
    }
    
    return true;
}

struct String{
    String(const char *_data){  
        count = str_len(_data);
        max_count = count;
        
        if (max_count < 16){
            max_count = 16;
        }
        
        data = (char*)malloc(max_count * sizeof(char));
        
        str_copy(data, _data);
    }
    
    String(){  
        count = 0;
        max_count = 16;
        
        data = (char*)malloc(max_count * sizeof(char));
    }
    
    String(String *str_to_copy){
        count = str_to_copy->count;
        max_count = str_to_copy->max_count;
        
        data = (char*)malloc(max_count * sizeof(char));
        str_copy(data, str_to_copy->data);
    }
    
    char *data;
    size_t count;
    size_t max_count;
    
    void operator+=(const char *add_str){
        size_t add_count = str_len(add_str);
        
        //+1 to safely put '\0' at end
        if (count + add_count + 1 > max_count){
            max_count *= 2;
            char old_data[count];
            str_copy(old_data, data);
            free(data);
            
            data = (char*)malloc(max_count * sizeof(char));
            
            str_copy(data, old_data);
        }
        
        str_copy(data + count, add_str);
        count += add_count; 
        data[count] = '\0';
    }
    
    void operator+=(char ch){
        //+1 to safely put '\0' at end
        if (count + 2 > max_count){
            max_count *= 2;
            char old_data[count];
            str_copy(old_data, data);
            free(data);
            
            data = (char*)malloc(max_count * sizeof(char));
            
            str_copy(data, old_data);
        }
        
        data[count] = ch;
        count++;; 
        data[count] = '\0';
    }
    
    b32 operator==(String str1){
        if (count != str1.count) return false;
        
        for (int i = 0; i < count; i++){
            if (data[i] != str1.data[i]) return false;
        }
        
        return true;
    }
    
    b32 operator==(const char *line){
        int len = str_len(line);
    
        if (count != len) return false;
        
        for (int i = 0; i < count; i++){
            if (data[i] != line[i]) return false;
        }
        
        return true;
    }
    
    void clear(){
        count = 0;   
        data[0] = '\0';
    }
    
    void free_str(){
        free(data);
        count = 0;
    }
};


