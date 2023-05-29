{ This test program computes the Nth Fibonacci number
    using recursion }

program computeFib2

-- global variables
declare
  n: constant := 10;

-- recursion function
procedure reFibonacci (n: integer) return integer
begin
    if (n = 0) then
        return 0;
    end if;
    if (n = 1) then
        begin
            return 1;
        end;
    else
        return reFibonacci(n - 1) + reFibonacci(n - 2);
    end if;
end;
end reFibonacci;

-- main program 
begin
  print "N: ";
  println n;
  print "Result of recursion computation:";
  println reFibonacci(n);
end;
end computeFib2