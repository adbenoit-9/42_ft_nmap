echo		7/udp
discard		9/udp		sink null
daytime		13/udp
chargen		19/udp		ttytst source
fsp		21/udp		fspd
time		37/udp		timserver
tacacs		49/udp
domain		53/udp
bootps		67/udp
bootpc		68/udp
tftp		69/udp
kerberos	88/udp		kerberos5 krb5 kerberos-sec	# Kerberos v5
sunrpc		111/udp		portmapper
ntp		123/udp				# Network Time Protocol
netbios-ns	137/udp				# NETBIOS Name Service
netbios-dgm	138/udp				# NETBIOS Datagram Service
snmp		161/udp
snmp-trap	162/udp		snmptrap
cmip-man	163/udp
cmip-agent	164/udp
xdmcp		177/udp			# X Display Manager Control Protocol
ipx		213/udp				# IPX [RFC1234]
ptp-event	319/udp
ptp-general	320/udp
rpc2portmap	369/udp				# Coda portmapper
codaauth2	370/udp				# Coda authentication server
clearcase	371/udp		Clearcase
ldap		389/udp
svrloc		427/udp
https		443/udp				# HTTP/3
kpasswd		464/udp
isakmp		500/udp				# IPSEC key management
rtsp		554/udp
asf-rmcp	623/udp		# ASF Remote Management and Control Protocol
ldp		646/udp
biff		512/udp		comsat
who		513/udp		whod
syslog		514/udp
talk		517/udp
ntalk		518/udp
route		520/udp		router routed	# RIP
gdomap		538/udp
dhcpv6-client	546/udp
dhcpv6-server	547/udp
ldaps		636/udp
tinc		655/udp
domain-s	853/udp				# DNS over DTLS [RFC8094]
openvpn		1194/udp
ms-sql-m	1434/udp			# Microsoft SQL Monitor
datametrics	1645/udp	old-radius
sa-msg-port	1646/udp	old-radacct
l2f		1701/udp	l2tp
radius		1812/udp
radius-acct	1813/udp	radacct
nfs		2049/udp			# Network File System
gnunet		2086/udp
rtcm-sc104	2101/udp
venus		2430/udp			# Venus callback/wbc interface
venus-se	2431/udp			# udp sftp side effect
codasrv		2432/udp			# server port
codasrv-se	2433/udp			# udp sftp side effect
mon		2583/udp
icpv2		3130/udp	icp		# Internet Cache Protocol
isns		3205/udp			# iSNS Server Port
nut		3493/udp
ipsec-nat-t	4500/udp			# IPsec NAT-Traversal [RFC3947]
iax		4569/udp			# Inter-Asterisk eXchange
sip		5060/udp
sip-tls		5061/udp
mdns		5353/udp			# Multicast DNS
gnutella-svc	6346/udp
gnutella-rtr	6347/udp
babel		6696/udp			# Babel Routing Protocol
afs3-fileserver 7000/udp
afs3-callback	7001/udp			# callbacks to cache managers
afs3-prserver	7002/udp			# users & groups database
afs3-vlserver	7003/udp			# volume location database
afs3-kaserver	7004/udp			# AFS/Kerberos authentication
afs3-volser	7005/udp			# volume managment server
afs3-bos	7007/udp			# basic overseer process
afs3-update	7008/udp			# server-to-server updater
afs3-rmtsys	7009/udp			# remote cache manager service
kerberos4	750/udp		kerberos-iv kdc	# Kerberos (server)
kerberos-master	751/udp		kerberos_master	# Kerberos authentication
passwd-server	752/udp		passwd_server	# Kerberos passwd server
zephyr-srv	2102/udp			# Zephyr server
zephyr-clt	2103/udp			# Zephyr serv-hm connection
zephyr-hm	2104/udp			# Zephyr hostmanager
moira-ureg	779/udp		moira_ureg	# Moira user registration
predict		1210/udp			# predict -- satellite tracking
rplay		5555/udp			# RPlay audio service
sgi-cmsd	17001/udp		# Cluster membership services daemon
sgi-crsd	17002/udp
sgi-gcd		17003/udp			# SGI Group membership daemon
asp		27374/udp
