from sys import stdin
n=int(stdin.readline())
a=map(int,raw_input().split())
h='NO'
p=0
s=sum(a)
if s%2==0:
 x=set()
 x.add(0)
 for i in a:
  p+=i
  x.add(p)
 p=0
 for i in a:
  p+=i
  if(i+s/2)in x and p<=(i+s/2):h='YES'
  if(s/2-i) in x and p > (s/2-i):h='YES'
print h