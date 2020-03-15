set terminal gif animate optimize size 640,480
set output 'p2_merge_sort.gif'
set title 'merge sort'
unset zeroaxis
unset border
unset tics
unset key
unset colorbox
do for [i = 1 : 100] {
  plot sprintf("data/merge/%03d", i) with point pointtype 7 title sprintf("t=%d", i)
}

unset output