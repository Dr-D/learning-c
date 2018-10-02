# socket-messaging

This will be a small project that involves discovery of peers using multicast and creates a cache that works over unicast.

Having further thought on this it looks like it will involve mutliple threads.
One to allow a heartbeat for checking current peers.

A second to set up the unicast socket(s) to allow for peer to peer data sharing.

The main thread will start the threads and may want some logic to restart the threads if they go down.

Will have to think about how to resolve a cache where two nodes update the cache at the same time.

## Other
Thinking ahead - may need to have unique id for each server/node in the cluster and the multicast will be a hearbeat that broadcasts this information.
Each instance will need an ip address in a configuration file - when client sends ip addresses and we start opening unicast sockets between instances they must all be configured to be on same network. 

Will need a collection to record the server/node ids being broadcast.

Simple algorithm that can order the ip addresses and then can connect to the two servers with the closest ip addresses one above and one below. NB may only be single or two servers/nodes in the cluster so will need a check for this. i.e. dont form cluster for single node and only create single tcp socket for two nodes.

Thinking even further ahead - will need buffer/queue on each node to record changes and timings to the shared information/caches.
Do we want a second multicast message type that multicasts the time of the first item on the queue for each node - may be better than trying to make changes transactional. I.e if an update starts at two separate nodes then one set of changes will need to be rolled back and reapplied if the update happens at the same time.

What if two or more nodes have the same time for an update need some way to prioritise a server/node, as the transaction is same time we will never know which server/nodes information should be applied first or last so the server/node priority does not need to be sophisticated unless we want it to be.

Do we want writes to have priority over reads on a server/node i.e. may need mutex(s) to ensure writes occurr before a read - may need to think about this a bit more as we will have a buffer on each node but that buffer may not contain the correct information if servers/nodes are waiting to update the information/cache. It may be that we just have to live with the fact data the information/cache across a cluster is not always going to be upto date and the application needs to be robust enough to deal with it.
