void __cdecl browse_record_finish_kind13(c1xx_browse_record *rec,fe_macro *macro)

{
  char cVar1;
  c1xx_browse_record *pcVar2;
  fe_macro *pfVar3;
  uint *entity;
  uint position;
  
  pfVar3 = macro;
  pcVar2 = rec;
  rec->flags = rec->flags & 0xfd;
  position = (uint)macro->name->text;
  rec->attributes = 0;
  rec->name = (char *)position;
  rec->name_record = macro->name;
  cVar1 = macro->def->kind;
  rec->kind = '\x03';
  rec->type = (cVar1 != '\0') + '\x05';
  entity = (uint *)(*g_il_emitter->vtbl->assign_entity_id)
                             (g_il_emitter,(int *)&rec,macro->def->browse_id);
  pfVar3->def->browse_id = *entity;
  pcVar2->entity = pfVar3->def->browse_id;
  return;
}

