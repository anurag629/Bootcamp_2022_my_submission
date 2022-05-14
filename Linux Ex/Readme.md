# Solution of Exercise of Linux

## Solution 1 :
### Varients of <code>ls</code> command

* <code>ls</code> : List all directries
  
   ![Screenshot from 2022-05-14 10-07-55](https://user-images.githubusercontent.com/78868769/168410978-63e8ae52-3aa1-48e5-a88a-19a1dc141f46.png)

* <code>ls -l</code> : shows files or directory, size, modified date and time, file or folder name & owner of the file, &its permission

    ![Screenshot from 2022-05-14 10-08-12](https://user-images.githubusercontent.com/78868769/168410983-88ecca38-1d32-4a22-97ca-cf372128be2a.png)

* <code>ls -a</code> : View hidden files

    ![Screenshot from 2022-05-14 10-14-39](https://user-images.githubusercontent.com/78868769/168411042-f21d422d-4d98-41a4-98e5-786fd2779ad6.png)
    
* <code>ls -lb</code> : list files in human readable form

    ![Screenshot from 2022-05-14 10-15-57](https://user-images.githubusercontent.com/78868769/168411097-051b6b6b-7fa2-4e60-a73e-a776c12b951a.png)

* <code>ls -F</code> : list files and direc with '/' char at the end

    ![Screenshot from 2022-05-14 10-16-19](https://user-images.githubusercontent.com/78868769/168411106-578c3185-7c4c-4278-9f89-922d4e1a2c62.png)

* <code>ls -r</code> : list files in reverse order

    ![Screenshot from 2022-05-14 10-16-55](https://user-images.githubusercontent.com/78868769/168411111-d60129b7-8331-45d0-bfb0-fcefcbadb196.png)

* <code>ls --help</code> : shows ls command help page

    ![Screenshot from 2022-05-14 10-18-45](https://user-images.githubusercontent.com/78868769/168411133-ae3acc1d-65e1-4863-9629-6f09f9edee15.png)


### Varients of <code>cp</code>


* Syntax : <code>cp [options] source desination</code>

    * <code>cp -a</code> : archive files
    * <code>cp -f</code> : force copy by removing the designation file if needed
    * <code>cp -i</code> : iteractive - ask before overrite
    * <code>cp -l</code> : link file instead of copying
    * <code>cp -L</code> : follow symbolic link
    * <code>cp -n</code> : no file overite
    * <code>cp -R</code> : recursive copy
    * <code>cp -u</code> : update
    * <code>cp -v</code> : print information message

* Copy sigle file to directory :
    
    <code>cp hello.c temp</code>

* Copy multiple files :

    <code>cp hello.c sum.c temp</code>

* Copy all files :

    <code>cp *.c temp</code>
