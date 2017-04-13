==========================================================================
The TNet SDK version 1.6.7
==========================================================================

  Welcome the TNet SDK.

  Content of this file:

  1. Directory structure overview
  2. How to start
  3. dependencies
  4. License
  5. Contact



==========================================================================
1. Directory structure overview
==========================================================================

  You will find some directories after decompressing the archive in which
  came the SDK. These are:
  
  \bin         Some compiled example applications, just start them to see
			   the TNet Engine in action.
  \include     Header files to include when using the engine.
  \lib         Lib to link with your programs when using the engine.


==========================================================================
2. How to start
==========================================================================

  To see the engine in action in Windows, just go to the \bin
  directories, and start some applications. 
  
  To start developing own applications and games with the engine take 
  a look at the 03.Hybrid example in the \source\examples directory.

  To compile:

  Microsoft Windows 7/10
  Using CMake GUI, go into the root directory, indicate the source as the
  root folder, and the build folder as the target for the CMake output.
  The GUI version of CMake was tested with Windows 7 and 10.

  Ubuntu 16.04
  Just go into the root directory and run these commands:
	~$ cmake ./
	~$ make
  	
==========================================================================
3. dependencies
==========================================================================

This is a simple wrapper for the ENet Networking engine. Therefore,
to use it you will need the ENet source code, that already is shipped with
this SDK.

To know more about ENet visit:http://enet.bespin.org/
	
==========================================================================
4. License
==========================================================================
MIT License

Copyright (c) 2015-2017 Aramis Hornung Moraes

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

--------------------------------------------------------------------------
TNet may include ENet code
It's license is the following:

Copyright (c) 2002-2015 Lee Salzman

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files
(the "Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

==========================================================================
5. Contact
==========================================================================

  If you have problems, questions or suggestions, please visit the 
  official homepage of the TNet Engine:
  
  https://aramis.bitbucket.io/
  
  If you want to contact the author of the engine, please send an IM to
  Aramis Hornung Moraes at:
  https://plus.google.com/u/1/107642337350816468504
