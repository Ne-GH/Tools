#! /usr/bin/bash


if [ $# -le 0 ] ; then
    timeout 2s ping -c1 www.bing.com >> /dev/null
fi


if [ $? -eq 0 ] ; then
    echo "Network is good"
else
    echo "Network is bad"
fi

