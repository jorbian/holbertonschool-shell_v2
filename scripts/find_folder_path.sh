#!/usr/bin/bash

TARGET_FOLDER_NAME=$([ -n "$1" ] && echo "$1" || echo "include")
SEARCH_FOLDER_PARENT=$([ -n "$2" ] && echo "$2" || echo "GitHub")

find_search_folder()
{
    if [[ -z "$1" ]]; then
        DIRECTORY=$(pwd)
    else
        DIRECTORY=$1
    fi
    DIRECTORY="$(dirname "$DIRECTORY")"

    CURR_BASENAME="$(basename "$DIRECTORY")"
    NEXT_BASENAME="$(basename $(dirname "$DIRECTORY"))"

    if [[ $NEXT_BASENAME = $CURR_BASENAME ]]; then
        echo ""
    elif [[ $NEXT_BASENAME = $SEARCH_FOLDER_PARENT ]]; then
        echo $DIRECTORY
    else
        echo $(find_search_folder $DIRECTORY)
    fi
}

SEARCH_FOLDER=$(find_search_folder)

if [[ -z $SEARCH_FOLDER ]]; then
    echo "ERROR: SEARCH FOLDER NOT FOUND." >&2
    exit 64
fi

for FOLDER_PATH in $(ls -d $SEARCH_FOLDER/*/); do

    FOLDER_PATH_BASENAME="$(basename $FOLDER_PATH)"

    if [[ $FOLDER_PATH_BASENAME = $TARGET_FOLDER_NAME ]]; then
        break
    fi
done

echo $(dirname "$FOLDER_PATH")/$(basename "$FOLDER_PATH")
