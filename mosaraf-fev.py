#!/usr/bin/env python

import os
import time
import subprocess

def clear_screen():
    os.system('clear')

def connect_to_server():
    server_address = input("Enter the server IP address: ")
    user = input("Enter your target name: ")
    PASSWORD = input("Enter password: ")
    print(f"Trying to connect to {user}@{server_address}...")
    os.system(f'sshpass -p {PASSWORD} ssh {user}@{server_address}')
    if os.WEXITSTATUS(os.system("echo $?")) == 0:
        print("SSH connection established.")
    else:
        print("Failed to establish SSH connection.")
    exit()


def chhost():
    new_hostname = input("Enter new hostname: ")
    os.system(f'hostnamectl set-hostname {new_hostname}')
    print(f"The hostname has been changed to {new_hostname}. Please restart to take effect.\n")


def tycom():
    user_command = input("Enter your command: ")
    command_output = subprocess.check_output(user_command, shell=True)
    print("output:\n", command_output.decode())

    print("Do you want to store this output in a file?")
    type = input("Type:- Yes or No: ")

    if(type == 'Yes'):
        file_name = input("Enter your file name: ")
        # Store the command and its output in a file
        with open(file_name + ".txt", "w") as f:
            f.write(f"Command: {user_command}\n")
            f.write(f"Output:\n{command_output.decode()}")
        
        print("output has been store in", file_name)
    else:
        exit



while True:
    clear_screen()

    print("                                   #######################################")
    print("                                   !!                                   !!")
    print("                                   !!     WELCOME TO MOSARAF WORLD      !!")
    print("                                   !!                                   !!")
    print("                                   #######################################\n\n")

    name = input("Who are you? and What's your name? ")

    if name.lower() == "kamal":
        print("\nOh Wow, You are mine Dear sir\n")
        time.sleep(4)
        print("What would you like to do here? All are yours")
        print("\n1 - Connect via ssh")
        print("2 - To change hostname")
        print("3 - Execute Command")
        print("4 - Option")
        print("5 - Option")
        print("6 - Something else..")
        print("7 - Exit\n")

        distro = input()

        if distro == "1":
            connect_to_server()
        elif distro == "2":
            chhost()
        elif distro == "3":
            tycom()
        elif distro == "4":
            print("You type number 4 option")
        elif distro == "5":
            print("You type number 5 option")
        elif distro == "6":
            print("Have to add so many cool things.")
        elif distro == "7":
            exit()
        else:
            print("you didn't enter an appropriate choice.")

    else:
        print("Sorry! You are not permanent")

    choice = input("Would you like to run the code again? (yes/no) ")

    if choice.lower() in ["n", "no"]:
        break

print("Exiting program...")

