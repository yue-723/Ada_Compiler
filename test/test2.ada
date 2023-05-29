{ Hello World Example }
program HelloWorld
  declare
  a:  integer ;
  b:  integer ;
  c: boolean ;
  d: boolean ;
  begin -- main statements
    -- Print text to the console
    for ( b in 11 .. 9 ) loop
      a := a + b ; 
    end loop ;
    c := true;
    d := false;
    print (a) ;
    print (c) ;
    println (d) ;

    if (  not a > b) then
        begin
            b := 100;
            println b;
        end;
    else
        println a + b;
    end if;
    println ("Hello World");
  end;
end HelloWorld