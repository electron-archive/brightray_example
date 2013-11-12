#!/bin/bash

if [ $# != 2 ]; then
  echo "Usage:"
  echo "  $0 src-file dest-file"
  exit 1
fi

rm -f "$2"                    &&
  cp "$1" "$2"                &&
  sudo chown root.root "$2"   &&
  sudo chmod 4755 "$2"        || (
  cat <<EOF

------------------------------------------------------------------------
The chrome sandbox must be root-owned and setuid.  This script failed to
make it so.  You might be able to run brightray_example with the
--disable-setuid-sandbox flag, or set
CHROME_DEVEL_SANDBOX=/usr/lib/chromium-browser/chrome-sandbox before
running it.
------------------------------------------------------------------------

EOF
exit 1
)
