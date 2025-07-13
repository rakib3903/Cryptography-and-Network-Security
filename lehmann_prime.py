import random

def lehmann_primality_test(p, t=10):
    if p == 2:
        return True, 100.0 
    if p < 2 or p % 2 == 0:
        return False, 0.0 

    for _ in range(t):
        a = random.randrange(2, p - 1)
        exp = (p - 1) // 2
        r = pow(a, exp, p)

        if r != 1 and r != p-1:
            return False, 0.0  

    confidence = (1 - 1 / (2 ** t)) * 100
    return True, confidence

number = 807906569837771
t = 11
result, confidence = lehmann_primality_test(number, t)

if result:
    print(f"{number} is probably prime with {confidence:.6f}% confidence after {t} tests.")
else:
    print(f"{number} is definitely not prime")


# 1. 309622241329033
# 2. 263350964244289
# 3. 807906569837771
# 4. 958323720155513
# 5. 868831599848783
