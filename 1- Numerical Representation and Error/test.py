def calculateValue(initialValue):
    result = initialValue
    for i in range(1,26):
        result = result * i - 1
    return result

print(calculateValue(1.718281828459045))