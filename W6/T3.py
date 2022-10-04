import os
abspath = os.path.abspath(__file__)
dname = os.path.dirname(abspath)
os.chdir(dname)

# Addresses are calculated: base + virtual-address-offset
os.system("./relocation.py -s 1")
#>> This gives the valid physical address: 14145

os.system("./relocation.py -s 2")
# >> Valid Addresses: 15586, 15615

os.system("./relocation.py -s 3")
# >> Valid Addresses: 8983, 8929
#################################

os.system("./relocation.py -s 0 -n 10")
# To make all the virtual registers valid, the limit (-l) must be 930

#################################

os.system("./relocation.py  -s 1 -n 10 -l 100")
# To fit all the adresses to memory, the base can be at most 16284. Base + limit must not exceed physical memory (2^14 = 16384)

#################################
os.system("./relocation.py  -s 1 -n 10 -l 100 -p 32m")
os.system("./relocation.py  -s 1 -n 10 -l 100 -p 1g -a 32m")
#................ etc. address memory (-a) must be smaller than physical memory (-p)
#################################


def run_reloc(args,output):
    """ Run relocation.py with args and save results to output -file"""
    os.system("./relocation.py {} > {}".format(args,output))


def count_valids(f):
    """ Count how many times 'VALID' appears in f."""
    with open(f,"r") as file:
        tx = file.read()
        count = tx.count("VALID")
    return count
import random
get_args = lambda a : "-s {} -c -n 100 -l {} -p 1g -a {}".format(random.randint(1,101),random.randint(0,a),a)
#as_ = [i for i in range(10,10**8,100000)]
as_ = [i for i in range(10,10**8,100000)]
print(as_)
file = "./tmp.txt"
counts = []

import matplotlib.pyplot as plt
for a in as_:
    args = get_args(a)
    run_reloc(args,file)
    counts.append(count_valids(file))
    #os.remove(file)
    print(counts)
plt.plot(as_,counts)
plt.show()







