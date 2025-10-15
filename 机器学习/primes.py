def primes(n):
    if n <= 1:
        return False
    for i in range(2,int(n**0.5)+1):
         if n % i == 0:
            return False
    return True

def get_primes(n):
    primes_list = []
    num = 2
    while len(primes_list) < n:
        if primes(num) :
            primes_list.append(num)
        num += 1
    print(primes_list)
get_primes(int(input("输入一个数")))


