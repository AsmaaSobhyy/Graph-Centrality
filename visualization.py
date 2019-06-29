import networkx as nx
import matplotlib.pyplot as plt

G=nx.Graph()

f = open("input.txt", "r")
k=list(map(str,f.readline().split()))

n=k[0]
m=int(k[1])
#print(m)

for i in range (0,m):
    ins = list(map(str,f.readline().split()))
    G.add_edge(ins[0],ins[1],weight=ins[2])

f.close()


plt.figure(1,figsize=(10,6))
pos=nx.spring_layout(G)
nx.draw(G,pos, with_labels = True)
labels = nx.get_edge_attributes(G,'weight')
nx.draw_networkx_edge_labels(G,pos,edge_labels=labels)
plt.savefig("simple_path.png") # save as png
plt.show() # display
