
def foo():
    print("Tasty banana!")
    
def kohta2():
    print(foo.__code__.co_code)
    print( [byte for byte in foo .__code__.co_code])
    # Teksti muoto tekisi koodista helpommin ymmärrettävää
    
def disas_foo():
    import dis
    dis.dis(foo)
    #>> ### Python loads the variables to the stack.
    #  3       0 LOAD_GLOBAL              0 (print)             ## Push 'print' to stacks
    #          2 LOAD_CONST               1 ('Tasty banana!')   ## Push string to stack
    #          4 CALL_FUNCTION            1                     ## Pops function and arg from stack and calls it, pushes return to stack           
    #          6 POP_TOP                                        ## Remove top of stack, to remove return value
    #          8 LOAD_CONST               0 (None)              ## Push to stack
    #         10 RETURN_VALUE                                   ## Return top of stack


if __name__ == "__main__":
    kohta2()
    disas_foo()