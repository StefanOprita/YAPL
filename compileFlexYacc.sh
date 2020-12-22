if [[ $# -eq 1 ]]
then
    yacc $1.y -d
    flex $1.l
    gcc lex.yy.c y.tab.c -ll -o $1.exe
else
    if [[ $# -eq 3 ]]
    then
        yacc $1 -d
        flex $2
        gcc lex.yy.c y.tab.c -ll -o $3.exe
    else
        echo "Usage : compileFlexYacc <name> (without the .l extension!)"
        echo "OR compileFlexYacc <name1>.y <name2>.l <finalName>"
    fi
    
fi


