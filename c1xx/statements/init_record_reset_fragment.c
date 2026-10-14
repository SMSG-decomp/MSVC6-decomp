void __cdecl init_record_reset_fragment(c1_symbol *sym)

{
  c1_symbol *pcVar1;
  int iVar2;
  int iVar3;
  
  if (PTR_104e0a40 == (c1_type *)0x0) {
    (sym->tail).data.value_lo = 0;
  }
  else {
    iVar2 = type_size(PTR_104e0a40);
    iVar3 = init_unsized_array_count();
    (sym->tail).data.value_lo = iVar2 * iVar3;
  }
  PTR_104e0a40 = (c1_type *)0x0;
  init_construct_remaining_elements();
  pcVar1 = sym_class_needing_init(sym);
  if ((pcVar1 != (c1_symbol *)0x0) &&
     (((sym->flags5 & 4) == 0 || ((((pcVar1->detail).cls)->implicit_state41 & 2) != 0)))) {
    init_emit_placement_construct(sym);
  }
  init_end_declaration(sym);
  if ((g_il_block_level != '\0') && (((byte)g_compile_flags_c4 & 0x20) == 0)) {
    sym->key_ref = sym->key_ref & 0xfffffff8;
  }
  g_init_symbol = (c1_symbol *)0x0;
  return;
}

