{ Hello World Example }
program HelloWorld
  declare
  a:  integer ;
  b:  integer ;
  begin -- main statements
    -- Print text to the console
    for ( b in 11 .. 9 ) loop
      a := a + b ; 
    end loop ;
    print (a) ;
    println ("Hello World");
  end;
end HelloWorld
