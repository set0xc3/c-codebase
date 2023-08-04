#!/bin/bash

(echo \[ ; cat .cache/cdb/* ; echo {}\]) | perl -0777 -pe 's/,\n\{\}//igs' | jq . | grep -v 'no-default-config' > compile_commands.json
exit

echo '[' > compile_commands.json
for file in cdb/*.json; do
  chunk="$(cat $file | sed -n '/{/,/}/p')"
  echo "$chunk" >> compile_commands.json
done
sed -i '$s/.$//' compile_commands.json
echo ']' >> compile_commands.json
