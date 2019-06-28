import networkx as nx
import matplotlib.pyplot as plt

G=nx.Graph()



G.add_edge("0","1",weight=1)
G.add_edge("0","2",weight=1)
G.add_edge("1","3",weight=1)
G.add_edge("3","2",weight=1)
G.add_edge("3","4",weight=1)
G.add_edge("2","4",weight=3)

pos=nx.spring_layout(G)
nx.draw(G,pos, with_labels = True)
labels = nx.get_edge_attributes(G,'weight')
nx.draw_networkx_edge_labels(G,pos,edge_labels=labels)
plt.savefig("simple_path.png") # save as png
plt.show() # display
