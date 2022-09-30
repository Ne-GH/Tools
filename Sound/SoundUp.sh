CUR_SOUND=$(amixer get Master | grep -o "\\[[0-9]\{1,3\}%\\]" | grep -o "[0-9]\{1,3\}")

CUR_SOUND=$((CUR_SOUND))

if [ $CUR_SOUND -lt 100 ] ; then
    CUR_SOUND=$((CUR_SOUND+5))
fi

~/Projects/Tools/Sound/SetSound.sh $CUR_SOUND
