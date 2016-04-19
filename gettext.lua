-- gettext.lua
-- $Id: gettext.lua,v 2.0 2016/04/18 18:55 BAerowing Exp $
-- Lua wrapper functions for Lua 5.3.x gettext binding.

-- BEGIN gettext.lua --

GetText = require("lgettext")

function _(str, ...)
	return string.format(GetText.gettext(str), table.unpack(arg))
end

function n_(str, ...)
    return string.format(GetText.ngettext(str), table.unpack(arg))
end

return GetText

-- END of gettext.lua --
