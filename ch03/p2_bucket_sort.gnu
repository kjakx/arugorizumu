set terminal gif animate optimize size 640,480
set output 'p2_bucket_sort.gif'
set title 'bucket sort'
unset zeroaxis
unset border
unset tics
unset key
unset colorbox
do for [i = 1 : 101] {
  plot sprintf("data/bucket/%03d", i) with point pointtype 7 title sprintf("t=%d", i)
}

unset output