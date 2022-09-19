tcpmux		1/tcp				# TCP port service multiplexer
echo		7/tcp
discard		9/tcp		sink null
systat		11/tcp		users
daytime		13/tcp
netstat		15/tcp
qotd		17/tcp		quote
chargen		19/tcp		ttytst source
ftp-data	20/tcp
ftp		21/tcp
ssh		22/tcp				# SSH Remote Login Protocol
telnet		23/tcp
smtp		25/tcp		mail
time		37/tcp		timserver
whois		43/tcp		nicname
tacacs		49/tcp				# Login Host Protocol (TACACS)
domain		53/tcp				# Domain Name Server
gopher		70/tcp				# Internet Gopher
finger		79/tcp
http		80/tcp		www		# WorldWideWeb HTTP
kerberos	88/tcp		kerberos5 krb5 kerberos-sec	# Kerberos v5
iso-tsap	102/tcp		tsap		# part of ISODE
acr-nema	104/tcp		dicom		# Digital Imag. & Comm. 300
pop3		110/tcp		pop-3		# POP version 3
sunrpc		111/tcp		portmapper	# RPC 4.0 portmapper
auth		113/tcp		authentication tap ident
nntp		119/tcp		readnews untp	# USENET News Transfer Protocol
epmap		135/tcp		loc-srv		# DCE endpoint resolution
netbios-ssn	139/tcp				# NETBIOS session service
imap2		143/tcp		imap		# Interim Mail Access P 2 and 4
snmp		161/tcp				# Simple Net Mgmt Protocol
snmp-trap	162/tcp		snmptrap	# Traps for SNMP
cmip-man	163/tcp				# ISO mgmt over IP (CMOT)
cmip-agent	164/tcp
mailq		174/tcp			# Mailer transport queue for Zmailer
bgp		179/tcp				# Border Gateway Protocol
smux		199/tcp				# SNMP Unix Multiplexer
qmtp		209/tcp				# Quick Mail Transfer Protocol
z3950		210/tcp		wais		# NISO Z39.50 database
pawserv		345/tcp				# Perf Analysis Workbench
zserv		346/tcp				# Zebra server
rpc2portmap	369/tcp
codaauth2	370/tcp
ldap		389/tcp			# Lightweight Directory Access Protocol
svrloc		427/tcp				# Server Location
https		443/tcp				# http protocol over TLS/SSL
snpp		444/tcp				# Simple Network Paging Protocol
microsoft-ds	445/tcp				# Microsoft Naked CIFS
kpasswd		464/tcp
submissions	465/tcp		ssmtp smtps urd # Submission over TLS [RFC8314]
saft		487/tcp			# Simple Asynchronous File Transfer
rtsp		554/tcp			# Real Time Stream Control Protocol
nqs		607/tcp				# Network Queuing system
qmqp		628/tcp
ipp		631/tcp				# Internet Printing Protocol
ldp		646/tcp				# Label Distribution Protocol
exec		512/tcp
login		513/tcp
shell		514/tcp		cmd syslog	# no passwords used
printer		515/tcp		spooler		# line printer spooler
gdomap		538/tcp				# GNUstep distributed objects
uucp		540/tcp		uucpd		# uucp daemon
klogin		543/tcp				# Kerberized `rlogin' (v5)
kshell		544/tcp		krcmd		# Kerberized `rsh' (v5)
afpovertcp	548/tcp				# AFP over TCP
nntps		563/tcp		snntp		# NNTP over SSL
submission	587/tcp				# Submission [RFC4409]
ldaps		636/tcp				# LDAP over SSL
tinc		655/tcp				# tinc control port
silc		706/tcp
kerberos-adm	749/tcp				# Kerberos `kadmin' (v5)
domain-s	853/tcp				# DNS over TLS [RFC7858]
rsync		873/tcp
ftps-data	989/tcp				# FTP over SSL (data)
ftps		990/tcp
telnets		992/tcp				# Telnet over SSL
imaps		993/tcp				# IMAP over SSL
pop3s		995/tcp				# POP-3 over SSL
socks		1080/tcp			# socks proxy server
proofd		1093/tcp
rootd		1094/tcp
openvpn		1194/tcp
rmiregistry	1099/tcp			# Java RMI Registry
lotusnote	1352/tcp	lotusnotes	# Lotus Note
ms-sql-s	1433/tcp			# Microsoft SQL Server
ingreslock	1524/tcp
datametrics	1645/tcp	old-radius
sa-msg-port	1646/tcp	old-radacct
kermit		1649/tcp
groupwise	1677/tcp
radius		1812/tcp
radius-acct	1813/tcp	radacct		# Radius Accounting
cisco-sccp	2000/tcp			# Cisco SCCP
nfs		2049/tcp			# Network File System
gnunet		2086/tcp
rtcm-sc104	2101/tcp			# RTCM SC-104 IANA 1/29/99
gsigatekeeper	2119/tcp
gris		2135/tcp		# Grid Resource Information Server
cvspserver	2401/tcp			# CVS client/server operations
venus		2430/tcp			# codacon port
venus-se	2431/tcp			# tcp side effects
codasrv		2432/tcp			# not used
codasrv-se	2433/tcp			# tcp side effects
mon		2583/tcp			# MON traps
dict		2628/tcp			# Dictionary server
f5-globalsite	2792/tcp
gsiftp		2811/tcp
gpsd		2947/tcp
gds-db		3050/tcp	gds_db		# InterBase server
isns		3205/tcp			# iSNS Server Port
iscsi-target	3260/tcp
mysql		3306/tcp
ms-wbt-server	3389/tcp
nut		3493/tcp			# Network UPS Tools
distcc		3632/tcp			# distributed compiler
daap		3689/tcp			# Digital Audio Access Protocol
svn		3690/tcp	subversion	# Subversion protocol
suucp		4031/tcp			# UUCP over SSL
sysrqd		4094/tcp			# sysrq daemon
sieve		4190/tcp			# ManageSieve Protocol
epmd		4369/tcp			# Erlang Port Mapper Daemon
remctl		4373/tcp		# Remote Authenticated Command Service
f5-iquery	4353/tcp			# F5 iQuery
ntske		4460/tcp	# Network Time Security Key Establishment
mtn		4691/tcp			# monotone Netsync Protocol
radmin-port	4899/tcp			# RAdmin Port
sip		5060/tcp			# Session Initiation Protocol
sip-tls		5061/tcp
xmpp-client	5222/tcp	jabber-client	# Jabber Client Connection
xmpp-server	5269/tcp	jabber-server	# Jabber Server Connection
cfengine	5308/tcp
postgresql	5432/tcp	postgres	# PostgreSQL Database
freeciv		5556/tcp	rptp		# Freeciv gameplay
amqps		5671/tcp			# AMQP protocol over TLS/SSL
amqp		5672/tcp
x11		6000/tcp	x11-0		# X Window System
x11-1		6001/tcp
x11-2		6002/tcp
x11-3		6003/tcp
x11-4		6004/tcp
x11-5		6005/tcp
x11-6		6006/tcp
x11-7		6007/tcp
gnutella-svc	6346/tcp			# gnutella
gnutella-rtr	6347/tcp			# gnutella
redis		6379/tcp
sge-qmaster	6444/tcp	sge_qmaster	# Grid Engine Qmaster Service
sge-execd	6445/tcp	sge_execd	# Grid Engine Execution Service
mysql-proxy	6446/tcp			# MySQL Proxy
ircs-u		6697/tcp		# Internet Relay Chat via TLS/SSL
bbs		7000/tcp
font-service	7100/tcp	xfs		# X Font Service
http-alt	8080/tcp	webcache	# WWW caching service
puppet		8140/tcp			# The Puppet master service
bacula-dir	9101/tcp			# Bacula Director
bacula-fd	9102/tcp			# Bacula File Daemon
bacula-sd	9103/tcp			# Bacula Storage Daemon
xmms2		9667/tcp	# Cross-platform Music Multiplexing System
nbd		10809/tcp			# Linux Network Block Device
zabbix-agent	10050/tcp			# Zabbix Agent
zabbix-trapper	10051/tcp			# Zabbix Trapper
amanda		10080/tcp			# amanda backup services
dicom		11112/tcp
hkp		11371/tcp			# OpenPGP HTTP Keyserver
db-lsp		17500/tcp			# Dropbox LanSync Protocol
dcap		22125/tcp			# dCache Access Protocol
gsidcap		22128/tcp			# GSI dCache Access Protocol
wnn6		22273/tcp			# wnn6
kerberos4	750/tcp		kerberos-iv kdc
kerberos-master	751/tcp
krb-prop	754/tcp		krb_prop krb5_prop hprop # Kerberos slave propagation
iprop		2121/tcp			# incremental propagation
supfilesrv	871/tcp			# Software Upgrade Protocol server
supfiledbg	1127/tcp		# Software Upgrade Protocol debugging
poppassd	106/tcp				# Eudora
moira-db	775/tcp		moira_db	# Moira database
moira-update	777/tcp		moira_update	# Moira update protocol
spamd		783/tcp				# spamassassin daemon
skkserv		1178/tcp			# skk jisho server port
rmtcfg		1236/tcp			# Gracilis Packeten remote config server
xtel		1313/tcp			# french minitel
xtelw		1314/tcp			# french minitel
zebrasrv	2600/tcp			# zebra service
zebra		2601/tcp			# zebra vty
ripd		2602/tcp			# ripd vty (zebra)
ripngd		2603/tcp			# ripngd vty (zebra)
ospfd		2604/tcp			# ospfd vty (zebra)
bgpd		2605/tcp			# bgpd vty (zebra)
ospf6d		2606/tcp			# ospf6d vty (zebra)
ospfapi		2607/tcp			# OSPF-API
isisd		2608/tcp			# ISISd vty (zebra)
fax		4557/tcp			# FAX transmission service (old)
hylafax		4559/tcp			# HylaFAX client-server protocol (new)
munin		4949/tcp	lrrd		# Munin
nrpe		5666/tcp			# Nagios Remote Plugin Executor
nsca		5667/tcp			# Nagios Agent - NSCA
canna		5680/tcp			# cannaserver
syslog-tls	6514/tcp			# Syslog over TLS [RFC5425]
sane-port	6566/tcp	sane saned	# SANE network scanner daemon
ircd		6667/tcp			# Internet Relay Chat
zope-ftp	8021/tcp			# zope management by ftp
tproxy		8081/tcp			# Transparent Proxy
omniorb		8088/tcp			# OmniORB
clc-build-daemon 8990/tcp			# Common lisp build daemon
xinetd		9098/tcp
git		9418/tcp			# Git Version Control System
zope		9673/tcp			# zope server
webmin		10000/tcp
kamanda		10081/tcp			# amanda backup services (Kerberos)
amandaidx	10082/tcp			# amanda backup services
amidxtape	10083/tcp			# amanda backup services
sgi-cad		17004/tcp			# Cluster Admin daemon
binkp		24554/tcp			# binkp fidonet protocol
asp		27374/tcp			# Address Search Protocol
csync2		30865/tcp			# cluster synchronization tool
dircproxy	57000/tcp			# Detachable IRC Proxy
tfido		60177/tcp			# fidonet EMSI over telnet
fido		60179/tcp			# fidonet EMSI over TCP
