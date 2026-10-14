void __fastcall prepend_entry_frame_operand(c2_function *fn,c2_tuple *entry)

{
  c2_operand *pcVar1;
  c2_symbol *sym;
  c2_operand *pcVar2;
  
  if (fn->struct_return != (c2_fe_symbol *)0x0) {
    sym = fe_symbol_get_storage(fn->struct_return);
    pcVar2 = operand_new_sym(0x14a,g_ptr_type,sym);
    pcVar1 = entry->src;
    entry->src = pcVar2;
    pcVar2->next = pcVar1;
  }
  return;
}

