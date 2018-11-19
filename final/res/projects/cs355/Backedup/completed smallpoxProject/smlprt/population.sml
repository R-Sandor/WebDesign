val file = "/home/raphael/cs355/smlprt/pop_data.txt" ;

fun read file =
let val inStream = TextIO.openIn file

in
        TextIO.input1 inStream
end