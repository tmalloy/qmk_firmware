#!/bin/bash

echo "Sleeping 5 seconds, put keyboard into flash mode..."
sleep 5
PATH=/usr/local/bin:$PATH arch -x86_64 qmk flash -kb gboards/gergoplex -km tmalloy
