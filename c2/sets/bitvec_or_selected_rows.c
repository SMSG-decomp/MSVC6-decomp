void __fastcall bitvec_or_selected_rows(c2_bitvec *dst,c2_bitvec *selector,c2_bitvec **rows)

{
  uint32_t uVar1;
  
  uVar1 = bitvec_iter_next(selector);
  while (uVar1 != 0xffffffff) {
    bitvec_or(dst,rows[uVar1]);
    uVar1 = bitvec_iter_next((c2_bitvec *)0x0);
  }
  return;
}

