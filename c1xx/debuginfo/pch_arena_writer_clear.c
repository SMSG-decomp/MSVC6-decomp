void * __fastcall pch_arena_writer_clear(void *obj)

{
  int iVar1;
  uint *cursor;
  
  cursor = obj;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *cursor = 0;
    cursor = cursor + 1;
  }
  return obj;
}

