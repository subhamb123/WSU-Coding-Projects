# CptS 355 - Spring 2023 - Assignment 3 - Python

# Please include your name and the names of the students with whom you discussed any of the problems in this homework
# Name: Subham Behera
# Collaborators: 

debugging = False
def debug(*s): 
     if debugging: 
          print(*s)

from functools import reduce

## problem 1(a) - aggregate_log  - 5%
def aggregate_log(log):
     aggregate = dict()

     for i in log.values():
          for day in i.keys():
               if aggregate.get(day) == None:
                    aggregate[day] = i.get(day)
               else:
                    aggregate[day] += i.get(day)

     return aggregate

## problem 1(b) - combine_dict– 6%
def combine_dict(log1, log2):
     aggregate = dict()
     
     for day in log1.keys():
          if aggregate.get(day) == None:
               aggregate[day] = log1.get(day)
          else:
               aggregate[day] += log1.get(day)
     
     for day in log2.keys():
          if aggregate.get(day) == None:
               aggregate[day] = log2.get(day)
          else:
               aggregate[day] += log2.get(day)

     return aggregate

## problem 1(c) - merge_logs– 12%
def merge_logs(list):
     aggregate = dict()

     for log in list:
          for course, days in log.items():
               if aggregate.get(course) == None:
                    sub = dict()
                    for day in days:
                         if sub.get(day) == None:
                              sub[day] = days.get(day)
                         else:
                              sub[day] += days.get(day)

                    aggregate[course] = sub
               else:
                    sub = dict()
                    for day in days:
                         if sub.get(day) == None:
                              sub[day] = days.get(day)
                         else:
                              sub[day] += days.get(day)
                    
                    aggregate[course] = combine_dict(aggregate.get(course), sub)

     return aggregate

## problem 2(a) - most_hours – 15%
from functools import reduce
def most_hours(log_input):
     max_hours = reduce(lambda x, y: x if sum(log_input[x].values()) >= sum(log_input[y].values()) else y, log_input.keys())
     return (max_hours, sum(log_input[max_hours].values()))

## problem 2(b) - filter_log – 15%
def filter_log(log_input, day, hours):
     filtered = filter(lambda x: day in x and x[day] >= hours, log_input.values())
     return list(map(lambda x: list(log_input.keys())[list(log_input.values()).index(x)], filtered))

## problem 3 - graph_cycle – 12% 
def graph_cycle(graph, node):
     def helper(graph, node, result):
          if len(result) != len(set(result)):
               pass
          else:
               result.append(node)
               helper(graph, graph.get(node)[0], result)

          return result
     
     result = helper(graph, node, [])

     i = 0
     while i < len(result):
          if result[i] == result[-1]:
               break
          else:
               result.pop(0)
               i = 0

     return result
               
## problem 4 - filter_iter – 15% 
class filter_iter():
     def __init__(self, it, op):
          self.it = iter(it)
          self.op = op

     def __next__(self):
          while True:
               value = next(self.it)
               if self.op(value):
                    return value
     
     def __iter__(self):
          return self

## problem 5 - merge – 10% 
def merge(it1, it2, size):
     i = 0
     result = []
     temp1 = True
     temp2 = True

     while i < size:
          if temp1:
               try:
                    value1 = next(it1)
               except:
                    return result
               temp1 = False
          if temp2:
               try:
                    value2 = next(it2)
               except:
                    return result
               temp2 = False

          if value1 <= value2:
               result.append(value1)
               temp1 = True
               i+=1
          else:
               result.append(value2)
               temp2 = True
               i+=1
     
     if temp1:
          next(it1)
     if temp2:
          next(it2)
     return result