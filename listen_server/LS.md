# Listen Server

```python
Same Wi-Fi / LAN
┌──────────────┐
│  Client A    │
│ (Laptop/Phone)│
└──────┬───────┘
       │
┌──────▼───────┐
│   HOST       │  ← Listen Server
│ (Laptop)     │
│ - Manages users
│ - Routes messages
│ - Also chats
└──────┬───────┘
       │
┌──────▼───────┐
│  Client B    │
│ (Laptop/Phone)│
└──────────────┘

```
## Roles in Your System
### Host Device (Listen Server)

The host does everything:

Opens a listening socket

Accepts connections from LAN devices

Maintains:

Connected user list

User IDs / names

Routes messages:

Client → Client

Client → Host

Host → Client

Also has a local client interface for itself

### Other Devices (Clients)

Discover host (manually or automatically)

Connect to host

Send messages to host

Receive messages from host

## Host layer

```python
HOST DEVICE
│
├── Server Logic
│   ├── Accept connections
│   ├── Maintain client list
│   ├── Route messages
│
└── Local Client Logic
    ├── Send messages
    └── Receive messages

```

## Network Model
### Protocol

TCP

Single port (example: 5000)

One socket per connected client

Guaranteed delivery

Ordered messages

Perfect for chat & debugging