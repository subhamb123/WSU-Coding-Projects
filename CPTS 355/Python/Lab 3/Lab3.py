# CptS 355 - Spring 2023 - Lab 3
# Please include your name here
# Subham Behera

debugging = False
def debug(*s): 
     if debugging: 
          print(*s)

## problem 1 getNumCases 
# def getNumCases(data, counties, months):
#      cases = 0
#      for county in counties:
#           for dCounty in data.keys():
#                if county == dCounty:
#                     for month in months:
#                          for dMonth in data.values().keys():
#                               if month == dMonth:
#                                    cases += data.values().get(dMonth)
#                                    break

## problem 2 getMonthlyCases
def getMonthlyCases(data):
     d = dict()
     for(county, log) in data.items():
          for(month, num) in log.items():
               if month not in d:
                    d[month] = {}
               d[month][county] = num
     return d

from functools import reduce
## problem 3 mostCases 
def map_helper(log):
     return reduce(lambda x,y: x+y, log.values())

def mostCases(data):
     monthlyCases = getMonthlyCases(data)
     map_result = list(map(lambda t: (t[0], map_helper(t[1])), monthlyCases.items()))
     return reduce(lambda t1,t2: t1 if t1[1] >= t2[1] else t2, map_result)

## problem 4a) searchDicts(L,k)


## problem 4b) searchDicts2(L,k)
def searchDicts2(tL, k):
     def helper(tL, k, ind):
          if k in tL[ind][1]:
               return tL[ind][1][k]
          else:
               if ind == 0:
                    return None
               else:
                    return helper(tL, k, tL[ind][0])
          
     return helper(tL, k, len(tL) - 1)


## problem 5 - getLongest
def getLongest(L):
     getLonger = lambda x,y: x if len(x) >= len(y) else y
     longest = ''
     for item in L:
          if isinstance(item, list):
               longest = getLonger(longest, getLongest(item))
          else:
               longest = getLonger(longest, item)
     return longest

## problem 6 - apply2nextN 
class apply2nextN(object):
     def __init__(self, op, n, it):
          self.input1 = it
          self.op = op
          self.n = n
          self.current = self._getNextInput()
     
     def _getNextInput(self):
          try:
               current = self.input1.__next__()
          except:
               current = None
          return current
     
     def __next__(self):
          if self.current is None:
               raise StopIteration
          temp_n = self.n
          total = self.current
          self.current = self._getNextInput()
          while(temp_n > 1):
               if(self.current is not None):
                    total = self.op(total, self.current)
               else:
                    break
               self.current = self._getNextInput()
               temp_n -= 1
          
          return total
     
     def __iter__(self):
          return self

     
     