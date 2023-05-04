#!/bin/bash


clear


echo "                                   #######################################"
echo "                                   !!                                   !!"
echo "                                   !!     WELCOME TO MOSARAF WORLD      !!"
echo "                                   !!                                   !!"
echo "                                   #######################################"
echo
echo
echo
echo


function connect_to_server(){
    read -p "Enter the server IP address: " server_address
    read -p "Enter your target name: " user
    echo "Enter password: "
    read -s PASSWORD
    echo "Trying to connect to $user@$server_address..."
    sshpass -p $PASSWORD ssh $user@$server_address
    if [ $? -eq 0 ]; then
        echo "SSH connection established."
    else
        echo "Failed to establish SSH connection."
    fi
    exit
}


function installjen(){

sudo apt update -y
sudo apt install openjdk-11-jre -y

curl -fsSL https://pkg.jenkins.io/debian-stable/jenkins.io-2023.key | sudo tee \
  /usr/share/keyrings/jenkins-keyring.asc > /dev/null
echo deb [signed-by=/usr/share/keyrings/jenkins-keyring.asc] \
  https://pkg.jenkins.io/debian-stable binary/ | sudo tee \
  /etc/apt/sources.list.d/jenkins.list > /dev/null
sudo apt-get update -y
sudo apt-get install jenkins -y
}


function chhost(){
	read -p "Enter new hostname: " new_hostname
	hostnamectl set-hostname "$new_hostname"
	echo "This hostname has been change to $new_hostname. Please restart to system to take effect."
}

while true; do
    read -p "Who are you? and What's your name?  " name

    if [ "$name" == "Kamal" ] || [ "$name" == "kamal" ]; then
	echo ""
        echo "Oh Wow, You are mine Dear sir"
	sleep 3 
	echo ""
        echo "What would you like to do here? All are your"
        sleep 2
	echo
        echo "1 - Connect via ssh"
        echo "2 - To install jenkins (On linux only)"
        echo "3 - To change hostname"
        echo "4 - Option"
        echo "5 - Option"
        echo "6 - Something else.."
        echo "7 - Exit"
        echo

        read distro

        case $distro in
	    1) connect_to_server;;
            2) installjen;;
            3) chhost;;
            4) echo "You type number 4 option";;
            5) echo "You type number 5 option";;
            6) echo "Have to add so many cool things.";;
            7) exit;;
            *) echo "you didn't enter an appropriate choice.";;
        esac

    else
        echo "Sorry! You are not permanent"
    fi

    read -p "Would you like to run the code again? (yes/no) " choice

    if [[ "$choice" =~ ^[nN][oO]?$|^no$ ]]; then
        break
    fi
done

echo "Exiting program..."










