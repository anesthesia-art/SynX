class Student:
    def __init__(self):
        self.name = None
        self.age = None
        self.__scores = {}

    def get_average(self):
        sum_ = 0
        for key,value in self.__scores.items():
            sum_ += value
        return "{:.2f}".format(sum_ / len(self.__scores))

    def update_scores(self,subject,value):
        self.__scores.update({subject:value})

    def introduce(self):
        print(f"我是{self.name},今年{self.age}岁，成绩：{self.__scores}")

# 创建两个使学生对象
stu1 = Student()
stu1.name = 'youth'
stu1.age = 20
stu1.update_scores('语文',90)
stu1.update_scores('数学',85)
stu1.update_scores('英语',92)
num1 = stu1.get_average()
stu1.introduce()
print("我是",stu1.name,"我的均分为",num1)

stu2 = Student()
stu2.name = 'alan'
stu2.age = 19
stu2.update_scores('语文',90)
stu2.update_scores('数学',110)
stu2.update_scores('英语',82)
num2 = stu2.get_average()
stu2.introduce()
print("我是",stu2.name,"我的均分为",num2)

# 更新成绩
stu1.update_scores('数学',100)
num3 = stu1.get_average()
print(stu1.name,"的分数更新后，均分为",num3)

# 继承
class GraduateStudent(Student):
    research_topic = None
    def introduce(self):
        print(f"我是{self.name},今年{self.age}岁，研究方向{self.research_topic}")

s1 = GraduateStudent()
s1.name = 'David'
s1.age = 27
s1.research_topic = '机器学习'
s1.introduce()

# 多态
class Animal:
    def sound(self):
        pass

class Dog(Animal):
    def sound(self):
        print("汪汪汪")

class Cat(Animal):
    def sound(self):
        print("喵喵喵")

dog = Dog()
cat = Cat()
cat.sound()
dog.sound()

# 迭代
my_list = [1,2,3,4] #可迭代对象
my_iter = iter(my_list) #用iter转化为迭代器
print(next(my_iter))
print(next(my_iter))
print(next(my_iter))
print(next(my_iter))

# 编程实例(询问AI后改进，添加了self.index = 0 这一个变量)
class BatchDataLoader:
    def __init__(self,data,batch_size):
        self.data = data
        self.batch_size = batch_size
        self.index = 0

    def __iter__(self):
        self.index = 0
        return self

    def __next__(self):
        if self.index >= len(self.data):
           raise StopIteration
        end = self.index + self.batch_size
        batch_data = self.data[self.index:end]
        self.index = end
        return batch_data

#shuffle 询问AI shuffle的用法后改进
import random
class BatchDataLoader2(BatchDataLoader):
    def __init__(self, data, batch_size, shuffle=False):
        super().__init__(data, batch_size)
        self.shuffle = shuffle
        self.shuffled_data = list(data) if shuffle else data

    def __iter__(self):
        if self.shuffle:
            random.shuffle(self.shuffled_data)
        super().__iter__()
        return self

    def __next__(self):
        if self.index >= len(self.shuffled_data):
           raise StopIteration
        end = self.index + self.batch_size
        batch_data = self.shuffled_data[self.index:end]
        self.index = end
        return batch_data

data = list(range(1,21))
loader = BatchDataLoader2(data,6,shuffle=True)
for batch in loader:
    print(batch)



