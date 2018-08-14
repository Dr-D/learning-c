# socket-messaging

This will be a small project that involves discovery of peers using multicast and creates a cache that works over unicast.

Having further thought on this it looks like it will involve mutliple threads.
One to allow a heartbeat for checking current peers.

A second to set up the unicast socket(s) to allow for peer to peer data sharing.

The main thread will start the threads and may want some logic to restart the threads if they go down.

Will have to think about how to resolve a cache where two nodes update the cache at the same time.





