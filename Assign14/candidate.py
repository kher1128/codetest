from itertools import combinations
import pandas as pd

def solution(relation):
    answer = []
    
    df = pd.DataFrame(relation)
    
    col_list = set(df.columns)
    col_cnt = len(col_list)
    unique = len(df)
    
    for i in range(1, col_cnt + 1):
        candidate = list(combinations(col_list, i))
        
        for tuples in candidate:
            tup = len(df[list(tuples)].apply(lambda x :"".join(x), axis = 1).unique())
            
            if tup == unique:
                check = False
                for lst in answer:
                    if lst & set(list(tuples)) == lst:
                        check = True
                        break
                if not check :
                    answer.append(set(list(tuples)))
    
    return len(answer)
