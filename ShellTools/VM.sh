#!/usr/bin/bash
#

sudo systemctl start libvirtd

sudo virsh net-start default

sudo virt-manager

# echo "请在打开虚拟机前确保挂载了虚拟磁盘所在的硬盘"
