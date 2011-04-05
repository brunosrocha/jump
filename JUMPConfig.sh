#!/bin/bash
#
# Automatically Link Header Files
#

###### ###### ###### ###### ###### ###### ###### ###### 
# Print Header.
printHeader() {
	echo 'JUMP Library Installation Script 1.0'
	echo ''
}

###### ###### ###### ###### ###### ###### ###### ###### 
# Print Usage Help.
printHelp() {
	echo 'Usage:'
	echo '   JUMPConfig.sh <option>'
	echo ''
	echo '   -configure         Configure all JUMP Headers.'
	echo '   -clean             Clean all configured JUMP Headers.'
	echo '   -cleanconfigure    Clean all configured JUMP Headers and install again.'
	echo ''
}

###### ###### ###### ###### ###### ###### ###### ###### 
# Clean all.
cleanAll() {
	# if Headers Directory exist...
	if [ -d "Headers" ]; then
		echo 'Cleaning...'
		rm -r Headers
		# Confirm.
		if [ ! -d "Headers" ]; then
			echo Ok!
		else
			echo "Can't delete! Please check..."
		fi
	else 
		echo "Can't clean because the 'Headers' folder doesn't exist."
	fi
	echo ''
}

###### ###### ###### ###### ###### ###### ###### ###### 
# Configure
configure() {
	# if Headers Directory doesn't exist...
	if [ ! -d "Headers" ]; then
		echo "Creating Main Headers Directory..."
		mkdir Headers
	else
		echo "'Headers' folder already exist, you must clean it first."
		echo ''
		return
	fi

	echo "Acessing Main Headers Directory..."
	cd Headers

	######## ######## ######## ######## ######## ######## ########  
	# if JUMPCore Directory exist...
	if [ -d "../JUMPCore/Headers" ]; then
		echo "Linking JUMPCore Headers..."
		ln -s ../JUMPCore/Headers/* .
	fi

	######## ######## ######## ######## ######## ######## ########  
	# if JUMPCore Directory exist...
	if [ -d "../JUMPData/Headers" ]; then
		echo "Linking JUMPData Headers..."
		ln -s ../JUMPData/Headers/* .
	fi

	######## ######## ######## ######## ######## ######## ########  
	# if JUMPCore Directory exist...
	if [ -d "../JUMPDatabase/Headers" ]; then
		echo "Linking JUMPDatabase Headers..."
		ln -s ../JUMPDatabase/Headers/* .
	fi

	######## ######## ######## ######## ######## ######## ########  
	# if JUMPCore Directory exist...
	if [ -d "../JUMPNetwork/Headers" ]; then
		echo "Linking JUMPNetwork Headers..."
		ln -s ../JUMPNetwork/Headers/* .
	fi

	######## ######## ######## ######## ######## ######## ########  
	# if JUMPCore Directory exist...
	if [ -d "../JUMPUserInterface/Headers" ]; then
		echo "Linking JUMPUserInterface Headers..."
		ln -s ../JUMPUserInterface/Headers/* .
	fi

	######## ######## ######## ######## ######## ######## ########  
	# if JUMPCore Directory exist...
	if [ -d "../JUMPLogger/Headers" ]; then
		echo "Linking JUMPLogger Headers (Includes Log4CocoaTouch and NSLogger..."
		ln -s ../JUMPLogger/Headers/* .
		ln -s ../JUMPLogger/Libraries/Log4CocoaTouch/Headers/* .
		ln -s ../JUMPLogger/Libraries/NSLogger/Headers/* .
	fi
}

###### ###### ###### ###### ###### ###### ###### ###### 
# Conditional parameters.
printHeader
case "$1" in
      "-configure")
        configure
        ;;
      "-clean")
        cleanAll
        ;;
      "-cleanconfigure")
        cleanAll
		configure
        ;;
      *)
      # Help so..
        printHelp
        ;;
    esac