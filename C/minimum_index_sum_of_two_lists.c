/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize){
    int len = list1Size > list2Size ? list1Size : list2Size;
    char** result = malloc(len * sizeof(char*));
    for(int i = 0; i < len; i++) result[i] = malloc(31 * sizeof(char));
    int least = list1Size + list2Size;
    int index = 0;    
    
    for(int i = 0; i < list1Size; i++) {            
        for(int j = 0; j < list2Size; j++) {
            if(strcmp(list1[i], list2[j]) == 0 && (i+j) == least)
                strcpy(result[index++], list1[i]);
            if(strcmp(list1[i], list2[j]) == 0 && (i+j) < least) {
                index = 0;
                strcpy(result[index++], list1[i]);
                least = i + j;
            }
        }
    }
    
    *returnSize = index;
    return result;
}
