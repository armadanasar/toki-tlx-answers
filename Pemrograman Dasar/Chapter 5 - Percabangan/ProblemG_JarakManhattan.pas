var
  x1, y1, x2, y2, distance: longint;
begin
  readln(x1, y1, x2, y2);
  distance := (abs(x1-x2)) + (abs(y1-y2));
  writeln(distance);
end.