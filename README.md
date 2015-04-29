# lua-proctitle

Set your process' name from Lua so that it shows up differently in programs like `ps` or `netstat`.

# Example

```lua
local proctitle = require 'proctitle'

proctitle 'new title'
```

# Motivation

Some programs will set the process title of their processes to reflect their roles.  For
example, nginx sets its worker process' titles to indicate that they are worker processes.
I had the situation where I wanted [Prosody](http://prosody.im) listed as 'prosody' in
`netstat` output, so I wrote this little module.

# Portability

This depends on `__progname` from glibc, so this will only work if Lua is using GNU libc as
its C library.  Patches adding support for other configurations are encouraged!
