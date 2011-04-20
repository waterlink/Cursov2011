if [ $# -lt 3 ]
then 
	echo "Usage: sc_addvalue file var value"
	exit
fi
rm temp
cat $1 | while :
do
	read instr
	a1=`echo "$instr" | grep "$2"`
	a2=`echo "$instr"`
	a3=`echo "$instr" | grep "#end"`
	if [ "$a1" != "" ] 
	then
		echo " $instr $3 " >> temp
	elif [ "$a3" != "" ] 
	then
		echo "#end" >> temp
		break;
	else
		echo " $instr " >> temp
	fi
done
cp temp text

