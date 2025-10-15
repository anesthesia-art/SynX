def fibonacci(n):
    if n <= 0:
        print("输入的数字无效")
    elif n == 1:
        print([0])
    else:
        fib = [0,1]
        for i in range(2,n):
            fib.append(fib[i-1] + fib[i-2])
    print("斐波那契数列的前", n, "项为：", fib)

fibonacci(int(input("请输入要输出的斐波那契数列的项数：")))
