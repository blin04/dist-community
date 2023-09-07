"""
program used for testing performances of dist algorithm
"""

import networkx as nx

G = nx.Graph()

# read nodes
f = open("../dataset/t_n", 'r')

for line in f:
    line = line.split(' ')
    G.add_node(int(line[0]))

f.close()

# read edges
f = open("../dataset/t_e", 'r')

for line in f:
    line = line.split(' ')
    G.add_edge(int(line[0]), int(line[1]))

f.close()

comp = nx.connected_components(G)
mod = nx.community.modularity(G, nx.connected_components(G))
print("Modularity is: " + str(mod))

# calculate edge betweenness
while G.number_of_edges() > 0:
    betweenness = nx.edge_betweenness_centrality(G)
    print(" --------- ")
    print(betweenness)

    max_val = -1
    edge_to_del = None
    for edge, val in betweenness.items():
        if float(val) > max_val:
            max_val = val
            edge_to_del = edge

    print(edge_to_del)
    G.remove_edge(*edge_to_del)
