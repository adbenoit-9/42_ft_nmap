# FT_NMAP (@42Paris)
*Recoding a part of the nmap port scanner.*

## Usage 

```
$ git clone https://github.com/adbenoit-9/42_ft_nmap.git
$ cd 42_ft_nmap
$ make
$ sudo ./ft_nmap [options]
```

## Description

<p style="margin: 0px; margin-top: 1em; margin-bottom: 1.5em;margin-left: 1em">
Detect open ports, identify hosted services and obtain information on the
operating system of a distant computer.
</p>

### Options

<p style="margin-top: 1em;">
    <strong>--help</strong><br>
    Print help info and exit.<br><br>
    <strong>--ip</strong> <ins>host</ins><br>
    Ip addresses to scan.<br><br>
    <strong>--file</strong> <ins>name</ins><br>
    File name containing IP addresses to scan.<br><br>
    <strong>--filter</strong> <ins>state</ins><br>
    Filter the output by the state of the port (open, closed, filtered, unfiltered).<br><br>
    <strong>--ports</strong> <ins>number/range</ins><br>
    Ports to be scanned (default 1 to 1024).<br><br>
    <strong>--scan</strong> <ins>type</ins><br>
    Type of scan to run (SYN, NULL, ACK, FIN, XMAS, UDP).<br><br>
    <strong>--speedup</strong> <ins>number</ins><br>
    Number of parallel threads to use (default 0, max 250).<br><br>
    <strong>--verbose</strong><br>
    verbose output.<br><br>
    <strong>-4</strong><br>
    Use IPv4.<br><br>
    <strong>-6</strong><br>
    Use IPv6.<br><br>
</p>


*In collaboration with [lmariott](https://github.com/leonmariotto) 🔥*
