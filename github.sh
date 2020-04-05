#!/bin/bash
echo "github script to automate repository creation and update"

if ["$1" -eq push];
then
    git status;
else
    echo "No argument entered script halts"
fi
