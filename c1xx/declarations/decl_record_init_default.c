c1_decl_record * __thiscall
decl_record_init_default(c1_decl_record *rec,void *name,c1_overload_set *qualifier)

{
  int iVar1;
  uint *cursor;
  c1_decl_record *pcVar2;
  uint *dst;
  
  pcVar2 = rec;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    pcVar2->spec_type = (c1_type *)0x0;
    pcVar2 = (c1_decl_record *)&pcVar2->chain_head;
  }
  cursor = g_default_decl_specifiers;
  dst = rec->spec;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *dst = *cursor;
    cursor = cursor + 1;
    dst = dst + 1;
  }
  rec->name = name;
  rec->qualifier = qualifier;
  return rec;
}

