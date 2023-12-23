@REM 循环10次
@FOR /L %%i IN (1,1,10) DO (
    @REM 执行python脚本build.py, 输出到 data%%i.in
    @dataspawn.exe > data%%i.in
    FG.exe < data%%i.in > data%%i.out
timeout /t 1
)
