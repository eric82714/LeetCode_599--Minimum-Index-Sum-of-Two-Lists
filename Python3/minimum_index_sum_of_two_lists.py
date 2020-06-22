class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        result = []
        least = len(list1) + len(list2)
        
        for i in range(len(list1)):
            for j in range(len(list2)):
                if list1[i] == list2[j] and (i+j) == least:
                    result = [list1[i]] + result
                if list1[i] == list2[j] and (i+j) < least: 
                    result = [list1[i]]
                    least = i + j
                
        return result
