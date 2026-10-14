void __fastcall type_check_function_cast_and_bitfield(c1_declarator *d)

{
  c1_u32 cVar1;
  c1_type *pcVar2;
  c1_symbol *pcVar3;
  
  cVar1 = d->kind;
  if (cVar1 == 3) {
    d->kind = 7;
    return;
  }
  if (cVar1 == 1) {
    pcVar3 = d->sym;
    if (pcVar3 == (c1_symbol *)0x0) {
      pcVar3 = sym_new_from_declarator(d,5);
    }
    diag_error(0x290,pcVar3);
  }
  else if (cVar1 != 2) {
    if ((cVar1 == 4) && ((g_compile_flags_c8 & 0x20000000) == 0)) {
      diag_error(0x42);
    }
    pcVar2 = type_member_pointer_to_2(d->type,'\x01');
    d->type = pcVar2;
    return;
  }
  d->kind = 8;
  return;
}

