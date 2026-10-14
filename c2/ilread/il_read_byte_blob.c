void __fastcall il_read_byte_blob(c2_fe_symbol *rec,int arena)

{
  uint16_t uVar1;
  uint8_t *cursor;
  int iVar2;
  uint32_t size;
  
  uVar1 = il_read_short();
  size = (uint32_t)(short)uVar1;
  (rec->u44).length = uVar1;
  cursor = arena_alloc(arena,size);
  *(uint8_t **)((int)&rec->u3e + 2) = cursor;
  if (0 < (int)size) {
    do {
      iVar2 = il_read_byte();
      *cursor = (uint8_t)iVar2;
      cursor = cursor + 1;
      size = size - 1;
    } while (size != 0);
  }
  return;
}

