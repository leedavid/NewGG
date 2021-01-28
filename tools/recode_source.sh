#!/bin/bash
PATTERNS="*.h *.cpp"

recodeconditional()
{
	encoding=$(file -i "$1" | sed "s/.*charset=\(.*\)$/\1/")

	echo $encoding
	case $encoding in
        	utf-16le)
                	recode UTF-16..UTF8 "$1"
                	;;
        	utf-8)
            		;;
        	*)
                	recode GBK..UTF8 "$1"
                	;;
	esac
}

for pattern in $PATTERNS
do
	old_ifs=$IFS
	IFS=$'\n'
	for file in $(find -type f -name $pattern)
	do
		recodeconditional "$file"
	done
	IFS=old_ifs
done
