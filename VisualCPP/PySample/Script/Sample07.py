'''
Python (Sample07.py)코드입니다.
'''

from PyExt import DbgString, SumAndAverage

DbgString("Sample07.py\n")
nStart = 1
nStop = 10
nSum, nAverage = SumAndAverage(nStart, nStop)
DbgString("SumAndAverage(%d, %d) : 합 => %d, 평균 => %d\n"% ( nStart, nStop, nSum, nAverage))