c2_eh_state * __fastcall cxx_eh_new_object_record(uint32_t kind,uint32_t guard,uint32_t flag)

{
  c2_eh_state *pcVar1;
  
  pcVar1 = arena_alloc(1,0x44);
  pcVar1->next = g_eh_object_records;
  g_eh_object_records = pcVar1;
  pcVar1->flags = pcVar1->flags & 0xfffffe00 ^ kind & 0xff | (guard & 1) << 8;
  if (guard != 0) {
    create_eh_guard_local(&pcVar1->guard_bit,&pcVar1->guard_word);
  }
  pcVar1->flags = (flag & 1) << 9 | pcVar1->flags & 0xfffffdff;
  return pcVar1;
}

