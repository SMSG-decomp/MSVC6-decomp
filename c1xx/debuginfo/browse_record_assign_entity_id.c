void __cdecl browse_record_assign_entity_id(void *pos,c1_symbol *sym)

{
  c1_symbol *sym_00;
  c1_u32 *pcVar1;
  
  sym_00 = sym;
  pcVar1 = (c1_u32 *)(*g_il_emitter->vtbl->assign_entity_id)(g_il_emitter,(int *)&sym,sym->entity);
  sym_00->entity = *pcVar1;
  decl_position_set_symbol(pos,sym_00);
  return;
}

