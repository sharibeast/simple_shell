#!/bin/bash
echo "# this script list all contributors of this repository \n
To generate  list of authors use list_authors.sh file" > AUTHORS
echo >> AUTHORS


git log --format="%aN <%aE>" | sort -uf >> AUTHORS