set terminal gif animate delay 1 optimize size 640,480
set output 'p2_selection_sort.gif'
set nozeroaxis
unset colorbox
set palette rgbformulae 33, 13, 10
do for [i = 1 : 100] {
  plot sprintf("data/%03d", i) with point pointstyle 8 title sprintf("t=%d", i))
}

unset output