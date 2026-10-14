void __fastcall source_file_record_add(c2_fe_symbol *s)

{
  char *pcVar1;
  c2_source_file_record *pcVar2;
  
  pcVar2 = arena_alloc(0,0xc);
  pcVar1 = s->name;
  pcVar2->id = s->id;
  pcVar2->name = pcVar1;
  pcVar2->next = g_source_file_records;
  g_source_file_records = pcVar2;
  return;
}

