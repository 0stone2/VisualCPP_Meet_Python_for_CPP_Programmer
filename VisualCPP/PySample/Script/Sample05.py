'''
Python (Sample05.py)코드입니다.
'''
from PyExt import DbgString, Sum

DbgString("Sample05.py\n")
nStart = 1
nStop = 10
nSum = Sum(nStart, nStop)
DbgString("sum(%d, %d) : %d\n" % ( nStart, nStop, nSum))
