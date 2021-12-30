# Radix Sort

# 정의

---

- 기수 정렬은 **낮은 자리수**부터 비교 하여 정렬해 간다는 것을 기본 개념으로 하는 정렬 알고리즘이다.

기수로는 정수, 낱말 , 천공 카드 등 다양한 자료를 사용할 수 있으나 크기가 **유한**하고 **사전순**으로 정렬할 수 있어야 한다.

기수정렬은 비교연산을 하지 않으며 정렬 **속도**가 빠르지만 데이터 전체 크기에 기수 테이블의 크기만한 **메모리가 더** 필요하기도 합니다 그리하여 데이터 전체 크기에 따라 안정이 될수도있고
불안정 정렬이 될 수 도있는 정렬이다.

**버킷 정렬**의 일종으로 취급 되기도 한다.

여기서 **버킷 정렬**이란 , 배열의 원소를 여러 버킷으로 분산하여 작동하는 정렬 알고리즘이다.
버킷은 빈이라고도 불리운다. 그래서 버킷을 빈정렬으로도 불리기도합니다.

**기수정렬**은 이 **버킷정렬**을 기반으로 행해진다고 생각하면 편합니다.

# Logic

---

**LSD** ( 최하위 유효 숫자 ) 방식의 정렬과 **MSD** ( 최상위 유효숫자 ) 방식의 정렬로 나뉘어 지는데 
보통 정수를 정렬할때에는 LSD 기수정렬을, 문자열 혹은 가변길이의 데이터방식을 정리할때에는 MSD 기수정렬 방식을 사용한다.

예를들어 

<aside>
💡 # Before LSD Sort
Integer_Array = [1, 10, 2, 3, 4, 5, 6, 7, 8, 9]

</aside>

라는 배열이 선언되있다 가정할때 , 짧은 키가 먼저나오고 긴키가 후순위에 나오는 **사전순** 정리가 되어지는데, 이는 정수 표현의 일반적인 순서와 일치합니다. 

<aside>
💡 # ing LSD Sort
Integer_Array = [ 10, 1 , 2 , 3, 4, 5, 6, 7, 8, 9]

</aside>

1의 자릿수를 비교하여 먼저 정렬을 수행한뒤,

<aside>
💡 #After LSD Sort
Integer_Array = [ 1 , 2 , 3 , 4 , 5 , 6 , 7, 8, 9, 10]

</aside>

10의 자릿수를 비교하여 정렬을 수행하면 위의 결과가 실행되며 정렬이 완료됩니다.

코드 구현 자체의 난이도도 낮고 더 짧은 키는 오른쪽에 정렬후 왼쪽이 공백문자로 채워지는 셈이기때문에 LSD기수정렬 방식은 안정정렬에 속합니다.

MSD 기수정렬 방식은 문자열 혹은 고정 길이 정수 표현 정렬에 적합한데.

예를들어 

<aside>
💡 # Before MSD Sort
variable_Array = [’midnight’, ‘badge’,  ‘bag’, ‘worker’,   ‘banner’, ‘wander’]

</aside>

라는 배열이 선언 되었다 가정할때 , 가장 오른쪽 키값인 wander에 따라서 해당하는 값의 bucket에 넣습니다.

<aside>
💡 # After MSD Sort
variable_Array = [’badge’ ,’bag’, ‘banner', ‘midnight’, ‘wander', ‘worker’ ]

</aside>

정렬 후 의 모습이다. 대략적으로 b라는 값이 주어져 정렬이 점진적으로 완성되어지기 때문에 마지막까지 비교하지 않아도 되는 모습을 볼수있습니다.
이것은 성능적인 이점으로 다가옵니다.

- [ ]  MSD의 정렬 방식은 잘 이해를 하기 어려운 부분이있어 부연 설명은  다음 Writter 에게 MSD를 맡깁니다..

마지막으로 RADIX SORT 의 방식의 GIf를 보며 마치겠습니다.

# LSD 방식

![Radix_Sort_LSD](https://user-images.githubusercontent.com/47372381/147730008-b5c8337d-a867-4fb1-a891-c2d18c109267.gif)


# MSD 방식

![hlfsiC](https://user-images.githubusercontent.com/47372381/147729994-d183c93e-8664-41f0-8f5d-af2683a4e1a2.gif)





                                                                  

# 시간 복잡도: O

---

- 시간복잡도의 경우LSD 와 MSD의 방식에 따라 변경되어 집니다.
정렬 대상의 수를 N, 모든 정렬의 대상 길이를 M이라고 표현할때,

<aside>
💡 #LSD
#Best and Worst Case
O(N*M)

</aside>

<aside>
💡 #MSD
# Best Case
O(N)
# Worst Case
O(N*M)

</aside>

# 장점 / 단점

---

장점으론  원소의 크기와 배열에 크기에 따라서 빠르게도 정렬이 가능하지만, 원소의 크기와 배열의 크기가 증가함에 따라 버킷의 수가 증가하므로 메모리에 영향을 받고 부하를 줄수도있다. == 배열 정렬의 속도가 떨어질 수 있다.

# 출처

---

[](https://web.archive.org/web/20120208114359/http://goanna.cs.rmit.edu.au/~jz/fulltext/acsc03sz.pdf)

[[ch 10-2] 복잡하지만 효율적인 정렬 알고리즘_3(기수 정렬)](https://yahma.tistory.com/82)

[MSD( Most Significant Digit ) Radix Sort - GeeksforGeeks](https://www.geeksforgeeks.org/msd-most-significant-digit-radix-sort/)

[Counting Sort](https://www.cs.miami.edu/home/burt/learning/Csc517.091/workbook/countingsort.html)

[Radix Sort (MSD) on Make a GIF](https://makeagif.com/gif/radix-sort-msd-hlfsiC)

[vMR0Dt on Make A Gif, Animated Gifs](https://makeagif.com/i/vMR0Dt)
