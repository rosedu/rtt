$ cat hello.stp
probe begin
{
    print("hello rtt")
    exit()
}

$ stap hello.stp
hello rtt
