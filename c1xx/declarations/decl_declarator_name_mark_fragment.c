byte * __cdecl
decl_declarator_name_mark_fragment
          (c1_symbol *sym,byte *new_tok,int has_ctor,int has_dtor,int set_flags1_80,
          int set_flags3_01)

{
  c1_symbol *sym_00;
  
  if (((sym->flags2 & 0x10) != 0) && ((sym->type->code & 0x200) != 0)) {
    diag_error(0xf2);
  }
  if (*new_tok == 0x96) {
    sym_00 = (c1_symbol *)**(undefined4 **)(new_tok + 8);
  }
  else {
    sym_00 = *(c1_symbol **)(new_tok + 8);
  }
  expr_resolve_overload_set_member(sym_00,(c1_symbol *)0x0);
  if (has_ctor != 0) {
    sym_00->flags1 = sym_00->flags1 | 0x10;
  }
  if (has_dtor != 0) {
    sym_00->flags1 = sym_00->flags1 | 0x20;
  }
  if (set_flags1_80 != 0) {
    sym_00->flags1 = sym_00->flags1 | 0x80;
  }
  if (set_flags3_01 == 0) {
    return new_tok;
  }
  sym_00->flags3 = sym_00->flags3 | 1;
  return new_tok;
}

