void __fastcall
alias_add_call_memeffects(c2_tuple *t,c2_eh_state *eh_object,uint32_t cls,c2_symbol *scope)

{
  c2_function *pcVar1;
  c2_operand *pcVar2;
  c2_alias_memeffect *rec;
  c2_symbol *pcVar3;
  c2_symbol_cell *pcVar4;
  
  pcVar2 = operand_new_memeffect(cls);
  tuple_merge_memeffect_src(t,pcVar2);
  pcVar2 = operand_new_memeffect(cls);
  tuple_merge_memeffect_dst(t,pcVar2);
  if ((eh_object != (c2_eh_state *)0x0) &&
     (pcVar1 = eh_object->funclet, pcVar1 != (c2_function *)0x0)) {
    rec = arena_alloc(4,0x18);
    alias_collect_symbols_in_range(pcVar1->cfg->first->head,(c2_tuple *)0x0,0,1,rec);
    pcVar3 = get_cxx_eh_record();
    if (pcVar3 != (c2_symbol *)0x0) {
      pcVar4 = symbol_list_add_unique(rec->read,pcVar3->storage,1);
      rec->read = pcVar4;
    }
    pcVar2 = operand_new_memeffect(g_alias_class_count);
    tuple_merge_memeffect_src(t,pcVar2);
    rec->src_cls = g_alias_class_count;
    g_alias_class_count = g_alias_class_count + 1;
    rec->scope = scope;
    rec->next = g_alias_eh_effect_records;
    g_alias_eh_effect_records = rec;
  }
  return;
}

