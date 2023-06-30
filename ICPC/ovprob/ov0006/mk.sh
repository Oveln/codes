//调用mk.run,将输出流定位到%x%.in
//调用main.run,将输入流定位到%x%.in,输出流定位到%x%.out
//x是1~10的循环变量
//本文件是sh脚本

for i in `seq 1 10`
do
    echo "Test $i"
    ./mk.run > $i.in
    ./main.run < $i.in > $i.out
done
