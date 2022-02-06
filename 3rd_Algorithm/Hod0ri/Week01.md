# 1543 문서 검색 (실버 4)
![image](https://user-images.githubusercontent.com/65306839/152671830-173c86c8-7f38-4f81-abd9-1b4b73011078.png)

### 풀이 과정
1. 첫째 줄에 문서, 둘째 줄에 찾을 워드라면 워드의 길이 만큼 문서를 잘라 비교
2. 비교해서 찾은 경우 셈을 함

※ 주의 : 같지 않은 경우, 인덱스 1만 증가

### 코드 순서 (with Pseudo-code)
doc, word, count, index 할당  
반복하는데, word와 word길이 만큼 자른 doc이 같으면 count  
이후 count 출력  
```
GET doc, word
SET count = 1, index = 0
WHILE index <= doc's Length - word's Length
  IF doc[index:index + word's Length] == word
    INCREMENT 1 count
    INCREMENT word's Length index
  ELSE
    INCREMENT 1 index
PRINT count
```

### 코드 (Code)
```py
# Input Value
doc = input()
word = input()

# Init Value (Count, Index)
count = 0
index = 0

while index <= len(doc) - len(word):
    if doc[index:index + len(word)] == word:
        count += 1
        # Add Index (word Length)
        index += len(word)
    else:
        index += 1
print(count)
```
