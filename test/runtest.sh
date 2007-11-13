#!/bin/sh
#BHEADER**********************************************************************
# Copyright (c) 2007,  Lawrence Livermore NationalSecurity, LLC.
# Produced at the Lawrence Livermore National Laboratory.
# Written by the HYPRE team. UCRL-CODE-222953.
# All rights reserved.
#
# This file is part of HYPRE (see http://www.llnl.gov/CASC/hypre/).
# Please see the COPYRIGHT_and_LICENSE file for the copyright notice, 
# disclaimer, contact information and the GNU Lesser General Public License.
#
# HYPRE is free software; you can redistribute it and/or modify it under the
# terms of the GNU General Public License (as published by the Free Software 
# Foundation) version 2.1 dated February 1999.
#
# HYPRE is distributed in the hope that it will be useful, but WITHOUT ANY 
# WARRANTY; without even the IMPLIED WARRANTY OF MERCHANTABILITY or FITNESS 
# FOR A PARTICULAR PURPOSE.  See the terms and conditions of the GNU General
# Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program; if not, write to the Free Software Foundation,
# Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
#
# $Revision$
#EHEADER**********************************************************************

# global variables
BatchMode=0
NoRun=0
JobCheckInterval=10        #sleep time between jobs finished check
InputString=""
RunString=""
ExecFileNames=""           #string of executable file names used
TestDirNames=""            #string of names of TEST_* directories used
HOST=`hostname|cut -c1-4`  #first 4 characters of host platform name

function usage
{
   printf "\n"
   printf "$0 [options] {test_path}/{test_name}.sh\n"
   printf "\n"
   printf " where: {test_path} is the directory path to the test script;\n"
   printf "        {test_name} is a user defined name for the test script\n"
   printf "\n"
   printf " with options:\n"
   printf "    -h|-help       prints this usage information and exits\n"
   printf "    -n|-norun      turn off execute mode, echo what would be run\n"
   printf "    -t|-trace      echo each command\n"
   printf "    -D <var>       define <var> when running tests\n"
   printf "\n"
   printf " This is the hypre test driver script.  It is run stand-alone\n"
   printf " or by the autotest regression test script.  It is assumed that\n"
   printf " there are test directories test/TEST_{solver} that contain:\n" 
   printf "   1. Individual test scripts named {test_name}.jobs that provide\n"
   printf "         the mpirun execution syntax\n"
   printf "   2. Test run output files named {test_name}.out.{number}\n"
   printf "   3. Individual scripts to compare (usually using diff) output\n"
   printf "         files from corresponding {test_name}.jobs scripts\n"
   printf "\n"
   printf " Ideally, the *.jobs and *.sh scripts can be run as stand-alone\n"
   printf " shell script files.  A test is considered successful when there \n"
   printf " are no error files generated by the *.sh scripts.\n"
   printf "\n"
   printf " NOTE: This script knows about most of the ASC machines\n"
   printf " and will automatically use the Livermore Computing Resource\n" 
   printf " Management (LCRM) batch system as needed.\n"
   printf "\n"
   printf " Example usage: ./runtest.sh -t TEST_sstruct/*.sh\n"
   printf "\n"
}

# generate default command based on the first 4 characters of the platform name
function MpirunString
{
   case $HOST in
      alc*) shift
         RunString="srun -p pdebug -n$*"
         ;;
      mcr*) shift
         RunString="srun -p pdebug -n$*"
         ;;
      peng*) shift
         RunString="srun -p pdebug -n$*"
         ;;
      thun*) shift
         RunString="srun -p pdebug -n$*"
         ;;
      vert*) shift
         RunString="srun -p pdebug -n$*"
         ;;
      *bgl*) shift
         BatchMode=1
         MY_NUM_TASKS=$1  
         MY_EXECUTE_DIR=`pwd`
         MY_EXECUTE_JOB=`pwd`/$EXECFILE
         shift
         shift
         MY_ARGS="$*"
         RunString="mpirun -verbose 1 -np $MY_NUM_TASKS -exe $MY_EXECUTE_JOB"
         RunString="${RunString} -cwd $MY_EXECUTE_DIR -args \" $MY_ARGS \" "
         ;;
      up*) CPUS_PER_NODE=8
         POE_NUM_PROCS=$2
         POE_NUM_NODES=`expr $POE_NUM_PROCS + $CPUS_PER_NODE - 1`
         POE_NUM_NODES=`expr $POE_NUM_NODES / $CPUS_PER_NODE`
         shift
         shift
         MY_ARGS="$*"
         RunString="poe $EXECFILE -rmpool pbatch -procs $POE_NUM_PROCS"
         RunString="${RunString} -nodes $POE_NUM_NODES $MY_ARGS"
         ;;
      tux*) BatchMode=0
         MACHINES_FILE="hostname"
         if [ ! -f $MACHINES_FILE ] ; then
            hostname > $MACHINES_FILE
         fi
         MPIRUN=`type mpirun|sed -e 's/^.* //'`
         RunString="$MPIRUN -machinefile $MACHINES_FILE $*"
         ;;
      *) MPIRUN=`type mpirun|sed -e 's/^.* //'`
         RunString="$MPIRUN $*"
         ;;
   esac
}

# determine the "number of nodes" desired by dividing the "number of processes"
# by the "number of CPU's per node" which can't be determined dynamically (real
# ugly hack)
function CalcNodes
{
   NUM_PROCS=1
   NUM_NODES=1
   CPUS_PER_NODE=1
   case $HOST in
      alc*) CPUS_PER_NODE=2
         ;;
      mcr*) CPUS_PER_NODE=2
         ;;
      peng*) CPUS_PER_NODE=2
         ;;
      thun*) CPUS_PER_NODE=4
         ;;
      *bgl*) CPUS_PER_NODE=2
         ;;
      up*) CPUS_PER_NODE=8
         ;;
      vert*) CPUS_PER_NODE=2
         ;;
      *) CPUS_PER_NODE=1
         ;;
   esac

   while [ "$1" ]
   do
      case $1 in
         -n*) NUM_PROCS=$2
            NUM_NODES=`expr $NUM_PROCS + $CPUS_PER_NODE - 1`
            NUM_NODES=`expr $NUM_NODES / $CPUS_PER_NODE`
            return $NUM_NODES
            ;;
         *) shift
            ;;
      esac
   done
   return 1
}

# extract the "number of processes/task"
function CalcProcs
{
   while [ "$1" ]
   do
      case $1 in
         -n*) return $2
            ;;
         *) shift
            ;;
      esac
   done
   return 1
}

# determine if HOST machine can process batch queues
#    set to run in debug pool unless batch MUST be used.
function CheckBatch
{
   case $HOST in
      alc*) BATCH_MODE=0
         ;;
      mcr*) BATCH_MODE=0
         ;;
      peng*) BATCH_MODE=0
         ;;
      thun*) BATCH_MODE=0
         ;;
      *bgl*) BATCH_MODE=1
         ;;
      up*) BATCH_MODE=0
         ;;
      vert*) BATCH_MODE=0
         ;;
      *) BATCH_MODE=0
         ;;
   esac
   return $BATCH_MODE
}

# check the path to the executable if the executable exists; save the name to
# ExecFileNames
function CheckPath
{
   while [ "$1" ]
   do
      case $1 in
         -n*) EXECFILE=$3
            if [ -x $StartDir/$EXECFILE ] ; then
               cp -f $StartDir/$EXECFILE $EXECFILE
               ExecFileNames="$ExecFileNames $EXECFILE"
               return 0
            else
               echo "Cannot find executable!!!"
               return 1
            fi
            return 0
            ;;
         *) shift
            ;;
      esac
   done
   return 1
}

# initialize the common part of the " PsubCmd" string, ugly global vars!
# global "RunName" is assumed to be predefined
#
# on ubgl, as of 8/2006, only allowable number of nodes are 32, 128 and 
# multiples of 512
function PsubCmdStub
{
   CalcNodes "$@"
   NumNodes=$?
   CalcProcs "$@"
   NumProcs=$?
   case $HOST in
      alc*) PsubCmd="psub -c alc,pbatch -b casc -r $RunName -ln $NumProcs"
         ;;
      mcr*) PsubCmd="psub -c mcr,pbatch -b casc -r $RunName -ln $NumProcs"
         ;;
      peng*) PsubCmd="psub -c pengra,pbatch -b casc -r $RunName -ln $NumProcs"
         ;;
      thun*) PsubCmd="psub -c thunder,pbatch -b casc -r $RunName -ln $NumNodes -g $NumProcs"
         ;;
      ubgl*) PsubCmd="psub -c ubgl -pool pbatch -b science -r $RunName -ln 32"
         ;;
      up*) PsubCmd="psub -c up -pool pbatch -b a_casc -r $RunName -ln $NumProcs"
         ;;
      vert*) PsubCmd="psub -c vertex,pbatch -b casc -r $RunName -ln $NumProcs"
         ;;
      *) PsubCmd="psub -b casc -r $RunName -ln $NumProcs"
         ;;
   esac
}

# read job file line by line saving arguments
function ExecuteJobs
{
   StartDir=$1
   WorkingDir=$2
   InputFile=$3
   ReturnFlag=0              # error return flag
   BatchFlag=0               # #BATCH option detected flag 
   BatchCount=0              # different numbering for #Batch option
   PrevPid=0
   SavePWD=`pwd`
##
##     move to specified directory
   cd $WorkingDir

##     open *.jobs files for reading
   while read InputLine
   do
      case $InputLine in
         "#BATCH"*) BatchFlag=1
            BatchFile=""
            ;;

         "#END"*) BatchFlag=0
            chmod +x $BatchFile
            PsubCmd="$PsubCmd -o $OutFile -e $ErrFile `pwd`/$BatchFile"
            if [ "$NoRun" -eq 0 ] ; then
               CmdReply=`$PsubCmd`
            fi
            PrevPid=`echo $CmdReply | cut -d \  -f 2`
            while [ "`pstat | grep $PrevPid`" ]
            do
               sleep $JobCheckInterval
            done
            BatchFile=""
            ;;

         *mpirun*)
            RunCmd=`echo $InputLine| sed -e 's/^[ \t]*mpirun[ \t]*//'` 
            RunCmd=`echo $RunCmd | sed -e 's/[ \t]*>.*$//'`
            OutFile=`echo $InputLine | sed -e 's/^.*>//'`
            OutFile=`echo $OutFile | sed -e 's/ //g'`
            ErrFile=`echo $OutFile | sed -e 's/\.out\./.err./'`
            RunName=`echo $OutFile | sed -e 's/\.out.*$//'`
            CheckPath $RunCmd               # check path to executable
            if [ "$?" -gt 0 ] ; then
               cat >> $RunName.err <<- EOF
Executable doesn't exist command: 
$InputLine 
EOF
               ReturnFlag=1
               break
            fi
            MpirunString $RunCmd            # construct "RunString"
            case $HOST in
               *bgl*) RunString="${RunString} > `pwd`/$OutFile 2>`pwd`/$ErrFile"
            esac
            if [ "$BatchMode" -eq 0 ] ; then
               ${RunString} > $OutFile 2> $ErrFile </dev/null
            else
               if [ "$BatchFlag" -eq 0 ] ; then
                  BatchFile=`echo $OutFile | sed -e 's/\.out\./.batch./'`
                  cat > $BatchFile <<- EOF 
#!/bin/sh
cd `pwd`
${RunString}
EOF
                  chmod +x $BatchFile
                  PsubCmdStub ${RunCmd}
                  case $HOST in
                     *bgl*) PsubCmd="$PsubCmd `pwd`/$BatchFile"
                            ;;
                         *) PsubCmd="$PsubCmd -o $OutFile -e $ErrFile `pwd`/$BatchFile"
                            ;;
                  esac
                  if [ "$NoRun" -eq 0 ] ; then
                     CmdReply=`$PsubCmd`
                  fi
                  PrevPid=`echo $CmdReply | cut -d \  -f 2`
                  while [ "`pstat | grep $PrevPid`" ]
                  do
                     sleep $JobCheckInterval
                  done
               else                          # BatchFlag set
                  if [ "$BatchFile" -eq "" ] ; then
                     BatchFile=$InputFile.batch.$BatchCount
                     BatchCount=BatchCount+1
                     cat > $BatchFile <<- EOF
#!/bin/sh
cd `pwd`
${RunString}
EOF
                  else
                     cat >> $BatchFile <<- EOF
${RunString}
EOF
                  fi
                  PsubCmdStub ${RunCmd}     # construct a PsubCmd string
               fi                           # BatchFlag set
            fi                              # BatchMode set
            ;;

         *"#"*) :
            ;; 

         *)
            NOTBLANK=`echo $InputLine | sed 's/[ \n\t]//g'`
            if [ "$NOTBLANK" ] ; then
               echo "Found something unexpected in $WorkingDir/$InputFile.jobs"
               echo "--> $InputLine"
               exit 1
            fi
            ;;
      esac
   done < $InputFile.jobs           # done with open *.jobs file for reading
   cd $SavePWD
   return $ReturnFlag
}

#   compare output files as defined in *.sh files
function ExecuteTest
{
   StartDir=$1
   WorkingDir=$2
   InputFile=$3
   SavePWD=`pwd`
   cd $WorkingDir
   (cat $InputFile.err.* > $InputFile.err)
   (./$InputFile.sh     >> $InputFile.err 2>&1 &) 
   cd $SavePWD
}

#  report errors from PURIFY and/or INSURE if run 
function PostProcess
{
   StartDir=$1
   WorkingDir=$2
   InputFile=$3
   SavePWD=`pwd`
   cd $WorkingDir
   if [ "$BatchMode" -eq 0 ] ; then
      if [ -f purify.log ] ; then
         mv purify.log $InputFile.purify.log
         grep -i hypre_ $InputFile.purify.log >> $InputFile.err
      elif [ -f insure.log ] ; then
         mv insure.log $InputFile.insure.log
         grep -i hypre_ $InputFile.insure.log >> $InputFile.err
      fi
   fi
   cd $SavePWD
}

               
# removes executable and hostname files from all TEST_* directories
function CleanUp
{
   if [ "$BatchMode" -eq 0 ] ; then
      for i in $TestDirNames
      do 
         for j in $ExecFileNames
         do 
            ExecuteFile=$i/$j
            if [ -x $ExecuteFile ] ; then
               rm -f $ExecuteFile
               rm -f hostname
            fi
         done
         ExecuteFile=$i/hostname
         if [ -f $ExecuteFile ] ; then
            rm -f $ExecuteFile
         fi
      done
   fi
}

# process files
function StartCrunch
{
   CheckBatch
   BatchMode=$?
   ExecuteJobs "$@"
   RtnCode=$?
   if [ "$RtnCode" -eq 0 ] ; then
      ExecuteTest "$@"
      RtnCode=$?
   fi
   if [ "$RtnCode" -eq 0 ] ; then
      PostProcess "$@"
   fi
}

# main

while [ "$*" ]
do
   case $1 in
      -h|-help)
         usage
         exit
         ;;
      -n|-norun)
         NoRun=1
         shift
         ;;
      -t|-trace)
         set -xv
         shift
         ;;
      -D)
         shift
         eval export `echo $1`=1
         shift
         ;;
      *) InputString=$1
         if [ "$InputString" ] ; then
            if [ -r $InputString ] ; then
               FilePart=`basename $InputString .sh`
               DirPart=`dirname $InputString`
               CurDir=`pwd`
               TestDirNames="$TestDirNames $DirPart"
               case $DirPart in
                  TEST_examples)
                     ExampleFiles="ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex8 ex9"
                     BabelExampleFiles="ex5b ex5b77"
                     cd ../examples
                     for file in $ExampleFiles $BabelExampleFiles
                     do
                        if [ -x $file ]
                        then
                           cp -f $file $CurDir
                        fi
                     done
                     cd $CurDir
                     ;;
               esac
               if [ -r $DirPart/$FilePart.jobs ] ; then
                  StartCrunch $CurDir $DirPart $FilePart
               else
                  printf "%s: test command file %s/%s.jobs does not exist\n" \
                     $0 $DirPart $FilePart
                  exit 1
               fi
            else
               printf "%s: test command file %s does not exist\n" \
                  $0 $InputString
               printf "can not find .sh file\n"
               exit 1
            fi
         else
            printf "%s: Strange input parameter=%s\n" $0 $InputString
            exit 1
         fi
         shift
         ;;
   esac
done
#
#     remove exectutable files from TEST_* directories
CleanUp $TestDirNames $ExecFileNames
