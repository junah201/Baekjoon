#18301  Rats

import math

n,m,k=map(int,input().split())
print(math.floor((n + 1)*(m + 1)/(k + 1)-1))