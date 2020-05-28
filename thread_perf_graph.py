import os
import csv
import matplotlib as mpl
import matplotlib.pylab as plt

result = []
for num_thread in range(1, 12):
    cmd = f'./main -t {num_thread} -n 3 1024 1024 1024'
    stream = os.popen(cmd)
    output = stream.read()
    throughput = output.split('\n')[-3].split()[-2]
    result.append(throughput)

# print(result)

plt.plot(list(map(float, result)))
plt.title("Thread num & running time")
plt.xlabel("num thread")
plt.ylabel("sec")
plt.savefig("graph.png", dpi=300)
