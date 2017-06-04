#!/bin/bash

OUTDIR="../../output"
LOGDIR="../../log"
LOGNAME="analysis.log"
LOGFILE=$LOGDIR/$LOGNAME

rm -f -r -d $OUTDIR
rm -f -r -d $LOGDIR

mkdir -p  $OUTDIR
mkdir -p  $LOGDIR

printf  "Static code analysis of c++ examples that base on Scott Meyers rules" >> $LOGFILE

LIST=`find ../../ -name *exam* | sort | tr '\n' ' '`

for ONE_OF_LIST in $LIST
do
	for EXTYPE in "good" "bad"
	do
		# log #
		RDIR="$ONE_OF_LIST/$EXTYPE"
		echo $RDIR
		printf  "\n\nAnalysis: $RDIR" >> $LOGFILE

		# file extration #
		MAINF=`ls -A1 $ONE_OF_LIST/$EXTYPE/Mrs*.cpp`
		FL=$(basename $MAINF)
		FNAME="${FL%.*}" 
		#echo $FNAME

		# g++ #
		echo >> $LOGFILE
		g++ -std=c++11 -Weffc++ $MAINF -o $OUTDIR/$FNAME 1>> $LOGFILE 2>> $LOGFILE
		
	done
done
