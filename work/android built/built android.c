
https://source.android.com/setup/downloading


sets to built Android source code:


Installing Repo

Repo is a tool that makes it easier to work with Git in the context of Android. For more information about Repo, see the Developing section.

To install Repo:

1.    Make sure you have a bin/ directory in your home directory and that it is included in your path:

    mkdir ~/bin
    PATH=~/bin:$PATH

2.

Download the Repo tool and ensure that it is executable:

curl https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
chmod a+x ~/bin/repo



 After installing Repo, set up your client to access the Android source repository:

 1.   Create an empty directory to hold your working files. If you're using MacOS, this has to be on a case-sensitive filesystem. Give it any name you like:

    mkdir WORKING_DIRECTORY
    cd WORKING_DIRECTORY
2.

Configure git with your real name and email address. To use the Gerrit code-review tool, you will need an email address that is connected with a registered Google account. Make sure this is a live address at which you can receive messages. The name that you provide here will show up in attributions for your code submissions.

git config --global user.name "Your Name"
git config --global user.email "you@example.com"

3.

Run repo init to bring down the latest version of Repo with all its most recent bug fixes. You must specify a URL for the manifest, which specifies where the various repositories included in the Android source will be placed within your working directory.

repo init -u https://android.googlesource.com/platform/manifest

To check out a branch other than "master", specify it with -b. For a list of branches, see Source Code Tags and Builds.

repo init -u https://android.googlesource.com/platform/manifest -b android-4.0.1_r1

4.


Downloading the Android Source Tree

To pull down the Android source tree to your working directory from the repositories as specified in the default manifest, run

repo sync





