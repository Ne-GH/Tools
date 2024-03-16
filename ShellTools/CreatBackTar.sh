cd /
tar -cvpzf /backup.tar.gz --exclude=/proc --exclude=/sys --exclude=/dev --exclude=/run --exclude=/mnt --exclude=/media --exclude=/tmp --exclude=/lost+found --exclude=/var/log --exclude=/var/cache/apt/archives --exclude=/usr/src/linux-headers* --exclude=/home/*/.gvfs --exclude=/home/*/.cache --exclude=/home/*/.local/share/Trash --exclude=/home/yongheng/.SteamGames --exclude=/home/yongheng/VArch --exclude=/home/yongheng/.local/share/Steam/steamapps --exclude=/var/lib/libvirt/images --exclude=/backup.tar.gz --exclude=/var/cache/pacman/pkg /

mv /backup.tar.gz /home/yongheng/backup-`date +%Y-%m-%d`.tar.gz
