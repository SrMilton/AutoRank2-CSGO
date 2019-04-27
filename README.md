# AutoRank2-CSGO
## Author: https://github.com/srmilton

### Description
This code will read a text file called by accounts.txt with username and password of the Steam's account which you want to upgrade. It will log in on Steam with that account, open CSGO, inject your cheat and auto join in a match.

### How to use
Create a text file called by "accounts" in the same folder of the .exe, and put your username and password like the example:
```
username123 password123
username456 password456
accounttoupgrade antbruteforcepassword157
anotheraccount anotherpass
```

### Requirements
You will need a cheat preset with aimbot and walkbot ON. (If you have auto queue in your cheat, you will need to change the code). Don't forget to save your cheat.dll in the same folder of the .exe and change the name of the cheat.dll in the code (preset csgocheat.dll).

### How it works
The entire program works with Sleep so if your computer needs more time to works fine with the AutoRank, fell free to change it. The program will read the account in the text file and log in Steam. After that, open CSGO and inject your Dll. The auto queue in the AutoRank was made with mouse clicking (Resolution 1600x900), change it if you need.
