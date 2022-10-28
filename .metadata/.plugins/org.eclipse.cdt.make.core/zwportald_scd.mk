# This is a generated file. Please do not edit.

.PHONY: all

COMMANDS := 	\
	    scd_cmd_1

all: $(COMMANDS)

scd_cmd_1:
	@echo begin generating scanner info for $@
	gcc -D 'OS_LINUX=1' -D 'TCP_PORTAL=1' -D '_REENTRANT=1' -D '_LARGEFILE64_SOURCE=1' -D 'LDAP_DEPRECATED=1' -D 'ZWP_DEBUG=1' -D 'ZWP_DEBUG_MUTEX=1' -D 'HAVE_LIBZWSCENE=1' -O0 -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/src/zwave/zwportald/src" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/src/zwave/zwportald/src/util" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/src/zwave/zwportald/src/avi" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/src/zwave/zwportald/src/service" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/src/zwave/zwportald/src/messages/scenes" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/src/zwave/zwportald/src/modules/scenes" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/install/openssl/include" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/install/hcapi/include" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/install/libconfig/include" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/install/libzwscene/include" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/install/glib/include/glib-2.0" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/install/glib/include/glib-2.0/include" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/install/zlib/include" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/install/libffi/lib/libffi-3.0.13/include" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/install/simclist/include" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/install/openldap/include" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/install/avro/include" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/install/apr/include/apr-1" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/install/apr-util/include/apr-1" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/install/sqlite/include" -I "/home/del/workspace/sdk/Z-Ware SDK 1.11/src/zwportal/install/curl/include" -E -P -v -dD specs.c
	@echo end generating scanner info for $@


