'''
    张三85,92,78
    李四95,91,93
    王五56,56,96
    赵六87,78,95
    孙七89,68,94
    用合适的数据结构储存这份数据。
计算每名学生的总分和平均分，并输出如下格式：
张三: 总分=255, 平均分=85.0

在储存的数据结构中补充遗漏数据：姓名：郑十，语文：92，数学：91，英语：86
找出总分最高的学生，输出姓名和总分。
给赵六的数学成绩加 5 分，同时更新总分和平均分，并输出修改后的信息。
输出每科平均分和每科最高分的学生（同分则全部列出）。
'''


scores = {
    '张三': [85, 92, 78],
    '李四': [95, 91, 93],
    '王五': [56, 56, 96],
    '赵六': [87, 78, 95],
    '孙七': [89, 68, 94],
    }
subjects = ['语文', '数学', '英语']

# 学生的总分和平均分
for name,marks in scores.items():
    total = sum(marks)
    avg = total / len(marks)
    print(f'{name}: 总分={total}, 平均分={avg:.1f}')

# 补充遗漏数据
scores['郑十'] = [92, 91, 86]

# 找出总分最高的学生
max_total = 0
top_students = ""
for name,marks in scores.items():
    total = sum(marks)
    if total > max_total:
        max_total = total
        top_students = name
print(f'总分最高的学生是{top_students}，总分={max_total}')

# 给赵六的数学成绩加5分
scores['赵六'][1] += 5

# 计算修改后的总分和平均分
name = '赵六'
total = sum(scores[name])
avg = total / len(scores[name])
print(f'{name}: 总分={total}, 平均分={avg:.1f}')

# 每科平均分和最高分的学生 不会，只想到挨个算