for z in range(int(input())):
    x = int(input())
    cnt = 2; st = 1; prev_st = 0; min = 1
    while st < x:
        prev_st = st
        st += cnt
        cnt += 1
        min += 1
    if st - x >= x - prev_st:
        min -= 1
        min += x - prev_st
    else:
        min += st - x
    print(min)