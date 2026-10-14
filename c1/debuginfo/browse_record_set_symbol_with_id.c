void __cdecl browse_record_set_symbol_with_id(c1_browse_record *rec,c1_symbol *sym)

{
  c1_symbol *sym_00;
  c1_u32 *pcVar1;
  
  sym_00 = sym;
  pcVar1 = (c1_u32 *)(*g_il_emitter->vtbl->assign_entity_id)(g_il_emitter,(uint *)&sym,sym->entity);
  sym_00->entity = *pcVar1;
  browse_record_set_symbol(rec,sym_00);
  return;
}

