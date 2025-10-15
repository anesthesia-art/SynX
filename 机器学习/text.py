import numpy as np
import random

np.random.seed(42)
x = np.random.rand(100, 1) * 10  
y = 2 * x + 3 + np.random.randn(100, 1) * 1.5  # 加入一些噪声

x = x.flatten()
y = y.flatten()

def compute_loss(w, b, x, y):
    """计算平方和损失函数"""
    n = len(x)
    predictions = w * x + b
    loss = (1/(2*n)) * np.sum((predictions - y) ** 2)
    return loss

def gradient_descent(x, y, learning_rate=0.1, iterations=5, 
                     method='batch', batch_size=10):
    
    n = len(x)
    w = 0.0  # 初始化w
    b = 0.0  # 初始化b
    
    print(f"初始参数: w={w:.6f}, b={b:.6f}, 损失={compute_loss(w, b, x, y):.6f}")
    print("开始迭代...")
    
    for i in range(iterations):
        if method == 'batch':
            # 批量梯度下降：使用所有样本计算梯度
            predictions = w * x + b
            dw = (1/n) * np.sum((predictions - y) * x)
            db = (1/n) * np.sum(predictions - y)
            
        elif method == 'stochastic':
            # 随机梯度下降：随机选择一个样本计算梯度
            idx = random.randint(0, n-1)
            prediction = w * x[idx] + b
            dw = (prediction - y[idx]) * x[idx]
            db = prediction - y[idx]
            
        elif method == 'mini-batch':
            # Mini-batch梯度下降：随机选择batch_size个样本计算梯度
            indices = random.sample(range(n), batch_size)
            x_batch = x[indices]
            y_batch = y[indices]
            predictions = w * x_batch + b
            dw = (1/batch_size) * np.sum((predictions - y_batch) * x_batch)
            db = (1/batch_size) * np.sum(predictions - y_batch)
        
        # 更新参数
        w = w - learning_rate * dw
        b = b - learning_rate * db
        
        # 计算当前损失
        loss = compute_loss(w, b, x, y)
        
        # 打印当前迭代的参数和损失
        print(f"迭代 {i+1}/{iterations}: w={w:.6f}, b={b:.6f}, 损失={loss:.6f}")
    
    return w, b

print("===== 随机梯度下降 =====")
sgd_w, sgd_b = gradient_descent(x, y, learning_rate=0.1, iterations=5, method='stochastic')

print("\n===== Mini-batch梯度下降 (batch_size=10) =====")
mbgd_w, mbgd_b = gradient_descent(x, y, learning_rate=0.1, iterations=5, 
                                  method='mini-batch', batch_size=10)

print("\n===== 批量梯度下降 =====")
bgd_w, bgd_b = gradient_descent(x, y, learning_rate=0.1, iterations=5, method='batch')
print(f"\n最终结果 (随机梯度下降): w={sgd_w:.6f}, b={sgd_b:.6f}")
print(f"最终结果 (Mini-batch梯度下降): w={mbgd_w:.6f}, b={mbgd_b:.6f}")
print(f"最终结果 (批量梯度下降): w={bgd_w:.6f}, b={bgd_b:.6f}")