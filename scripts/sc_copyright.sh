usage="Usage: sc_copyright.sh target file"

if [ $# -lt 2 ]
then
	echo "$usage"
	exit
fi

cat "./etc/copyright" | while :
do

	read instr

	if [ "`echo "$instr" | grep "#end"`" != "" ]
	then
		break
	fi

	case $1 in

		c)

			echo "//	$instr" >> $2

			;;

		sh)

			echo "#	$instr" >> $2

			;;

		*)

			echo "$usage"
			exit
			;;


	esac

done

