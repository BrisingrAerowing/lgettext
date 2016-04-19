# LGettext - A GNU Gettext binding for Lua 5.3

This is a 'fork' of the original LGettext sources found at [gnu-darwin.org](http://src.gnu-darwin.org/ports/devel/lua-gettext/work/gettext-1.5/)

Numerous modifications have been performed, including:

  * Porting from Lua 5.0 to Lua 5.3
  * Adding additional Gettext methods
    * gettext (Renamed from Translate)
    * dgettext
    * dcgettext
    * ngettext
    * dngettext
    * dcngettext
  * Adding LC_* constants for using with the dc* functions
    * If a constant is not defined in the C library for the platform, it will still appear, but have the value -1.
    * LC_MESSAGES is defined by Gettext if it is not otherwise defined, so it is always available.
    * POSIX specific LC_* defines are:
      * LC_PAPER
      * LC_NAME
      * LC_ADDRESS
      * LC_TELEPHONE
      * LC_MEASUREMENT
      * LC_IDENTIFICATION
 
 