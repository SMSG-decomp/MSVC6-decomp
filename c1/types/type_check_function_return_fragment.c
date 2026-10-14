void __cdecl
type_check_function_return_fragment
          (ushort extra_bits,uint extra_based,ushort mods_bits,c1_type_declarator *declarator)

{
  c1_u16 *pcVar1;
  c1_type *pcVar2;
  
  diag_error(0x5b);
  decl_add_pointer_modifier(declarator,&mods_bits,&extra_bits);
  declarator->last->code = 0x86;
  pcVar2 = declarator->last;
  if ((pcVar2->code & 0x8f) == 0x83) {
    pcVar2 = type_skip_arrays(pcVar2->base);
  }
  if ((pcVar2->flags & 8) != 0) {
    diag_error(0xd4,declarator->sym);
    declarator->flags30 = declarator->flags30 | 1;
    pcVar1 = &declarator->last->flags;
    *pcVar1 = *pcVar1 & 0xffe7;
  }
  return;
}

