## Minitalk: ~15h of Coding

**Description**:
Minitalk is a client-server application designed to transmit characters bit by bit using UNIX signals. The project was developed without the use of dynamic memory allocation (except ft_printf for printing unsigned int (bonus client bits counter)) or global variables.

**Functionality**:
- **Client**:
  - Verifies provided arguments and outputs error messages for any issues.
  - Sends characters sequentially, bit by bit, to the server using SIGUSR1 and SIGUSR2 signals.
  - *SIGUSR1* signifies bit 1.
  - *SIGUSR2* signifies bit 0.

- **Server**:
  - Receives bits from the client and reconstructs characters using static variables.
  - Outputs characters once a complete character (8 bits) is received.

**Used Functions**:
- *ft_printf*
- *ft_atoi*
- *ft_isdigit*

**Bonus Features**:
- Server acknowledges receipt of *SIGUSR1* or *SIGUSR2* signals by sending *SIGUSR1* to the client.
- Server sends *SIGUSR2* to the client upon receiving the end character ('\0').
- Client increments a static counter upon receiving *SIGUSR1* to track the number of signals sent by the server.
- Client uses *ft_printf* to display the total count upon receiving *SIGUSR2*.
