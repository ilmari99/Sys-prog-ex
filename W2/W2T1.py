def adder(a,b):
    """Add two positive integers a and b together using the concept of half adders.
    
    Sources:    https://realpython.com/python-operators-expressions/#bitwise-operators
                https://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/
    Args:
        a (int): 
        b (int):

    Returns:
        int: 
    """
    while b != 0:
        carry = a & b   # count of logical AND for each bit in a and b (eq. 1010 & 0101 = 0)
        a = a ^ b       # XOR for bits in a and b
        b = carry << 1  # assign 2*carry to b
    return a