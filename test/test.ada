program Example
    -- constant and variable declaration
    declare
        globali1: integer := 5;
        globali2: integer;
        globali3: integer;
        globalb1: boolean := true;
        constGlobali1: constant: integer := 5;
        globalConstantS1: constant: string := "Hello";
        
    -- function declaration
    procedure fibonacci(a: integer) return integer
        begin
            if (a <= 2) then
                return 1;
            end if;

            return fibonacci(a - 1) + fibonacci(a - 2);
        end;
    end fibonacci;

    procedure add (a: integer; b: integer) return integer
        begin
            return a + b;
        end;
    end add;

    procedure forLoopTest()
        declare
            n: integer;
        begin
            for (n in 1 .. 10) loop
                println n;
            end loop;
        end;
    end forLoopTest;

    procedure whileLoopTest()
        declare
            n: integer;
        begin
            n := 0;
            while (n <= 10) loop
                begin
                    n := n + 1;
                    println n;
                end;
            end loop;
        end;
    end whileLoopTest;

    -- main block
    begin

        println "# print constant string";
        println globalConstantS1;

        println "# procedure recursion test";
        println "# fibonacci(20) should be 6765";
        globali3 := fibonacci(20);
        println globali3;

        println "# for loop test";
        forLoopTest();

        println "# while loop test";
        whileLoopTest();

        println "# if statement test";
        print "globali1: ";
        println globali1;

        globali2 := add(globali1, 5);
        println "globali2 := add(globali1, 5);";
        print "globali2: ";
        println globali2;

        if (globali2 = 10) then
            begin
                println "(globali2 = 10) executed!";
            end;
        else
            println "(globali2 /= 10) executed!";
        end if;

        if (globali2 = 15) then
            begin
                println "(globali2 = 15) executed!";
            end;
        end if;
    end;
end Example