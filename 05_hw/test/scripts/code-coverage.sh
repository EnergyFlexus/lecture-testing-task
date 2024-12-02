# use after running tests
cd ../build/test
llvm-profdata merge -sparse default.profraw -o default.profdata
llvm-cov show ./tests.exe -instr-profile="default.profdata"
llvm-cov report ./tests.exe -instr-profile="default.profdata"