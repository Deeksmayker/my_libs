#pragma once

#include <string.h>

template<typename T>
struct Dynamic_Array{
    T *data;
    int count = 0;
    int max_count = 0;

    Dynamic_Array(int _max_count){
        max_count = _max_count;
        count = 0;
        data = (T*)malloc(_max_count * sizeof(T));
    }
    
    Dynamic_Array(){
        max_count = 1;
        count = 0;
        data = (T*)malloc(max_count * sizeof(T));
    }
    
    T get(int index){
        return data[index];
    }
    
    T* get_ptr(int index){
        return &data[index];
    }
    
    void add(T value){
        //if (count >= max_count) return;
        
        if (count >= max_count){     
            assert(max_count > 0);
        
            max_count *= 2;
            
            T *old_data = (T*)malloc(count * sizeof(T));
            
            mem_copy(old_data, data, count * sizeof(T));
            free(data);
            
            data = (T*)malloc(max_count * sizeof(T));
            mem_copy(data, old_data, count * sizeof(T));
            
            free(old_data);
        }
        
        // T* element = get(count);
        // mem_copy(element, value, sizeof(T));
        data[count] = value;
        count++;
    }
    
    void remove(int index){
        if (index == count - 1){
            count--;
            return;
        }
    
        // for (int i = index; i < count - 1; i++){
        //     // T *current_element = get_ptr(i);
        //     // T *next_element    = get_ptr(i + 1);
        //     //mem_copy(get_ptr(i), get_ptr(i+1), sizeof(T));
            
            
        // }
        
        memmove(get_ptr(index), get_ptr(index+1), sizeof(T) * (count - index - 1));
        
        //mem_copy(get_ptr(index), last_ptr(), sizeof(T));
        
        count--;
    }
    
    T last(){
        return data[count-1];
    }
    
    T* last_ptr(){
        return &data[count-1];
    }
    
    void clear(){
        // free(data);
        // data = (T*)malloc(max_count * sizeof(T));
        count = 0;
    }
    
    void free_arr(){
        free(data);
    }
    
    // ~Array(){
    //     free(data);   
    // }
};

template<typename T, int C>
struct Array{
    T data[C];
    int count = 0;
    int max_count = 0;

    Array(){
        max_count = C;
        count = 0;
    }
    
    T get(int index){
        return data[index];
    }
    
    T* get_ptr(int index){
        return &data[index];
    }
    
    void add(T value){
        assert(count < max_count);     
        
        data[count++] = value;
    }
    
    void remove(int index){
        if (index == count - 1){
            count--;
            return;
        }
        
        memmove(get_ptr(index), get_ptr(index+1), sizeof(T) * (count - index - 1));
        count--;
    }
    
    void remove_first_half(){
        int half_count = (int)((float)count * 0.5f);
        int even_correction = count % 2 == 0 ? -1 : 0;
        mem_copy(get_ptr(0), get_ptr(half_count + even_correction), half_count * sizeof(T));
        
        count = half_count;
    }
    
    T pop(){
        assert(count > 0);
    
        return data[--count];
    }
    
    T* pop_ptr(){
        assert(count > 0);
    
        return &data[--count];
    }
    
    T last(){
        return data[count-1];
    }
    
    T* last_ptr(){
        return &data[count-1];
    }
    
    void clear(){
        count = 0;
    }
};

template<typename T>
void copy_array(Dynamic_Array<T> *dest, Dynamic_Array<T> *src){
    //*dest = *src;
    dest->clear();
    
    for (int i = 0; i < src->count; i++){
        dest->add(src->get(i));
    }
    
    //dest->data = (T*)malloc(dest->count * sizeof(T));
    //mem_copy(dest->data, src->data, dest->count * sizeof(T));
}

void split_str(String str, const char *separators, int separators_count, Dynamic_Array<String> *result){
    result->clear();

    String current_string = String();
    
    for (int i = 0; i < str.count; i++){
        char ch = str.data[i];
        
        int need_separate = 0;
        for (int s = 0; s < separators_count; s++){
            if (ch == separators[s]){
                need_separate = 1;
                break;
            }
        }
        
        if (need_separate){
            if (current_string.count != 0){
                String copied_string = String(&current_string);
                result->add(copied_string);
                
                current_string.clear();
            }
        } else{
            current_string += ch;   
        }
    }
    
    if (current_string.count != 0){
        result->add(current_string);
    }
}

Dynamic_Array<String> split_str(String str, const char *separators, int separators_count){
    Dynamic_Array<String> result = Dynamic_Array<String>(10);
    
    split_str(str, separators, separators_count, &result);
    
    return result;
}

void free_string_array(Dynamic_Array<String> *arr){
    for (int i = 0; i < arr->count; i++){
        arr->get_ptr(i)->free_str();
    }
    
    arr->free_arr();
}
