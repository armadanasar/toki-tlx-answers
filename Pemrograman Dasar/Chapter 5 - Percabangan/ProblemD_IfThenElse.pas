var
	x: longint;
begin
	readln(x);
	
	if (x > 0) then
		begin
			writeln('positif');
		end
	else
		begin
			if (x = 0) then
				begin
					writeln('nol');
				end	
			else
				begin
					writeln('negatif');
				end
		end;
end.