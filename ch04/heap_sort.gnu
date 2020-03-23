set terminal gif animate optimize size 640,480
set output 'heap_sort.gif'
set title 'heap sort'
unset zeroaxis
unset border
unset tics
unset key
unset colorbox
do for [i = 1 : 201] {
  plot sprintf("data/heap/%03d", i) with point pointtype 7
}

unset output