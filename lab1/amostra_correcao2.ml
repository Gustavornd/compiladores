(* Helpers para contornar a restrição de índice dinâmico *)
let get arr i = arr.(0)
let set arr i v = arr.(0) <- v

let rec func vx vy n tax tay tbx tby tcx tcy tcor =
  if n <= 0 then
    1.0
  else if n = 1 then
    1.01 + ((float_of_int vx.(0)) /. 1.e2) + ((float_of_int vy.(0)) /. 0.1e-2) - float_of_int (tax * tax) + float_of_int (tby * tcx)
  else begin
    let res = ref 0.25e-13 in
    let i = ref (n - 1) in
    begin
      while !i >= 0 && (get vx !i) > 0 do
        let temp = float_of_int (((get vy !i) * (get vx !i)) mod 123) in
        if temp < 0.0 then
          res := !res - (!res *. 2.e-2) + (func vx vy (n - 1) tax tay tbx tby tcx tcy tcor) *. temp - float_of_int (tay * tcor)
        else begin
          res := !res + (!res *. 0.3e3) + (func vx vy (n - 2) tax tay tbx tby tcx tcy tcor) *. temp + float_of_int (tcx * tcor);
          print_endline "Estranho, ne?"
        end;
        i := !i - 1
      done
    end;
    !res
  end

let f2_a tax tay tbx tby tcx tcy tcor =
  let a = ref 0 in
  let soma = [| 0.0; 0.0; 0.0; 0.0; 0.0; 0.0; 0.0; 0.0; 0.0; 0.0 |] in
  if (tax >= 10 || tby > 20 || tay < 30 || tbx <= 50) && not (tcx <> 90 || tcy = 0) then
    10 mod 3
  else begin
    a := 1;
    begin
      while !a < 10 do
        let total = ref 0 in
        total := !total + (tcx * tcy);
        total := !total + (tbx * tay);
        total := !total + (tax * tby);
        set soma !a (float_of_int (!total mod 100));
        a := !a + 1
      done
    end;
    0
  end

let rec fatorialA n =
  if n <= 1 then 1
  else n * fatorialA (n - 1)

let rec fatorialB n =
  let a = n - 1 in
  if n <= 1 then 1
  else n * fatorialB a

let rec fatorialC n p =
  if n <= 1 then 1
  else fatorialC (n - 1) (p * n)

let rec fatorialD n p =
  let a = n - 1 in
  let b = p * n in
  if n <= 1 then 1
  else fatorialD a b

let rec fatorialE n p =
  if n <= 1 then 
    1
  else begin
    let a = n - 1 in
    let b = p * n in
    fatorialD a b
  end

let c1 a b =
  if a < b then 1 else 2

let c2 a b =
  if a <= b then 1 else 2

let c3 a b =
  if a > b then 1 else 2

let c4 a b =
  if a >= b then 1 else 2

let c5_a a b =
  if a = b then 1 else 2

let c5_b a b =
  if a <> b then 1 else 2

let d1 a b =
  if a <> b && a < b then 1 else 2

let d2 a b =
  if not (a <> b && a < b) then 1 else 2

let d3 a b =
  if not (a <> b && a < b) || (a + 2 = b) then 1 else 2

let e1 a_in b =
  let a = ref a_in in
  let x = not (!a <> b && !a < b) || (!a + 2 = b) in
  if !a <> b || x || !a + 5 = b then begin
    a := !a + 1
  end;
  2

let e2_a a_in b_in =
  let a = ref a_in in
  let b = ref b_in in
  let x = not (!a <> !b && !a < !b) || (!a + 2 = !b) in
  begin
    while !a <> !b || x || !a + 5 = !b do
      a := !a + 1;
      begin
        while !a < !b do
          b := !b - 1
        done
      end
    done
  end;
  2

let e2_b a_in b_in =
  let a = ref a_in in
  let b = ref b_in in
  let x = not (!a <> !b && !a < !b) || (!a + 2 = !b) in
  begin
    while !a <> !b || x || !a + 5 = !b do
      a := !a + 1;
      begin
        while fatorialA !a < !b do
          b := !b - 1
        done
      end
    done
  end;
  x || !a > 0

let f1 seg_ini_x seg_ini_y seg_fim_x seg_fim_y p_x p_y =
  let ax = float_of_int seg_ini_x in
  let ay = float_of_int seg_ini_y in
  let bx = float_of_int seg_fim_x in
  let by = float_of_int seg_fim_y in
  let px = float_of_int p_x in
  let py = float_of_int p_y in
  let abx = bx - ax in
  let aby = by - ay in
  let apx = px - ax in
  let apy = py - ay in
  let ab2 = (abx *. abx) + (aby *. aby) in
  let t_init = ((apx *. abx) + (apy *. aby)) /. ab2 in
  
  let t_lim1 = if t_init < 0.0 then 0.0 else t_init in
  let t = if t_lim1 > 1.0 then 1.0 else t_lim1 in
  
  let qx = ax + (t *. abx) in
  let qy = ay + (t *. aby) in
  let dx = px - qx in
  let dy = py - qy in
  sqrt ((dx *. dx) + (dy *. dy))

let dist2 ax ay bx by =
  let dx = ax - bx in
  let dy = ay - by in
  (dx * dx) + (dy * dy)

let f2_b seg_ini_x seg_ini_y seg_fim_x seg_fim_y p_x p_y =
  let ax = seg_ini_x in
  let ay = seg_ini_y in
  let bx = seg_fim_x in
  let by = seg_fim_y in
  let px = p_x in
  let py = p_y in
  
  let abx = bx - ax in
  let aby = by - ay in
  let apx = px - ax in
  let apy = py - ay in
  let bpx = px - bx in
  let bpy = py - by in
  
  let dot1 = (apx * abx) + (apy * aby) in
  let dot2 = (bpx * abx) + (bpy * aby) in
  
  if dot1 <= 0 then
    dist2 px py ax ay
  else if dot2 >= 0 then
    dist2 px py bx by
  else begin
    let cross = (abx * apy) - (aby * apx) in
    (cross * cross) / ((abx * abx) + (aby * aby))
  end

let area_poligono px_arr py_arr n =
  let soma = ref 0 in
  let i = ref 0 in
  begin
    while !i < n do
      let j = (!i + 1) mod n in
      soma := !soma + ((get px_arr !i) * (get py_arr j)) - ((get px_arr j) * (get py_arr !i));
      i := !i + 1
    done
  end;
  if !soma < 0 then soma := -(!soma);
  (float_of_int !soma) /. 2.0

let area_pol () =
  let poli_x = [| 0; 0; 0 |] in
  let poli_y = [| 0; 0; 0 |] in
  area_poligono poli_x poli_y 150