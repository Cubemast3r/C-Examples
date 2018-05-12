#include <iostream>
#include <libintl.h>
#include <locale.h>

using namespace std;


int main( int argc, char* argv[])
{
    setlocale(LC_ALL,"");
    bindtextdomain("i18n","/usr/share/locale");
    textdomain("i18n");
    cout <<  gettext("Hello Jerry Cotton !") << endl;
    
    return 0;
}

/** Instructions:

> mkdir -p po/de/

  // Extract the strings
> xgettext -o po/de/i18n.po -s i18n.cpp
// * ATTENTION: this is the same as: "> make PO"

//   edit the newly created .po file like that: 
> cat i18n.po
*
    # SOME DESCRIPTIVE TITLE.
    # Copyright (C) YEAR THE PACKAGE'S COPYRIGHT HOLDER
    # This file is distributed under the same license as the PACKAGE package.
    # FIRST AUTHOR <U.x@xyz.com>, 2018.
    #
    #, fuzzy
    msgid ""
    msgstr ""
    "Project-Id-Version: i18n 1.0\n"
    "Report-Msgid-Bugs-To: U.x@xyz.com\n"
    "POT-Creation-Date: 2018-03-15 10:57+0100\n"
    "PO-Revision-Date: YEAR-MO-DA HO:MI+ZONE\n"
    "Last-Translator: Uwe Xaver <U.x@xyz.com>\n"
    "Language-Team: german <LL@li.org>\n"
    "Language: de\n"
    "MIME-Version: 1.0\n"
    "Content-Type: text/plain; charset=UTF-8\n"
    "Content-Transfer-Encoding: 8bit\n"


    #: i18n.cpp:14
    msgid "Hello Jerry Cotton !"
    msgstr "Hallo Jeremias Baumwolle !"
*

//   create an MO (.mo) file using the following command:
> msgfmt po/de/i18n.po -o po/de/i18n.mo
// * ATTENTION: this is the same as: "> make MO"

//   in root mode copy the MO file to /usr/share/locale/de/LC_MESSAGES.

> sudo cp -vf po/de/i18n.mo /usr/share/locale/de/LC_MESSAGES/
> [sudo] Passwort für Uwe: 
'i18n.mo' -> '/usr/share/locale/de/LC_MESSAGES/i18n.mo'

//   compile your C file:

> cd ../..
> make
g++ -c -Wall i18n.cpp -o i18n.o
g++ i18n.o  -o i18n

// @see for environment variables: https://www.gnu.org/software/gettext/manual/html_node/gettext-grok.html
// * 
// * This is the ranking of the highest priority environment variable used for determining the language: 
// * 
// * LANGUAGE
// * LC_ALL
// * LC_xxx, according to selected locale category
// * LANG 

> ./i18n 
Hallo Jeremias Baumwolle !

> LANGUAGE=en; ./i18n 
Hello Jerry Cotton !
*/
