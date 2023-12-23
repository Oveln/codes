@REM 循环10次
@FOR /L %%i IN (1,1,10) DO (
    @REM 执行python脚本build.py, 输出到 data%%i.in
    @python build.py > data%%i.in
    B.exe < data%%i.in > data%%i.out
)
```