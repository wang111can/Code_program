def get_(x) :
    if x >= '0' and x <= '9' :
        return ord(x)
    if x >= 'A' and x <= 'Z':
        return ord(x) - ord('A') + 10
    if x >= 'a' and x <= 'z':
        return ord(x) - ord('A') + 10 


print(get_('A'))
n = int(input())


for _ in range(n):
    a, b, s = input().split();
    a = int(a)
    b = int(b)
    s = s[::-1]
    num = 0
    # for i in s:
    
