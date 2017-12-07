clang-format --style=LLVM -dump-config > .clang-format
sed -i "s/BreakBeforeBraces: Attach/BreakBeforeBraces: Allman/g" .clang-format
sed -i "s/ColumnLimit:     80/ColumnLimit:     120/g" .clang-format
sed -i "s/TabWidth:        8/TabWidth:        4/g" .clang-format

