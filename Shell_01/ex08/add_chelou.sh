#!/bin/sh

#FT_NBR1="\\\'?\"\\\"'\\"
#FT_NBR2="rcrdmddd"

C1=$(echo $FT_NBR1 | sed "s/\'/0/g" | sed 's/\\/1/g' | sed "s/\"/2/g" | sed "s/?/3/g" | sed "s/!/4/g")
C2=$(echo $FT_NBR2 | tr 'mrdoc' '01234')

echo "obase=13; ibase=5; $C1 + $C2" | bc | tr '0123456789ABC' 'gtaio luSnemf'

