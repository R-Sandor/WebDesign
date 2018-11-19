fun writeFile filename content =
    let val fd = TextIO.openAppend filename
        val _ = TextIO.output (fd, content) handle e => (TextIO.closeOut fd; raise e)
        val _ = TextIO.closeOut fd
    in () end;
