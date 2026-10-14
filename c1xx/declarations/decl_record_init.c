void * __thiscall decl_record_init(void *rec,c1_type *type,void *spec)

{
  c1_symbol *pcVar1;
  int iVar2;
  uint *cursor_2;
  uint *cursor;
  
  cursor_2 = rec;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *cursor_2 = 0;
    cursor_2 = cursor_2 + 1;
  }
  pcVar1 = sym_new_in_current_scope();
  *(c1_symbol **)((int)rec + 0x34) = pcVar1;
  cursor = (uint *)((int)rec + 0x1c);
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *cursor = *(uint *)spec;
    spec = (uint *)((int)spec + 4);
    cursor = cursor + 1;
  }
  *(c1_type **)rec = type;
  return rec;
}

