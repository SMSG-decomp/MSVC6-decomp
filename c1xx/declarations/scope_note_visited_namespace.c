void __thiscall scope_note_visited_namespace(void *scope,int ns)

{
  c1_u8 *pcVar1;
  short *psVar2;
  
  if (*(int *)((int)scope + 0x218) == 0) {
    pcVar1 = symtab_record_new_kind4();
    *(c1_u8 **)((int)scope + 0x218) = pcVar1;
  }
  psVar2 = vector_find_or_add(*(short **)((int)scope + 0x218),ns);
  *(short **)((int)scope + 0x218) = psVar2;
  return;
}

