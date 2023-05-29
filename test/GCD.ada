{* GCD.sp
 *
 * Compute GCD(n1, n2)
 *}
program computeGCD
-- constant and variable declarations
declare
  n1: constant := 400;
  n2: integer;
  ans := 0;

-- iterative function
procedure GCD (n1: integer; n2: integer) return integer
declare
  rem : integer;
begin
  println "";
  while (n2 > 0) loop
    declare
        rem := 0;
    begin
        print n1;
        print " % ";
        print n2;
        print " = ";
        read rem;
        rem := n1 % n2;
        println rem;
        n1 := n2;
        n2 := rem;
    end;
  end loop;
  println "";
  return n1;
end;
end GCD;

-- main statements
begin
  n2 := 997;
  
  ans := GCD(n1, n2);
  print "GCD(""";
  print n1;
  print """, """;
  print n2;
  print """) = """;
  print ans;
  print """";
  println "";
end
end computeGCD