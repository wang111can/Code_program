n = int(input())
l, r = map(int, input().split())
a = []
b = l
for _ in range(n):
    A, B = map(int, input().split())
    a.append((A * B, A, B));

# print(a)
a.sort()
# print(a)
ans = 0
for i in range(n):
    ans = max(ans, b // a[i][2]) 
    b = b * a[i][1];    
print(ans)