import math

n = int(input())
l = int(input())
while(n > 1):
    m = int(input())
    l = l*m // math.gcd(l, m)
    n -= 1;
print(l)