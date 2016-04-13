Last login: Sun Mar  6 09:06:17 on ttys000
Brians-Air:~ Briandawgg$ ls
Applications		Dropbox			Pictures
Creative Cloud Files	Google Drive		Public
Desktop			Library			brians-project
Documents		Movies			microscope
Downloads		Music
Brians-Air:~ Briandawgg$ ssh z5035087@cse.unsw.edu.au
z5035087@cse.unsw.edu.au's password: 
Connection closed by 129.94.242.19
Brians-Air:~ Briandawgg$ ssh z5035087@cse.unsw.edu.au
Warning: Permanently added the RSA host key for IP address '129.94.242.49' to the list of known hosts.
z5035087@cse.unsw.edu.au's password: 
Permission denied, please try again.
z5035087@cse.unsw.edu.au's password: 

                       You are using a computer owned by
 University of New South Wales  -  School of Computer Science and Engineering



           ***** This service is for authorised clients only *****

 ****************************************************************************
 *                                                                          *
 * WARNING:     It is a criminal offence to:                                *
 *                                                                          *
 *              i.  Obtain access to data without permission                *
 *                        (Penalty 2 years imprisonment)                    *
 *              ii. Damage, delete, alter or insert data without permission *
 *                        (Penalty 10 years imprisonment)                   *
 *                                                                          *
 ****************************************************************************
No mail.
weill % ls
Desktop    Downloads  Pictures	Templates  public_html
Documents  Music      Public	Videos
weill % gcc --version
gcc (Debian 4.9.2-10cse1) 4.9.2
Copyright (C) 2014 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

weill % echo 'Eureka!'
Eureka!
weill % echo

weill % echo lol
lol
weill % echo 'lol'
lol
weill % echo "lol"
lol
weill % ls
Desktop    Downloads  Pictures	Templates  public_html
Documents  Music      Public	Videos
weill % Desktop
-bash: Desktop: command not found
weill % cd Desktop
weill % ls
weill % .. 
-bash: ..: command not found
weill % //
-bash: //: is a directory
weill % ..
-bash: ..: command not found
weill % ls
weill % echo lol
lol
weill % Downloads
-bash: Downloads: command not found
weill % cd Downloads
-bash: cd: Downloads: No such file or directory
weill % ls
weill % exit
logout
Connection to cse.unsw.edu.au closed.
Brians-Air:~ Briandawgg$ ssh z5035087@cse.edu.au
The authenticity of host 'cse.edu.au (192.252.158.119)' can't be established.
RSA key fingerprint is 51:1c:30:16:fb:5a:7f:a4:b3:14:ac:fe:83:a2:22:f5.
Are you sure you want to continue connecting (yes/no)? yes
Warning: Permanently added 'cse.edu.au,192.252.158.119' (RSA) to the list of known hosts.
z5035087@cse.edu.au's password: 
Permission denied, please try again.
z5035087@cse.edu.au's password: 
Permission denied, please try again.
z5035087@cse.edu.au's password: 
Permission denied (publickey,password).
Brians-Air:~ Briandawgg$ ssh z5035087@cse.unsw.edu.au
z5035087@cse.unsw.edu.au's password: 

                       You are using a computer owned by
 University of New South Wales  -  School of Computer Science and Engineering



           ***** This service is for authorised clients only *****

 ****************************************************************************
 *                                                                          *
 * WARNING:     It is a criminal offence to:                                *
 *                                                                          *
 *              i.  Obtain access to data without permission                *
 *                        (Penalty 2 years imprisonment)                    *
 *              ii. Damage, delete, alter or insert data without permission *
 *                        (Penalty 10 years imprisonment)                   *
 *                                                                          *
 ****************************************************************************
No mail.
wagner % ls
Desktop    Downloads  Pictures	Templates  public_html
Documents  Music      Public	Videos
wagner % Templates
-bash: Templates: command not found
wagner % open Templates
Couldnt get a file descriptor referring to the console
Could not get a file descriptor referring to the console
wagner % cd Templates
wagner % ls
wagner % cd
wagner % ls
Desktop    Downloads  Pictures	Templates  public_html
Documents  Music      Public	Videos
wagner % Public
-bash: Public: command not found
wagner % cd Public
wagner % ls
wagner % cd
wagner % ls
Desktop    Downloads  Pictures	Templates  public_html
Documents  Music      Public	Videos
wagner % cd Documents
wagner % ls
wagner % cd
wagner % ls
Desktop    Downloads  Pictures	Templates  public_html
Documents  Music      Public	Videos
wagner % cd Pictures
wagner % ls
wagner % cd
wagner % ls
Desktop    Downloads  Pictures	Templates  public_html
Documents  Music      Public	Videos
wagner % exit
logout
Connection to cse.unsw.edu.au closed.
Brians-Air:~ Briandawgg$ Homebrew
-bash: Homebrew: command not found
Brians-Air:~ Briandawgg$ The missing package manager for OS X
-bash: The: command not found
Brians-Air:~ Briandawgg$ 
Brians-Air:~ Briandawgg$ 
Brians-Air:~ Briandawgg$ Install Homebrew
usage: install [-bCcpSsv] [-B suffix] [-f flags] [-g group] [-m mode]
               [-o owner] file1 file2
       install [-bCcpSsv] [-B suffix] [-f flags] [-g group] [-m mode]
               [-o owner] file1 ... fileN directory
       install -d [-v] [-g group] [-m mode] [-o owner] directory ...
Brians-Air:~ Briandawgg$ 
Brians-Air:~ Briandawgg$ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
Paste that at a Terminal prompt.

The script explains what it will do and then pauses before it does it. There are more installation options here (needed on 10.5).

What Does Homebrew Do?

Homebrew installs the stuff you need that Apple didn’t.

$ brew install wget
Homebrew installs packages to their own directory and then symlinks their files into /usr/local.

$ cd /usr/local
$ find Cellar
Cellar/wget/1.16.1
Cellar/wget/1.16.1/bin/wget
Cellar/wget/1.16.1/share/man/man1/wget.1

$ ls -l bin
bin/wget -> ../Cellar/wget/1.16.1/bin/wget
Homebrew won’t install files outside its prefix, and you can place a Homebrew installation wherever you like.

Trivially create your own Homebrew packages.

$ brew create https://foo.com/bar-1.0.tgz
Created /usr/local/Library/Formula/bar.rb
It's all git and ruby underneath, so hack away with the knowledge that you can easily revert your modifications and merge upstream updates.

$ brew edit wget # opens in $EDITOR!
Homebrew formulae are simple Ruby s==> This script will install:
/usr/local/bin/brew
/usr/local/Library/...
/usr/local/share/man/man1/brew.1
==> The following directories will be made group writable:
/usr/local/.
/usr/local/bin
==> The following directories will have their owner set to Briandawgg:
/usr/local/.
/usr/local/bin
==> The following directories will have their group set to admin:
/usr/local/.
/usr/local/bin

Press RETURN to continue or any other key to abort
Brians-Air:~ Briandawgg$ ula
-bash: ula: command not found
Brians-Air:~ Briandawgg$   homepage "https://www.gnu.org/software/wget/"
-bash: homepage: command not found
Brians-Air:~ Briandawgg$   url "https://ftp.gnu.org/gnu/wget/wget-1.15.tar.gz"
-bash: url: command not found
Brians-Air:~ Briandawgg$   sha256 "52126be8cf1bddd7536886e74c053ad7d0ed2aa89b4b630f76785bac21695fcd"
-bash: sha256: command not found
Brians-Air:~ Briandawgg$ 
Brians-Air:~ Briandawgg$   def install
-bash: def: command not found
Brians-Air:~ Briandawgg$     system "./configure", "--prefix=#{prefix}"
-bash: system: command not found
Brians-Air:~ Briandawgg$     system "make", "install"
-bash: system: command not found
Brians-Air:~ Briandawgg$   end
-bash: end: command not found
Brians-Air:~ Briandawgg$ end
-bash: end: command not found
Brians-Air:~ Briandawgg$ Homebrew complements OS X. Install your gems with gem, and their dependencies with brew.
-bash: Homebrew: command not found
Brians-Air:~ Briandawgg$ 
Brians-Air:~ Briandawgg$ Further Documentation
-bash: Further: command not found
Brians-Air:~ Briandawgg$ https://git.io/brew-docs
-bash: https://git.io/brew-docs: No such file or directory
Brians-Air:~ Briandawgg$ 
Brians-Air:~ Briandawgg$ Original code by Max Howell. Website by Rémi Prévost.
-bash: Original: command not found
Brians-Air:~ Briandawgg$ Fork me on GitHub
-bash: Fork: command not found
Brians-Air:~ Briandawgg$ /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
==> This script will install:
/usr/local/bin/brew
/usr/local/Library/...
/usr/local/share/man/man1/brew.1
==> The following directories will be made group writable:
/usr/local/.
/usr/local/bin
==> The following directories will have their owner set to Briandawgg:
/usr/local/.
/usr/local/bin
==> The following directories will have their group set to admin:
/usr/local/.
/usr/local/bin

Press RETURN to continue or any other key to abort
==> /usr/bin/sudo /bin/chmod g+rwx /usr/local/. /usr/local/bin
Password:
==> /usr/bin/sudo /usr/sbin/chown Briandawgg /usr/local/. /usr/local/bin
==> /usr/bin/sudo /usr/bin/chgrp admin /usr/local/. /usr/local/bin
==> /usr/bin/sudo /bin/mkdir /Library/Caches/Homebrew
==> /usr/bin/sudo /bin/chmod g+rwx /Library/Caches/Homebrew
==> /usr/bin/sudo /usr/sbin/chown Briandawgg /Library/Caches/Homebrew
==> Downloading and installing Homebrew...
remote: Counting objects: 4060, done.
remote: Compressing objects: 100% (3910/3910), done.
remote: Total 4060 (delta 35), reused 1870 (delta 19), pack-reused 0
Receiving objects: 100% (4060/4060), 3.33 MiB | 362.00 KiB/s, done.
Resolving deltas: 100% (35/35), done.
From https://github.com/Homebrew/homebrew
 * [new branch]      master     -> origin/master
HEAD is now at ae798e6 cassandra: update 3.3_1 bottle.
==> Installation successful!
==> Next steps
Run `brew help` to get started
Brians-Air:~ Briandawgg$ ls
Applications		Dropbox			Pictures
Creative Cloud Files	Google Drive		Public
Desktop			Library			brians-project
Documents		Movies			microscope
Downloads		Music
Brians-Air:~ Briandawgg$ ssh z5035087@cse.unsw.edu.au
z5035087@cse.unsw.edu.au's password: 

                       You are using a computer owned by
 University of New South Wales  -  School of Computer Science and Engineering



           ***** This service is for authorised clients only *****

 ****************************************************************************
 *                                                                          *
 * WARNING:     It is a criminal offence to:                                *
 *                                                                          *
 *              i.  Obtain access to data without permission                *
 *                        (Penalty 2 years imprisonment)                    *
 *              ii. Damage, delete, alter or insert data without permission *
 *                        (Penalty 10 years imprisonment)                   *
 *                                                                          *
 ****************************************************************************
No mail.
wagner % sublime
-bash: sublime: command not found
wagner % nano

  GNU nano 2.2.4                New Buffer                            Modified  

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {
   printf ("I am awesome!\n");
   return EXIT_SUCCESS;
}













^G Get Help  ^O WriteOut  ^R Read File ^Y Prev Page ^K Cut Text  ^C Cur Pos
^X Exit      ^J Justify   ^W Where Is  ^V Next Page ^U UnCut Text^T To Spell
