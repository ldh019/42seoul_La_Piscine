#!/bin/sh

ifconfig -a | grep "^\tether" | awk '{print $2}'
