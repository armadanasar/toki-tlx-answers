var
    input, fractional: real;
    truncated, floor, ceil: longint;
begin
    readln(input);
    fractional := frac(input);
    truncated := trunc(input);
    if (fractional = 0) then
      begin
        ceil := truncated;
        floor := truncated;
      end
    else
      begin
        if (truncated < 0) then
          begin
            ceil := truncated;
            floor := truncated - 1;
          end
        else 
          begin
            floor := truncated;
            ceil := truncated + 1;
          end;
      end;
      
      writeln(floor, ' ', ceil);
      //writeln(round(2.0));
end.