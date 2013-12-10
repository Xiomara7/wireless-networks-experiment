for file in `ls *.dot`
do 
    dot -Kfdp -n -Tpdf -o ${file/.dot/}.pdf $file
done
