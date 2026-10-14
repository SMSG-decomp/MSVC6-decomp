void __cdecl sym_queue_destructible_object(c1_symbol *sym)

{
  int iVar1;
  c1_symbol *fn;
  
  if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
       ((g_compile_flags_c8 & 0x10000000) != 0)) ||
      ((((g_compile_flags_c8 & 0x40000000) != 0 && (((byte)g_compile_flags_cc & 8) == 0)) &&
       ((g_compile_flags_c4 & 0x200) == 0)))) || (((byte)g_compile_flags_cc & 0x50) != 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = 4;
  }
  iVar1 = list_push_in_arena(&g_pending_destructor_helpers + g_block_depth,iVar1);
  *(c1_symbol **)(iVar1 + 4) = sym;
  if ((sym->type->code & 0x200) != 0) {
    fn = (c1_symbol *)class_find_complete_destructor(sym->type);
    special_member_need_definition(fn);
  }
  return;
}

