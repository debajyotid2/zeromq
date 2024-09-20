#!/bin/bash

DEPENDENCY_DIR=../external

cd $DEPENDENCY_DIR || exit 1
git submodule update --init --recursive || exit 7
for dir in ./*; do
    (
        cd "$dir" || exit 1
        git pull origin main
    )
done

# if [ "$1" = "" ]; then
#     NUM_THREADS=1
# else
#     NUM_THREADS=$1
# fi
