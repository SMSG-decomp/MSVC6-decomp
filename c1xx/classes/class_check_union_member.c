char __cdecl class_check_union_member(c1_symbol *union_sym,c1_symbol *member)

{
  byte bVar1;
  c1_symbol *pcVar2;
  char cVar3;
  
  cVar3 = '\x01';
  if ((member->storage & 7) == 3) {
    diag_extension_warning_or_error(0xcb,0x26b,0x53,g_class_def_stack[g_class_depth].cls,member);
  }
  if ((g_compile_flags_cc & 0x100000) != 0) {
    return '\x01';
  }
  pcVar2 = sym_class_type_of(member);
  if (pcVar2 != (c1_symbol *)0x0) {
    bVar1 = ((pcVar2->detail).cls)->implicit_state41;
    if ((bVar1 & 4) == 0) {
      diag_error(0x26d,union_sym,member);
      return '\0';
    }
    if ((bVar1 & 2) == 0) {
      diag_error(0x26c,union_sym,member);
      return '\0';
    }
    if ((bVar1 & 8) == 0) {
      diag_error(0x26e,union_sym,member);
      return '\0';
    }
    if ((bVar1 & 0x10) == 0) {
      diag_error(0x26f,union_sym,member);
      cVar3 = '\0';
    }
  }
  return cVar3;
}

