set terminal gif animate delay 1 optimize size 640,480
set output 'p2_insertion_sort.gif'
set title 'insertion sort'
unset zeroaxis
unset border
unset tics
unset key
unset colorbox
do for [i = 1 : 100] {
  plot sprintf("data/insertion/%03d", i) with point pointtype 7 title sprintf("t=%d", i)
}

unset output