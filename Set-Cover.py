def setCover(n,m,x,s):
    e=[]
    while len(x)>0:
        mx=[]
        maxCom=0
        for i in range(len(s)):
            cur=s[i]&x
            if len(cur)>maxCom:
                maxCom=len(cur)
                mx=s[i]
        x-=mx
        e.append(mx)
    print("Sets in Set Cover : ")
    for set in e:
        print(set)
    

n=int(input("Enter Number of elements : "))
print("Enter X : ",end=" ")
x=set(map(int,input().split()))
m=int(input("Enter Number of Sets : "))
s=[]
print("Enter sets : ")
for _ in range(m):
    s.append(set(map(int,input().split()))) 
setCover(n,m,x,s)
