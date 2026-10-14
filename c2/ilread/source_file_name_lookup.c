char * __fastcall source_file_name_lookup(uint32_t id)

{
  uint32_t uVar1;
  c2_source_file_record *pcVar2;
  
  uVar1 = g_source_file_records->id;
  pcVar2 = g_source_file_records;
  while (uVar1 != id) {
    pcVar2 = pcVar2->next;
    uVar1 = pcVar2->id;
  }
  return pcVar2->name;
}

