set terminal gif animate optimize size 640,480
set output 'p2_quick_sort.gif'
set title 'quick sort'
unset zeroaxis
unset border
unset tics
unset key
unset colorbox
do for [i = 1 : 162] {
  plot sprintf("data/quick/%03d", i) with point pointtype 7 title sprintf("t=%d", i)
}

unset output