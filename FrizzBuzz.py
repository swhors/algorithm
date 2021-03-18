"""
n의 값이 주면, 1에서 n까지 이 값을 출력하면 그 값이 3의 배수이면 Frizz을 5의 배수이면 Buzz을 출력하라.
그리고, 3과 5의 배수 인 경우에는 FrizzBuzz을 출력하라

예
 입력 : n = 15
 출력 :
    1
    2
    Frizz
    4
    Buzz
    Frizz
    7
    8
    Frizz
    Buzz
    11
    Frizz
    13
    14
    FrizzBuzz
"""

def fizzBuzz(n):
    for i in range(0, n):
        threes = ((i+1) % 3 == 0)
        fives = ((i+1) % 5 == 0)
        if threes and fives:
            print('FizzBuzz')
        elif threes:
            print('Fizz')
        elif fives:
            print('Buzz')
        else:
            print(i+1)
if __name__ == '__main__':
    fizzBuzz(15)
