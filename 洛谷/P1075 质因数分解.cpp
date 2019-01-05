var
  n,i:longint;
begin
 read(n);
 for i:=2 to n do
  if n mod i=0 then begin
                      write(n div i);
                      break;
                    end;
end.