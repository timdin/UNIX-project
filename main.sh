#!/bin/bash

while getopts ":d:vhs" opt; do
	case $opt in
		d)
			echo "doing download with the input $OPTARG" >&2
			python search_automaiton.py $OPTARG
			python page_automation.py
			chmod u+x download_script.sh
			./download_script.sh
			rm download_script.sh
			rm url_list.txt
			;;
		v)
			echo "opening viewer..." >&2
			;;
		h)
			echo "please use -v to open the GUI reader, use -d KEYWORD to do the search" >&2
			exit 1
			;;
		s)
			echo "setting up the enviroment..."
			./setup.sh
			;;
		:)
			echo "please add the keyword you would like to search!">&2
			exit 1
			;;
	esac
done
