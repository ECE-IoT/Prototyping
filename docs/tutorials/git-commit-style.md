# Branching System
## Git in a nutshell!
### What is Git?

Git is a Version Control System (VCS). With the utilization of Git the entire history of the project can be tracked. This means the VCS automatically tracks every minute change in the project and allows users to revert back to a previous version no matter how often the file got changed. 

Here is an *Example* **GIT TREE** 

![iu-2.png](https://bitbucket.org/repo/g5EKkgo/images/1696685577-iu-2.png)

The other main advantage is that Git allows people to work together seamlessly. With Git people can contribute onto the same project without disturbing each other's files. This allows team-members to work on different *features* within the project at the same time and easily merge changes together later on [^1].

### Basic terminology[^1]

Repository
 : A Repository is a folder that is watched by Git. Here all file changes will be detected. A "Repo" builds up as the frame of everything 

Branch
 : A Branch is an independent line of development. There will exists multiple branches within a Repo. Every Branch is its own working directory.

Clone
 : A clone is a simply copy of a repository that's downloaded and stored on the own computer.

Commit
 : A commit is a set of one ore more changes to a file (or a set of files). Every chang will create an unique ID ("hash") which helps keeping track of the history of the project. 

 Master
 : That's the default (initial) development branch. It's automatically created at the birth of the Repo. The master branch is usually used for merging the final result of a project together. 

For a more in-depth look have a look at the website: [codeburst.io](https://codeburst.io/git-and-github-in-a-nutshell-b0a3cc06458f)

### Basic Commands

There are some basic commands that should be mastered right away when working with `git`. 

**Clone**

With this command a repository with the suited `link` is cloned into the `.` directory. 
```bash
git clone <link> . 
```

**Branch**

With this command 

**Add**

This command is need to add new changes to a commit from the `.` directory.
```bash
git add . 
```

**Commit**

With this command the changes are ported to the repository and added to the version control
```bash
git commit -m "SUITABLE MESSAGE"
```

**Push**

With this command the changes are uploaded to the remote repository
```bash
git push
```

**Pull**

With this command new changes are downloaded to the local repository
```bash
git pull
```

## Commit Style 

In order to achieve a uniform naming for commit messages the following **commit style** should be used when creating a new commit message. 

| Keyword | Description                                                                                                                                                                                     |
| ------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| ADD     | Is used if there is a new change in the code. **f.e** `git commit -m "ADD function XY()"`                                                                                                       |
| FIX     | Used for minor changes, bugfixes of an already existing part of the code. **f.e** `git commit -m "FIX functionality of XY"`                                                                     |
| REF     | Written short for: REFACTOR. Is used when there is a major change in multiple code-segments and the structure of the code is reworked. **f.e** `git commit -m "UPDATE setup of analog sensors"` |

[^1]: source: [https://codeburst.io/git-and-github-in-a-nutshell-b0a3cc06458f](https://codeburst.io/git-and-github-in-a-nutshell-b0a3cc06458f)