n = 3000
m = 3000
with open("data.txt", "w") as f:
    f.write(f"{n} {m} ")
    for i in range(n):
        for j in range(m):
            f.write(" 1")
