if [ $# -lt 3 ]
then 
	echo "Usage: sc_delvalue file var value"
	exit
fi
rm temp
cat $1 | while :
do
	read instr
	a1=`echo "$instr" | grep "$2"`
	a2=`echo "$instr"`
	a3=`echo "$instr" | grep "#end"`
	a4=`echo "$instr" | grep "$3"`
	if [ "$a1" != "" ] 
	then
		if [ "$a4" != "" ]
		then
			echo " $instr " | sed s/" $3 "/" "/g >> temp
		else
			echo " $instr " >> temp
		fi
	elif [ "$a3" != "" ] 
	then
		echo "#end" >> temp
		break;
	else
		echo " $instr " >> temp
	fi
done
cp temp text

