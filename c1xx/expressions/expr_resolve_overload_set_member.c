c1_symbol * __cdecl expr_resolve_overload_set_member(c1_symbol *sym,c1_symbol *decl)

{
  c1_symbol *sym_00;
  c1_symbol *pcVar1;
  byte bVar2;
  
  if (sym == (c1_symbol *)0x0) {
    return (c1_symbol *)0x0;
  }
  if ((sym->kind & 0x1f) == 0x12) {
    sym_00 = *(c1_symbol **)(*(int *)sym->type + 8);
  }
  else {
    sym_00 = sym;
    sym = (c1_symbol *)0x0;
  }
  pcVar1 = sym_00;
  if ((sym_00->flags2 & 0x20) != 0) {
    if ((sym_00->flags2 & 0x10) == 0) {
      pcVar1 = (c1_symbol *)((int)&sym_00->next[-1].tail + 4);
    }
    else {
      sym_00 = (c1_symbol *)((int)&sym_00->next[-1].tail + 4);
    }
  }
  if (((byte)g_compile_flags_c4 & 0x10) != 0) goto LAB_1040dd04;
  if (decl != (c1_symbol *)0x0) {
    bVar2 = decl->kind & 0x1f;
    if ((bVar2 == 7) || (bVar2 == 8)) {
      bVar2 = sym_00->kind & 0x1f;
      if (((bVar2 == 0x10) || (((bVar2 == 7 || (bVar2 == 6)) || (bVar2 == 0x11)))) ||
         (((bVar2 == 8 || (bVar2 == 0x1b)) ||
          ((bVar2 == 0x1a &&
           (((bVar2 = **(byte **)sym_00->type & 0x1f, bVar2 == 0x10 || (bVar2 == 7)) ||
            ((bVar2 == 6 || (((bVar2 == 0x11 || (bVar2 == 8)) || (bVar2 == 0x1b)))))))))))) {
        pcVar1 = (c1_symbol *)
                 ovl_find_function_with_type(sym_00,decl->type,1,0,decl,(c1_declarator *)0x0,1);
        if (pcVar1 == (c1_symbol *)0x0) {
          return (c1_symbol *)0x0;
        }
        goto LAB_1040dd04;
      }
      diag_error(0x3f,sym_00);
    }
    else if ((decl->flags2 & 0x10) != 0) goto LAB_1040dd04;
  }
  pcVar1 = sym_00;
LAB_1040dd04:
  if (sym != (c1_symbol *)0x0) {
    *(c1_symbol **)(*(int *)sym->type + 8) = pcVar1;
    pcVar1 = sym;
  }
  return pcVar1;
}

