<!-- Copyright (c) 2012-2016 K Team. All Rights Reserved. -->
Here are instructions for installing K from the release zip/tgz archive.

1. Prerequisites:
  * Java Runtime Edition version 8 or higher
    http://www.oracle.com/technetwork/java/javase/downloads/index.html
    * To make sure java is installed properly, call `java -version` in a terminal.

2. Install:
  * Unzip this directory in your preferred location.  For convenient usage,
    update your $PATH with <preferred-location>/k/bin.

3. Test:
  * Go to one of the examples (say k/tutorial/2_languages/1_simple/1_untyped/).
    Assuming k/bin is in your $PATH, you can compile definitions using 
    the `kompile simple-untyped.k` command.
    To execute a program you can use `krun tests/diverse/factorial.simple`.

4. (Optional) Latex:
  * To use the pdf backend, a relatively recent installation 
    of Latex is required.  Besides basic packages, the following (texlive)
    packages are needed: 
  * bera, bezos, bookmark, datetime, ec, etoolbox, fancybox, fancyvrb, import, 
    listings, marginnote, microtype, ms, pdfcomment, pgf (up-to-date), preview, 
    soul, stmaryrd, times, titlesec, ucs, url, xcolor, and xkeyval.

5. (Optional) OCAML:
  * To use the OCAML backend requires an installation of the OCAML package
    manager OPAM. Instructions on installing OPAM are available here:
    https://opam.ocaml.org/doc/Install.html
  * Once opam is installed, you can prepare the installation to run
    the OCAML backend by running the "k-configure-opam" script found
    in the lib directory. You will also need to run ``eval `opam config env` ``
    afterwards to update your environment.

--------------------------------------------------------------------------

We present some instructions for installing TeX Live on Unix-like machines.

Although most linux users prefer using a package manager we strongly advise 
them to install texlive manually as our latex compilation is only known to 
work with a texlive 2010 distribution and the most recent version of the 
pgf package. 

To do that one can use the TeX Live Quick install method 
<http://www.tug.org/texlive/quickinstall.html>.

For Mac OSX users the preferred method is to install MacTex
<http://www.tug.org/mactex/>

A full TeX Live installation should provide all the latex packages mentioned
in the prerequisites. Note however that our LaTeX macros rely on a quite 
recent version of the pgf package. To make sure you have the latest version
of this package you can upgrade it using the TeX Live package manager.
   
    $ tlmgr update pgf 

If using a partial TeX Live installation which does not provide all the 
TeX Live packages specified above, these can be installed with the command:
    
    $ tlmgr install  bera bezos bookmark datetime ec etoolbox fancybox \
                     fancyvrb import listings marginnote microtype ms \
                     pdfcomment pgf preview soul stmaryrd times titlesec ucs \
                     url xcolor xkeyval 
