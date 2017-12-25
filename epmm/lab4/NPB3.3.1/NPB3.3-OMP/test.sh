# cp ./config/make.def.orig ./config/make.def
# for i in A
# do
# 	echo $i orig
# 	time make SP CLASS=$i > /dev/null
# 	env OMP_NUM_THREADS=2 ./bin/sp."$i".x > ./bin/sp."$i"_out.orig
# done
# cp ./config/make.def.prof ./config/make.def
# for i in A
# do
# 	rm SP/*.gcda
# 	echo $i prof
# 	time make SP CLASS=$i > /dev/null
# 	env OMP_NUM_THREADS=2 ./bin/sp."$i".x > ./bin/sp."$i"_out.prof
# done
cp ./config/make.def.with ./config/make.def
for i in A
do
	echo $i final
	time make SP CLASS=$i > /dev/null
	env OMP_NUM_THREADS=2 operf -e CPU_CLK_UNHALTED:100000:0:1:1,LLC_REFS:100000:0x4f:0:1:1,LLC_MISSES:100000:0x41:0:1:1 ./bin/sp."$i".x > ./bin/sp."$i"_out.final
	opreport -l ./bin/sp."$i".x > "$i"_prof_func.txt
	opreport -c ./bin/sp."$i".x | gprof2dot -f oprofile | dot -Tpng -o "$i".png
	opannotate -s ./bin/sp."$i".x > "$i"_anno.txt
	mv ./oprofile_data ./oprofile_data_"$i"
done
