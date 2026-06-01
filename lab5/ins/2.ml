let func () : unit =
  let soma = ref 0 in
  let i = ref 1 in
  while !i < 10 do
    i := !i + 1;
    soma := !soma + !i
  done
