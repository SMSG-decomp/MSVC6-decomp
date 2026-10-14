void __cdecl browse_record_finish_kind13(c1_browse_record *rec,fe_macro *macro)

{
  char cVar1;
  char *pcVar2;
  fe_macro *pfVar3;
  uint *puVar4;
  
  pfVar3 = macro;
  pcVar2 = macro->name->text;
  rec->attributes = 0;
  rec->name = pcVar2;
  rec->name_record = macro->name;
  cVar1 = macro->def->kind;
  rec->kind = '\x03';
  rec->sub_kind = (cVar1 != '\0') + '\x05';
  puVar4 = (uint *)(*g_il_emitter->vtbl->assign_entity_id)
                             (g_il_emitter,(uint *)&macro,macro->def->browse_id);
  pfVar3->def->browse_id = *puVar4;
  rec->id = pfVar3->def->browse_id;
  return;
}

